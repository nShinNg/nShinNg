#!/bin/bash

# Check if FT_USER environment variable is set
if [ -z "$FT_USER" ]; then
    echo "Error: FT_USER environment variable not set"
    exit 1
fi

# Print groups for the specified user
groups "$FT_USER" 2>/dev/null | tr ' ' ',' | tr -d '\n'