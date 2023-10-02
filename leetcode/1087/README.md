# [1087. Brace Expansion (Medium)](https://leetcode.com/problems/brace-expansion/)

<p>You are given a string <code>s</code> representing a list of words. Each letter in the word has one or more options.</p>

<ul>
	<li>If there is one option, the letter is represented as is.</li>
	<li>If there is more than one option, then curly braces delimit the options. For example, <code>"{a,b,c}"</code> represents options <code>["a", "b", "c"]</code>.</li>
</ul>

<p>For example, if <code>s = "a{b,c}"</code>, the first character is always <code>'a'</code>, but the second character can be <code>'b'</code> or <code>'c'</code>. The original list is <code>["ab", "ac"]</code>.</p>

<p>Return all words that can be formed in this manner, <strong>sorted</strong> in lexicographical order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> s = "{a,b}c{d,e}f"
<strong>Output:</strong> ["acdf","acef","bcdf","bcef"]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> s = "abcd"
<strong>Output:</strong> ["abcd"]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 50</code></li>
	<li><code>s</code> consists of curly brackets <code>'{}'</code>, commas&nbsp;<code>','</code>, and lowercase English letters.</li>
	<li><code>s</code> is guaranteed to be a valid input.</li>
	<li>There are no nested curly brackets.</li>
	<li>All characters inside a pair of consecutive opening and ending curly brackets are different.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Backtracking](https://leetcode.com/tag/backtracking/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Decode String (Medium)](https://leetcode.com/problems/decode-string/)
* [Letter Case Permutation (Medium)](https://leetcode.com/problems/letter-case-permutation/)
* [Brace Expansion II (Hard)](https://leetcode.com/problems/brace-expansion-ii/)

## Solution 1. Backtracking

```cpp
// OJ: https://leetcode.com/problems/brace-expansion/
// Author: github.com/lzl124631x
// Time: O(NK) where K is the total number of possible branches
// Space: O(N)
class Solution {
public:
    vector<string> expand(string s) {
        vector<vector<char>> v;
        for (int i = 0, N = s.size(); i < N; ++i) {
            if (s[i] == '{') {
                ++i;
                v.emplace_back();
                while (s[i] != '}') {
                    v.back().push_back(s[i++]);
                    if (s[i] == ',') ++i;
                }
                sort(begin(v.back()), end(v.back()));
            } else v.push_back({ s[i] });
        }
        vector<string> ans;
        string tmp;
        function<void(int)> dfs = [&](int i) {
            if (i == v.size()) {
                ans.push_back(tmp);
                return;
            }
            for (int j = 0; j < v[i].size(); ++j) {
                tmp += v[i][j];
                dfs(i + 1);
                tmp.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};
```