# [1447. Simplified Fractions (Medium)](https://leetcode.com/problems/simplified-fractions/)

<p>Given an integer <code>n</code>, return a list of all <strong>simplified</strong> fractions between 0 and 1 (exclusive) such that the denominator is less-than-or-equal-to <code>n</code>. The fractions can be in <strong>any</strong> order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> ["1/2"]
<strong>Explanation: </strong>"1/2" is the only unique fraction with a denominator less-than-or-equal-to 2.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 3
<strong>Output:</strong> ["1/2","1/3","2/3"]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 4
<strong>Output:</strong> ["1/2","1/3","1/4","2/3","3/4"]
<strong>Explanation: </strong>"2/4" is not a simplified fraction because it can be simplified to "1/2".</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
</ul>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/simplified-fractions/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                if (gcd(i, j) != 1) continue;
                ans.push_back(to_string(j) + "/" + to_string(i));
            }
        }
        return ans;
    }
};
```