# [792. Number of Matching Subsequences (Medium)](https://leetcode.com/problems/number-of-matching-subsequences/)

<p>Given a string <code>s</code> and an array of strings <code>words</code>, return <em>the number of</em> <code>words[i]</code> <em>that is a subsequence of</em> <code>s</code>.</p>

<p>A <strong>subsequence</strong> of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.</p>

<ul>
	<li>For example, <code>"ace"</code> is a subsequence of <code>"abcde"</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abcde", words = ["a","bb","acd","ace"]
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are three strings in words that are a subsequence of s: "a", "acd", "ace".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= words.length &lt;= 5000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 50</code></li>
	<li><code>s</code> and <code>words[i]</code> consist of only lowercase English letters.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Coupang](https://leetcode.com/company/coupang)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Is Subsequence (Easy)](https://leetcode.com/problems/is-subsequence/)
* [Shortest Way to Form String (Medium)](https://leetcode.com/problems/shortest-way-to-form-string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-of-matching-subsequences/
// Author: github.com/lzl124631x
// Time: O(S + NWlogS)
// Space: O(S)
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& A) {
        vector<int> index[26];
        for (int i = 0; i < s.size(); ++i) index[s[i] - 'a'].push_back(i);
        int ans = 0;
        for (auto &w : A) {
            int i = 0, j = 0;
            for (; i < w.size(); ++i) {
                auto &v = index[w[i] - 'a'];
                auto it = lower_bound(begin(v), end(v), j);
                if (it == end(v)) break;
                j = *it + 1;
            }
            ans += i == w.size();
        }
        return ans;
    }
};
```