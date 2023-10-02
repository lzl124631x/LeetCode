# [2710. Remove Trailing Zeros From a String (Easy)](https://leetcode.com/problems/remove-trailing-zeros-from-a-string)

<p>Given a <strong>positive</strong> integer <code>num</code> represented as a string, return <em>the integer </em><code>num</code><em> without trailing zeros as a string</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> num = "51230100"
<strong>Output:</strong> "512301"
<strong>Explanation:</strong> Integer "51230100" has 2 trailing zeros, we remove them and return integer "512301".
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> num = "123"
<strong>Output:</strong> "123"
<strong>Explanation:</strong> Integer "123" has no trailing zeros, we return integer "123".
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= num.length &lt;= 1000</code></li>
	<li><code>num</code> consists&nbsp;of only digits.</li>
	<li><code>num</code> doesn't&nbsp;have any leading zeros.</li>
</ul>

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/remove-trailing-zeros-from-a-string
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string removeTrailingZeros(string s) {
        while (s.back() == '0') s.pop_back();
        return s;
    }
};
```