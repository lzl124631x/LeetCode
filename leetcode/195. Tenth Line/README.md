# [195. Tenth Line (Easy)](https://leetcode.com/problems/tenth-line/)

<p>Given a text file&nbsp;<code>file.txt</code>, print&nbsp;just the 10th line of the&nbsp;file.</p>

<p><strong>Example:</strong></p>

<p>Assume that <code>file.txt</code> has the following content:</p>

<pre>Line 1
Line 2
Line 3
Line 4
Line 5
Line 6
Line 7
Line 8
Line 9
Line 10
</pre>

<p>Your script should output the tenth line, which is:</p>

<pre>Line 10
</pre>

<div class="spoilers"><b>Note:</b><br>
1. If the file contains less than 10 lines, what should you output?<br>
2. There's at least three different solutions. Try to explore all possibilities.</div>


**Companies**:  
[Google](https://leetcode.com/company/google)

## Solution 1.

```sh
# OJ: https://leetcode.com/problems/tenth-line/
# Author: github.com/lzl124631x
[ $(cat file.txt | wc -l) -ge 10 ] && head -10 file.txt | tail -1
```