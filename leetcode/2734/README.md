# [2734. Lexicographically Smallest String After Substring Operation (Medium)](https://leetcode.com/problems/lexicographically-smallest-string-after-substring-operation)

<p>You are given a string <code>s</code> consisting of only lowercase English letters. In one operation, you can do the following:</p>
<ul>
	<li>Select any non-empty substring of <code>s</code>, possibly the entire string, then replace each one of its characters with the previous character of the English alphabet. For example, 'b' is converted to 'a', and 'a' is converted to 'z'.</li>
</ul>
<p>Return <em>the <strong>lexicographically smallest</strong> string you can obtain after performing the above operation <strong>exactly once</strong>.</em></p>
<p>A <strong>substring</strong> is a contiguous sequence of characters in a string.</p>
<code>x</code>
<strong>lexicographically smaller</strong>
<code>y</code>
<code>x[i]</code>
<code>y[i]</code>
<code>i</code>
<code>x[i] != y[i]</code>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "cbabc"
<strong>Output:</strong> "baabc"
<strong>Explanation:</strong> We apply the operation on the substring starting at index 0, and ending at index 1 inclusive. 
It can be proven that the resulting string is the lexicographically smallest. 
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "acbbc"
<strong>Output:</strong> "abaab"
<strong>Explanation:</strong> We apply the operation on the substring starting at index 1, and ending at index 4 inclusive. 
It can be proven that the resulting string is the lexicographically smallest. 
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> s = "leetcode"
<strong>Output:</strong> "kddsbncd"
<strong>Explanation:</strong> We apply the operation on the entire string. 
It can be proven that the resulting string is the lexicographically smallest. 
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 3 * 10<sup>5</sup></code></li>
	<li><code>s</code> consists of lowercase English letters</li>
</ul>

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Shifting Letters (Medium)](https://leetcode.com/problems/shifting-letters/)
* [Lexicographically Smallest String After Applying Operations (Medium)](https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/)

## Solution 1. Greedy

```cpp
// OJ: https://leetcode.com/problems/lexicographically-smallest-string-after-substring-operation
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string smallestString(string s) {
        int i = 0, N = s.size();
        while (i < N && s[i] == 'a') ++i;
        if (i == N) {
            s.back() = 'z';
        } else {
            while (i < N && s[i] != 'a') s[i++]--;
        }
        return s;
    }
};
```