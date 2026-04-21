#!/bin/sh

echo "Enter first number:"
read a

echo "Enter second number:"
read b

if [ "$a" -gt "$b" ]; then
    echo "Greatest is $a"
else
    echo "Greatest is $b"
fi
