#!/bin/bash
cd leetcode/
folder=$1
mkdir "$folder"
cd "$folder"
cat "../../quiz.js" > README.md
echo "// OJ: 
// Author: github.com/lzl124631x
// Time: O()
// Space: O()" > s1.cpp
echo "DONE: "$folder