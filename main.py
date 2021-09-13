#!/usr/bin/python

import socket

host = "/tmp/9Lq7BNBnBycd6nxy.socket"

sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
sock.connect((host))

while 1:
        received = str(sock.recv(1024), "utf-8")
        print(float(received))

        sock.sendall(bytes('Compra!' + "\n", "utf-8"))