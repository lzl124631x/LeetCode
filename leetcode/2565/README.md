# [2565. Subsequence With the Minimum Score (Hard)](https://leetcode.com/problems/subsequence-with-the-minimum-score)

<p>You are given two strings <code>s</code> and <code>t</code>.</p>

<p>You are allowed to remove any number of characters from the string <code>t</code>.</p>

<p>The score of the string is <code>0</code> if no characters are removed from the string <code>t</code>, otherwise:</p>

<ul>
	<li>Let <code>left</code> be the minimum index among all removed characters.</li>
	<li>Let <code>right</code> be the maximum index among all removed characters.</li>
</ul>

<p>Then the score of the string is <code>right - left + 1</code>.</p>

<p>Return <em>the minimum possible score to make </em><code>t</code><em>&nbsp;a subsequence of </em><code>s</code><em>.</em></p>

<p>A <strong>subsequence</strong> of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., <code>&quot;ace&quot;</code> is a subsequence of <code>&quot;<u>a</u>b<u>c</u>d<u>e</u>&quot;</code> while <code>&quot;aec&quot;</code> is not).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abacaba&quot;, t = &quot;bzaa&quot;
<strong>Output:</strong> 1
<strong>Explanation:</strong> In this example, we remove the character &quot;z&quot; at index 1 (0-indexed).
The string t becomes &quot;baa&quot; which is a subsequence of the string &quot;abacaba&quot; and the score is 1 - 1 + 1 = 1.
It can be proven that 1 is the minimum score that we can achieve.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;cde&quot;, t = &quot;xyz&quot;
<strong>Output:</strong> 3
<strong>Explanation:</strong> In this example, we remove characters &quot;x&quot;, &quot;y&quot; and &quot;z&quot; at indices 0, 1, and 2 (0-indexed).
The string t becomes &quot;&quot; which is a subsequence of the string &quot;cde&quot; and the score is 2 - 0 + 1 = 3.
It can be proven that 3 is the minimum score that we can achieve.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length, t.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> and <code>t</code> consist of only lowercase English letters.</li>
</ul>


**Companies**:
[DoorDash](https://leetcode.com/company/doordash)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers), [String](https://leetcode.com/tag/string), [Binary Search](https://leetcode.com/tag/binary-search)

**Similar Questions**:
* [Longest Common Subsequence (Medium)](https://leetcode.com/problems/longest-common-subsequence)

**Hints**:
* Maintain two pointers: i and j. We need to perform a similar operation: while t[0:i] + t[j:n] is not a subsequence of the string s, increase j.
* We can check the condition greedily. Create the array leftmost[i] which denotes minimum index k, such that in prefix s[0:k] exists subsequence t[0:i]. Similarly, we define rightmost[i].
* If leftmost[i] < rightmost[j] then t[0:i] + t[j:n] is the subsequence of s.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/subsequence-with-the-minimum-score
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(M)
class Solution {
public:
    int minimumScore(string s, string t) {
        int M = s.size(), N = t.size();
        vector<int> matchRight(M + 1, N - 1);
        for (int i = M - 1, j = N - 1; i >= 0; --i) {
            if (j >= 0 && s[i] == t[j]) --j;
            matchRight[i] = j;
        }
        int ans = matchRight[0] + 1;
        for (int i = 0, j = 0; i < M; ++i) {
            if (j < N && s[i] == t[j]) ++j;
            ans = min(ans, max(0, matchRight[i + 1] - j + 1));
        }
        return ans;
    }
};
```