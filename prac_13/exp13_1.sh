#!/bin/sh

echo "Enter your age:"
read age

if [ "$age" -gt 18 ]; then
    echo "adult"
else
    echo "not adult"
fi
