#server端
import socket
import pretty_errors

print("""""
████████▄               ▄████████           ▀████    ▐████▀              ▄█   ▄█▄ 
███   ▀███             ███    ███             ███▌   ████▀              ███ ▄███▀ 
███    ███             ███    █▀               ███  ▐███                ███▐██▀   
███    ███             ███                     ▀███▄███▀               ▄█████▀    
███    ███           ▀███████████              ████▀██▄               ▀▀█████▄    
███    ███                    ███             ▐███  ▀███                ███▐██▄   
███   ▄███              ▄█    ███            ▄███     ███▄              ███ ▀███▄ 
████████▀             ▄████████▀            ████       ███▄             ███   ▀█▀ 
                                                                        ▀         
"""
      "")
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  #创建socket并说明其使用协议
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)  #
server.bind(("127.0.0.1", 25466))  #绑定服务器ip及端口号
server.listen()  #开始监听客户端请求

print("[服务器开起]  等待客户端连接")
try:
    while True:
        sock, addr = server.accept()
        print("客户端已连接")
        data = sock.recv(1024)
        sock.send(data)
        sock.close()
finally:
    sock.close()
    server.close()
