# [2609. Find the Longest Balanced Substring of a Binary String (Easy)](https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string)

<p>You are given a binary string <code>s</code> consisting only of zeroes and ones.</p>
<p>A substring of <code>s</code> is considered balanced if<strong> all zeroes are before ones</strong> and the number of zeroes is equal to the number of ones inside the substring. Notice that the empty substring is considered a balanced substring.</p>
<p>Return <em>the length of the longest balanced substring of </em><code>s</code>.</p>
<p>A <b>substring</b> is a contiguous sequence of characters within a string.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "01000111"
<strong>Output:</strong> 6
<strong>Explanation:</strong> The longest balanced substring is "000111", which has length 6.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "00111"
<strong>Output:</strong> 4
<strong>Explanation:</strong> The longest balanced substring is "0011", which has length 4.&nbsp;
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> s = "111"
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no balanced substring except the empty substring, so the answer is 0.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 50</code></li>
	<li><code>'0' &lt;= s[i] &lt;= '1'</code></li>
</ul>

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int N = s.size(), i = 0, ans = 0;
        while (i < N) {
            int zero = 0, one = 0;
            while (i < N && s[i] == '0') ++i, ++zero;
            while (i < N && s[i] == '1') ++i, ++one;
            ans = max(ans, min(zero, one) * 2);
        }
        return ans;
    }
};
```