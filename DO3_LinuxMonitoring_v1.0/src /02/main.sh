#!/bin/bash

source "$(dirname "$0")/system_info.sh"
source "$(dirname "$0")/save_info.sh"

print_system_info
print_network_info
print_memory_info
print_space_info
save_info
