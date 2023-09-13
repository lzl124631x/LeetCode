# [1209. Remove All Adjacent Duplicates in String II (Medium)](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/)

<p>You are given a string <code>s</code> and an integer <code>k</code>, a <code>k</code> <strong>duplicate removal</strong> consists of choosing <code>k</code> adjacent and equal letters from <code>s</code> and removing them, causing the left and the right side of the deleted substring to concatenate together.</p>

<p>We repeatedly make <code>k</code> <strong>duplicate removals</strong> on <code>s</code> until we no longer can.</p>

<p>Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abcd", k = 2
<strong>Output:</strong> "abcd"
<strong>Explanation: </strong>There's nothing to delete.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "deeedbbcccbdaa", k = 3
<strong>Output:</strong> "aa"
<strong>Explanation: 
</strong>First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "pbbcggttciiippooaais", k = 2
<strong>Output:</strong> "ps"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>2 &lt;= k &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> only contains lower case English letters.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/)

**Similar Questions**:
* [Remove All Adjacent Duplicates In String (Easy)](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)
* [Replace Non-Coprime Numbers in Array (Hard)](https://leetcode.com/problems/replace-non-coprime-numbers-in-array/)

## Solution 1. Stack

```cpp
// OJ: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> st;
        for (char c : s) {
            if (st.empty() || st.back().first != c) st.emplace_back(c, 1);
            else if (++st.back().second == k) st.pop_back();
        }
        string ans;
        for (auto &[c, cnt] : st) {
            while (cnt--) ans += c;
        }
        return ans;
    }
};
```