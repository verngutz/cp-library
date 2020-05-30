#!/bin/bash
echo -e "\e[33m"
echo -e "rm $1"
rm $1
echo -e "g++ -std=c++17 -Wall -g -fsanitize=address,undefined -fuse-ld=gold -DDEBUG -o $1 $1.cpp"
g++ -std=c++17 -Wall -g -fsanitize=address,undefined -fuse-ld=gold -DDEBUG -o $1 $1.cpp
echo -e "chmod +x $1"
chmod +x $1
echo -e "./$1 < input.txt"
./$1 < input.txt
echo -e "\e[39m"
