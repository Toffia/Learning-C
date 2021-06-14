#!/bin/bash

if [ "$1" == "" ]; then
 echo "Usage: $0 <cprogram>"
else 
 echo "Compiling $1"
 echo
 gcc -o temp $1
 echo
 echo "Launching $1"
 echo
 ./temp $2 $3 $4 $5
 echo
 rm temp
fi

 # trap ctrl-c and call ctrl_c()
trap ctrl_c INT

function ctrl_c() {
        echo "** Trapped CTRL-C"
        rm temp
        exit 1
}

#for i in `seq 1 5`; do
#    sleep 1
#    echo -n "."
#done