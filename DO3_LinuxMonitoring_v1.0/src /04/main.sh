#!/bin/bash

source "$(dirname "$0")/check.sh"
source "$(dirname "$0")/colors.sh"
source "$(dirname "$0")./03/system_info.sh"
source "$(dirname "$0")/config_reader.sh"

read_config
check_input "$column1_background" "$column1_font_color" "$column2_background" "$column2_font_color"

print_system_info "$column1_background" "$column1_font_color" "$column2_background" "$column2_font_color"
print_network_info "$column1_background" "$column1_font_color" "$column2_background" "$column2_font_color"
print_memory_info "$column1_background" "$column1_font_color" "$column2_background" "$column2_font_color"
print_space_info "$column1_background" "$column1_font_color" "$column2_background" "$column2_font_color"

echo ""
color_scheme
