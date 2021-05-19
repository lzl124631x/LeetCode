# [1781. Sum of Beauty of All Substrings (Medium)](https://leetcode.com/problems/sum-of-beauty-of-all-substrings/)

<p>The <strong>beauty</strong> of a string is the difference in frequencies between the most frequent and least frequent characters.</p>

<ul>
	<li>For example, the beauty of <code>"abaacc"</code> is <code>3 - 1 = 2</code>.</li>
</ul>

<p>Given a string <code>s</code>, return <em>the sum of <strong>beauty</strong> of all of its substrings.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "aabcb"
<strong>Output:</strong> 5
<strong>Explanation: </strong>The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aabcbaa"
<strong>Output:</strong> 17
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;=<sup> </sup>500</code></li>
	<li><code>s</code> consists of only lowercase English letters.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            int cnt[26] = {};
            for (int j = i; j < s.size(); ++j) {
                ++cnt[s[j] - 'a'];
                int mx = INT_MIN, mn = INT_MAX;
                for (int k = 0; k < 26; ++k) {
                    mx = max(mx, cnt[k]);
                    if (cnt[k]) mn = min(mn, cnt[k]);
                }
                ans += mx - mn;
            }
        }
        return ans;
    }
};
```