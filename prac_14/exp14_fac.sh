#!/bin/bash

echo "enter no"
read n

fac=1
i=1

while [ $i -le $n ] 
do
fac=$((fac*i))
i=$((i+1))
done
echo " facto is $fac"

