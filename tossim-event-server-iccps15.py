#!/usr/bin/env python
from TOSSIM import Tossim
from random import *
from TestNetworkMsg import *
import sys
import socket
import os
import time
import os.path
import numpy as np
from subprocess import call
import random

#rssi_linkError = {
#	-78: 0.345,
#	-74: 0.2,
#	-70: 0.147,
#	-66: 0.085,
#	-62: 0.058,
#}

rssi_linkError = {
	-62: 0.035,
	-66: 0.11,
	-70: 0.125,
	-74: 0.17,
	-78: 0.19,
	-82: 0.24,
	-86: 0.43,
}



kconnect1={
	20: -0.592222,
	21: -0.568992,
	22:	-0.541237,
	23:	-0.507183,
	24:	-0.465542,
	25:	-0.414768,
	26:	-0.353005,
	27:	-0.278028,
	28:	-0.267309,
	29:	-0.256199,
	30:	-0.24468,
	31:	-0.232733,
	32:	-0.22034,
	33:	-0.20748,
	34:	-0.194133,
	35:	-0.19654,
	36:	-0.199065,
	37:	-0.201708,
	38:	-0.204468,
	39:	-0.207345,
	40:	-0.210339,
	41:	-0.21345,
}

kconnect2={
	23:	-0.546018,
	24:	-0.511801,
	25:	-0.470319,
	26:	-0.41968,
	27:	-0.358042,
	28:	-0.283183,
	29:	-0.192431,
	30:	-0.0825811,
	31:	-0.0653402,
	32:	-0.0474029,
	33:	-0.0287902,
	34:	-0.00949119,
	35:	0.0105166,
	36:	0.0312596,
	37:	0.0527667,
	38:	0.0516197,
	39:	0.0503853,
	40:	0.0490508,
	41:	0.0476124,
	42:	0.0460688,
	43:	0.0444198,
	44:	0.0426656,

}

kconnect3={
	26:	-0.547402,
	27:	-0.511102,
	28:	-0.466912,
	29:	-0.412925,
	30:	-0.347179,
	31:	-0.267304,
	32:	-0.170448,
	33:	-0.0531863,
	34:	-0.0348501,
	35:	-0.0157374,
	36:	0.00411403,
	37:	0.0247108,
	38:	0.046075,
	39:	0.0682343,
	40:	0.0912192,
	41:	0.0900133,
	42:	0.08873,
	43:	0.0873519,
	44:	0.0858732,
	45:	0.0842921,
	46:	0.0826082,
	47:	0.0808217,
}

kconnect4={
	29:	-0.560627,
	30:	-0.524238,
	31:	-0.479835,
	32:	-0.425505,
	33:	-0.359261,
	34:	-0.278701,
	35:	-0.180938,
	36:	-0.0625028,
	37:	-0.0442835,
	38:	-0.0252715,
	39:	-0.00550773,
	40:	0.0150134,
	41:	0.0363139,
	42:	0.0584217,
	43:	0.0813678,
	44:	0.079809,
	45:	0.0781749,
	46:	0.076447,
	47:	0.0746191,
	48:	0.0726895,
	49:	0.0706576,
	50:	0.0685235,
}



def get_max_delta(num_node):
	res = -9999
	new_k = 0
	if num_node in kconnect1 and res < kconnect1[num_node]:
		res = kconnect1[num_node]
		new_k = 1
	if num_node in kconnect2 and res < kconnect2[num_node]:
		res = kconnect2[num_node]
		new_k=2
	if num_node in kconnect3 and res < kconnect3[num_node]:
		res = kconnect3[num_node]	
		new_k=3
	if num_node in kconnect4 and res < kconnect4[num_node]:
		res = kconnect4[num_node]
		new_k=4
	return new_k

enable_main=1
if enable_main:
	def main():
		rssi_level=sys.argv[1]
		return {'y0':rssi_level}
	rssi_level=int(main()['y0'])
else:
	rssi_level=-20;

t = Tossim([])
t.addChannel('printf', sys.stdout)
t.addChannel("DataFeedback", sys.stdout)
r = t.radio()

# offline network topology initialization to make 1-DR = p_1*d^2+p_2*d^2+p_3
#print "linkError: ", str(rssi_linkError[rssi_level])
#subprocess.call(["a.out", str(rssi_linkError[rssi_level])])


