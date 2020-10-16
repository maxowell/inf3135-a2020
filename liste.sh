#!/bin/bash

result=`grep '...passed' stdin`
echo "$result" > stdin
result=`grep -o 'test_.*_.' stdin`
echo -e "\n$result\n"
rm stdin
