#!/bin/bash

print_system_info() {
    echo "HOSTNAME = $(hostname)"
    echo "TIMEZONE = $(timedatectl show --property=Timezone --value) UTC $(date +%:z)"
    echo "USER = $(whoami)"
    echo "OS = $(lsb_release -ds)"
    echo "DATE = $(date '+%d %b %Y %H:%M:%S')"
    echo "UPTIME = $(uptime -p)"
    echo "UPTIME_SEC = $(awk '{print $1}' /proc/uptime)"
}

print_network_info() {
    echo "IP = $(hostname -I | awk '{print $1}')"
    echo "MASK = $(ip -o -4 addr show | awk '{print $4}' | cut -d/ -f2 | head -n1)"
    echo "GATEWAY = $(ip route | grep default | awk '{print $3}')"
}


print_memory_info() {
    echo "RAM_TOTAL = $(awk '/MemTotal/ {printf "%.3f GB\n", $2/1024/1024}' /proc/meminfo)"
    echo "RAM_USED = $(free | awk '/Mem:/ {printf "%.3f GB\n", ($2-$7)/1024/1024}')"
    echo "RAM_FREE = $(free | awk '/Mem:/ {printf "%.3f GB\n", $7/1024/1024}')"
}

print_space_info() {
    echo "SPACE_ROOT = $(df / | awk 'NR==2 {printf "%.2f MB\n", $2/1024}')"
    echo "SPACE_ROOT_USED = $(df / | awk 'NR==2 {printf "%.2f MB\n", $3/1024}')"
    echo "SPACE_ROOT_FREE = $(df / | awk 'NR==2 {printf "%.2f MB\n", $4/1024}')"
}
