# [168. Excel Sheet Column Title (Easy)](https://leetcode.com/problems/excel-sheet-column-title)

<p>Given an integer <code>columnNumber</code>, return <em>its corresponding column title as it appears in an Excel sheet</em>.</p>
<p>For example:</p>
<pre>A -&gt; 1
B -&gt; 2
C -&gt; 3
...
Z -&gt; 26
AA -&gt; 27
AB -&gt; 28 
...
</pre>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> columnNumber = 1
<strong>Output:</strong> "A"
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> columnNumber = 28
<strong>Output:</strong> "AB"
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> columnNumber = 701
<strong>Output:</strong> "ZY"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= columnNumber &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

**Companies**:
[Microsoft](https://leetcode.com/company/microsoft), [Apple](https://leetcode.com/company/apple), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Excel Sheet Column Number (Easy)](https://leetcode.com/problems/excel-sheet-column-number/)
* [Cells in a Range on an Excel Sheet (Easy)](https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/excel-sheet-column-title
// Author: github.com/lzl124631x
// Time: O(log_26^N)
// Space: O(1) extra space
class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while (n) {
            n--;
            ans += 'A' + n % 26;
            n /= 26;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
```