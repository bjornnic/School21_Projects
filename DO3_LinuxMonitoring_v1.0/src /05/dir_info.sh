#!/bin/bash

dir_path="$1"

get_info() {

total_dir=$(sudo find "$dir_path" -type f| wc -l)
top_folders=$(sudo du -h --max-depth=1 "$dir_path" | sort -hr | awk 'NR>1 {print NR-1 " - " $2 ", " $1}' | head -n 5)
total_files=$(sudo find "$dir_path" -type f | wc -l)
config_files=$(sudo find "$dir_path" -type f -name "*.conf" | wc -l)
text_files=$(sudo find "$dir_path" -type f -name "*.txt" | wc -l)
exe_files=$(sudo find "$dir_path" -type f -executable | wc -l)
log_files=$(sudo find "$dir_path" -type f -name "*.log" | wc -l)
archives=$(sudo find "$dir_path" -type f \( -name "*.zip" -o -name "*.tar" -o -name "*.rar" -o -name "*.gz" -o -name "*.Z" -o -name "*.tgz" -o -name "*.7z" \) | wc -l)
sym_links=$(sudo find "$dir_path" -type l | wc -l)
top_big_files=$(sudo find "$dir_path" -type f -exec du -h {} + | sort -hr | head -10 | awk '{n = split($2, arr, "/"); filename = arr[n]; ext = (split(filename, arr_ext, ".") > 1) ? arr_ext[length(arr_ext)] : ""; printf "%d - %s, %s%s\n", NR, $2, $1, (ext ? ", " ext : "")}')
top_exe_files=$(sudo find "$dir_path" -type f -executable -exec du -h {} + | sort -hr | head -10 | awk '{printf "%d - %s, %s, ", NR, $2, $1; system("md5sum " $2 " | cut -d\" \" -f1")}')

echo "Total number of folders (including all nested ones) = $total_dir"
echo "TOP 5 folders of maximum size arranged in descending order (path and size):"
echo "$top_folders"
echo "Total number of files = $total_files"
echo "Number of:"
echo "Configurations files (with the .conf extension) = $config_files"
echo "Text files = $text_files" 
echo "Executable file = $exe_files"
echo "Log files (with extension .log) = $log_files"
echo "Archive files = $archives"
echo "Symbolic links = $sym_links"
echo "TOP 10 files of maximum size arranged in descending order (path, size and type):"
echo "$top_big_files"
echo "TOP 10 executable files of the maximum size arranged in descending order (path, size and MD5 hash of file):"
echo "$top_exe_files"
}