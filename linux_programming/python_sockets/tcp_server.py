import socket

soc = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
host = "127.0.0.1"
port = 8000

ip_address = socket.gethostbyname(host)
soc.bind((ip_address,port))

soc.listen(10)

conn,adds = soc.accept()

print "connection established "+adds[0]
msg = conn.recv(1024)

while msg != 'q':
	print msg
	msg = conn.recv(1024)
	
conn.close()



