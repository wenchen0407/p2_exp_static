#!/usr/bin/env python
from TOSSIM import Tossim
from random import *
from TestNetworkMsg import *
import sys
import socket

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_address = ('localhost', 10030)
sock.connect(server_address)
try:
	message  = 'client';
	#print "message", message
	sock.sendall(message)
	amount_received = 0	
	amount_expected = len(message)
	#print "amount expected: ", amount_expected
	while amount_received < amount_expected:
		data = sock.recv(90)
		if data:
			amount_received += len(data)
			#print >>sys.stderr, 'received "%s"' % data
			print data
	#print "finised request"

finally:
    sock.close()


