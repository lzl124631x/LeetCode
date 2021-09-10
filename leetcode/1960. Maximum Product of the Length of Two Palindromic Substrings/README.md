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
public:
    long long maxProduct(string s) {
        long long ans = 0, N = s.size();
        vector<int> r(N), right(N);
        for (int i = 0, L = 0, R = -1; i < N; ++i) {
            int k = i > R ? 1 : min(r[L + R - i], R - i + 1);
            while (0 <= i - k && i + k < N && s[i - k] == s[i + k]) k++;
            r[i] = k--;
            if (i + k > R) {
                L = i - k;
                R = i + k;
            }
        }
        queue<array<int, 2>> q, q1; // index, radius
        // right[i] is the length of the longest palinedome in [i, n)
        for (int i = N - 1; i >= 0; --i) {
            while (q.size() && q.front()[0] - q.front()[1] >= i) q.pop(); // if the queue front's range can't cover `i`, pop it.
            q.push({i, r[i]});
            right[i] = 1 + (q.front()[0] - i) * 2; // now queue front is the rightmost range that can cover `i`. It must be the center of the longest palindrom in `[i, n)`.
        }
        long long left = 0;
        // left is the length of the longest palindrome in [0, i].
        for (int i = 0; i < N - 1; ++i) {
            while (q1.size() && q1.front()[0] + q1.front()[1] <= i) q1.pop();
            q1.push({i, r[i]});
            left = max(left, 1LL + (i - q1.front()[0]) * 2);
            ans = max(ans, left * right[i + 1]);
        }
        return ans;
    }
};
```

```cpp
// OJ: https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-substrings/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-substrings/discuss/1389958/Manacher-and-Queue
class Solution {
    vector<int> manachers(string s, int n) {
        vector<int> r(n), l2r(n, 1);
        for (int i = 0, L = 0, R = -1; i < n; ++i) {
            int k = (i > R) ? 1 : min(r[L + R - i], R - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
                l2r[i + k] = 2 * k + 1;
                k++;
            }
            r[i] = k--;
            if (i + k > R) {
                L = i - k;
                R = i + k;
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