def initialize_network():

	# this is topology for channel 26
	f = open("topo.txt", "r")

	#wireless rssi topology injection & model establishment
	lines = f.readlines()
	#initialize schedule
	L_topo=list()
	L_topo.append(0)
	topo=lines[0].split()
	for topo_node in topo:
	    L_topo.append(int(topo_node))

	#print "L_topo: ", L_topo
	for channel_1 in [22, 23, 24, 25, 26]:
		channel=channel_1
		rssi_strength=rssi_level
		neignbour_strength=100
		sync_rssi_strength=100
		
		#for sender in range(1, 51):
		#	for receiver in range(1, 51):
		#		r.add(sender, receiver, float(neignbour_strength), channel_1)

		for i in range(1, len(lines)-1):
		    nodes_pre = lines[i].split()
		    nodes_post = lines[i+1].split()
		    for node1 in nodes_pre:
		        r.add(int(node1), 0, float(sync_rssi_strength), channel)
		        r.add(0, int(node1), float(sync_rssi_strength), channel)
		        #print "( "+str(node1)+", "+"0 )"+" rssi_level: "+str(float(sync_rssi_strength))
		        #schedule[i][j]=int(node1)
		        for node2 in nodes_post:
		            if i<len(lines)-2:
		                r.add(int(node1), int(node2), float(rssi_level), channel)
		                r.add(int(node2), int(node1), float(rssi_level), channel)
		            else:
		                r.add(int(node1), int(node2), float(neignbour_strength), channel)
		                r.add(int(node2), int(node1), float(neignbour_strength), channel)		            	
		                print "( "+str(node1)+", "+str(node2)+" )"+" rssi_level: "+str(float(neignbour_strength))
		                print "( "+str(node2)+", "+str(node1)+" )"+" rssi_level: "+str(float(neignbour_strength))

		for node in lines[len(lines)-1].split():
			r.add(int(node), 0, float(sync_rssi_strength), channel)
			r.add(0, int(node), float(sync_rssi_strength), channel)
			#print "( "+str(node)+", "+"0 )"+" rssi_level: "+str(float(sync_rssi_strength))
		i=0
		for line in lines:
		    if i!=0:
		        ns = line.split()
		        for n in ns:
		            for sibling in ns:
		                if int(n)!=int(sibling):
		                    r.add(int(n), int(sibling), float(neignbour_strength), channel)
		                    r.add(int(sibling), int(n), float(neignbour_strength), channel)
		                    #print "( "+str(n)+", "+str(sibling)+" )"+" rssi_level: "+str(float(-10))
		                    #print "( "+str(sibling)+", "+str(n)+" )"+" rssi_level: "+str(float(-10))
		    i=i+1
		for sensor in range(1, 51):
			r.add(sensor, 0, float(sync_rssi_strength), channel_1)
			r.add(0, sensor, float(sync_rssi_strength), channel_1)

	
	for node in range(0, 51):
		m = t.getNode(node);
		for channel in [22, 23, 24, 25, 26]:
			if channel==22:
				noise = open("noise_chan22_110.txt", "r")
				lines = noise.readlines()
			elif channel==23:
				noise = open("noise_chan23_110.txt", "r")
				lines = noise.readlines()
			elif channel==24:
				noise = open("noise_chan24_110.txt", "r")
				lines = noise.readlines()
			elif channel==25:
				noise = open("noise_chan25_110.txt", "r")
				lines = noise.readlines()
			elif channel==26:
				noise = open("noise_chan26_110.txt", "r")
				lines = noise.readlines()
			for line in lines:
				strrr = line.strip()
				if (strrr != ""):
					val = int(strrr)
					m.addNoiseTraceReading(val, channel)
			m.createNoiseModel(channel);
		m.turnOn()
		m.bootAtTime(0)
		print "Booting ", node, " at time ", str(0)
	return len(topo)
	#

# initial network topology

