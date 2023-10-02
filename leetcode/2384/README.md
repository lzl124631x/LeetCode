# [2384. Largest Palindromic Number (Medium)](https://leetcode.com/problems/largest-palindromic-number)

<p>You are given a string <code>num</code> consisting of digits only.</p>
<p>Return <em>the <strong>largest palindromic</strong> integer (in the form of a string) that can be formed using digits taken from </em><code>num</code>. It should not contain <strong>leading zeroes</strong>.</p>
<p><strong>Notes:</strong></p>
<ul>
	<li>You do <strong>not</strong> need to use all the digits of <code>num</code>, but you must use <strong>at least</strong> one digit.</li>
	<li>The digits can be reordered.</li>
</ul>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> num = "444947137"
<strong>Output:</strong> "7449447"
<strong>Explanation:</strong> 
Use the digits "4449477" from "<u><strong>44494</strong></u><u><strong>7</strong></u>13<u><strong>7</strong></u>" to form the palindromic integer "7449447".
It can be shown that "7449447" is the largest palindromic integer that can be formed.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> num = "00009"
<strong>Output:</strong> "9"
<strong>Explanation:</strong> 
It can be shown that "9" is the largest palindromic integer that can be formed.
Note that the integer returned should not contain leading zeroes.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= num.length &lt;= 10<sup>5</sup></code></li>
	<li><code>num</code> consists of digits.</li>
</ul>

**Companies**:
[Adobe](https://leetcode.com/company/adobe), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Longest Palindrome (Easy)](https://leetcode.com/problems/longest-palindrome/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/largest-palindromic-number
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string largestPalindromic(string s) {
        int cnt[10] = {};
        for (char c : s) cnt[c - '0']++;
        string ans;
        for (int i = 9; i >= 0; --i) {
            int c = cnt[i] / 2;
            if (i > 0 || ans.size()) { // avoid adding leading zeros
                while (c-- > 0) ans += '0' + i;
                cnt[i] %= 2;
            }
        }
        int m = 9;
        while (m >= 0 && cnt[m] == 0) --m;
        return ans + (m >= 0 ? string(1, '0' + m) : "") + string(rbegin(ans), rend(ans));
    }
};
```