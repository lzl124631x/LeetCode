# [2496. Maximum Value of a String in an Array (Easy)](https://leetcode.com/problems/maximum-value-of-a-string-in-an-array)

<p>The <strong>value</strong> of an alphanumeric string can be defined as:</p>
<ul>
	<li>The <strong>numeric</strong> representation of the string in base <code>10</code>, if it comprises of digits <strong>only</strong>.</li>
	<li>The <strong>length</strong> of the string, otherwise.</li>
</ul>
<p>Given an array <code>strs</code> of alphanumeric strings, return <em>the <strong>maximum value</strong> of any string in </em><code>strs</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> strs = ["alic3","bob","3","4","00000"]
<strong>Output:</strong> 5
<strong>Explanation:</strong> 
- "alic3" consists of both letters and digits, so its value is its length, i.e. 5.
- "bob" consists only of letters, so its value is also its length, i.e. 3.
- "3" consists only of digits, so its value is its numeric equivalent, i.e. 3.
- "4" also consists only of digits, so its value is 4.
- "00000" consists only of digits, so its value is 0.
Hence, the maximum value is 5, of "alic3".
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> strs = ["1","01","001","0001"]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
Each string in the array has value 1. Hence, we return 1.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= strs.length &lt;= 100</code></li>
	<li><code>1 &lt;= strs[i].length &lt;= 9</code></li>
	<li><code>strs[i]</code> consists of only lowercase English letters and digits.</li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Maximum Subarray (Medium)](https://leetcode.com/problems/maximum-subarray/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-value-of-a-string-in-an-array
// Author: github.com/lzl124631x
// Time: O(NS)
// Space: O(1)
class Solution {
public:
    int maximumValue(vector<string>& A) {
        int ans = 0;
        for (auto &s : A) {
            int i = 0, num = 0;
            for (; i < s.size() && isdigit(s[i]); ++i) num = num * 10 + s[i] - '0';
            ans = max(ans, i == s.size() ? num : (int)s.size());
        }
        return ans;
    }
};
```