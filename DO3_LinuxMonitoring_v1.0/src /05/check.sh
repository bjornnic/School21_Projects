#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Error: enter one parameter (path to directory)."
    exit 1
fi

if [[ "$1" != */ ]]; then
    echo "Error: the parameter must end with "/"."
    exit 1
fi

if [ ! -d "$1" ]; then
    echo "Error: the specified directory does not exist."
    exit 1
fi

