import sys
"""evaluetes simple expressions such as a+b , a+c etc.
	pass this as an aguement to the file(escape special charectors in shell while executing ex: a \* b) """

def evaluate_expr(expr):
	
	try:
		if(expr[1] == '+'):
			return float(expr[0]) + float(expr[2]);
		if(expr[1] == '/'):
			return float(expr[0]) / float(expr[2]);
		if(expr[1] == '-'):
			return float(expr[0]) - float(expr[2]);
		if(expr[1] == '*' or expr[1] == ".") :
			return float(expr[0]) * float(expr[2]);
		if(expr[1] == '**' or expr[1] == "^") :
			return float(expr[0]) ** float(expr[2]);
		else :
			print  ("Invalid operator. Use +, -, *, **, ^ ")

	except ZeroDivisionError:
		print ("zero division error")
	except IndexError :
		print ("Usage :%s value1 (+|-|*|/|**|^) value2"%(sys.argv[0]))
	except ValueError:
		print ("Invalid Operand used")
	except : 
		print ("Some error Ocuured")


if __name__ == "__main__":
	
	while (True):
		print ("Enter simple expression with 2 opreands and an operator. ex: (a+b)")
		x=raw_input();
		print list(x)
		# reslt = evaluate_expr(sys.argv[1:])
		# if(reslt):
		# 	print ("result : %d"%reslt) ;


