# [504. Base 7 (Easy)](https://leetcode.com/problems/base-7/)

<p>Given an integer <code>num</code>, return <em>a string of its <strong>base 7</strong> representation</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> num = 100
<strong>Output:</strong> "202"
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> num = -7
<strong>Output:</strong> "-10"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-10<sup>7</sup> &lt;= num &lt;= 10<sup>7</sup></code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/base-7/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(logN)
class Solution {
public:
    string convertToBase7(int n) {
        if (n == 0) return "0";
        string ans;
        bool neg = false;
        if (n < 0) n = -n, neg = true;
        while (n) {
            ans += '0' + n % 7;
            n /= 7;
        }
        if (neg) ans += '-';
        reverse(begin(ans), end(ans));
        return ans;
    }
};
```