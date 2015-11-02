# to chechk the given number is amstrong or not

import sys

def check_amstrong(intNum):
	#convert the number to string
	strNum = str(intNum);
	#convbert the string to list
	ListNum = list(strNum);

	#calculate power of length

	size_num =  len(ListNum);
	sum = 0;
	for i in ListNum:
		sum=sum+(int(i)**size_num);

	#	assert sum == 371
	if (sum == intNum):
		return 1;
	return 0
	


if __name__ == "__main__":
	li = []
	for i in sys.argv[1:]:
		try:
			check_amstrong(int(i));
		except ValueError:
			li.append(i)

	if(li):
		print("{} is not a valid integer".format(li));
