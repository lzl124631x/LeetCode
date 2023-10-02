# [132. Palindrome Partitioning II (Hard)](https://leetcode.com/problems/palindrome-partitioning-ii)

<p>Given a string <code>s</code>, partition <code>s</code> such that every <span data-keyword="substring-nonempty">substring</span> of the partition is a <span data-keyword="palindrome-string">palindrome</span>.</p>

<p>Return <em>the <strong>minimum</strong> cuts needed for a palindrome partitioning of</em> <code>s</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aab&quot;
<strong>Output:</strong> 1
<strong>Explanation:</strong> The palindrome partitioning [&quot;aa&quot;,&quot;b&quot;] could be produced using 1 cut.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;a&quot;
<strong>Output:</strong> 0
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;ab&quot;
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code> consists of lowercase English letters only.</li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple), [Bloomberg](https://leetcode.com/company/bloomberg), [Yahoo](https://leetcode.com/company/yahoo), [TikTok](https://leetcode.com/company/tiktok)

**Related Topics**:  
[String](https://leetcode.com/tag/string), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming)

**Similar Questions**:
* [Palindrome Partitioning (Medium)](https://leetcode.com/problems/palindrome-partitioning)
* [Palindrome Partitioning IV (Hard)](https://leetcode.com/problems/palindrome-partitioning-iv)
* [Maximum Number of Non-overlapping Palindrome Substrings (Hard)](https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings)
* [Number of Great Partitions (Hard)](https://leetcode.com/problems/number-of-great-partitions)

## Solution 1.

Let `dp[i+1]` be the minimum number of palindrome segments partitioned from `s[0..i]`.

```
dp[0] = 0
dp[i+1] = min( dp[j] + 1 | p[j][i] is true )
```

The answer is `dp[N]`

```cpp
// OJ: https://leetcode.com/problems/palindrome-partitioning-ii
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int minCut(string s) {
        bool p[2000][2000] = {}; // p[i][j] = true if s[i][j] is a palindrome
        int N = s.size(), dp[2001] = {};
        for (int i = 0; i < N; ++i) {
            p[i][i] = true;
            for (int k = 1; i - k >= 0 && i + k < N && s[i - k] == s[i + k]; ++k) p[i - k][i + k] = true;
            if (i - 1 >= 0 && s[i - 1] == s[i]) {
                p[i - 1][i] = true;
                for (int k = 1; i - 1 - k >= 0 && i + k < N && s[i - 1 - k] == s[i + k]; ++k) p[i - 1 - k][i + k] = true;
            }
        }
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (p[j][i]) {
                    dp[i + 1] = min(dp[i + 1], 1 + dp[j]);
                }
            }
        }
        return dp[N] - 1;
    }
};
```