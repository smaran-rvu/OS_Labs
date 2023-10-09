#!/bin/bash

num1=$1
num2=$2

if [ $num1 -gt $num2 ]
then
    echo "1st number should be lesser than the 2nd number"
else
    num3=$num1
    # while [ $(($num2+1)) -gt $num3 ]
    while [ $num3 -lt $((num2+1)) ]
    do
        echo $num3
        num3=$(($num3+1))
    done
fi
