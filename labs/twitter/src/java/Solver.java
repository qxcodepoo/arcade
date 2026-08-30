import java.util.Arrays;
import java.util.Collection;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.stream.Collectors;

class MessageException extends RuntimeException {
    public MessageException(String message) {
        super(message);
    }
}

class Message {
    private int id;
    private String username;
    private String msg;
    //utiliza um set para eliminar duplicatas
    private Set<String> likes;
    public int getId() {
        return this.id;
    }
    //Initialize all attributes
    public Message(int id, String username, String msg) {
        this.id = id;
        this.username = username;
        this.msg = msg;
        this.likes = new TreeSet<String>();
    }
    //add username to likes collection
    public void like(String username) {
        likes.add(username);
    }
    //mount output string
    public String toString() {
        return this.id + ":" + this.username + " (" + this.msg + ")" +
            (this.likes.isEmpty() ? "" : " [" + this.likes.stream().collect(Collectors.joining(", ")) + "]");
    }
}

class Inbox {
    private Map<Integer, Message> unread; //storeReadedMsg unread tweets
    private Map<Integer, Message> allMsgs; //storeReadedMsg read tweets

    public Inbox() {
        this.unread = new TreeMap<>();
        this.allMsgs = new TreeMap<>();
    }

    //stores message both in unread as in allMsgs
    public void storeUnreadMsg(Message tweet) {
        this.unread.put(tweet.getId(), tweet);
        this.allMsgs.put(tweet.getId(), tweet);
    }

    //stores message as a readed Message
    public void storeReadedMsg(Message tweet) {
        this.allMsgs.put(tweet.getId(), tweet);
    }

    //return unread and clean unread Msgs
    public Collection<Message> getUnread() {
        Collection<Message> aux = unread.values();
        this.unread.clear();
        return aux;
    }

    //return all messages
    public Collection<Message> getAll() {
        return allMsgs.values();
    }

    //search for a tweet with this id and return it or throw a MessageException
    public Message getTweet(int id) {
        Message msg = allMsgs.get(id);
        if(msg == null)
            throw new MessageException("fail: tweet nao existe");
        return msg;
    }
    //return allMsgs
    public String toString() {
        return allMsgs.values().stream().map(m -> "" + m).collect(Collectors.joining("\n"));
    }
}

class User{
    private String username; //each user has a unique username
    private Map<String, User> followers; //os meus seguidores
    private Map<String, User> following; //aqueles que eu sigo
    private Inbox inbox; //each user has an inbox

    // Initialize all attributes
    public User(String id) {
        this.username = id;
        followers = new TreeMap<>();
        following = new TreeMap<>();
        inbox = new Inbox();
    }

    //if it's still not following
    //add other to this.following
    //add this to other.followers
    public void follow(User other) {
        if(other == this || following.containsKey(other.username))
            return;
        this.following.put(other.username, other);
        other.followers.put(this.username, this);
    }

    //get the User other from following using username parameter
    //if other is null then return
    //remove other from following
    //remove this from other.followers
    public void unfollow(String username) {
        if(!following.containsKey(username))
            return;
        User other = following.get(username);
        this.following.remove(username);
        other.followers.remove(this.username);
    }

    //retrieve the tweet from inbox and uses method like
    public void like(int twId) {
        this.inbox.getTweet(twId).like(this.username);
    }

    //return inbox object
    public Inbox getInbox() {
        return this.inbox;
    }

    //Store the message in the user's inbox
    //Put the message as an unread message in each of the follower's inbox
    //for each follower, follower.getInbox().st(msg)
    public void sendTweet(Message tw) {
        this.inbox.storeReadedMsg(tw);
        this.followers.values().forEach(user -> user.getInbox().storeUnreadMsg(tw));
    }

    //show all followers and following by name
    public String toString() {
        return username + "\n" +
            "  seguidos   [" + this.following.keySet().stream().collect(Collectors.joining(", ")) + "]\n" +
            "  seguidores [" + this.followers.keySet().stream().collect(Collectors.joining(", ")) + "]";
    }
}

class Controller {
    private Map<String, User> users;
    private Map<Integer, Message> tweets;
    private int nextTwId = 0;

    //create tweet objetc using nextTwId and store it in tweets map
    private Message createTweet(String sender, String msg) {
        Message tw = new Message(nextTwId++, sender, msg);
        tweets.put(tw.getId(), tw);
        return tw;
    }

    public Controller() {
        users = new TreeMap<>();
        tweets = new TreeMap<>();
    }
    //add User if not found
    public void addUser(String username) {
        User user = users.get(username);
        if(user == null)
            users.put(username, new User(username));
    }
    //get user by username or throw a MessageException
    public User getUser(String username) {
        User user = users.get(username);
        if(user == null)
            throw new MessageException("fail: usuario nao encontrado");
        return user;
    }
    //create a new Tweet using createTweet method
    //get the user with getUser
    //call user.sendTweet to deliver the tweet
    public void sendTweet(String username, String msg) {
        User user = this.getUser(username);
        Message tw = this.createTweet(username, msg);
        user.sendTweet(tw);
    }
    //return the toString of allUsers
    public String toString() {
        return this.users.values().stream().map(u -> "" + u).collect(Collectors.joining("\n"));
    }
}

//!KEEP
public class Solver {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Controller sistema = new Controller();
        while(true) {
            String line = scanner.nextLine();
            System.out.println("$" + line);
            List<String> ui = Arrays.asList(line.split(" "));
            try {
                if (ui.get(0).equals("end")) {
                    break;
                } else if (ui.get(0).equals("addUser")) {
                    sistema.addUser(ui.get(1));
                } else if (ui.get(0).equals("show")) {
                    System.out.println(sistema);
                } else if (ui.get(0).equals("follow")) {//goku tina
                    sistema.getUser(ui.get(1)).follow(sistema.getUser(ui.get(2)));
                } else if (ui.get(0).equals("twittar")) {//goku msg
                    sistema.sendTweet(ui.get(1), ui.stream().skip(2).collect(Collectors.joining(" ")));
                } else if (ui.get(0).equals("unread")) {//user
                    System.out.println(sistema.getUser(ui.get(1))); 
                } else if (ui.get(0).equals("timeline")) {//user
                    System.out.println(sistema.getUser(ui.get(1)).getInbox());
                } else if (ui.get(0).equals("like")) {//goku 
                    sistema.getUser(ui.get(1)).like(Integer.parseInt(ui.get(2)));
                } else if (ui.get(0).equals("unfollow")) {//goku tina
                    sistema.getUser(ui.get(1)).unfollow(ui.get(2));
                } else {
                    System.out.println("fail: comando invalido");
                }
            } catch(MessageException rt) {
                System.out.println(rt.getMessage());
            }
        }
        scanner.close();
    }
}
//!OFF
