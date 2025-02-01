#!/bin/bash

print_system_info() {
    print_line "$1" "$2" "HOSTNAME" "$3" "$4" "$(hostname)"
    print_line "$1" "$2" "TIMEZONE" "$3" "$4" "$(timedatectl show --property=Timezone --value) UTC $(date +%:z)"
    print_line "$1" "$2" "USER" "$3" "$4" "$(whoami)"
    print_line "$1" "$2" "OS" "$3" "$4" "$(lsb_release -ds)"
    print_line "$1" "$2" "DATE" "$3" "$4" "$(date '+%d %b %Y %H:%M:%S')"
    print_line "$1" "$2" "UPTIME" "$3" "$4" "$(uptime -p)"
    print_line "$1" "$2" "UPTIME_SEC" "$3" "$4" "$(awk '{print $1}' /proc/uptime)"
}

print_network_info() {
    print_line "$1" "$2" "IP" "$3" "$4" "$(hostname -I | awk '{print $1}')"
    print_line "$1" "$2" "MASK" "$3" "$4" "$(ip -o -4 addr show | awk '{print $4}' | cut -d/ -f2 | head -n1)"
    print_line "$1" "$2" "GATEWAY" "$3" "$4" "$(ip route | grep default | awk '{print $3}')"
}

print_memory_info() {
    print_line "$1" "$2" "RAM_TOTAL" "$3" "$4" "$(awk '/MemTotal/ {printf "%.3f GB\n", $2/1024/1024}' /proc/meminfo)"
    print_line "$1" "$2" "RAM_USED" "$3" "$4" "$(free | awk '/Mem:/ {printf "%.3f GB\n", ($2-$7)/1024/1024}')"
    print_line "$1" "$2" "RAM_FREE" "$3" "$4" "$(free | awk '/Mem:/ {printf "%.3f GB\n", $7/1024/1024}')"
}

print_space_info() {
    print_line "$1" "$2" "SPACE_ROOT" "$3" "$4" "$(df / | awk 'NR==2 {printf "%.2f MB\n", $2/1024}')"
    print_line "$1" "$2" "SPACE_ROOT_USED" "$3" "$4" "$(df / | awk 'NR==2 {printf "%.2f MB\n", $3/1024}')"
    print_line "$1" "$2" "SPACE_ROOT_FREE" "$3" "$4" "$(df / | awk 'NR==2 {printf "%.2f MB\n", $4/1024}')"
}