#!/bin/bash
if [ -z $1 ]
  then
    echo "Quiz # not provided"
    exit 1
fi
git add README.md
git add leetcode/$1*
git commit -m $1
git push