def get_new_topo(new_noise_strength):
	f = open("topology.txt", "r")

	#wireless rssi topology injection & model establishment
	lines = f.readlines()
	#initialize schedule
	L_topo=list()
	L_topo.append(0)
	topo=lines[0].split()
	for topo_node in topo:
	    L_topo.append(int(topo_node))

	#print "L_topo: ", L_topo
	for channel_1 in [22, 23, 24, 25, 26]:
		channel=channel_1
		rssi_strength=new_rssi_level
		neignbour_strength=100
		sync_rssi_strength=100
		
		#for sender in range(1, 51):
		#	for receiver in range(1, 51):
		#		r.add(sender, receiver, float(neignbour_strength), channel_1)

		for i in range(1, len(lines)-1):
		    nodes_pre = lines[i].split()
		    nodes_post = lines[i+1].split()
		    for node1 in nodes_pre:
		        r.add(int(node1), 0, float(sync_rssi_strength), channel)
		        r.add(0, int(node1), float(sync_rssi_strength), channel)
		        #print "( "+str(node1)+", "+"0 )"+" rssi_level: "+str(float(sync_rssi_strength))
		        #schedule[i][j]=int(node1)
		        for node2 in nodes_post:
		            if i<len(lines)-2:
		                r.add(int(node1), int(node2), float(rssi_strength), channel)
		                r.add(int(node2), int(node1), float(rssi_strength), channel)
		            else:
		                r.add(int(node1), int(node2), float(neignbour_strength), channel)
		                r.add(int(node2), int(node1), float(neignbour_strength), channel)		            	
		                print "( "+str(node1)+", "+str(node2)+" )"+" rssi_level: "+str(float(neignbour_strength))
		                print "( "+str(node2)+", "+str(node1)+" )"+" rssi_level: "+str(float(neignbour_strength))

		for node in lines[len(lines)-1].split():
			r.add(int(node), 0, float(sync_rssi_strength), channel)
			r.add(0, int(node), float(sync_rssi_strength), channel)
			#print "( "+str(node)+", "+"0 )"+" rssi_level: "+str(float(sync_rssi_strength))
		i=0
		for line in lines:
		    if i!=0:
		        ns = line.split()
		        for n in ns:
		            for sibling in ns:
		                if int(n)!=int(sibling):
		                    r.add(int(n), int(sibling), float(neignbour_strength), channel)
		                    r.add(int(sibling), int(n), float(neignbour_strength), channel)
		                    #print "( "+str(n)+", "+str(sibling)+" )"+" rssi_level: "+str(float(-10))
		                    #print "( "+str(sibling)+", "+str(n)+" )"+" rssi_level: "+str(float(-10))
		    i=i+1
		for sensor in range(1, 51):
			r.add(sensor, 0, float(sync_rssi_strength), channel_1)
			r.add(0, sensor, float(sync_rssi_strength), channel_1)

	for node in range(0, len(topo)+1):
		m = t.getNode(node);
		for channel in [22, 23, 24, 25, 26]:
			if channel==22:
				noise = open("noise_chan22_110.txt", "r")
				lines = noise.readlines()
			elif channel==23:
				noise = open("noise_chan23_110.txt", "r")
				lines = noise.readlines()
			elif channel==24:
				noise = open("noise_chan24_110.txt", "r")
				lines = noise.readlines()
			elif channel==25:
				noise = open("noise_chan25_110.txt", "r")
				lines = noise.readlines()
			elif channel==26:
				noise = open("noise_chan26_110.txt", "r")
				lines = noise.readlines()
			for line in lines:
				strrr = line.strip()
				if (strrr != ""):
					val = int(strrr)-new_noise_strength
					m.addNoiseTraceReading(val, channel)
			m.createNoiseModel(channel);
		m.turnOn()
		m.bootAtTime(0)
		print "Booting ", node, " at time ", str(0)

initialize_network()
totalnode = 20
#print "totalnode: ", totalnode
CONNECTIVITY = 4
RSSI_DURATION = 60
THRESHOLD = 0.7
NUM_MEASUREMENTS=3
BACKLEVELS = 7
CONSEGOODNH=2
good_NH_counter=0
curr_NH_ratio=0.0
counter =0
#last_NH_ratio=0.0
#interval = 36
p1=-0.7141
p2=-0.1383
p3=0.3305

seed=0

FRAMELENGTH=55
MAXNODES = 50
# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_address = ('localhost', 10030)
print >>sys.stderr, 'starting up on %s port %s' % server_address
sock.bind(server_address)
sock.listen(1)

run_count = 1
sample_times = 0
consecutive_NH_counter=0
#flag bit for all 14 flows: 8 emergency flows + 2 regular flows + 4 actuation flows, 0 means not received.
measure_list=['0', '0', '0', '0', '0', '0', '0', '0', '0']

delaylist = np.empty(9)
delaylist.fill(float(totalnode)/float(100))

