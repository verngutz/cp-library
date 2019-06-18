#!/bin/bash
tc=1
while : ; do
    echo -e "\e[34m./$1 $tc > input.txt\e[39m"
    ./$1 $tc > input.txt
    echo -e "\e[34m./$2 < input.txt > output1.txt\e[39m"
    ./$2 < input.txt > output1.txt
    echo -e "\e[34m./$3 < input.txt > output2.txt\e[39m"
    ./$3 < input.txt > output2.txt
    echo -e "\e[34m./$4 < output1.txt > score1.txt\e[39m"
    ./$4 < output1.txt > score1.txt
    echo -e "\e[34m./$4 < output2.txt > score2.txt\e[39m"
    ./$4 < output2.txt > score2.txt
    if ! cmp --silent score1.txt score2.txt ; then
        echo -e "\e[31mtest failed\e[39m"
        break
    fi
    echo -e "\e[32m$((tc++)) test cases passed\e[39m"
done
