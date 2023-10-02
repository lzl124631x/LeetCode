#!/bin/bash

file="README.md"
rm $file
echo "# LeetCode

Author: [github.com/lzl124631x](https://github.com/lzl124631x)

My C++ Code for LeetCode OJ.

Please give this repo a :star: if it inspires you. Thanks. :blush:

😩 Hate manually copy & pasting the example testcases when solving LeetCode problems?  
👉 Try my [LeetCode Testcase Extractor](https://liuzhenglai.com/post/5e6f2551e9a0d01760b274d8)

Now I'm using a Chrome Extension I developed -- [LeetCoder](https://chrome.google.com/webstore/detail/gkmoalkjclphfhgnhdlilebaolpdkgpf) -- to facilitate my having fun on LeetCode. Features including but not limited to:
* showing stats
* copying problem, answer and **testcases**
* randomly picking a problem.

\# | Title | Difficulty | Solution
---|---|---|---" >> $file

dirs=$(cd leetcode/ && ls -1d *) # list all dir names
total_number=$(wc -l <<< "$dirs") # count number of dirs. I must wrap $dirs in double quotes otherwise the names are in the same line in macos
i=1
dirs=$(sort -n <<< "$dirs") # sort dirs
for d in $dirs; do # https://unix.stackexchange.com/questions/33909/list-files-sorted-numerically
    re="# \[([0-9]+)\.\ (.*)\ \((Easy|Medium|Hard)\)\]\((.*)\)"
    first=""
    read -r first < "leetcode/$d/README.md" # Using read is blazing fast compared to `head -1`!
    title="?"
    difficulty="?"
    if [[ $first =~ $re ]]; then
        title=${BASH_REMATCH[2]}
        difficulty=${BASH_REMATCH[3]}
    fi
    printf '\r%s%%' "$(($i*100/$total_number))"
    line="$d | $title | $difficulty | [Solution](leetcode/$d)"
    echo $line >> $file
    i=$(($i+1))
done

echo "

# FAQ

## Space Complexity

I always only estimate the **extra** space **excluding** the space taken by the answer.

This is because the space for the answer is needed anyway for all algorithms of the same problem and it is the extra space that tells good algorithms apart from bad ones.

For example, assume a problem's answer always takes \`O(N^2)\` space. Algorithm A takes \`O(1)\` extra space, algorithm B takes \`O(N)\` extra space, and algorithm C takes \`O(N^2)\` extra space.

Which algorithm is better from space complexity perspective? Definitely algorithm A is the best, algorithm B is the second and algorithm C is the worst.

But if we take the answer space into account, all these three algorithms have the same \`O(N^2)\` space complexity overall.

So, only estimating the **extra** space **excluding** the answer space helps us better understand the algorithm's overhead.

# License

All rights reserved by [github.com/lzl124631x](https://github.com/lzl124631x). Contact me if you want to redistribute the code. No commercial use." >> $file

printf "\rDONE"