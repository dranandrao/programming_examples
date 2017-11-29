import socket

try:
	soc = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
except socket.error as msg:
	print "socket creation error "+msg
	exit(0)

host = "127.0.0.1"
port = 8000

try:
	soc.bind((host,port))
except socket.error as msg:
	print "socket bind failed"+msg
	exit(0)

print "socket creation successful"

data = soc.recvfrom(1024)
while data[0] != 'q':
	print data[0]#printing the data.
	soc.sendto(data[0],data[1])#sending data back to client.
	data = soc.recvfrom(1024)#for further iteration.

soc.close()


