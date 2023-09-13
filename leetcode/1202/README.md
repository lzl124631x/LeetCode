# [1202. Smallest String With Swaps (Medium)](https://leetcode.com/problems/smallest-string-with-swaps)

<p>You are given a string <code>s</code>, and an array of pairs of indices in the string&nbsp;<code>pairs</code>&nbsp;where&nbsp;<code>pairs[i] =&nbsp;[a, b]</code>&nbsp;indicates 2 indices(0-indexed) of the string.</p>

<p>You can&nbsp;swap the characters at any pair of indices in the given&nbsp;<code>pairs</code>&nbsp;<strong>any number of times</strong>.</p>

<p>Return the&nbsp;lexicographically smallest string that <code>s</code>&nbsp;can be changed to after using the swaps.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "dcab", pairs = [[0,3],[1,2]]
<strong>Output:</strong> "bacd"
<strong>Explaination:</strong> 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "dcab", pairs = [[0,3],[1,2],[0,2]]
<strong>Output:</strong> "abcd"
<strong>Explaination: </strong>
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"</pre>

<p><strong class="example">Example 3:</strong></p>

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


**Companies**:
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Union Find](https://leetcode.com/tag/union-find/)

**Similar Questions**:
* [Minimize Hamming Distance After Swap Operations (Medium)](https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/)
* [Process Restricted Friend Requests (Medium)](https://leetcode.com/problems/process-restricted-friend-requests/)
* [Largest Number After Digit Swaps by Parity (Medium)](https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/)
* [Lexicographically Smallest Beautiful String (Medium)](https://leetcode.com/problems/lexicographically-smallest-beautiful-string/)

## Solution 1. Union Find

```cpp
// OJ: https://leetcode.com/problems/smallest-string-with-swaps/
// Author: github.com/lzl124631x
// Time: O((N + P) * logN)
// Space: O(N)
class UnionFind {
    vector<int> id;
public:
    UnionFind(int n) : id(n) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        id[find(a)] = find(b);
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& P) {
        int N = s.size();
        UnionFind uf(N);
        for (auto &p : P) uf.connect(p[0], p[1]);
        unordered_map<int, vector<int>> m; // root index -> set of indices in the same group
        for (int i = 0; i < N; ++i) m[uf.find(i)].push_back(i);
        for (auto &[r, v] : m) sort(begin(v), end(v), [&](int a, int b) { return s[a] > s[b]; });
        string ans(N, 0);
        for (int i = 0; i < N; ++i) {
            ans[i] = s[m[uf.find(i)].back()];
            m[uf.find(i)].pop_back();
        }
        return ans;
    }
};
```