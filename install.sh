#!/bin/bash

# Define installation directories
INCLUDE_DIR="/usr/local/include"
LIB_DIR="/usr/local/lib"

# Create the necessary directories if they don't exist
mkdir -p "$INCLUDE_DIR"
mkdir -p "$LIB_DIR"

# Copy the header file to the include directory
cp src/cdb.h "$INCLUDE_DIR"

# Compile the CDB library
g++ -c src/cdb.cpp -o cdb.o

# Create the static library
ar rcs libcdb.a cdb.o

# Move the library to the library directory
mv libcdb.a "$LIB_DIR"

# Clean up object files
rm cdb.o

echo "CDB library installed successfully!"
echo "You can now use it with #include <cdb.h> and link with -lcdb"
