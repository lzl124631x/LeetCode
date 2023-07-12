# [2645. Minimum Additions to Make Valid String (Medium)](https://leetcode.com/problems/minimum-additions-to-make-valid-string)

<p>Given a string <code>word</code> to which you can insert letters "a", "b" or "c" anywhere and any number of times, return <em>the minimum number of letters that must be inserted so that <code>word</code> becomes <strong>valid</strong>.</em></p>
<p>A string is called <strong>valid </strong>if it can be formed by concatenating the string "abc" several times.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> word = "b"
<strong>Output:</strong> 2
<strong>Explanation:</strong> Insert the letter "a" right before "b", and the letter "c" right next to "a" to obtain the valid string "<strong>a</strong>b<strong>c</strong>".
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> word = "aaa"
<strong>Output:</strong> 6
<strong>Explanation:</strong> Insert letters "b" and "c" next to each "a" to obtain the valid string "a<strong>bc</strong>a<strong>bc</strong>a<strong>bc</strong>".
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> word = "abc"
<strong>Output:</strong> 0
<strong>Explanation:</strong> word is already valid. No modifications are needed. 
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= word.length &lt;= 50</code></li>
	<li><code>word</code> consists of letters "a", "b"&nbsp;and "c" only.&nbsp;</li>
</ul>

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Stack](https://leetcode.com/tag/stack/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Merge Strings Alternately (Easy)](https://leetcode.com/problems/merge-strings-alternately/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-additions-to-make-valid-string
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int addMinimum(string s) {
        int i = 0, N = s.size(), ans = 0;
        while (i < N) {
            int start = i++;
            while (i < N && s[i] > s[i - 1]) ++i;
            ans += 3 - i + start;
        }
        return ans;
    }
};
```