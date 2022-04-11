#!/bin/bash
# format: {problem #} [-d]
# -d: Don't push
# -r: Update readme
if [ -z $1 ]
  then
    echo "Problem # not provided"
    exit 1
fi
# https://www.aplawrence.com/Unix/getopts.html
args=`getopt d $*`
set -- $args
push=true
readme=false
for i
do
  case "$i" in
    -d) shift;push=false;;
    -r) shift;readme=true;;
  esac
done
if [ "$readme" = true ] ; then
  ./readme.sh
  echo "README updated"
fi
git add README.md
git add leetcode/$1.*
git commit -m $1
if [ "$push" = true ] ; then
  git push
fi