#!/bin/sh

# To make creating files easier
for var in "$@"
do
    echo "" > "$var.cpp"
done
