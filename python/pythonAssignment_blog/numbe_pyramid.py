#""" 9.Implement a python code to print a number pyramid. (Make use of for loop)"""

import sys


def printPyramid(num):
	try:
		num = int(num)

	except:
		print ("arguement passed invalid. Pass only integer")

		sys.exit()
	strP=""
	#space that each line should print in the start of the line
	space_start="  "
	#spacce between integer is ioone less than start space
	space_btw = " "	
	for i in range(0,num):
		#loop to add space
		for j in range(0,num-i-1):
			strP=strP+space_start
		#loop to print increasing numbers
		for j in xrange(0,i+1):
			strP = strP+str(j)+space_btw
		#loop to store decreasing numbers
		for j in xrange(i,0,-1):
			strP = strP+str(j-1)+space_btw
		#completion of one line so add new line to start before next loop

		#-------uncomment bellow for a single for loop
		# for j in xrange(0,i+i+1):
		# 	if(j>i):
		# 		j=i-1-(j%(i+1))
		# 	strP = strP+str(j)+" "

		strP += "\n"

	print ("pyramid of size {} : \n{}".format(num,strP));





if __name__ == "__main__":

	printPyramid(sys.argv[1])


