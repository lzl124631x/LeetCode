# [1256. Encode Number (Medium)](https://leetcode.com/problems/encode-number/)

<p>Given a non-negative integer <code>num</code>, Return its <em>encoding</em> string.</p>

<p>The encoding is done by converting the integer to a string using a secret function that you should deduce from the following table:</p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/06/21/encode_number.png" style="width: 164px; height: 360px;"></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> num = 23
<strong>Output:</strong> "1000"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> num = 107
<strong>Output:</strong> "101100"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= num &lt;= 10^9</code></li>
</ul>

**Companies**:  
[Quora](https://leetcode.com/company/quora)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [Convert to Base -2 (Medium)](https://leetcode.com/problems/convert-to-base-2/)

## Solution 1.

The answer is the binary representation of `n + 1` truncating to the least `floor(log(n + 1))` significant digits.

```cpp
// OJ: https://leetcode.com/problems/encode-number/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(logN)
class Solution {
public:
    string encode(int n) {
        ++n;
        string ans;
        int len = log(n);
        while (n) {
            ans += '0' + (n & 1);
            n >>= 1;
        }
        if (ans.size() > len) ans.pop_back();
        return string(rbegin(ans), rend(ans));
    }
};
```