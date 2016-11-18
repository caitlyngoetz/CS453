#!/bin/bash

sudo ./booga_load

for drive in 0 1 2 3 
do
	for bytes in 1 24 3456 23457695 12308504 10000389
	do 
		./test-booga $drive $bytes read > /dev/null
	done
done

sudo ./booga_unload
