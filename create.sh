#!/bin/bash
cd leetcode/
folder=$1
mkdir "$folder"
cd "$folder"
cat "../../quiz.js" > README.md
cat "../../answer.js" > s1.cpp
echo "DONE: "$folder