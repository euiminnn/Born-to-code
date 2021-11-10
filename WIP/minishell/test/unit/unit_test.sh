#!/bin/bash

test() {
    local test_file=$1

    printf " ... "
    ./a.out &> output
    if [ "$(diff output answer)" == "" ]; then
        printf "\033[32mpassed\e[0m\n"
    else
        printf "\033[31mFAILED\e[0m\n"
        printf "===============================================\n"
        diff -u output answer | cat
        printf "===============================================\n"
        printf "$(pwd)/$test_file\n"
        printf "$(pwd)/answer\n"
        printf "$(pwd)/output\n"
        printf "===============================================\n"
    fi
}

test $1
