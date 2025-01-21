#!/bin/bash

S21_GREP="./s21_grep"
GREP="grep"
TEST_FILE="test.txt"
PATTERN_FILE="pattern_file.txt"
TEST_NUMBER=1

run_test() {
    local options=$1

    $S21_GREP $options $TEST_FILE > s21_output.txt 2>/dev/null
    $GREP $options $TEST_FILE > grep_output.txt 2>/dev/null

    if diff -q s21_output.txt grep_output.txt > /dev/null; then
        echo "Test $TEST_NUMBER: pass"
    else
        echo "Test $TEST_NUMBER: failed"
    fi
    rm -f s21_output.txt grep_output.txt
    ((TEST_NUMBER++))
}

run_tests() {
    run_test "Hello"
    run_test "-i Hello"
    run_test "-v Hello"
    run_test "-c Hello"
    run_test "-n Hello"
    run_test "-l Hello"
    run_test "-s NonExistentPattern"
    run_test "-e Hello -e World"
    run_test "-f $PATTERN_FILE"
    run_test "-o Hello"
    run_test "-c -v Hello"
    run_test "-i -n Hello"
    run_test "-o -n Hello"
    run_test "-s -v Hello"
    run_test "-f $PATTERN_FILE -c"
    run_test "-f $PATTERN_FILE -n"
    run_test "-f $PATTERN_FILE -v"
    run_test "-i -v Hello"
    run_test "-i -c Hello"
    run_test "-i -n Hello"
    run_test "-v -c Hello"
    run_test "-v -n Hello"
    run_test "-c -n Hello"
    run_test "-c -o Hello"
    run_test "-n -o Hello"
    run_test "-i -v -c Hello"
    run_test "-i -c -n Hello"
    run_test "-i -c -o Hello"
    run_test "-v -c -n Hello"
    run_test "-v -c -o Hello"
    run_test "-c -n -o Hello"
    run_test "-i -v -c -n Hello"
    run_test "-i -c -n -o Hello"
    run_test "-v -c -n -o Hello"
    run_test "-i -v -c -n -o Hello"
}

run_tests
