#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Usage: ./b.sh from to" >&2
    exit -1
fi

re='^[0-9]+$'
if ! [[ $1 =~ $re ]] ; then
    echo "Usage: ./b.sh from to" >&2
    echo "error: $1 is not a number" >&2; exit 1
elif ! [[ $2 =~ $re ]] ; then
    echo "Usage: ./b.sh from to" >&2
    echo "error: $2 is not a number" >&2; exit 1
fi

for i in $(seq -f "%02g" $1 $2)
do
   gcc $i.c -c -ansi -Wall
done