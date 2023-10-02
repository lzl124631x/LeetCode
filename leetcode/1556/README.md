# [1556. Thousand Separator (Easy)](https://leetcode.com/problems/thousand-separator/)

<p>Given an&nbsp;integer <code>n</code>, add a dot (".")&nbsp;as the thousands separator and return it in&nbsp;string format.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 987
<strong>Output:</strong> "987"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 1234
<strong>Output:</strong> "1.234"
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 123456789
<strong>Output:</strong> "123.456.789"
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> n = 0
<strong>Output:</strong> "0"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= n &lt; 2^31</code></li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/thousand-separator/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string thousandSeparator(int n) {
        if (n == 0) return "0";
        int d = 0;
        string ans;
        while (n) {
            ans += '0' + n % 10;
            n /= 10;
            if (++d % 3 == 0 && n) ans += '.';
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
```