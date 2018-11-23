#!/bin/bash
if [ -z "$1" ]
  then
    echo "Quiz Title not provided"
    exit 1
fi
cd leetcode/
folder=$1
mkdir "$folder"
cd "$folder"
cat "../../quiz.js" > README.md
cat "../../answer.js" > s1.cpp
echo "DONE: "$folder