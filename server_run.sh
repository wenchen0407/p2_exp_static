#!/bin/bash

rm noise_record.txt delay.txt result.txt send.txt rev.txt noise_generation_distribution.txt network_health.txt link_prob.txt sensor_data.txt

echo $1
echo $2
g++ $1
./a.out 20 1 1
python tossim-event-server-iccps15.py $2

