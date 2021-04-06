#!/bin/sh
echo "-----------"
./a.out 1 2 3
echo "-----------"
./a.out 1a1 2 3
echo "-----------"
./a.out "1 2 a32"
echo "-----------"
./a.out "1a2 3"
echo "-----------"
./a.out "1\n3"
echo "-----------"
./a.out "1\t2 3"
echo "-----------"
./a.out 2147483647
echo "-----------"
./a.out "-2147483648"
echo "-----------"
./a.out "-4-"
echo "-----------"
./a.out -4-
echo "-----------"
./a.out 4 4 8 7 -7 7- -7 -8
echo "-----------"
./a.out 1 2 3 -4- 4
echo "-----------"
./a.out - 4
echo "-----------"
./a.out "- 4"

echo "CHECK DUPLICATES"
echo "-----------"
./a.out 1 2 3 47 2 8
