import mysql.connector
from mysql.connector import Error

try:
	conn = mysql.connector.connect(host="localhost",database="gym",user="root",password="root")
	query = "insert into customer(name,email_id,mobile_number)values(%s,%s,%s)"
	cursor = conn.cursor()
	cursor.execute(query,('anand','ananddr.dranand@gmail.com',7259485997))

	conn.commit()

except Error as msg:
	print "Error connecting to database",msg

finally:
	cursor.close()
	conn.close()
