#!/bin/bash

declare -A colors=(
    [1]="97"
    [2]="91"
    [3]="92"
    [4]="94"
    [5]="95"
    [6]="30"
)

declare -A bg_colors=(
    [1]="107"
    [2]="101"
    [3]="102"
    [4]="104"
    [5]="105"
    [6]="40"
)

print_line() {
    echo -e "\e[${bg_colors[$1]};${colors[$2]}m $3 \e[0m = \e[${bg_colors[$4]};${colors[$5]}m $6 \e[0m"
}
