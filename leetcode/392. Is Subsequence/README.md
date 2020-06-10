# [392. Is Subsequence (Easy)](https://leetcode.com/problems/is-subsequence/)

<p>Given a string <b>s</b> and a string <b>t</b>, check if <b>s</b> is subsequence of <b>t</b>.</p>

<p>A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, <code>"ace"</code> is a subsequence of <code>"abcde"</code> while <code>"aec"</code> is not).</p>

<p><b>Follow up:</b><br>
If there are lots of incoming S, say S1, S2, ... , Sk where k &gt;= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?</p>

<p><b>Credits:</b><br>
Special thanks to <a href="https://leetcode.com/pbrother/">@pbrother</a> for adding this problem and creating all test cases.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> s = "abc", t = "ahbgdc"
<strong>Output:</strong> true
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> s = "axc", t = "ahbgdc"
<strong>Output:</strong> false
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 100</code></li>
	<li><code>0 &lt;= t.length &lt;= 10^4</code></li>
	<li>Both strings consists only of lowercase characters.</li>
</ul>


**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Number of Matching Subsequences (Medium)](https://leetcode.com/problems/number-of-matching-subsequences/)
* [Shortest Way to Form String (Medium)](https://leetcode.com/problems/shortest-way-to-form-string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/is-subsequence/
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0, M = s.size(), N = t.size();
        for (; i < M && j < N; ++j) {
            if (s[i] == t[j]) ++i;
        }
        return i == M;
    }
};
```