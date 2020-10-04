# [6. ZigZag Conversion (Medium)](https://leetcode.com/problems/zigzag-conversion/)

<p>The string <code>"PAYPALISHIRING"</code> is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)</p>

<pre>P   A   H   N
A P L S I I G
Y   I   R
</pre>

<p>And then read line by line: <code>"PAHNAPLSIIGYIR"</code></p>

<p>Write the code that will take a string and make this conversion given a number of rows:</p>

<pre>string convert(string s, int numRows);</pre>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "PAYPALISHIRING", numRows = 3
<strong>Output:</strong> "PAHNAPLSIIGYIR"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "PAYPALISHIRING", numRows =&nbsp;4
<strong>Output:</strong>&nbsp;"PINALSIGYAHRPI"
<strong>Explanation:</strong>

P     I    N
A   L S  I G
Y A   H R
P     I</pre>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/zigzag-conversion/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int N = s.size(), d = (numRows - 1) * 2;
        string ans;
        for (int i = 0; i < numRows; ++i) {
            int w = 2 * i; 
            for (int j = i; j < N;) {
                ans += s[j];
                w = d - w;
                if (!w) w = d;
                j += w;
            }
        }
        return ans;
    }
};
```