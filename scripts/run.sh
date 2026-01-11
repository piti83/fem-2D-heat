#!/bin/bash

set +x

mkdir -p out

echo "Running mes..."

./bin/mes "$@"

echo "mes ended."
