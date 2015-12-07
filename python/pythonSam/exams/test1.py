import sys
import os
argv=sys.argv


def sumOfArg(argv):
	error = [];
	sum=0;

	for i in argv[0:]:
		try:
			print i
			sum=sum+int(i);
		except:
			error.append(i);
	if error:
		print error,"is not a number"
	print __name__
	print "sum is ",sum
	return
	pass

def fnc(x,y=10,*variable):
	x=x.copy()
	print "y",y
	x['d']=99

	print "bellow are variable length arg"
	for i in variable:
		print i,len(variable),type(i)

	return

if __name__ == 'test1':
	print "I am called"

def __main__(argc):
	print "i am main function .. but no body calls me"

if __name__ == '__main__':
	#sumOfArg(argv[1:]);	x= input("a,b")
	l={'d':2};
	fnc(l,989898,5445,56565,5656)
	print l

	#x=True

