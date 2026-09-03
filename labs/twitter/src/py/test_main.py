import unittest

from main import TweetNotFoundError, Twitter, UserNotFoundError


class TwitterTest(unittest.TestCase):
    def test_tweet_reaches_author_and_followers(self) -> None:
        twitter = Twitter()
        for username in ("goku", "sara"):
            twitter.add_user(username)
        twitter.follow("goku", "sara")
        twitter.tweet("sara", "hello world")
        self.assertIn("0:sara (hello world)", str(twitter.user("goku").timeline))

    def test_unfollow_removes_authors_tweets_and_like_is_shared(self) -> None:
        twitter = Twitter()
        for username in ("goku", "sara", "tina"):
            twitter.add_user(username)
        twitter.follow("goku", "sara")
        twitter.tweet("sara", "hello")
        twitter.like("goku", 0)
        self.assertIn("[goku]", str(twitter.user("sara").timeline))
        twitter.unfollow("goku", "sara")
        self.assertEqual("", str(twitter.user("goku").timeline))

    def test_missing_users_and_tweets_are_reported(self) -> None:
        twitter = Twitter()
        with self.assertRaises(UserNotFoundError):
            twitter.user("nobody")
        twitter.add_user("goku")
        with self.assertRaises(TweetNotFoundError):
            twitter.like("goku", 0)


if __name__ == "__main__":
    unittest.main()
