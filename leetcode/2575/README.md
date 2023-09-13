# [2575. Find the Divisibility Array of a String (Medium)](https://leetcode.com/problems/find-the-divisibility-array-of-a-string)

<p>You are given a <strong>0-indexed</strong> string <code>word</code> of length <code>n</code>&nbsp;consisting of digits, and a positive integer&nbsp;<code>m</code>.</p>
<p>The <strong>divisibility array</strong> <code>div</code> of <code>word</code> is an integer array of length <code>n</code> such that:</p>
<ul>
	<li><code>div[i] = 1</code> if the&nbsp;<strong>numeric value</strong>&nbsp;of&nbsp;<code>word[0,...,i]</code> is divisible by <code>m</code>, or</li>
	<li><code>div[i] = 0</code> otherwise.</li>
</ul>
<p>Return<em> the divisibility array of</em><em> </em><code>word</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> word = "998244353", m = 3
<strong>Output:</strong> [1,1,0,0,0,1,1,0,0]
<strong>Explanation:</strong> There are only 4 prefixes that are divisible by 3: "9", "99", "998244", and "9982443".
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> word = "1010", m = 10
<strong>Output:</strong> [0,1,0,1]
<strong>Explanation:</strong> There are only 2 prefixes that are divisible by 10: "10", and "1010".
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code><font face="monospace">word.length == n</font></code></li>
	<li><code><font face="monospace">word</font></code><font face="monospace"> consists of digits from <code>0</code>&nbsp;to <code>9</code></font></li>
	<li><code><font face="monospace">1 &lt;= m &lt;= 10<sup>9</sup></font></code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Subarray Sums Divisible by K (Medium)](https://leetcode.com/problems/subarray-sums-divisible-by-k/)
* [Make Sum Divisible by P (Medium)](https://leetcode.com/problems/make-sum-divisible-by-p/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-the-divisibility-array-of-a-string
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> divisibilityArray(string s, int m) {
        vector<int> ans;
        long long r = 0;
        for (char c : s) {
            r = (r * 10 + c - '0') % m;
            ans.push_back(r == 0);
        }
        return ans;
    }
};
```