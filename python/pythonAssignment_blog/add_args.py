# author: sohan99


import sys

def add_args(arg_list):
	"""function to find the sum of given iterables"""
	sum = 0.0;
	notInt=[];
	for i in arg_list:
		try:
			sum=sum + float(i)
		except: 
			notInt.append(i);
	pass
	# print if invalid arguements passed
	if(notInt):
		print("{} is not a valid arguement to calculate sum".format(notInt));
	# return 0 if no value sent else return calculated sum
	return sum


if __name__ == "__main__":
	result = add_args(sys.argv[1:]);
	print ("sum : %d"%(result))
