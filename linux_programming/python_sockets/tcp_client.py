import socket

try:
	soc = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
except socket.error as msg:
	print "error creating socket"+msg
	exit(0)

host = "127.0.0.1"
port = 8000

try:
	remote_ip = socket.gethostbyname(host)
except socket.gaierror as error:
	print "host not resolved"+ error

soc.connect((remote_ip,port))
msg = raw_input("Enter the msg..")
while msg != 'q':

	soc.send(msg)
	msg = raw_input("-->")
	
soc.send("q")

soc.close()

