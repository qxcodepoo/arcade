/*************************
 * Created by Lucas Robs *
 *************************/

import java.util.*;

class WhatsappService{
  private HashMap<String, Chat> rep_chat = new HashMap<String, Chat>();
  private HashMap<String, User> rep_user = new HashMap<String, User>();
  
  protected User getUser(String userId) {
    return rep_user.get(userId);
  }
  
  protected Chat getChat(String chatId) {
    return rep_chat.get(chatId);
  }
  
  public String getUsersChat(String chatId) {
    Chat chat = getChat(chatId);
    StringBuilder users = new StringBuilder();
    users.append("[");
    for(User user : chat.getUsers().values())
      users.append(user.getId()+ " ");
    if (users.length() > 1)
      users.deleteCharAt(users.length()-1);
    users.append("]");
    return users.toString();
  }

  public String getChatsUser(String userId) {
    User user = getUser(userId);
    StringBuilder chats = new StringBuilder();
    chats.append("[");
    for(Chat chat : user.getChats().values())
      chats.append(chat.getId() + " ");
    if (chats.length() > 1)
      chats.deleteCharAt(chats.length()-1);
    chats.append("]");
    return(chats.toString());
  }

  public String getNotifyUser(String userId  ) {
      User user = getUser(userId);
      StringBuilder chats = new StringBuilder();  
      chats.append("[");
      for(Chat chat : user.getChats().values()) {
        chats.append(chat.getId());
        if (user.getNotifyUser(chat.getId()).getUnreadCount() > 0)
          chats.append("("+ user.getNotifyUser(chat.getId()).getUnreadCount() +") ");
        else
          chats.append(" ");
      }
      if (chats.length() > 1)
        chats.deleteCharAt(chats.length()-1);
      chats.append("]");
      return(chats.toString());
    }

  protected boolean chatExiste(Chat chat) {
    if (chat == null) {
      return false;
    }
    return true;
  }

  protected boolean userExiste(User user) {
    if (user == null) {
      return false;
    }
    return true;
  }

  public void createChat(String userId, String chatId) {
    if (chatExiste(getChat(chatId))) {
      System.out.println("fail: chat "+ chatId +" ja existe");
      return;
    }
    Chat chat = new Chat(chatId);
    User user = getUser(userId);
    if (!userExiste(user)) {
      System.out.println("fail: User nao encontrado!");
      return;
    }
    chat.addUserChat(user);
    rep_chat.put(chatId, chat);
  }

  public void addByInvite(String guessId, String invitedId, String chatId) {
    Chat chat = getChat(chatId);
    User guess = getUser(guessId);
    User invited = getUser(invitedId);
    if (!userExiste(guess))
      System.out.println("fail: User "+ guessId +" nao encontrado!");
    else if (!userExiste(invited))
      System.out.println("fail: User "+ invitedId +" nao encontrado!");
    else if (!chatExiste(chat))
      System.out.println("fail: Chat "+ chatId +" nao encontrado!");
    chat.addByInvite(guess, invited);
  }

  public void createUser(String userId) {
    if (userExiste(rep_user.get(userId)))
      System.out.println("fail: User "+ userId +" já existe!");
    rep_user.put(userId, new User(userId));
  }

  public String allUsers() {
    StringBuilder users = new StringBuilder();
    users.append("[");
    for(User user : rep_user.values())
      users.append(user.getId() + " ");
    if (users.length() > 1)
      users.deleteCharAt(users.length()-1);
    users.append("]");
    return(users.toString());
  }

  public void removerUserChat(String userId, String chatId) {
    Chat chat = getChat(chatId);
    User user = getUser(userId);
    chat.rmUserChat(user);
  }

  public void sendMessage(String userId, String chatId, String message) {
    getChat(chatId).deliverZap(getUser(userId), message);
  }

  public String readMessageUserChat(String userId, String chatId) {
    User user = getUser(userId);
    Chat chat = getChat(chatId);
    if (userExiste(user) && chatExiste(chat)) {
      if (chat.hasUser(user)) {
        StringBuilder mensagensUnRead = new StringBuilder();
        int unreadCount = user.getNotifyUser(chatId).getUnreadCount();
        int sizeChat = chat.getInboxUser(user).getMsgs().size();
        int readCount = sizeChat - unreadCount;
        int i = 0;
        for(Msg msg : chat.getInboxUser(user).getMsgs()) {
          if (i >= readCount) {
            mensagensUnRead.append(msg.toString());
            if (i != sizeChat -1)
              mensagensUnRead.append("\n");
          }
          i++;
        }
        user.getNotifyUser(chatId).eraseCount();
        return mensagensUnRead.toString();
      } else {
        return "fail: user "+userId+" nao esta no chat "+chatId;
      }
    } else
      return "fail: chat ou user nao encontrado";
  }
}

class User{
  private String id;
  protected HashMap<String, Chat> chats  = new HashMap<String, Chat>();
  protected ArrayList<Counter> notify = new ArrayList<Counter>();

