# [806. Number of Lines To Write String (Easy)](https://leetcode.com/problems/number-of-lines-to-write-string/)

<p>We are to write the letters of a given string <code>S</code>, from left to right into lines. Each line has maximum width 100 units, and if writing a letter would cause the width of the line to exceed 100 units, it is written on the next line. We are given an array&nbsp;<code>widths</code>, an array where widths[0] is the width of 'a', widths[1] is the width of 'b', ..., and widths[25] is the width of 'z'.</p>

<p>Now answer two questions: how many lines have at least one character from <code>S</code>, and what is the width used by the last such line? Return your answer as an integer list of length 2.</p>

<p>&nbsp;</p>

<pre><strong>Example :</strong>
<strong>Input:</strong> 
widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
S = "abcdefghijklmnopqrstuvwxyz"
<strong>Output:</strong> [3, 60]
<strong>Explanation: </strong>
All letters have the same length of 10. To write all 26 letters,
we need two full lines and one line with 60 units.
</pre>

<pre><strong>Example :</strong>
<strong>Input:</strong> 
widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
S = "bbbcccdddaaa"
<strong>Output:</strong> [2, 4]
<strong>Explanation: </strong>
All letters except 'a' have the same length of 10, and 
"bbbcccdddaa" will cover 9 * 10 + 2 * 4 = 98 units.
For the last 'a', it is written on the second line because
there is only 2 units left in the first line.
So the answer is 2 lines, plus 4 units in the second line.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ul>
	<li>The length of <code>S</code> will be in the range&nbsp;[1, 1000].</li>
	<li><code>S</code> will only contain lowercase letters.</li>
	<li><code>widths</code> is&nbsp;an array of length <code>26</code>.</li>
	<li><code>widths[i]</code> will be in the range of <code>[2, 10]</code>.</li>
</ul>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-of-lines-to-write-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int lineWidth = 0, cnt = 1;
        for (char c : S) {
            if (lineWidth + widths[c - 'a'] > 100) {
                lineWidth = 0;
                ++cnt;
            }
            lineWidth += widths[c - 'a'];
        }
        return { cnt, lineWidth };
    }
};
```