#!/bin/bash

check_input() {
    if [[ $# -ne 4 ]]; then
        echo "Error: The script should run the original parameter numbers from 1 to 6."
        exit 1
    fi

    for param in "$@"; do
        if [[ ! $param =~ ^[1-6]$ ]]; then
            echo "Error: All parameters must be numbers from 1 to 6."
            exit 1
        fi
    done

    if [[ $1 -eq $2 ]]; then
        echo "Error: The background and font colors should not match."
        exit 1
    fi

    if [[ $3 -eq $4 ]]; then
        echo "Error: The background and font colors should not match."
        exit 1
    fi
}
