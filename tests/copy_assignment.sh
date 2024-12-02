#!/bin/bash

# Check if the correct number of arguments is passed
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <source_file> <destination_file>"
    exit 1
fi

SOURCE_FILE="$1"
DEST_FILE="$2"

# Check if the parent folder exists, in case it does not, create it.
DEST_DIR=$(dirname "$DEST_FILE")
if [ ! -d "$DEST_DIR" ]; then
    mkdir -p "$DEST_DIR"
    echo "Created destination directory: $DEST_DIR"
fi

# Resolve relative paths to absolute paths
SOURCE_FILE=$(realpath "$SOURCE_FILE")
DEST_FILE=$(realpath "$DEST_FILE")

# Check if the source file exists
if [ ! -f "$SOURCE_FILE" ]; then
    echo "Source file $SOURCE_FILE not found!"
    exit 1
fi

# Copy the source file to the destination
cp "$SOURCE_FILE" "$DEST_FILE"
echo "File copied to $DEST_FILE"

# Use awk to remove the main function, including nested blocks
awk '
BEGIN { inside_main = 0; open_braces = 0; }
{
    # Detect the start of the main function
    if ($0 ~ /int\s+main\s*\(.*\)\s*\{/) {
        inside_main = 1
        open_braces = 1  # Start counting braces inside main
        next  # Skip the line with the main function signature
    }

    # Process lines inside the main function
    if (inside_main) {
        # Increment open_braces for every opening brace '{'
        open_braces += gsub(/{/, "{")
        # Decrement open_braces for every closing brace '}'
        open_braces -= gsub(/}/, "}")
        
        # Skip the line if were inside the main function and braces are unbalanced
        if (open_braces > 0) {
            next
        } else {
            # Weve found the closing brace of the main function, stop skipping
            inside_main = 0
            next  # Skip the final closing brace
        }
    }

    # Print lines outside the main function
    print $0
}
' "$DEST_FILE" > temp_file && mv temp_file "$DEST_FILE"

# Notify user of completion
echo "'main' function removed from $DEST_FILE"
