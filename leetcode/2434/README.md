# [2434. Using a Robot to Print the Lexicographically Smallest String (Medium)](https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string)

<p>You are given a string <code>s</code> and a robot that currently holds an empty string <code>t</code>. Apply one of the following operations until <code>s</code> and <code>t</code> <strong>are both empty</strong>:</p>
<ul>
	<li>Remove the <strong>first</strong> character of a string <code>s</code> and give it to the robot. The robot will append this character to the string <code>t</code>.</li>
	<li>Remove the <strong>last</strong> character of a string <code>t</code> and give it to the robot. The robot will write this character on paper.</li>
</ul>
<p>Return <em>the lexicographically smallest string that can be written on the paper.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "zza"
<strong>Output:</strong> "azz"
<strong>Explanation:</strong> Let p denote the written string.
Initially p="", s="zza", t="".
Perform first operation three times p="", s="", t="zza".
Perform second operation three times p="azz", s="", t="".
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "bac"
<strong>Output:</strong> "abc"
<strong>Explanation:</strong> Let p denote the written string.
Perform first operation twice p="", s="c", t="ba". 
Perform second operation twice p="ab", s="c", t="". 
Perform first operation p="ab", s="", t="c". 
Perform second operation p="abc", s="", t="".
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> s = "bdda"
<strong>Output:</strong> "addb"
<strong>Explanation:</strong> Let p denote the written string.
Initially p="", s="bdda", t="".
Perform first operation four times p="", s="", t="bdda".
Perform second operation four times p="addb", s="", t="".
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of only English lowercase letters.</li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Find Permutation (Medium)](https://leetcode.com/problems/find-permutation/)

## Solution 1. Greedy + Stack

After we move a letter from `s` to `t`, we determine if we should write it. We write the back of `t` on paper only if there are no smaller letter in the remaining `s`.

```cpp
// OJ: https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string robotWithString(string s) {
        int N = s.size();
        vector<char> mn(N + 1, 'z');
        for (int i = N - 1; i >= 0; --i) {
            mn[i] = min(mn[i + 1], s[i]);
        }
        stack<char> st;
        string ans;
        for (int i = 0; i < N; ++i) {
            st.push(s[i]);
            while (st.size() && st.top() <= mn[i + 1]) {
                ans.push_back(st.top());
                st.pop();
            }
        }
        while (st.size()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
```