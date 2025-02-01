#!/bin/bash

save_info() {
    read -p "Save the information to a file? (Y/N): " answer
    if [[ "$answer" =~ ^[Yy]$ ]]; then
        filename="$(date +"%d_%m_%y_%H_%M_%S").status"
        {
            print_system_info
            print_network_info
            print_memory_info
            print_space_info
        } > "$filename"
        echo "The information has been saved to the file: $filename"
    fi
}
