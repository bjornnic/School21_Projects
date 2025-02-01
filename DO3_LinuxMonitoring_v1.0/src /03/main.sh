#!/bin/bash

source "$(dirname "$0")/check.sh"
source "$(dirname "$0")/colors.sh"
source "$(dirname "$0")/system_info.sh"

check_input "$@"
print_system_info "$@"
print_network_info "$@"
print_memory_info "$@"
print_space_info "$@"