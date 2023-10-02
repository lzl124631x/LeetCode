# [1147. Longest Chunked Palindrome Decomposition (Hard)](https://leetcode.com/problems/longest-chunked-palindrome-decomposition/)

<p>You are given a string <code>text</code>. You should split it to k substrings <code>(subtext<sub>1</sub>, subtext<sub>2</sub>, ..., subtext<sub>k</sub>)</code> such that:</p>

<ul>
	<li><code>subtext<sub>i</sub></code> is a <strong>non-empty</strong> string.</li>
	<li>The concatenation of all the substrings is equal to <code>text</code> (i.e., <code>subtext<sub>1</sub> + subtext<sub>2</sub> + ... + subtext<sub>k</sub> == text</code>).</li>
	<li><code>subtext<sub>i</sub> == subtext<sub>k - i + 1</sub></code> for all valid values of <code>i</code> (i.e., <code>1 &lt;= i &lt;= k</code>).</li>
</ul>

<p>Return the largest possible value of <code>k</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> text = "ghiabcdefhelloadamhelloabcdefghi"
<strong>Output:</strong> 7
<strong>Explanation:</strong> We can split the string on "(ghi)(abcdef)(hello)(adam)(hello)(abcdef)(ghi)".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> text = "merchant"
<strong>Output:</strong> 1
<strong>Explanation:</strong> We can split the string on "(merchant)".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> text = "antaprezatepzapreanta"
<strong>Output:</strong> 11
<strong>Explanation:</strong> We can split the string on "(a)(nt)(a)(pre)(za)(tpe)(za)(pre)(a)(nt)(a)".
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> text = "aaa"
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can split the string on "(a)(a)(a)".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 1000</code></li>
	<li><code>text</code> consists only of lowercase English characters.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Greedy](https://leetcode.com/tag/greedy/), [Rolling Hash](https://leetcode.com/tag/rolling-hash/), [Hash Function](https://leetcode.com/tag/hash-function/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/longest-chunked-palindrome-decomposition/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int longestDecomposition(string s) {
        int i = 0, N = s.size(), ans = 0; 
        while (i < N / 2) {
            int len = 1;
            for (; i + len <= N / 2; ++len) {
                int j = 0;
                for (; j < len && s[i + j] == s[N - i - len + j]; ++j);
                if (j == len) break; // found match
            }
            if (i + len > N / 2) break; // match not found.
            ans += 2;
            i += len;
        } 
        return ans + (i < (N + 1) / 2);
    }
};
```