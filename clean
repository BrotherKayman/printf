#!/bin/bash

# Check if a filename is provided as an argument
if [ $# -eq 0 ]; then
    echo "Usage: $0 <file_path>"
    exit 1
fi

file_path="$1"
file_name="$(basename "$file_path")"
backup="${file_name%.c}_backup.c"

#Create a backup
cp "$file_path" "$backup"

# Remove leading and trailing spaces on each line
sed -i 's/^[[:space:]]*//; s/[[:space:]]*$//' "$file_path"

# Remove consecutive spaces and replace with a single space
sed -i 's/[[:space:]]\{2,\}/ /g' "$file_path"

# Remove empty lines
sed -i '/^$/d' "$file_path"
#betty
betty "$file_path"
