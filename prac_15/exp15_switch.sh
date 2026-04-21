#!/bin/bash
echo "enter option"

echo "a = print date "
echo " b = list all files in current directory"

read ch

case $ch in
a)
echo " curr date"
date
;;
b)
echo " files in curr direc"
ls
;;
*)
echo " invalid"
;;
esac

