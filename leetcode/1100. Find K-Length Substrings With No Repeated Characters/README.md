# [1100. Find K-Length Substrings With No Repeated Characters (Medium)](https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/)

<p>Given a string <code>s</code> and an integer <code>k</code>, return <em>the number of substrings in </em><code>s</code><em> of length </em><code>k</code><em> with no repeated characters</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "havefunonleetcode", k = 5
<strong>Output:</strong> 6
<strong>Explanation:</strong> There are 6 substrings they are: 'havef','avefu','vefun','efuno','etcod','tcode'.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "home", k = 5
<strong>Output:</strong> 0
<strong>Explanation:</strong> Notice k can be larger than the length of s. In this case, it is not possible to find any substring.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
	<li><code>1 &lt;= k &lt;= 10<sup>4</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

## Solution 1. Fixed-length Sliding Window

```cpp
// OJ: https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int N = s.size(), ans = 0, cnt[26] = {}, unique = 0;
        for (int i = 0; i < N; ++i) {
            if (++cnt[s[i] - 'a'] == 1) ++unique;
            if (i - k >= 0 && --cnt[s[i - k] - 'a'] == 0) --unique;
            ans += unique == k;
        }
        return ans;
    }
};
```