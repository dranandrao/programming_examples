import mysql.connector
from mysql.connector import Error

try:
	conn = mysql.connector.connect(host="localhost",database="gym",user="root",password="root")
	query = 'select * from customer'
	cursor = conn.cursor()
	cursor.execute(query)

	row = cursor.fetchone()

	while row is not None:
		print row
		row = cursor.fetchone()

except Error as msg:
	print "Error connecting to database",msg

finally:
	cursor.close()
	conn.close()

