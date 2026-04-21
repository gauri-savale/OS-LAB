#!/bin/sh

echo "Enter your grade:"
read grade

if [ "$grade" -ge 75 ]; then
    echo "Distinction"
elif [ "$grade" -ge 65 ] && [ "$grade" -lt 75 ]; then
    echo "1st Division"
elif [ "$grade" -ge 55 ] && [ "$grade" -lt 65 ]; then
    echo "2nd Division"
else
    echo "3rd Division"
fi
