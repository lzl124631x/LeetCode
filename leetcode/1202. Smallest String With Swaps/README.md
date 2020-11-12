# [1202. Smallest String With Swaps (Medium)](https://leetcode.com/problems/smallest-string-with-swaps/)

<p>You are given a string <code>s</code>, and an array of pairs of indices in the string&nbsp;<code>pairs</code>&nbsp;where&nbsp;<code>pairs[i] =&nbsp;[a, b]</code>&nbsp;indicates 2 indices(0-indexed) of the string.</p>

<p>You can&nbsp;swap the characters at any pair of indices in the given&nbsp;<code>pairs</code>&nbsp;<strong>any number of times</strong>.</p>

<p>Return the&nbsp;lexicographically smallest string that <code>s</code>&nbsp;can be changed to after using the swaps.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "dcab", pairs = [[0,3],[1,2]]
<strong>Output:</strong> "bacd"
<strong>Explaination:</strong> 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "dcab", pairs = [[0,3],[1,2],[0,2]]
<strong>Output:</strong> "abcd"
<strong>Explaination: </strong>
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "cba", pairs = [[0,1],[1,2]]
<strong>Output:</strong> "abc"
<strong>Explaination: </strong>
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= pairs.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= pairs[i][0], pairs[i][1] &lt;&nbsp;s.length</code></li>
	<li><code>s</code>&nbsp;only contains lower case English letters.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Union Find](https://leetcode.com/tag/union-find/)

## Solution 1. Union Find

```cpp
// OJ: https://leetcode.com/problems/smallest-string-with-swaps/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
    vector<int> id;
    int find(int x) {
        return id[x] == x ? x : (id[x] = find(id[x]));
    }
    void connect(int x, int y) {
        int p = find(x), q = find(y);
        id[p] = q;
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& A) {
        int N = s.size();
        id.assign(N, 0);
        iota(begin(id), end(id), 0);
        for (auto &p : A) connect(p[0], p[1]);
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < N; ++i) m[find(i)].push_back(i);
        for (auto &[k, v] : m) sort(begin(v), end(v), [&](int a, int b) { return s[a] > s[b]; });
        string ans;
        for (int i = 0; i < N; ++i) {
            ans += s[m[find(i)].back()];
            m[find(i)].pop_back();
        }
        return ans;
    }
};
```