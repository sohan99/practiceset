#code to print the current username
#-- one implementation
import getpass
print ("current login user name is : {}".format(getpass.getuser()));

#-- other implementation
# import os
# if __name__=="__main__":
# 	print ("current login user name is : {}".format(os.getlogin()));