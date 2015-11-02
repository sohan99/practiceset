import argparse

parser= argparse.ArgumentParser("Description of example");

#print parser;
#----------------------------

# parser.add_argument("pos1",nargs="+",help="usage python argpar,.py value",type=float);
# #parser.add_argument("pos2",help="usage python argpar,.py value",type=float);



 

# args = parser.parse_args ()

# sum=0;
# for a in args.pos1:
# 	sum = sum + a;

# print ("sum of args is ",sum)


# print("printf if pass : ",args.pos1**3);
# print("printf if pass : ",args.pos2**3);


#-----------------------------


parser.add_argument('-n',"--number",nargs=2,type=int);

arg = parser.parse_args()

print arg