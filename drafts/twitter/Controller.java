import java.util.ArrayList;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

class Tweet{
    int id;
    String userId;
    String msg;
    ArrayList<String> likes;
    public Tweet(int id, String userId, String msg){
        this.id = id;
        this.userId = userId;
        this.msg = msg;
        this.likes = new ArrayList<String>();
    }
    public void darLike(String userId){
        for(String user : likes)
            if(user.equals(userId))
                return;
        likes.add(userId);
    }
    public String toString(){
        String saida = "";
        saida += this.id + ":" + this.userId + "( " + this.msg + ")";
        if(likes.size() > 0){
            saida += "[ ";
            for(String user : this.likes)
                saida += user + " ";
            saida += "]";
        }
        return saida;
    }
}

class Usuario{
    String id;
    ArrayList<Tweet> timeline; 
    ArrayList<Usuario> seguidores;
    ArrayList<Usuario> seguidos;

    public Usuario(String id){
        this.id = id;
        timeline = new ArrayList<Tweet>();
        seguidores = new ArrayList<Usuario>();
        seguidos = new ArrayList<Usuario>();
    }

    public void seguir(Usuario other){
        for(Usuario user : seguidos)
            if(user.id.equals(other.id))
                return;
        this.seguidos.add(other);
        other.seguidores.add(this);
    }

    public Tweet getTweet(int id){
        for(Tweet tw : timeline){
            if(tw.id == id)
                return tw;
        }
        throw new RuntimeException("fail: tweet nao existe");
    }

    public void twittar(Tweet tw){
        this.timeline.add(tw);
        for(Usuario user : seguidores)
            user.timeline.add(tw);
    }

    public String getTimeline(){
        String saida = "";
        for(Tweet tw : this.timeline)
            saida += tw + "\n";
        return saida;
    }

    public String toString(){
        String saida = id;
        saida += "\n  seguidos   [ ";
        for(Usuario user : seguidos)
            saida += user.id + " ";
        saida += "]\n  seguidores [ ";
        for(Usuario user : seguidores)
            saida += user.id + " ";
        saida += "]";
        return saida;
    }
}

class Sistema{
    Map<String, Usuario> usuarios;
    public Sistema(){
        usuarios = new TreeMap<String, Usuario>();
    }

    public void addUsuario(String id){
        Usuario user = usuarios.get(id);
        if(user == null){
            usuarios.put(id, new Usuario(id));
        }
    }

    public Usuario getUsuario(String id){
        Usuario user = usuarios.get(id);
        if(user == null)
            throw new RuntimeException("fail: usuario nao encontrado");
        return user;
    }

    public String toString(){
        String saida = "";
        for(Usuario user : usuarios.values())
            saida += user + "\n";
        return saida;
    }
}

public class Controller {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Sistema sistema = new Sistema();
        int nextTwId = 0;
        while(true){
            String line = scanner.nextLine();
            System.out.println("$" + line);
            String ui[] = line.split(" ");

            try {
                if (ui[0].equals("end"))
                    break;
                else if (ui[0].equals("addUser")) {
                    sistema.addUsuario(ui[1]);
                } else if (ui[0].equals("show")) {
                    System.out.print(sistema);
                } else if (ui[0].equals("follow")) {//goku tina
                    Usuario one = sistema.getUsuario(ui[1]);
                    Usuario two = sistema.getUsuario(ui[2]);
                    one.seguir(two);
                }
                else if (ui[0].equals("twittar")) {//goku msg
                    Usuario user = sistema.getUsuario(ui[1]);
                    String msg = "";
                    for(int i = 2; i < ui.length; i++)
                        msg += ui[i] + " ";
                    Tweet tw = new Tweet(nextTwId++, ui[1], msg);
                    user.twittar(tw);
                }
                else if (ui[0].equals("timeline")) {//goku tina
                    Usuario user = sistema.getUsuario(ui[1]);
                    System.out.print(user.getTimeline());
                }
                else if (ui[0].equals("like")) {//goku tina
                    Usuario user = sistema.getUsuario(ui[1]);
                    Tweet tw = user.getTweet(Integer.parseInt(ui[2]));
                    tw.darLike(ui[1]);
                }else{
                    System.out.println("fail: comando invalido");
                }
            }catch(RuntimeException rt){
                System.out.println(rt.getMessage());
            }
        }
        scanner.close();
    }

}
