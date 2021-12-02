#!/bin/bash
# format: {problem #} [-d]
# -d: Don't push
if [ -z $1 ]
  then
    echo "Problem # not provided"
    exit 1
fi
git add README.md
git add leetcode/$1.*
git commit -m $1
# https://www.aplawrence.com/Unix/getopts.html
args=`getopt d $*`
set -- $args
push=true
for i
do
  case "$i" in
    -d) shift;push=false;;
  esac
done
if [ "$push" = true ] ; then
  git push
fi