while True:
    connection, client_address = sock.accept()
    try:
        #print >>sys.stderr, 'Client call, No.', run_count
        while True:
            data = connection.recv(30)
            rcvedlist = ['0', '0', '0', '0', '0', '0', '0', '0', '0']            
            #print delaylist
            #delaylist = [0., 0., 0., 0., 0., 0., 0., 0., 0.]
            if data:
            	#emergency_intput = [int(x) for x in str(data).split(',')]    	
            	#rcvedlist = ['0', '0', '0', '0', '0', '0', '0', '0', '0', '0']
            	while (t.time() <= 97656250*run_count): # here the 100000000 represents 10ms
            		rcved = t.runNextEvent()
            		#print "received from runNextEvent: ", rcved
            		if rcved >0:
            			rcvedlist = list('{0:010b}'.format(rcved))
            			print "rcvedlist: ", rcvedlist
            			measure_list = rcvedlist
        		#print rcvedlist
            	run_count = run_count + 1

            	if run_count % (FRAMELENGTH+1) == 52:
            		sample_times +=1
            		# read delay.txt file
            		if os.path.isfile("delay.txt") == True:
            			f = open("delay.txt", "r")
            			lines = f.readlines()
	            		for line in lines:
	            			tokens=line.split()
	            			
	            			delaylist[int(tokens[0])-1]=float(tokens[1])/100
	            			#print "delay: ", delaylist[int(tokens[0])-1]
	            		os.remove("delay.txt")
	            		#reception=str(measure_list[0]) + ',' + str(measure_list[1]) + ',' + str(measure_list[2])+\
	            		#','+str(measure_list[3]) + ',' + str(measure_list[4]) + ',' + str(measure_list[5])+\
	            		#','+str(measure_list[6]) + ',' + str(measure_list[7]) + ',' + str(measure_list[8])+\
	            		#','+str(delaylist[0]) + ',' + str(delaylist[1]) + ',' + str(delaylist[2])+\
	            		#','+str(delaylist[3]) + ',' + str(delaylist[4]) + ',' + str(delaylist[5])+\
	            		#','+str(delaylist[6]) + ',' + str(delaylist[7]) + ',' + str(delaylist[8])
	            		for i in range(0, 9):
	            			print "delay: ", delaylist[i]
	            		reception=str(measure_list[0]) + ',' + str(measure_list[1]) + ',' + str(measure_list[2])+\
	            		','+str(delaylist[0]) + ',' + str(delaylist[1]) + ',' + str(delaylist[2])
	            	else:
	            		delaylist = np.empty(9)
	            		delaylist.fill(float(totalnode)/float(100))
	            		reception=str(measure_list[0]) + ',' + str(measure_list[1]) + ',' + str(measure_list[2])+\
	            		','+str(delaylist[0]) + ',' + str(delaylist[1]) + ',' + str(delaylist[2])
            		#avg_DR =  float(int(measure_list[0])+int(measure_list[1])+int(measure_list[2])+int(measure_list[3])+int(measure_list[4])+int(measure_list[5])+int(measure_list[6])+int(measure_list[7])+int(measure_list[8]))/float(NUM_MEASUREMENTS)
            		#avg_delay = float(delaylist[0]+delaylist[1]+delaylist[2]+delaylist[3]+delaylist[4]+delaylist[5]+delaylist[6]+delaylist[7]+delaylist[8])/float(NUM_MEASUREMENTS)
            		avg_DR =  float(int(measure_list[0])+int(measure_list[1])+int(measure_list[2]))/float(NUM_MEASUREMENTS)
            		avg_delay = float(delaylist[0]+delaylist[1]+delaylist[2])/float(NUM_MEASUREMENTS)
            		sub_network_health = p1*avg_delay*avg_delay+p2*avg_delay+p3-(1-avg_DR)
            		if sub_network_health >0:
            			good_NH_counter += 1
            		#print "avg_DR: ", avg_DR
            		#print "avg_delay: ", avg_delay
            		#print "sub network_health: ", sub_network_health
            		res_file = open("network_health.txt", "a")
            		res_file.write(str(avg_DR))
            		res_file.write('\t')
            		res_file.write(str(avg_delay))
            		res_file.write('\t')
            		res_file.write(str(sub_network_health))
            		res_file.write('\t')
            		res_file.write(str(good_NH_counter))
            		res_file.write('\t')
            		res_file.write(str(totalnode))
            		res_file.write('\n')
            		res_file.close()

            		control_input_file = open("control_input_file.txt", "a")
            		control_input_file.write(reception)
            		control_input_file.write('\n')
            		control_input_file.close()

            		measure_list=['0', '0', '0', '0', '0', '0', '0', '0', '0']

            	else :
					#reception=str(measure_list[0]) + ',' + str(measure_list[1]) + ',' + str(measure_list[2])+\
            		#','+str(measure_list[3]) + ',' + str(measure_list[4]) + ',' + str(measure_list[5])+\
            		#','+str(measure_list[6]) + ',' + str(measure_list[7]) + ',' + str(measure_list[8])+\
            		#','+str(delaylist[0]) + ',' + str(delaylist[1]) + ',' + str(delaylist[2])+\
            		#','+str(delaylist[3]) + ',' + str(delaylist[4]) + ',' + str(delaylist[5])+\
            		#','+str(delaylist[6]) + ',' + str(delaylist[7]) + ',' + str(delaylist[8])

            		reception=str(measure_list[0]) + ',' + str(measure_list[1]) + ',' + str(measure_list[2])+\
            		','+str(delaylist[0]) + ',' + str(delaylist[1]) + ',' + str(delaylist[2])

            	if run_count%(FRAMELENGTH+1) == 53 and sample_times == RSSI_DURATION:
            		# change the current rssi value, random generate a integer value from range(-84, -62)
            		new_noise = random.randint(0, 31)
            		print "new_rssi: ", new_noise
            		get_new_topo(new_noise)
            		RSSI_DURATION = random.randint(60, 200)

            	'''
            	if run_count%(FRAMELENGTH+1) == 53 and sample_times == SAMPLE:
            		noise_file = open("noise_generation_distribution.txt", "a")
            		noise_file.write('-----------------------------------\n')
            		noise_file.close()
            	'''
            	'''
            	if run_count%(FRAMELENGTH+1) == 53 and sample_times == SAMPLE:
            		curr_NH_ratio = float(good_NH_counter)/float(SAMPLE)
            		noise_file = open("noise_generation_distribution.txt", "a")
            		noise_file.write('---------------------------------\n')
            		noise_file.close()
            		if curr_NH_ratio > THRESHOLD:
            			consecutive_NH_counter += 1
            		else:
            			consecutive_NH_counter=0
            		if curr_NH_ratio <=THRESHOLD and totalnode < MAXNODES:
            			if good_NH_counter == 0:
            				totalnode += BACKLEVELS
            			else:
            				totalnode+= int(THRESHOLD/curr_NH_ratio)
            				if totalnode >MAXNODES:
            					totalnode = MAXNODES
            		
            			new_k = get_max_delta(totalnode)
            			print "add more node in the network, new node: ", totalnode, "new k: ", new_k
            			seed += 1
            			call(["./a.out", str(totalnode), str(new_k), str(seed)])
            			# set up new network topology
            			get_new_topo()
            		elif consecutive_NH_counter == CONSEGOODNH:
            			consecutive_NH_counter=0
            			totalnode = totalnode-1         			
            			new_k = get_max_delta(totalnode)
            			print "reduce one more node in the network, new node: ", totalnode, "new k: ", new_k
            			seed += 1
            			call(["./a.out", str(totalnode), str(new_k), str(seed)])
            			# set up new network topology
            			get_new_topo()
            		else:        			
            			last_NH_ratio = curr_NH_ratio
            	
            	if run_count%(FRAMELENGTH+1)==54 and sample_times == SAMPLE:
            		sample_times = 0
            		good_NH_counter=0
            		curr_NH_ratio=0.0
            	
            	
            	if run_count%(FRAMELENGTH+1) == 54:
            		counter += 1
            	if counter ==200:
            		totalnode += 1
            		new_k=get_max_delta(totalnode)
            		seed += 1
            		call(["./a.out", str(totalnode), str(new_k), str(seed)])
            		print "add more node in the network, new node: ", totalnode, "new k: ", new_k
            		#get_new_topo()
            		counter =0
            	'''
            	#print "sample_times", sample_times
            	#print "reception: ", reception
            	connection.sendall(reception)
            else:
            	break
    finally:
        connection.close()
print "reaching maximum nodes, network design approach fails, please redesign control system "
