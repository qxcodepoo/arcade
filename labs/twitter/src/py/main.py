from __future__ import annotations

from dataclasses import dataclass, field
from typing import TextIO


class TwitterError(Exception):
    pass


class UserNotFoundError(TwitterError):
    pass


class TweetNotFoundError(TwitterError):
    pass


@dataclass
class Tweet:
    identifier: int
    author: str
    text: str
    original: Tweet | None = None
    likes: set[str] = field(default_factory=set)
    deleted: bool = False

    def like(self, username: str) -> None:
        self.likes.add(username)

    def __str__(self) -> str:
        if self.deleted:
            return f"{self.identifier}: (esse tweet foi removido)"
        likes = "" if not self.likes else f" [{', '.join(sorted(self.likes))}]"
        return f"{self.identifier}:{self.author} ({self.text}){likes}"


class Timeline:
    def __init__(self) -> None:
        self._tweets: dict[int, Tweet] = {}

    def receive(self, tweet: Tweet) -> None:
        self._tweets[tweet.identifier] = tweet

    def remove_author(self, username: str) -> None:
        self._tweets = {
            identifier: tweet
            for identifier, tweet in self._tweets.items()
            if tweet.author != username
        }

    def find(self, identifier: int) -> Tweet:
        tweet = self._tweets.get(identifier)
        if tweet is None:
            raise TweetNotFoundError("fail: tweet nao existe")
        return tweet

    def __str__(self) -> str:
        visible = [tweet for tweet in self._tweets.values() if not tweet.deleted or tweet.original is not None]
        return "\n".join(str(tweet) for tweet in sorted(visible, key=lambda item: item.identifier, reverse=True))


@dataclass
class User:
    username: str
    followers: dict[str, User] = field(default_factory=dict)
    following: dict[str, User] = field(default_factory=dict)
    timeline: Timeline = field(default_factory=Timeline)

    def follow(self, other: User) -> None:
        if other is self:
            return
        self.following[other.username] = other
        other.followers[self.username] = self

    def unfollow(self, other: User) -> None:
        self.following.pop(other.username, None)
        other.followers.pop(self.username, None)
        self.timeline.remove_author(other.username)


class Twitter:
    def __init__(self) -> None:
        self.users: dict[str, User] = {}
        self.tweets: dict[int, Tweet] = {}
        self._next_tweet_id: int = 0

    def user(self, username: str) -> User:
        user = self.users.get(username)
        if user is None:
            raise UserNotFoundError("fail: usuario nao encontrado")
        return user

    def add_user(self, username: str) -> None:
        if username not in self.users:
            self.users[username] = User(username)

    def follow(self, follower: str, followed: str) -> None:
        self.user(follower).follow(self.user(followed))

    def unfollow(self, follower: str, followed: str) -> None:
        self.user(follower).unfollow(self.user(followed))

    def tweet(self, username: str, text: str) -> Tweet:
        author = self.user(username)
        result = Tweet(self._next_tweet_id, username, text)
        self._next_tweet_id += 1
        self.tweets[result.identifier] = result
        author.timeline.receive(result)
        for follower in author.followers.values():
            follower.timeline.receive(result)
        return result

    def like(self, username: str, identifier: int) -> None:
        self.user(username).timeline.find(identifier).like(username)

    def retweet(self, username: str, identifier: int, text: str) -> Tweet:
        source = self.user(username).timeline.find(identifier)
        result = self.tweet(username, text)
        result.original = source
        return result

    def remove_user(self, username: str) -> None:
        user = self.user(username)
        for other in list(user.followers.values()):
            other.unfollow(user)
        for other in list(user.following.values()):
            user.unfollow(other)
        for tweet in self.tweets.values():
            if tweet.author == username:
                tweet.deleted = True
        del self.users[username]

    def __str__(self) -> str:
        return "\n".join(
            f"{user.username}\n  seguidos   [{', '.join(sorted(user.following))}]\n"
            f"  seguidores [{', '.join(sorted(user.followers))}]"
            for user in sorted(self.users.values(), key=lambda item: item.username)
        )


def main(input_stream: TextIO, output_stream: TextIO) -> None:
    twitter = Twitter()
    for line in input_stream:
        words = line.split()
        try:
            match words:
                case ["add", username]:
                    twitter.add_user(username)
                case ["show"]:
                    print(twitter, file=output_stream)
                case ["follow", follower, followed]:
                    twitter.follow(follower, followed)
                case ["unfollow", follower, followed]:
                    twitter.unfollow(follower, followed)
                case ["twittar", username, *text]:
                    twitter.tweet(username, " ".join(text))
                case ["timeline", username]:
                    print(twitter.user(username).timeline, file=output_stream)
                case ["like", username, identifier]:
                    twitter.like(username, int(identifier))
                case ["rt", username, identifier, *text]:
                    twitter.retweet(username, int(identifier), " ".join(text))
                case ["rm", username]:
                    twitter.remove_user(username)
                case ["end"]:
                    break
        except (ValueError, TwitterError) as error:
            print(error, file=output_stream)


if __name__ == "__main__":
    import sys

    main(sys.stdin, sys.stdout)
