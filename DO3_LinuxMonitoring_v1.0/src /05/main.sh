#!/bin/bash

source "$(dirname "$0")/check.sh"
source "$(dirname "$0")/dir_info.sh"

start=$(date +%s.%N)

get_info

end=$(date +%s.%N)
execution_time=$(echo "$end - $start" | bc)

echo -n "Script execution time (in seconds) = "
printf "%.1f\n" "$execution_time"