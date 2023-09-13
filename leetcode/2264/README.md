# [2264. Largest 3-Same-Digit Number in String (Easy)](https://leetcode.com/problems/largest-3-same-digit-number-in-string)

<p>You are given a string <code>num</code> representing a large integer. An integer is <strong>good</strong> if it meets the following conditions:</p>

<ul>
	<li>It is a <strong>substring</strong> of <code>num</code> with length <code>3</code>.</li>
	<li>It consists of only one unique digit.</li>
</ul>

<p>Return <em>the <strong>maximum good </strong>integer as a <strong>string</strong> or an empty string </em><code>""</code><em> if no such integer exists</em>.</p>

<p>Note:</p>

<ul>
	<li>A <strong>substring</strong> is a contiguous sequence of characters within a string.</li>
	<li>There may be <strong>leading zeroes</strong> in <code>num</code> or a good integer.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> num = "6<strong><u>777</u></strong>133339"
<strong>Output:</strong> "777"
<strong>Explanation:</strong> There are two distinct good integers: "777" and "333".
"777" is the largest, so we return "777".
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> num = "23<strong><u>000</u></strong>19"
<strong>Output:</strong> "000"
<strong>Explanation:</strong> "000" is the only good integer.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> num = "42352338"
<strong>Output:</strong> ""
<strong>Explanation:</strong> No substring of length 3 consists of only one unique digit. Therefore, there are no good integers.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= num.length &lt;= 1000</code></li>
	<li><code>num</code> only consists of digits.</li>
</ul>


**Companies**:
[opentext](https://leetcode.com/company/opentext), [PayPay](https://leetcode.com/company/paypay)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Largest Odd Number in String (Easy)](https://leetcode.com/problems/largest-odd-number-in-string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/largest-3-same-digit-number-in-string
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string largestGoodInteger(string s) {
        char c = 0;
        for (int i = 2; i < s.size(); ++i) {
            if (s[i] == s[i - 1] && s[i] == s[i - 2]) c = max(c, s[i]);
        }
        return c ? string(3, c) : "";
    }
};
```