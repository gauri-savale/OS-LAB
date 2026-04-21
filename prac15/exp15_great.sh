#!/bin/bash

echo "Choose an option:"
echo "1. Check Even or Odd"
echo "2. Check Leap Year"
echo "3. Find Greatest of 3 Numbers"
read choice

case $choice in

1)
    echo "Enter a number:"
    read num

    if (( num % 2 == 0 ))
    then
        echo "$num is Even"
    else
        echo "$num is Odd"
    fi
    ;;

2)
    echo "Enter a year:"
    read year

    if (( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ))
    then
        echo "$year is a Leap Year"
    else
        echo "$year is Not a Leap Year"
    fi
    ;;

3)
    echo "Enter three numbers:"
    read a b c

    if (( a >= b && a >= c ))
    then
        echo "$a is the greatest"
    elif (( b >= a && b >= c ))
    then
        echo "$b is the greatest"
    else
        echo "$c is the greatest"
    fi
    ;;

*)
    echo "Invalid choice"
    ;;

esac
