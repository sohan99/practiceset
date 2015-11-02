

def checkKeys(Dict_val,key):
	if(Dict_val.has_key(key)):
		print("dictionary has the key : {}".format(key))
	else :
		print ("No key found : {}".format(key))

if __name__ == "__main__":
	key="apsple"
	dictv = {"app":"py","scope":"sys","ver":"1.x","apple":"no"}
	checkKeys(dictv,key)