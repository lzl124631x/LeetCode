# OJ: https://leetcode.com/problems/tenth-line/
# Author: github.com/lzl124631x
[ $(cat file.txt | wc -l) -ge 10 ] && head -10 file.txt | tail -1