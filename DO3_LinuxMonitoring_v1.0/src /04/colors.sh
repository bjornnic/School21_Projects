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

declare -A color_names=(
    [1]="white"
    [2]="red"
    [3]="green"
    [4]="blue"
    [5]="purple"
    [6]="black"
)

print_line() {
    echo -e "\e[${bg_colors[$1]};${colors[$2]}m $3 \e[0m = \e[${bg_colors[$4]};${colors[$5]}m $6 \e[0m"
}

color_scheme() {
    echo "Column 1 background = ${col1_bg_text} (${color_names[$column1_background]})"
    echo "Column 1 font color = ${col1_font_text} (${color_names[$column1_font_color]})"
    echo "Column 2 background = ${col2_bg_text} (${color_names[$column2_background]})"
    echo "Column 2 font color = ${col2_font_text} (${color_names[$column2_font_color]})"
}