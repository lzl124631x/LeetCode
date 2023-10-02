# [2048. Next Greater Numerically Balanced Number (Medium)](https://leetcode.com/problems/next-greater-numerically-balanced-number/)

<p>An integer <code>x</code> is <strong>numerically balanced</strong> if for every digit <code>d</code> in the number <code>x</code>, there are <strong>exactly</strong> <code>d</code> occurrences of that digit in <code>x</code>.</p>

<p>Given an integer <code>n</code>, return <em>the <strong>smallest numerically balanced</strong> number <strong>strictly greater</strong> than </em><code>n</code><em>.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> 22
<strong>Explanation:</strong> 
22 is numerically balanced since:
- The digit 2 occurs 2 times. 
It is also the smallest numerically balanced number strictly greater than 1.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 1000
<strong>Output:</strong> 1333
<strong>Explanation:</strong> 
1333 is numerically balanced since:
- The digit 1 occurs 1 time.
- The digit 3 occurs 3 times. 
It is also the smallest numerically balanced number strictly greater than 1000.
Note that 1022 cannot be the answer because 0 appeared more than 0 times.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 3000
<strong>Output:</strong> 3133
<strong>Explanation:</strong> 
3133 is numerically balanced since:
- The digit 1 occurs 1 time.
- The digit 3 occurs 3 times.
It is also the smallest numerically balanced number strictly greater than 3000.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 10<sup>6</sup></code></li>
</ul>

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/next-greater-numerically-balanced-number/
// Author: github.com/lzl124631x
// Time: O(C * logC) where `C` is the maximum possible input number.
// Space: O(1)
class Solution {
    bool balance(int n) {
        int cnt[10] = {};
        while (n) {
            if (n % 10 == 0) return false; // no 0 allowed
            cnt[n % 10]++;
            n /= 10;
        }
        for (int i = 1; i < 10; ++i) {
            if (cnt[i] && cnt[i] != i) return false;
        }
        return true;
    }
public:
    int nextBeautifulNumber(int n) {
        while (true) {
            ++n;
            if (balance(n)) return n;
        }
    }
};
```

## Discuss

https://leetcode.com/problems/next-greater-numerically-balanced-number/discuss/1537491/C%2B%2B-Brute-Force