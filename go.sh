#!/bin/bash
if [ $1 -eq 0 ]
  then
    echo "Quiz # not provided"
fi
git add README.md
git add leetcode/$1*
git commit -m $1
git push
