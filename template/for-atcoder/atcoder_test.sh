#!/bin/bash
echo -e "\e[33m"
echo -e "rm ${1:-main}"
rm ${1:-main}
echo -e "g++ -std=c++17 -Wall -g -fsanitize=address,undefined -fuse-ld=gold -DDEBUG -o ${1:-main} ${1:-main}.cpp"
g++ -std=c++17 -Wall -g -fsanitize=address,undefined -fuse-ld=gold -DDEBUG -o ${1:-main} ${1:-main}.cpp
echo -e "chmod +x ${1:-main}"
chmod +x ${1:-main}
echo -e "atcoder-tools test -e ./${1:-main}"
atcoder-tools test -e ./${1:-main}
echo -e "\e[39m"
