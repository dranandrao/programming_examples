import mysql.connector
from mysql.connector import Error

try:
	conn = mysql.connector.connect(host="localhost",database="gym",user="root",password="root")
	query = "delete from customer where id = '%d'"
	cursor = conn.cursor()
	cursor.execute(query,1)
	conn.commit()

except Error as msg:
	print "Error connecting to database",msg

finally:
	cursor.close()
	conn.close()