# [479. Largest Palindrome Product (Hard)](https://leetcode.com/problems/largest-palindrome-product/)

<p>Given an integer n, return <em>the <strong>largest palindromic integer</strong> that can be represented as the product of two <code>n</code>-digits integers</em>. Since the answer can be very large, return it <strong>modulo</strong> <code>1337</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> 987
Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> 9
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 8</code></li>
</ul>


**Companies**:  
[Yahoo](https://leetcode.com/company/yahoo)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/largest-palindrome-product/
// Author: github.com/lzl124631x
// Time: O(10^(2N))
// Space: O(N)
class Solution {
    long buildPalindrome(int n) {
        auto s = to_string(n);
        reverse(begin(s), end(s));
        return stol(to_string(n) + s);
    }
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        int upper = pow(10, n) - 1, lower = pow(10, n -1);
        for (int i = upper; i >= lower; --i) {
            long num = buildPalindrome(i);
            for (long j = upper; j * j >= num; --j) {
                if (num % j == 0) {
                    return num % 1337;
                }
            }
        }
        return -1;
    }
};
```

## TODO

read https://leetcode.com/problems/largest-palindrome-product/discuss/96306/Java-solutions-with-two-different-approaches