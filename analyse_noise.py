import numpy as np

f=open("noise_generation_distribution.txt", "r")
wf=open("link_prob.txt", "a");

lines = f.readlines()
lp=0.0
i=0
j=0
total=0.0
lst = []
for line in lines:
	#print i
	i += 1
	j += 1
	token = line.split()
	if len(token)==1:
		avg_lp=lp/i
		std_error=np.std(lst)/(pow(i, 0.5))
		#print "LP!!!!", avg_lp
		wf.write(str(avg_lp))
		wf.write('\t')
		wf.write(str(1-avg_lp))
		wf.write('\t')
		wf.write(str(std_error))
		wf.write('\n')
		lst=[]
		lp = 0.0
		i=0
	else:
		#print token[1]
		lp+=float(token[1])
		total+=float(token[1])
		lst.append(float(token[1]))
#print "final: ", total/j
total_avg = total/j
wf.write(str(total_avg))
wf.write('\t')
wf.write(str(1-total_avg))
wf.close()

