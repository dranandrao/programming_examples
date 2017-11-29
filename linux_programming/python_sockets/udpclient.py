import socket

try:
	soc = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
except socket.error as msg:
	print "Socket creation failed"+msg;

host = '127.0.0.1'
port = 8000

msg = raw_input("Enter the text to be sent..")


while msg != 'q':

	soc.sendto(msg,(host,port))

	data = soc.recvfrom(4000)
	print data[0]
	msg = raw_input("-->")

soc.sendto(msg,(host,port))