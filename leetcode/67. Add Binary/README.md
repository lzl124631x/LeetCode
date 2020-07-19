# [67. Add Binary (Easy)](https://leetcode.com/problems/add-binary/)

<p>Given two binary strings, return their sum (also a binary string).</p>

<p>The input strings are both <strong>non-empty</strong> and contains only characters <code>1</code> or&nbsp;<code>0</code>.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> a = "11", b = "1"
<strong>Output:</strong> "100"</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> a = "1010", b = "1011"
<strong>Output:</strong> "10101"</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>Each string consists only of <code>'0'</code> or <code>'1'</code> characters.</li>
	<li><code>1 &lt;= a.length, b.length &lt;= 10^4</code></li>
	<li>Each string is either <code>"0"</code> or doesn't contain any leading zero.</li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Add Two Numbers (Medium)](https://leetcode.com/problems/add-two-numbers/)
* [Multiply Strings (Medium)](https://leetcode.com/problems/multiply-strings/)
* [Plus One (Easy)](https://leetcode.com/problems/plus-one/)
* [Add to Array-Form of Integer (Easy)](https://leetcode.com/problems/add-to-array-form-of-integer/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/add-binary/
// Author: github.com/lzl124631x
// Time: O(A+B)
// Space: O(1)
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        string ans;
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) carry += a[i--] - '0';
            if (j >= 0) carry += b[j--] - '0';
            ans += '0' + (carry & 1);
            carry >>= 1;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
```