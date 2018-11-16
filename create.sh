#!/bin/bash
if [ $1 -eq '' ]
  then
    echo "Quiz # not provided"
fi
link=$1
content=`curl $link`
if [[ $content =~ questionId:\ \'([0-9]*)\' ]]; then
    qid=${BASH_REMATCH[1]}
fi
if [[ $content =~ \<title\>(.*)\ \-\ LeetCode\</title\> ]]; then
  title=${BASH_REMATCH[1]}
fi
cd leetcode/
folder=$qid". "$title
mkdir "$folder"
cd "$folder"
cat "../../quiz.js" > README.md
echo "// OJ: $link
// Author: github.com/lzl124631x
// Time: O()
// Space: O()" > s1.cpp
echo "DONE: "$folder