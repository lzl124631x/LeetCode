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
cat "../../sql-quiz.js" > README.md
cat "../../sql-answer.js" > s1.sql
echo "DONE: "$folder