'''Implement a python code to move the elements in 
the following: Index[first] movie to index[last],
 index[first+1] to index[last-1] and son on till mid is reached.'''
import sys
def reverseList(listVal):
	length = len(listVal);
	j=length-1;
	i=0;
	while (i<j):
		temp = listVal[i]
		listVal[i] = listVal[j]
		listVal[j] = temp
		i+=1
		j-=1

	return listVal;

if __name__ == "__main__":
	valu = reverseList(sys.argv[1:])
	# l=[12,2,3,4,5,6]
	# valu = reverseList(l)	# test for pass by referenece wil change the passed value
	# print l , valu	
	print ("after interchanging result : {}".format(valu))
	
