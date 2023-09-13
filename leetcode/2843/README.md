# [2843.   Count Symmetric Integers (Easy)](https://leetcode.com/problems/count-symmetric-integers)

<p>You are given two positive integers <code>low</code> and <code>high</code>.</p>
<p>An integer <code>x</code> consisting of <code>2 * n</code> digits is <strong>symmetric</strong> if the sum of the first <code>n</code> digits of <code>x</code> is equal to the sum of the last <code>n</code> digits of <code>x</code>. Numbers with an odd number of digits are never symmetric.</p>
<p>Return <em>the <strong>number of symmetric</strong> integers in the range</em> <code>[low, high]</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> low = 1, high = 100
<strong>Output:</strong> 9
<strong>Explanation:</strong> There are 9 symmetric integers between 1 and 100: 11, 22, 33, 44, 55, 66, 77, 88, and 99.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> low = 1200, high = 1230
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 4 symmetric integers between 1200 and 1230: 1203, 1212, 1221, and 1230.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= low &lt;= high &lt;= 10<sup>4</sup></code></li>
</ul>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Enumeration](https://leetcode.com/tag/enumeration/)

**Similar Questions**:
* [Palindrome Number (Easy)](https://leetcode.com/problems/palindrome-number/)
* [Sum of Digits in Base K (Easy)](https://leetcode.com/problems/sum-of-digits-in-base-k/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-symmetric-integers
// Author: github.com/lzl124631x
// Time: O((H - L) * lg(H))
// Space: O(lg(H))
class Solution {
    bool isSymmetric(int n) {
        auto s = to_string(n);
        if (s.size() % 2) return false;
        int N = s.size(), first = 0, second = 0;
        for (int i = 0; i < N; ++i) {
            if (i < N / 2) first += s[i] - '0';
            else second += s[i] - '0';
        }
        return first == second;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low ; i <= high; ++i) ans += isSymmetric(i);
        return ans;
    }
};
```