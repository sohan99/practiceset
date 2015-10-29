import os
import argparse
import socket


class argTest:
	def __init__(self):
		self.Va = "I am initialized \n"
		print("getting initialized \n")
		try:
			self.soc=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
		except socket.error, msg:
			print str(msg[0])
			print "soc creation failed :-( .. try again !!! : )" 
			return;

	def createSoc(self):
		print self.Va

	def getIpforHostName(self,host_name):
		try:
		    remote_ip = socket.gethostbyname( host_name )
		    print remote_ip
		    return remote_ip
		except socket.gaierror:
		    print 'Hostname could not be resolved. Exiting'
		    return 0;


	def connect_toNeighbour(self,remote_ip,port):
		try:
			conn = self.soc.connect((remote_ip,port))
			conn.close();
			print self.soc;
		except:
			print "connection failed to " + remote_ip +"at port "+ port
	

	def __del__(self):
		print "deleted"



if __name__ == '__main__':

	ss= argTest();
	ss.createSoc();
	ip=ss.getIpforHostName("www.google.com")
	ss.connect_toNeighbour(ip,80)
	#ss.connect_toNeighbour("172.16.51.53",80)

