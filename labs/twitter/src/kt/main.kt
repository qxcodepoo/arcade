open class TwitterError(message: String) : Exception(message)

class UserNotFoundError : TwitterError("fail: usuario nao encontrado")
class TweetNotFoundError : TwitterError("fail: tweet nao existe")

class Tweet(
    val identifier: Int,
    val author: String,
    val text: String,
    var original: Tweet? = null,
) {
    val likes: MutableSet<String> = linkedSetOf()
    var deleted: Boolean = false

    fun like(username: String): Unit {
        likes.add(username)
    }

    override fun toString(): String {
        if (deleted) {
            return "$identifier: (esse tweet foi removido)"
        }
        val likeList: String = if (likes.isEmpty()) "" else " [${likes.sorted().joinToString(", ")}]"
        return "$identifier:$author ($text)$likeList"
    }
}

class Timeline {
    private val tweets: MutableMap<Int, Tweet> = linkedMapOf()

    fun receive(tweet: Tweet): Unit {
        tweets[tweet.identifier] = tweet
    }

    fun removeAuthor(username: String): Unit {
        val identifiers: List<Int> = tweets.values
            .filter { it.author == username }
            .map { it.identifier }
        identifiers.forEach { tweets.remove(it) }
    }

    fun find(identifier: Int): Tweet =
        tweets[identifier] ?: throw TweetNotFoundError()

    override fun toString(): String =
        tweets.values
            .filter { !it.deleted || it.original != null }
            .sortedByDescending { it.identifier }
            .joinToString("\n")
}

class User(val username: String) {
    val followers: MutableMap<String, User> = linkedMapOf()
    val following: MutableMap<String, User> = linkedMapOf()
    val timeline: Timeline = Timeline()

    fun follow(other: User): Unit {
        if (other === this) {
            return
        }
        following[other.username] = other
        other.followers[username] = this
    }

    fun unfollow(other: User): Unit {
        following.remove(other.username)
        other.followers.remove(username)
        timeline.removeAuthor(other.username)
    }
}

class Twitter {
    private val users: MutableMap<String, User> = linkedMapOf()
    private val tweets: MutableMap<Int, Tweet> = linkedMapOf()
    private var nextTweetId: Int = 0

    fun user(username: String): User = users[username] ?: throw UserNotFoundError()

    fun addUser(username: String): Unit {
        if (!users.containsKey(username)) {
            users[username] = User(username)
        }
    }

    fun follow(follower: String, followed: String): Unit {
        user(follower).follow(user(followed))
    }

    fun unfollow(follower: String, followed: String): Unit {
        user(follower).unfollow(user(followed))
    }

    fun tweet(username: String, text: String): Tweet {
        val author: User = user(username)
        val tweet: Tweet = Tweet(nextTweetId, username, text)
        nextTweetId += 1
        tweets[tweet.identifier] = tweet
        author.timeline.receive(tweet)
        author.followers.values.forEach { it.timeline.receive(tweet) }
        return tweet
    }

    fun like(username: String, identifier: Int): Unit {
        user(username).timeline.find(identifier).like(username)
    }

    fun retweet(username: String, identifier: Int, text: String): Tweet {
        val source: Tweet = user(username).timeline.find(identifier)
        val retweet: Tweet = tweet(username, text)
        retweet.original = source
        return retweet
    }

    fun removeUser(username: String): Unit {
        val user: User = user(username)
        user.followers.values.toList().forEach { it.unfollow(user) }
        user.following.values.toList().forEach { user.unfollow(it) }
        tweets.values.filter { it.author == username }.forEach { it.deleted = true }
        users.remove(username)
    }

    override fun toString(): String = users.values
        .sortedBy { it.username }
        .joinToString("\n") { user ->
            "${user.username}\n  seguidos   [${user.following.keys.sorted().joinToString(", ")}]\n" +
                "  seguidores [${user.followers.keys.sorted().joinToString(", ")}]"
        }
}

fun main(): Unit {
    val twitter: Twitter = Twitter()

    while (true) {
        val line: String = readlnOrNull() ?: break
        println("\$$line")
        val words: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }

        try {
            when {
                words.size == 2 && words[0] == "add" -> twitter.addUser(words[1])
                words == listOf("show") -> println(twitter)
                words.size == 3 && words[0] == "follow" -> twitter.follow(words[1], words[2])
                words.size == 3 && words[0] == "unfollow" -> twitter.unfollow(words[1], words[2])
                words.size >= 2 && words[0] == "twittar" ->
                    twitter.tweet(words[1], words.drop(2).joinToString(" "))
                words.size == 2 && words[0] == "timeline" -> {
                    val timeline: String = twitter.user(words[1]).timeline.toString()
                    if (timeline.isNotEmpty()) println(timeline)
                }
                words.size == 3 && words[0] == "like" -> twitter.like(words[1], words[2].toInt())
                words.size >= 3 && words[0] == "rt" ->
                    twitter.retweet(words[1], words[2].toInt(), words.drop(3).joinToString(" "))
                words.size == 2 && words[0] == "rm" -> twitter.removeUser(words[1])
                words == listOf("end") -> break
            }
        } catch (_: NumberFormatException) {
            println(INVALID_ARGUMENT_MSG)
        } catch (error: TwitterError) {
            println(error.message ?: INVALID_ARGUMENT_MSG)
        }
    }
}

const val INVALID_ARGUMENT_MSG: String = "fail: argumento invalido"
