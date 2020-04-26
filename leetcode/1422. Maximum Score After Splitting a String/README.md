# [1422. Maximum Score After Splitting a String (Easy)](https://leetcode.com/problems/maximum-score-after-splitting-a-string)

<p>Given a&nbsp;string <code>s</code>&nbsp;of zeros and ones, <em>return the maximum score after splitting the string into two <strong>non-empty</strong> substrings</em> (i.e. <strong>left</strong> substring and <strong>right</strong> substring).</p>

<p>The score after splitting a string is the number of <strong>zeros</strong> in the <strong>left</strong> substring plus the number of <strong>ones</strong> in the <strong>right</strong> substring.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "011101"
<strong>Output:</strong> 5 
<strong>Explanation:</strong> 
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5 
left = "01" and right = "1101", score = 1 + 3 = 4 
left = "011" and right = "101", score = 1 + 2 = 3 
left = "0111" and right = "01", score = 1 + 1 = 2 
left = "01110" and right = "1", score = 2 + 1 = 3
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "00111"
<strong>Output:</strong> 5
<strong>Explanation:</strong> When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "1111"
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 500</code></li>
	<li>The string <code>s</code> consists of characters '0' and '1' only.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

`zero` and `one` are the counts of `0`s in `left` and `1`s in `right`.

First compute the count of all `1`s as `one`. Then for each `i` in range `[0, N - 2]`, increment `zero` if `s[i] == '0'` and decrement `one` if `s[i] == '1'`. The maximum `zero + one` is the result.

```cpp
// OJ: https://leetcode.com/problems/maximum-score-after-splitting-a-string
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxScore(string s) {
        int one = 0, zero = 0, ans = 0;
        for (char c : s) one += c == '1';
        for (int i = 0; i < s.size() - 1; ++i) {
            char c  = s[i];
            zero += c == '0';
            one -= c == '1';
            ans = max(ans, zero + one);
        }
        return ans;
    }
};
```