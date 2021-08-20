package socket;

public class Server {
    public static void main(String[] args) {
        SocketForServer socket=new SocketForServer(25466);
        socket.uiServer();
        socket.accept();
        socket.createOutStream("你好客户端");
        socket.createInStream(socket.accept(),1);
        socket.closeAll();
    }
}
