#!/bin/bash

fb=$(./s21_cat -b tests/test_2.txt)
fn=$(./s21_cat -n tests/test_2.txt)
fs=$(./s21_cat -s tests/test_2.txt)
fe=$(./s21_cat -e tests/test_2.txt)
ft=$(./s21_cat -t tests/test_2.txt)
fv=$(./s21_cat -v tests/test_2.txt)
fT=$(./s21_cat -T tests/test_2.txt)
fE=$(./s21_cat -E tests/test_2.txt)

cb=$(cat -b tests/test_2.txt)
cn=$(cat -n tests/test_2.txt)
cs=$(cat -s tests/test_2.txt)
ce=$(cat -e tests/test_2.txt)
ct=$(cat -t tests/test_2.txt)
cv=$(cat -v tests/test_2.txt)
cT=$(cat -T tests/test_2.txt)
cE=$(cat -E tests/test_2.txt)

RED='\033[0;31m'
GREEN='\033[0;32m'
NOCOLOR='\033[0m'


if [ "$fb" == "$cb" ]; then
    echo "${GREEN}Test -b done${NOCOLOR}"
else
    echo "${RED}Test -b failed${NOCOLOR}"
fi

if [ "$fn" == "$cn" ]; then
    echo  "${GREEN}Test -n done${NOCOLOR}"
else
    echo "${RED}Test -n failed${NOCOLOR}"
fi

if [ "$fs" == "$cs" ]; then
    echo "${GREEN}Test -s done${NOCOLOR}"
else
    echo "${RED}Test -s failed${NOCOLOR}"
fi

if [ "$fe" == "$ce" ]; then
    echo "${GREEN}Test -e done${NOCOLOR}"
else
    echo "${RED}Test -e failed${NOCOLOR}"
fi

if [ "$ft" == "$ct" ]; then
    echo "${GREEN}Test -t done${NOCOLOR}"
else
    echo "${RED}Test -t failed${NOCOLOR}"
fi

if [ "$ft" == "$ct" ]; then
    echo "${GREEN}Test -v done${NOCOLOR}"
else
    echo "${RED}Test -v failed${NOCOLOR}"
fi

echo "\nGNU Tests:\n"

if [ "$fT" == "$cT" ]; then
    echo "${GREEN}Test -T done${NOCOLOR}"
else
    echo "${RED}Test -T failed${NOCOLOR}"
fi

if [ "$fE" == "$cE" ]; then
    echo "${GREEN}Test -E done${NOCOLOR}"
else
    echo "${RED}Test -E failed${NOCOLOR}"
fi