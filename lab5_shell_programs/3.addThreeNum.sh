#!/bin/bash

echo "Add two numbers passed to the script"
echo "Parameters passed are $1, $2 and $3"
num1=$1
num2=$2
num3=$3
echo "Values in num1, num2 and num3 are $num1 $num2 and $num3"
let sum=($num1 + $num2 + $num3)
echo "The sum of the numbers passed is $sum"