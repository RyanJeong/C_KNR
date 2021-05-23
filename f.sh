#!/bin/sh
# filtering
# [$1, $2]
if [ "$#" -ne 2 ];
then
    echo "usage: f.sh FROM TO"
else
    for i in $(ls -d */); 
    do 
        #a=$(ls ${i%%/}/*.out 2>/dev/null | wc -l)
        num=$(find ${i%%/}/ -type f -name "*.out" | wc -l)
        if [ "$num" -ge "$1" ] && [ "$num" -le "$2" ];
        then
            echo ${i%%/}/
        fi
    done
fi
