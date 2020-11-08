#!/bin/bash

{ result=$(< /dev/stdin); echo "$result" > stdin; }
result=`grep '...passed' stdin`
echo "$result" > stdin
result=`grep -o 'valider.*_.' stdin`
echo -e "\n$result\n"
rm stdin
