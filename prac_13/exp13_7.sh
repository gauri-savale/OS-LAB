#!/bin/sh

echo "Enter first number:"
read a

echo "Enter second number:"
read b

echo "Enter third number:"
read c

if [ "$a" -ge "$b" ] && [ "$a" -ge "$c" ]; then
    echo "Largest is $a"
elif [ "$b" -ge "$a" ] && [ "$b" -ge "$c" ]; then
    echo "Largest is $b"
else
    echo "Largest is $c"
fi
