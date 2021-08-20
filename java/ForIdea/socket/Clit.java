package socket;

public class Clit {
    public static void main(String[] args) {
        SocketForClit socket=new SocketForClit("127.0.0.1",25466);
        socket.createOutStream("hello");
        socket.createInStream();
        socket.closeSocket();
    }
}
