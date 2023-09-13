# [1585. Check If String Is Transformable With Substring Sort Operations (Hard)](https://leetcode.com/problems/check-if-string-is-transformable-with-substring-sort-operations/)

<p>Given two strings&nbsp;<code>s</code> and <code>t</code>, you want to transform string&nbsp;<code>s</code> into string&nbsp;<code>t</code> using the following&nbsp;operation any number of times:</p>

<ul>
	<li>Choose a <strong>non-empty</strong> substring in&nbsp;<code>s</code>&nbsp;and sort it in-place&nbsp;so the characters are in&nbsp;<strong>ascending order</strong>.</li>
</ul>

<p>For example, applying the operation on the underlined substring in&nbsp;<code>"1<u>4234</u>"</code>&nbsp;results in <code>"1<u>2344</u>"</code>.</p>

<p>Return <code>true</code> if <em>it is possible to transform string <code>s</code>&nbsp;into string <code>t</code></em>. Otherwise,&nbsp;return <code>false</code>.</p>

<p>A <strong>substring</strong>&nbsp;is a contiguous sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "84532", t = "34852"
<strong>Output:</strong> true
<strong>Explanation:</strong> You can transform s into t using the following sort operations:
"84<u>53</u>2" (from index 2 to 3) -&gt; "84<u>35</u>2"
"<u>843</u>52" (from index 0 to 2) -&gt; "<u>348</u>52"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "34521", t = "23415"
<strong>Output:</strong> true
<strong>Explanation:</strong> You can transform s into t using the following sort operations:
"<u>3452</u>1" -&gt; "<u>2345</u>1"
"234<u>51</u>" -&gt; "234<u>15</u>"
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "12345", t = "12435"
<strong>Output:</strong> false
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "1", t = "2"
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>s.length == t.length</code></li>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> and <code>t</code>&nbsp;only contain digits from <code>'0'</code> to <code>'9'</code>.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. Greedy

```cpp
// OJ: https://leetcode.com/problems/check-if-string-is-transformable-with-substring-sort-operations/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://youtu.be/Pkd3FampKBk
class Solution {
public:
    bool isTransformable(string s, string t) {
        queue<int> q[10];
        for (int i = 0; i < s.size(); ++i) q[s[i] - '0'].push(i);
        for (int i = 0; i < t.size(); ++i) {
            int d = t[i] - '0';
            if (q[d].empty()) return false;
            for (int j = 0; j < d; ++j) {
                if (q[j].size() && q[j].front() < q[d].front()) return false;
            }
            q[d].pop();
        }
        return true;
    }
};
```