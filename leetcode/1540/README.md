# [1540. Can Convert String in K Moves (Medium)](https://leetcode.com/problems/can-convert-string-in-k-moves/)

<p>Given two strings&nbsp;<code>s</code>&nbsp;and&nbsp;<code>t</code>, your goal is to convert&nbsp;<code>s</code>&nbsp;into&nbsp;<code>t</code>&nbsp;in&nbsp;<code>k</code><strong>&nbsp;</strong>moves or less.</p>

<p>During the&nbsp;<code>i<sup>th</sup></code>&nbsp;(<font face="monospace"><code>1 &lt;= i &lt;= k</code>)&nbsp;</font>move you can:</p>

<ul>
	<li>Choose any index&nbsp;<code>j</code>&nbsp;(1-indexed) from&nbsp;<code>s</code>, such that&nbsp;<code>1 &lt;= j &lt;= s.length</code>&nbsp;and <code>j</code>&nbsp;has not been chosen in any previous move,&nbsp;and shift the character at that index&nbsp;<code>i</code>&nbsp;times.</li>
	<li>Do nothing.</li>
</ul>

<p>Shifting a character means replacing it by the next letter in the alphabet&nbsp;(wrapping around so that&nbsp;<code>'z'</code>&nbsp;becomes&nbsp;<code>'a'</code>). Shifting a character by&nbsp;<code>i</code>&nbsp;means applying the shift operations&nbsp;<code>i</code>&nbsp;times.</p>

<p>Remember that any index&nbsp;<code>j</code>&nbsp;can be picked at most once.</p>

<p>Return&nbsp;<code>true</code>&nbsp;if it's possible to convert&nbsp;<code>s</code>&nbsp;into&nbsp;<code>t</code>&nbsp;in no more than&nbsp;<code>k</code>&nbsp;moves, otherwise return&nbsp;<code>false</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "input", t = "ouput", k = 9
<strong>Output:</strong> true
<b>Explanation: </b>In the 6th move, we shift 'i' 6 times to get 'o'. And in the 7th move we shift 'n' to get 'u'.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abc", t = "bcd", k = 10
<strong>Output:</strong> false
<strong>Explanation: </strong>We need to shift each character in s one time to convert it into t. We can shift 'a' to 'b' during the 1st move. However, there is no way to shift the other characters in the remaining moves to obtain t from s.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "aab", t = "bbb", k = 27
<strong>Output:</strong> true
<b>Explanation: </b>In the 1st move, we shift the first 'a' 1 time to get 'b'. In the 27th move, we shift the second 'a' 27 times to get 'b'.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length, t.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= k &lt;= 10^9</code></li>
	<li><code>s</code>, <code>t</code> contain&nbsp;only lowercase English letters.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/can-convert-string-in-k-moves/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.size() != t.size()) return false;
        int cnt[26] = {};
        for (int i = 0; i < s.size(); ++i) {
            int d = t[i] - s[i];
            if (d == 0) continue;
            if (d < 0) d += 26;
            if (d + cnt[d]++ * 26 > k) return false;
        }
        return true;
    }
};
```