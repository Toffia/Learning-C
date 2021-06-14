#!/bin/bash

if [ "$1" == "" ]; then
 echo "Usage: $0 <cprogram>"
else 
 echo "Compiling $1"
 gcc -o temp $1
 echo "Launching $1"
 ./temp
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