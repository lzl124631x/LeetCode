# [2566. Maximum Difference by Remapping a Digit (Easy)](https://leetcode.com/problems/maximum-difference-by-remapping-a-digit)

<p>You are given an integer <code>num</code>. You know that Danny Mittal will sneakily <strong>remap</strong> one of the <code>10</code> possible digits (<code>0</code> to <code>9</code>) to another digit.</p>
<p>Return <em>the difference between the maximum and minimum</em><em>&nbsp;values Danny can make by remapping&nbsp;<strong>exactly</strong> <strong>one</strong> digit</em><em> in </em><code>num</code>.</p>
<p><strong>Notes:</strong></p>
<ul>
	<li>When Danny remaps a digit <font face="monospace">d1</font>&nbsp;to another digit <font face="monospace">d2</font>, Danny replaces all occurrences of <code>d1</code>&nbsp;in <code>num</code>&nbsp;with <code>d2</code>.</li>
	<li>Danny can remap a digit to itself, in which case <code>num</code>&nbsp;does not change.</li>
	<li>Danny can remap different digits for obtaining minimum and maximum values respectively.</li>
	<li>The resulting number after remapping can contain leading zeroes.</li>
	<li>We mentioned "Danny Mittal" to congratulate him on being in the top 10 in Weekly Contest 326.</li>
</ul>
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> num = 11891
<strong>Output:</strong> 99009
<strong>Explanation:</strong> 
To achieve the maximum value, Danny can remap the digit 1 to the digit 9 to yield 99899.
To achieve the minimum value, Danny can remap the digit 1 to the digit 0, yielding 890.
The difference between these two numbers is 99009.
</pre>
<p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> num = 90
<strong>Output:</strong> 99
<strong>Explanation:</strong>
The maximum value that can be returned by the function is 99 (if 0 is replaced by 9) and the minimum value that can be returned by the function is 0 (if 9 is replaced by 0).
Thus, we return 99.</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= num &lt;= 10<sup>8</sup></code></li>
</ul>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-difference-by-remapping-a-digit
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int minMaxDifference(int n) {
        auto s = to_string(n);
        char p = 0, q = s[0];
        string mx, mn;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '9') mx += s[i];
            else if (p == 0) {
                p = s[i];
                mx += '9';
            } else if (p == s[i]) mx += '9';
            else mx += s[i];
            if (s[i] == q) mn += '0';
            else mn += s[i];
        }
        return stoi(mx) - stoi(mn);
    }
};
```