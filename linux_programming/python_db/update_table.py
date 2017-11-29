import mysql.connector
from mysql.connector import Error

try:
	conn = mysql.connector.connect(host="localhost",database="gym",user="root",password="root")
	query = "update customer set name = %s where id = %s"
	cursor = conn.cursor()
	cursor.execute(query,('dranand',3))

	conn.commit()

except Error as msg:
	print "Error connecting to database",msg

finally:
	cursor.close()
	conn.close()
