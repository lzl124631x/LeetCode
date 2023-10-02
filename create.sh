#!/bin/bash
if [ -z "$1" ]
  then
    echo "Please provide a problem number."
    exit 1
fi
cd leetcode/
folder=$1
mkdir "$folder"
cd "$folder"
touch README.md
echo "DONE: "$folder