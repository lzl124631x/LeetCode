# [2283. Check if Number Has Equal Digit Count and Digit Value (Easy)](https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value)

<p>You are given a <strong>0-indexed</strong> string <code>num</code> of length <code>n</code> consisting of digits.</p>
<p>Return <code>true</code> <em>if for <strong>every</strong> index </em><code>i</code><em> in the range </em><code>0 &lt;= i &lt; n</code><em>, the digit </em><code>i</code><em> occurs </em><code>num[i]</code><em> times in </em><code>num</code><em>, otherwise return </em><code>false</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> num = "1210"
<strong>Output:</strong> true
<strong>Explanation:</strong>
num[0] = '1'. The digit 0 occurs once in num.
num[1] = '2'. The digit 1 occurs twice in num.
num[2] = '1'. The digit 2 occurs once in num.
num[3] = '0'. The digit 3 occurs zero times in num.
The condition holds true for every index in "1210", so return true.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> num = "030"
<strong>Output:</strong> false
<strong>Explanation:</strong>
num[0] = '0'. The digit 0 should occur zero times, but actually occurs twice in num.
num[1] = '3'. The digit 1 should occur three times, but actually occurs zero times in num.
num[2] = '0'. The digit 2 occurs zero times in num.
The indices 0 and 1 both violate the condition, so return false.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>n == num.length</code></li>
	<li><code>1 &lt;= n &lt;= 10</code></li>
	<li><code>num</code> consists of digits.</li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google), [JPMorgan](https://leetcode.com/company/jpmorgan)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Counting](https://leetcode.com/tag/counting/)

**Similar Questions**:
* [Self Dividing Numbers (Easy)](https://leetcode.com/problems/self-dividing-numbers/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool digitCount(string s) {
        int cnt[10] = {};
        for (int i = 0; i < s.size(); ++i) cnt[s[i] - '0']++;
        for (int i = 0; i < s.size(); ++i) {
            if (cnt[i] != s[i] - '0') return false;
        }
        return true;
    }
};
```