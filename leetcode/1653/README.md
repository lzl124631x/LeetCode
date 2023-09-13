# [1653. Minimum Deletions to Make String Balanced (Medium)](https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/)

<p>You are given a string <code>s</code> consisting only of characters <code>'a'</code> and <code>'b'</code>​​​​.</p>

<p>You can delete any number of characters in <code>s</code> to make <code>s</code> <strong>balanced</strong>. <code>s</code> is <strong>balanced</strong> if there is no pair of indices <code>(i,j)</code> such that <code>i &lt; j</code> and <code>s[i] = 'b'</code> and <code>s[j]= 'a'</code>.</p>

<p>Return <em>the <strong>minimum</strong> number of deletions needed to make </em><code>s</code><em> <strong>balanced</strong></em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "aababbab"
<strong>Output:</strong> 2
<strong>Explanation:</strong> You can either:
Delete the characters at 0-indexed positions 2 and 6 ("aa<u>b</u>abb<u>a</u>b" -&gt; "aaabbb"), or
Delete the characters at 0-indexed positions 3 and 6 ("aab<u>a</u>bb<u>a</u>b" -&gt; "aabbbb").
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "bbaaaaabb"
<strong>Output:</strong> 2
<strong>Explanation:</strong> The only solution is to delete the first two characters.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> is&nbsp;<code>'a'</code> or <code>'b'</code>​​.</li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Swiggy](https://leetcode.com/company/swiggy)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Stack](https://leetcode.com/tag/stack/)

**Similar Questions**:
* [Check if All A's Appears Before All B's (Easy)](https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/)

## Solution 1. Left-to-Right State Transition

Scan `s` and try using each point as a breakpoint. Keep track of the number of `a`s to the left and number of `b`s to the right. For each breackpoint, the longest string we can form is of length `a + b`. We find the global maximum of such length, and the answer is `N` minus this maximum value.

```cpp
// OJ: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minimumDeletions(string s) {
        int a = 0, b = 0, N = s.size();
        for (char c : s) b += c == 'b';
        int ans = b;
        for (int i = 0; i < N; ++i) {
            a += s[i] == 'a';
            b -= s[i] == 'b';
            ans = max(ans, a + b);
        }
        return N - ans;
    }
};
```