#!/bin/bash
# Script for annoying someone :]


if [ "$1" == "create" ]; then
	echo "* */3 * * * HI > ~/Desktop/FILE " >> temp
	crontab -l > temp
	cat temp
	crontab temp
	rm temp
	echo "Annoy file was created ;]"
elif [ "$1" == "remove" ]; then
	echo "Annoy file was removed 0_o"
else
	echo "Wrong usage. Try '$0 create/remove'"

fi




