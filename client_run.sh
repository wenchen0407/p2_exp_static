#!/bin/bash

rm result.txt send.txt rev.txt noise_generation_distribution.txt network_health.txt link_prob.txt

for seed in `seq 1 11200`;
#for seed in `seq 1 11200`;
#for seed in `seq 56000`;
do 
	echo $seed
	python tossim-event-client-ps.py
done

python analyse_noise.py
