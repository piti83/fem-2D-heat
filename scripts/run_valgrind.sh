#!/bin/bash

set +x

mkdir -p out/

echo "Starting memcheck..."

valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all -s --log-file="out/valgrind_log.txt" ./bin/mes "$@"

echo "Memcheck done."
echo "Results exported to ./out/valgrind_log.txt"


