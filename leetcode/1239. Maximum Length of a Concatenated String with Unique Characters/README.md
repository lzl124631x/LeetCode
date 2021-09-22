# [1239. Maximum Length of a Concatenated String with Unique Characters (Medium)](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/)

<p>Given an array of strings <code>arr</code>. String <code>s</code> is a concatenation of a sub-sequence of <code>arr</code> which have <strong>unique characters</strong>.</p>

<p>Return <em>the maximum possible length</em> of <code>s</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = ["un","iq","ue"]
<strong>Output:</strong> 4
<strong>Explanation:</strong> All possible concatenations are "","un","iq","ue","uniq" and "ique".
Maximum length is 4.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = ["cha","r","act","ers"]
<strong>Output:</strong> 6
<strong>Explanation:</strong> Possible solutions are "chaers" and "acters".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = ["abcdefghijklmnopqrstuvwxyz"]
<strong>Output:</strong> 26
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 16</code></li>
	<li><code>1 &lt;= arr[i].length &lt;= 26</code></li>
	<li><code>arr[i]</code> contains only lower case English letters.</li>
</ul>


**Companies**:  
[Tesla](https://leetcode.com/company/tesla), [Microsoft](https://leetcode.com/company/microsoft), [DiDi](https://leetcode.com/company/didi), [American Express](https://leetcode.com/company/american-express)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/), [Backtracking](https://leetcode.com/tag/backtracking/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1. Bitmask

```cpp
// OJ: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N)
class Solution {
public:
    int maxLength(vector<string>& A) {
        vector<int> v;
        for (auto &s : A) {
            int bs = 0, i = 0;
            for (; i < s.size(); ++i) {
                int j = s[i] - 'a';
                if (bs >> j & 1) break;
                bs |= 1 << j;
            }
            if (i == s.size()) v.push_back(bs);
        }
        int ans = 0;
        for (int m = 1; m < 1 << v.size(); ++m) {
            int bs = 0, i = 0;
            for (; i < v.size(); ++i) {
                if ((m >> i & 1) == 0) continue;
                if (bs & v[i]) break;
                bs |= v[i];
            }
            ans = max(ans, __builtin_popcount(bs));
        }
        return ans;
    }
};
```