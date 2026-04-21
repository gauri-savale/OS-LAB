#!/bin/bash
read -p "enter no " n
flag=0

for ((i=2;i<=n/2;i++))
do
if ((n % i == 0 )); then
flag=1
break
fi
done

if ((n<=1)); then
echo "not prime"
elif ((flag ==0)); then
echo "prime"
else
echo "not prime"
fi

