#hamming distance of the given string;
## implementation reffered from wiki example
def findHamDist(list1,list2):
	'''Implement a python code to check the hamming distance between two strings.'''
	if (len(list1)!=len(list2)):
		raise ValueError("Value length not matching.")
	return sum(ch1!=ch2 for ch1,ch2 in zip(list1,list2))

if __name__ == "__main__":
	# if problem sent is string
	print("Haming distance of '12345','54321' is %d "%findHamDist("12345","54321"));
	# if sent as list
	l1=[1,2,3,4,5,"21","junk"];
	l2=[5,4,3,2,1,"23","junk"];

	print("Hamming distance of {0} {1} is {2} ".format(l1, l2,findHamDist(l1,l2)));
