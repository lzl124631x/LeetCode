# [1960. Maximum Product of the Length of Two Palindromic Substrings (Hard)](https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-substrings/)

<p>You are given a <strong>0-indexed</strong> string <code>s</code> and are tasked with finding two <strong>non-intersecting palindromic </strong>substrings of <strong>odd</strong> length such that the product of their lengths is maximized.</p>

<p>More formally, you want to choose four integers <code>i</code>, <code>j</code>, <code>k</code>, <code>l</code> such that <code>0 &lt;= i &lt;= j &lt; k &lt;= l &lt; s.length</code> and both the substrings <code>s[i...j]</code> and <code>s[k...l]</code> are palindromes and have odd lengths. <code>s[i...j]</code> denotes a substring from index <code>i</code> to index <code>j</code> <strong>inclusive</strong>.</p>

<p>Return <em>the <strong>maximum</strong> possible product of the lengths of the two non-intersecting palindromic substrings.</em></p>

<p>A <strong>palindrome</strong> is a string that is the same forward and backward. A <strong>substring</strong> is a contiguous sequence of characters in a string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "ababbb"
<strong>Output:</strong> 9
<strong>Explanation:</strong> Substrings "aba" and "bbb" are palindromes with odd length. product = 3 * 3 = 9.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "zaaaxbbby"
<strong>Output:</strong> 9
<strong>Explanation:</strong> Substrings "aaa" and "bbb" are palindromes with odd length. product = 3 * 3 = 9.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>


**Companies**:  
[Codenation](https://leetcode.com/company/codenation)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Rolling Hash](https://leetcode.com/tag/rolling-hash/), [Hash Function](https://leetcode.com/tag/hash-function/)

## Solution 1. Manacher

```cpp
// OJ: https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-substrings/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-substrings/discuss/1389958/Manacher-and-Queue
class Solution {
    vector<int> manachers(string s, int n) {
        vector<int> m(n), l2r(n, 1);
        for (int i = 0, l = 0, r = -1; i < n; ++i) {
            int k = (i > r) ? 1 : min(m[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
                l2r[i + k] = 2 * k + 1;
                k++;
            }
            m[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
        for (int i = 1; i < n; i++) l2r[i] = max(l2r[i], l2r[i - 1]);
        return l2r;
    }
public:
    long long maxProduct(string s) {
        long long ans = 1, n = s.size();
        auto l2r = manachers(s, n);
        auto r2l = manachers(string(rbegin(s), rend(s)), n);
        for (int i = 0, j = n - 2; i < n - 1; ++i, --j) {
            long long tmp = ans;
            ans = max(ans, (long long)l2r[i] * r2l[j]);
        }
        return ans;
    }
};
```