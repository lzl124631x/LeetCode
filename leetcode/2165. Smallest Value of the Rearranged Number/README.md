# [2165. Smallest Value of the Rearranged Number (Medium)](https://leetcode.com/problems/smallest-value-of-the-rearranged-number/)

<p>You are given an integer <code>num.</code> <strong>Rearrange</strong> the digits of <code>num</code> such that its value is <strong>minimized</strong> and it does not contain <strong>any</strong> leading zeros.</p>

<p>Return <em>the rearranged number with minimal value</em>.</p>

<p>Note that the sign of the number does not change after rearranging the digits.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> num = 310
<strong>Output:</strong> 103
<strong>Explanation:</strong> The possible arrangements for the digits of 310 are 013, 031, 103, 130, 301, 310. 
The arrangement with the smallest value that does not contain any leading zeros is 103.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> num = -7605
<strong>Output:</strong> -7650
<strong>Explanation:</strong> Some possible arrangements for the digits of -7605 are -7650, -6705, -5076, -0567.
The arrangement with the smallest value that does not contain any leading zeros is -7650.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-10<sup>15</sup> &lt;= num &lt;= 10<sup>15</sup></code></li>
</ul>


**Similar Questions**:
* [Largest Number (Medium)](https://leetcode.com/problems/largest-number/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/smallest-value-of-the-rearranged-number/
// Author: github.com/lzl124631x
// Time: O(KlogK) where K is the number of digits in `n`
// Space: O(K)
class Solution {
public:
    long long smallestNumber(long long n) {
        if (n == 0) return 0;
        int sign = n >= 0 ? 1 : -1, zero = 0;
        n = abs(n);
        vector<int> d;
        while (n) {
            if (n % 10 == 0) ++zero;
            else d.push_back(n % 10);
            n /= 10;
        }
        if (sign == 1) {
            sort(begin(d), end(d));
            long ans = d[0];
            while (zero--) ans = 10 * ans;
            for (int i = 1; i < d.size(); ++i) {
                ans = 10 * ans + d[i];
            }
            return ans;
        } else {
            sort(begin(d), end(d), greater<>());
            long ans = 0;
            for (int i = 0; i < d.size(); ++i) {
                ans = 10 * ans + d[i];
            }
            while (zero--) ans = 10 * ans;
            return -ans;
        }
    }
};
```