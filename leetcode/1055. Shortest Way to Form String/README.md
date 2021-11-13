# [1055. Shortest Way to Form String (Medium)](https://leetcode.com/problems/shortest-way-to-form-string/)

<p>A <strong>subsequence</strong> of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., <code>"ace"</code> is a subsequence of <code>"<u>a</u>b<u>c</u>d<u>e</u>"</code> while <code>"aec"</code> is not).</p>

<p>Given two strings <code>source</code> and <code>target</code>, return <em>the minimum number of <strong>subsequences</strong> of </em><code>source</code><em> such that their concatenation equals </em><code>target</code>. If the task is impossible, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> source = "abc", target = "abcbc"
<strong>Output:</strong> 2
<strong>Explanation:</strong> The target "abcbc" can be formed by "abc" and "bc", which are subsequences of source "abc".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> source = "abc", target = "acdbc"
<strong>Output:</strong> -1
<strong>Explanation:</strong> The target string cannot be constructed from the subsequences of source string due to the character "d" in target string.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> source = "xyz", target = "xzyxz"
<strong>Output:</strong> 3
<strong>Explanation:</strong> The target string can be constructed as follows "xz" + "y" + "xz".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= source.length, target.length &lt;= 1000</code></li>
	<li><code>source</code> and <code>target</code> consist of lowercase English letters.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Is Subsequence (Easy)](https://leetcode.com/problems/is-subsequence/)
* [Number of Matching Subsequences (Medium)](https://leetcode.com/problems/number-of-matching-subsequences/)

## Solution 1. Greedy

```cpp
// OJ: https://leetcode.com/problems/shortest-way-to-form-string/
// Author: github.com/lzl124631x
// Time: O(CS + T) where `C = 26` is the size of character set, and `S`/`T` is the length of `source`/`target`
// Space: O(CS)
class Solution {
public:
    int shortestWay(string source, string target) {
        int N = source.size(), M = target.size(), next[1001][26] = {};
        for (int i = 0; i < 26; ++i) {
            for (int j = N - 1, index = -1; j >= -1; --j) {
                next[j + 1][i] = index;
                if (j >= 0 && source[j] == 'a' + i) index = j + 1;
            }
        }
        int ans = 1, cur = 0;
        for (int i = 0; i < M; ++i) {
            int c = target[i] - 'a';
            if (next[0][c] == -1) return -1; // `c` doesn't exist in `source`
            if (next[cur][c] == -1) { // don't have match in this round, add a new round.
                cur = 0;
                ++ans;
            }
            cur = next[cur][c];
        }
        return ans;
    }
};
```

## Solution 2. Binary Search

```cpp
// OJ: https://leetcode.com/problems/shortest-way-to-form-string/
// Author: github.com/lzl124631x
// Time: O(S + TlogS) where `S`/`T` is the length of `source`/`target`
// Space: O(S)
class Solution {
public:
    int shortestWay(string source, string target) {
        int ans = 1, cur = -1;
        unordered_map<char, vector<int>> m; // character -> an array of indices of this character in `source`
        for (int i = 0; i < source.size(); ++i) m[source[i]].push_back(i);
        for (char c : target) {
            if (m.count(c) == 0) return -1; // `c` doesn't exist in `source`
            auto it = upper_bound(begin(m[c]), end(m[c]), cur); // the next index must be greater than the current one.
            if (it == end(m[c])) { // don't have match in this round, add a new round. 
                cur = m[c][0];
                ++ans;
            } else cur = *it;
        }
        return ans;
    }
};
```