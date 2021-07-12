# [273. Integer to English Words (Hard)](https://leetcode.com/problems/integer-to-english-words/)

<p>Convert a non-negative integer <code>num</code> to its English words representation.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> num = 123
<strong>Output:</strong> "One Hundred Twenty Three"
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> num = 12345
<strong>Output:</strong> "Twelve Thousand Three Hundred Forty Five"
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> num = 1234567
<strong>Output:</strong> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
</pre><p><strong>Example 4:</strong></p>
<pre><strong>Input:</strong> num = 1234567891
<strong>Output:</strong> "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= num &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft), [Adobe](https://leetcode.com/company/adobe), [Square](https://leetcode.com/company/square), [Google](https://leetcode.com/company/google), [LinkedIn](https://leetcode.com/company/linkedin), [Walmart Labs](https://leetcode.com/company/walmart-labs)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/), [Recursion](https://leetcode.com/tag/recursion/)

**Similar Questions**:
* [Integer to Roman (Medium)](https://leetcode.com/problems/integer-to-roman/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/integer-to-english-words/
// Author: github.com/lzl124631x
// Time: O(lgN)
// Space: O(lgN)
class Solution {
    const string one[9] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    const string teen[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const string ty[10] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    const string segments[3] = {"Thousand", "Million", "Billion"};
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        vector<string> ans;
        int segIndex = -1;
        for (; num; num /= 1000) {
            int digits[3] = {}, segment = num % 1000;
            if (segIndex > -1 && segment) ans.push_back(segments[segIndex]);
            ++segIndex;
            for (int i = 0; i < 3 && segment; ++i) {
                digits[i] = segment % 10;
                segment /= 10;
            }
            if (digits[1] != 1 && digits[0]) ans.push_back(one[digits[0] - 1]);
            if (digits[1] == 1) {
                ans.push_back(teen[digits[0]]);
            } else if (digits[1] > 1) {
                ans.push_back(ty[digits[1] - 2]);
            }
            if (digits[2]) {
                ans.push_back("Hundred");
                ans.push_back(one[digits[2] - 1]);
            }
        }
        string merged;
        for (int i = ans.size() - 1; i >= 0; --i) {
            if (merged.size()) merged += " ";
            merged += ans[i];
        }
        return merged;
    }
};
```