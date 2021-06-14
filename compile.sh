#!/bin/bash

if [ "$1" == "" ]; then
 echo "Usage: $0 <cprogram>"
else 
 echo "Compiling $1.c"
 gcc -o temp $1.c
 echo "Launching $1.c"
 ./temp
fi

 # trap ctrl-c and call ctrl_c()
trap ctrl_c INT

function del() {
 rm temp.out
}

function ctrl_c() {
        echo "** Trapped CTRL-C"
        exit 1
}

#for i in `seq 1 5`; do
#    sleep 1
#    echo -n "."
#done