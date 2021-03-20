# [1796. Second Largest Digit in a String (Easy)](https://leetcode.com/problems/second-largest-digit-in-a-string)

<p>Given an alphanumeric string <code>s</code>, return <em>the <strong>second largest</strong> numerical digit that appears in </em><code>s</code><em>, or </em><code>-1</code><em> if it does not exist</em>.</p>

<p>An <strong>alphanumeric</strong><strong> </strong>string is a string consisting of lowercase English letters and digits.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "dfa12321afd"
<strong>Output:</strong> 2
<strong>Explanation:</strong> The digits that appear in s are [1, 2, 3]. The second largest digit is 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abc1111"
<strong>Output:</strong> -1
<strong>Explanation:</strong> The digits that appear in s are [1]. There is no second largest digit. 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code> consists of only lowercase English letters and/or digits.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/second-largest-digit-in-a-string
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int secondHighest(string s) {
        set<int> st;
        for (char c : s) {
            if (isdigit(c)) st.insert(c - '0');
        }
        if (st.size() < 2) return -1;
        return *next(st.rbegin());
    }
};
```