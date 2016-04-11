#!/bin/bash
make micaz sim
for t in tossim-call-control-testbed_temp.py
do
 echo Running $t...
 python $t > `basename $t .py`.log
done
for l in tossim-call-control-testbed_temp.log
do
	echo -e '\tSEND \t RCV \t LOST'
	
	SEND=`grep 'SEND: 181->170' $l | wc -l`
	RCV=`grep 'RECEIVE: 181->170' $l | wc -l`
	echo -e "$SEND $RCV \t" `expr $SEND - $RCV`
	
	SEND_1=`grep 'SEND: 155->171' $l | wc -l`
	RCV_1=`grep 'RECEIVE: 155->171' $l | wc -l`
	echo -e "$SEND_1 $RCV_1 \t" `expr $SEND_1 - $RCV_1`

done