  public User(String nome) {
    id = nome;
  }

  public HashMap<String, Chat> getChats() {
    return chats;
  }

  public ArrayList<Counter> getNotification() {
    return notify;
  }

  public Counter getNotifyUser(String chat) {
    for(Counter noty : notify)
      if (chat.equals(noty.getId()))
        return noty;
    return null;
  }

  public void addChat(Chat chat) {
    chats.put(chat.getId(), chat);
  }

  public void addNotification(Chat chat) {
    notify.add(new Counter(chat.getId()));
  }

  public void rmChat(Chat chat) {
    chats.remove(chat.getId());
  }

  public String getId() {
    return id;
  }
}

class Counter{
  public String chatId;
  public int  unreadCount;

  public Counter(String chatId) {
    this.chatId = chatId;
  }

  public String getId() {
    return chatId;
  }

  public int getUnreadCount() {
    return unreadCount;
  }

  public void increaseCount() {
    unreadCount++;
  }

  public void eraseCount() {
    unreadCount = 0;
  }
}

class Chat{
  private String id;
  protected HashMap<String, Inbox> inboxes = new HashMap<String, Inbox>();
  protected HashMap<String, User> users = new HashMap<String, User>();

  public Chat(String idChat) {
    id = idChat;
  }

  public String getMsgs(User user) {
    StringBuilder msgs = new StringBuilder();
    for(Msg m : getInboxUser(user).getMsgs())
      msgs.append("["+ m.userId +": "+ m.text+"]\n");
    msgs.deleteCharAt(msgs.length()-1);
    return msgs.toString();
  }

  public HashMap<String, User> getUsers() {
    return users;
  }

  public void deliverZap(User userSend, String message) {
    for(User user : users.values())
      if (userSend != user) {
        getInboxUser(user).addMsg(userSend.getId(), message);
        user.getNotifyUser(this.id).increaseCount();
      }
  }

  public Inbox getInboxUser(User user) {
    return inboxes.get(user.getId());
  }

  public int unreadCount(User user) {
    for(Inbox inbox : inboxes.values())
      if (inbox.user == user)
        return inbox.msgs.size();
    return 0;
  }

  public Boolean hasUser(User user) {
    return users.containsValue(user);
  }

  public void addUserChat(User user) {
    users.put(user.getId(), user);
    inboxes.put(user.getId(), new Inbox(user));
    user.addNotification(this);
    user.addChat(this);
  }

  public void addByInvite(User guess, User invited) {
    if (hasUser(guess))
      addUserChat(invited);
    else
      System.out.println("fail: user "+ guess.getId() +" nao esta em chat "+ this.id);
  }

  public void rmUserChat(User user) {
    user.rmChat(this);
    users.remove(user.getId());
    inboxes.remove(user.getId());
  }

  public String getId() {
    return id;
  }
}

class Inbox{
  public User user;
  public ArrayList<Msg> msgs = new ArrayList<Msg>();

  public Inbox(User user) {
    this.user = user;
  }

  public User getUser() {
    return user;
  }

  public void addMsg(String userId, String msg) {
    msgs.add(new Msg(userId, msg));
  }

  public ArrayList<Msg> getMsgs() {
    return msgs;
  }
}

class Msg{
  public String userId;
  public String text;

  public Msg(String userId, String msg) {
    this.userId = userId;
    text = msg;
  }

  public String toString() {
    return "["+userId+":"+" "+text+"]";
  }
}

public class Solver {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    WhatsappService zap = new WhatsappService();
    while(true) {
      String line = scanner.nextLine();
      System.out.println("$" + line);
      String[] ui = line.split(" ");
      if (ui[0].equals("end"))
        break;
      else if (ui[0].equals("addUser"))
        zap.createUser(ui[1]);
      else if (ui[0].equals("allUsers"))
        System.out.println(zap.allUsers());
      else if (ui[0].equals("newChat"))
        zap.createChat(ui[1], ui[2]);
      else if (ui[0].equals("chats"))
        System.out.println(zap.getChatsUser(ui[1]));
      else if (ui[0].equals("invite"))
        zap.addByInvite(ui[1], ui[2], ui[3]);
      else if (ui[0].equals("users"))
        System.out.println(zap.getUsersChat(ui[1]));
      else if (ui[0].equals("leave"))
        zap.removerUserChat(ui[1], ui[2]);
      else if (ui[0].equals("zap")) {
        StringBuilder msg = new StringBuilder();
        for(int i = 3; i < ui.length; i++)
          msg.append(ui[i]+" ");
        msg.deleteCharAt(msg.length()-1);
        zap.sendMessage(ui[1], ui[2], msg.toString());
      } else if (ui[0].equals("notify"))
        System.out.println(zap.getNotifyUser(ui[1]));
      else if (ui[0].equals("ler"))
        System.out.println(zap.readMessageUserChat(ui[1], ui[2]));
      else
        System.out.println("fail: comando invalido");
    }
    scanner.close();
  }
}