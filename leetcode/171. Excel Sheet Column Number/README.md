# [171. Excel Sheet Column Number (Easy)](https://leetcode.com/problems/excel-sheet-column-number/)

<p>Given a column title as appear in an Excel sheet, return its corresponding column number.</p>

<p>For example:</p>

<pre>    A -&gt; 1
    B -&gt; 2
    C -&gt; 3
    ...
    Z -&gt; 26
    AA -&gt; 27
    AB -&gt; 28 
    ...
</pre>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> "A"
<strong>Output:</strong> 1
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>"AB"
<strong>Output:</strong> 28
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>"ZY"
<strong>Output:</strong> 701
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 7</code></li>
	<li><code>s</code> consists only of uppercase English letters.</li>
	<li><code>s</code> is between "A" and "FXSHRXW".</li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Excel Sheet Column Title (Easy)](https://leetcode.com/problems/excel-sheet-column-title/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/excel-sheet-column-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for (char c : s) ans = ans * 26 + (c - 'A' + 1);
        return ans;
    }
};
```