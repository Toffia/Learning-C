#!/bin/bash
# Script for annoying someone :]


if [ "$1" == "create" ]; then
	echo "* */3 * * * echo "HI" > ~/Desktop/FILE " >> temp
	echo crontab -l
	crontab -l > temp
	crontab temp
	rm temp
	echo "Annoy file was created ;]"
elif [ "$1" == "remove" ]; then
	crontab -r
	echo "Annoy file was removed 0_o"
else
	echo "Wrong usage. Try '$0 create/remove'"

fi




