# [1573. Number of Ways to Split a String (Medium)](https://leetcode.com/problems/number-of-ways-to-split-a-string/)

<p>Given a binary string <code>s</code> (a string consisting only of '0's and '1's),&nbsp;we can split <code>s</code>&nbsp;into 3 <strong>non-empty</strong> strings s1, s2, s3 (s1+ s2+ s3 = s).</p>

<p>Return the number of ways <code>s</code> can be split such that the number of&nbsp;characters '1' is the same in s1, s2, and s3.</p>

<p>Since the answer&nbsp;may be too large,&nbsp;return it modulo&nbsp;10^9 + 7.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "10101"
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are four ways to split s in 3 parts where each part contain the same number of letters '1'.
"1|010|1"
"1|01|01"
"10|10|1"
"10|1|01"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "1001"
<strong>Output:</strong> 0
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "0000"
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are three ways to split s in 3 parts.
"0|0|00"
"0|00|0"
"00|0|0"
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "100100010100110"
<strong>Output:</strong> 12
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>s[i] == '0'</code>&nbsp;or&nbsp;<code>s[i] == '1'</code></li>
	<li><code>3 &lt;= s.length &lt;= 10^5</code></li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Split Array with Equal Sum (Medium)](https://leetcode.com/problems/split-array-with-equal-sum/)

## Solution 1.

First count the number of 1s. The the count is not divisible by 3, we can't split `s` into 3 parts, then return `0`.

If `cnt == 0`, what we need to do is to choose `2` out of the `N - 1` gaps between the `N` elements to split the `s`, so there are `combination(N - 1, 2) = (N - 1) * (N - 2) / 2` cases.

Othewise, we need to find the number of possible cases of `s1` and `s3` respectively.

For `s1`, that's the number of `0`s between the `cnt/3`-th (1-based) and `cnt/3 + 1`-th `1` from the left side, plus `1`. Let this be `left`.

For `s3`, that's the number of `0`s between the `cnt/3`-th (1-based) and `cnt/3 + 1`-th `1` from the right side, plus `1`. Let this be `right`.

And the answer is different combinations of `left` and `right` and thus is `left * right`.

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-split-a-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numWays(string s) {
        long mod = 1e9+7, cnt = 0;
        for (char c : s) cnt += c == '1';  // cnt is the count of all 1s
        if (cnt % 3) return 0;  // if cnt is not divisible by 3, we can't split the string into 3 parts, return 0
        if (cnt == 0) return (long)(s.size() - 1) * (s.size() - 2) / 2 % mod; // if cnt is 0, there are (N - 1) * (N - 2) / 2 cases.
        int i = 0, c = 0, left = 0, right = 0; // left and right are the numbers of possible cases for s1 and s2 respectively
        while (c <= cnt / 3) {
            c += s[i++] == '1';
            if (c == cnt / 3) ++left;
        }
        i = s.size() - 1, c = 0;
        while (c <= cnt / 3) {
            c += s[i--] == '1';
            if (c == cnt / 3) ++right;
        }
        return (long)left * right % mod; // The answer is simply left * right
    }
};
```