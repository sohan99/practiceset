''' program to print the multiplication table'''

import sys

def MulTablePrinter(num):
	"""prints multiplivcation table of number upto 10"""
	if type(num) not in (int,float):
		print "pass integer value else will print whatever sent"

	for i in range(1,11):
		print ("{} {} {} = {}".format(num,"*",i,num*i))

if __name__ == "__main__":
	for i in sys.argv[1:]:
		try:
			MulTablePrinter(float(i))
		except ValueError:
			MulTablePrinter(i)
		print "--------------------**-----------------"
	
