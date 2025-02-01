#!/bin/bash

source "$(dirname "$0")/check.sh"

if [[ $# -ne 1 ]]; then
    echo "Error: specify one text parameter."
    exit 1
fi

if check_number "$1"; then
    echo "Error: parameter cannot be a number or contain a number."
    exit 1
fi

echo "$1"
