#!/usr/bin/env python
import sys

delay_file = "delay.txt"
delay_res_file="delay_res.txt"

f = open(delay_file, "r")
result_file = open(delay_res_file, "w")
flow1=open("flow1.txt", "w");
flow2=open("flow2.txt", "w");
flow3=open("flow3.txt", "w");
flow4=open("flow4.txt", "w");
flow5=open("flow5.txt", "w");
flow6=open("flow6.txt", "w");
flow7=open("flow7.txt", "w");
flow8=open("flow8.txt", "w");
flow9=open("flow9.txt", "w");
flow10=open("flow10.txt", "w");

flow_record=[0 for i in range(10)]

def write_flow(curr_flow, value):
	if curr_flow=='1':
		print "write to flow1"
		flow1.write(value)
	if curr_flow=='2':
		print "write to flow2"
		flow2.write(value)
	if curr_flow=='3':
		print "write to flow3"
		flow3.write(value)
	if curr_flow=='4':
		print "write to flow4"
		flow4.write(value)
	if curr_flow=='5':
		print "write to flow5"
		flow5.write(value)
	if curr_flow=='6':
		print "write to flow6"
		flow6.write(value)
	if curr_flow=='7':
		print "write to flow7"
		flow7.write(value)
	if curr_flow=='8':
		print "write to flow8"
		flow8.write(value)
	if curr_flow=='9':
		print "write to flow9"
		flow9.write(value)
	if curr_flow=='10':
		print "write to flow10"
		flow10.write(value)

#wireless rssi topology injection & model establishment
lines = f.readlines()
for line in lines:

	curr_line=line.split()
	if curr_line[0]=='###################':
		print "hello!!!!!"
		for i in range(10):
			flow_record[i]=0
	else:
		if int(curr_line[0]) >0 and flow_record[int(curr_line[0])-1]==0:
			value=curr_line[0]+'\t'+curr_line[1]+'\n'
			print "value: ", value
			result_file.write(str(value))   
			write_flow(curr_line[0], str(value))
			flow_record[int(curr_line[0])-1]=1
		'''
		if i==0:
			curr_flow=curr_line[0]
			print "curr_flow:", curr_flow
			print "slot_time:", curr_line[1]
			value=curr_line[0]+'\t'+curr_line[1]+'\n'
			print "value: ", value
	       	        result_file.write(str(value))   
		       	write_flow(curr_line[0], str(value))
	       # result_file.close()
	        #result_file.write(" ")
	        #result_file.write(curr_line[1])
	        #result_file.write("\n")   
		if i!=0 and curr_line[0]!=curr_flow:
			curr_flow=curr_line[0]
			print "curr_flow:", curr_flow
			print "slot_time:", curr_line[1]
			value=curr_line[0]+'\t'+curr_line[1]+'\n'
			print "value: ", value
	        	result_file.write(str(value))  
		        write_flow(curr_line[0], str(value))
	        #result_file.write(" ")
	        #result_file.write(curr_line[1])
	        #result_file.write("\n")
	    '''
result_file.closed

