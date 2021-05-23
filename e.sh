#!/bin/sh
# unzip before compile
for i in $(ls -d */); 
do 
    unzip ${i%%/}/*.zip -d ${i%%/}/; 
    d=$(ls ${i%%/}/ -lR | grep ^d | wc -l)
    if [ "$d" -gt 0 ];
    then
        dir=$(ls -d ${i%%/}/*/);
        cp ~/Makefile $dir/ && make -C $dir/;
    else
        cp ~/Makefile ${i%%/}/ && make -C ${i%%/}/;
    fi
done
