# [1316. Distinct Echo Substrings (Hard)](https://leetcode.com/problems/distinct-echo-substrings/)

<p>Return the number of <strong>distinct</strong> non-empty substrings of <code>text</code>&nbsp;that can be written as the concatenation of some string with itself (i.e. it can be written as <code>a + a</code>&nbsp;where <code>a</code> is some string).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> text = "abcabcabc"
<strong>Output:</strong> 3
<b>Explanation: </b>The 3 substrings are "abcabc", "bcabca" and "cabcab".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> text = "leetcodeleetcode"
<strong>Output:</strong> 2
<b>Explanation: </b>The 2 substrings are "ee" and "leetcodeleetcode".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 2000</code></li>
	<li><code>text</code>&nbsp;has only lowercase English letters.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Rolling Hash](https://leetcode.com/tag/rolling-hash/)

## Solution 1. Rolling Hash

```cpp
// OJ: https://leetcode.com/problems/distinct-echo-substrings/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int distinctEchoSubstrings(string s) {
        int N = s.size(), mod = 1e8 + 7, cnt = 0;
        vector<long> v(N);
        for (int len = 1; len <= N / 2; ++len) {
            long hash = s[0] - 'a', p = 1;
            unordered_set<string> seen;
            for (int i = 1; i < N; ++i) {
                if (i < len) {
                    hash = (hash * 26 + s[i] - 'a') % mod;
                    p = (p * 26) % mod;
                } else {
                    hash = ((hash - (s[i - len] - 'a') * p) * 26 + s[i] - 'a') % mod;
                    if (hash < 0) hash += mod;
                    if (i - 2 * len + 1 >= 0 && v[i - len] == hash) {
                        auto a = s.substr(i - 2 * len + 1, len);
                        if (seen.count(a)) continue;
                        seen.insert(a);
                        if (a == s.substr(i - len + 1, len)) ++cnt;
                    }
                }
                v[i] = hash;
            }
        }
        return cnt;
    }
};
```