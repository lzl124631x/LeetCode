# [839. Similar String Groups (Hard)](https://leetcode.com/problems/similar-string-groups/)

<p>Two strings <code>X</code>&nbsp;and <code>Y</code>&nbsp;are similar if we can swap two letters (in different positions) of <code>X</code>, so that&nbsp;it equals <code>Y</code>. Also two strings <code>X</code> and <code>Y</code> are similar if they are equal.</p>

<p>For example, <code>"tars"</code>&nbsp;and <code>"rats"</code>&nbsp;are similar (swapping at positions <code>0</code> and <code>2</code>), and <code>"rats"</code> and <code>"arts"</code> are similar, but <code>"star"</code> is not similar to <code>"tars"</code>, <code>"rats"</code>, or <code>"arts"</code>.</p>

<p>Together, these form two connected groups by similarity: <code>{"tars", "rats", "arts"}</code> and <code>{"star"}</code>.&nbsp; Notice that <code>"tars"</code> and <code>"arts"</code> are in the same group even though they are not similar.&nbsp; Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.</p>

<p>We are given a list <code>A</code> of strings.&nbsp; Every string in <code>A</code> is an anagram of every other string in <code>A</code>.&nbsp; How many groups are there?</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> A = ["tars","rats","arts","star"]
<strong>Output:</strong> 2
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= A.length &lt;= 2000</code></li>
	<li><code>1 &lt;= A[i].length &lt;= 1000</code></li>
	<li><code>A.length * A[i].length &lt;= 20000</code></li>
	<li>All words in <code>A</code>&nbsp;consist of lowercase letters only.</li>
	<li>All words in <code>A</code> have the same length and are anagrams of each other.</li>
	<li>The judging time limit has been increased for this question.</li>
</ul>


**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Union Find](https://leetcode.com/tag/union-find/), [Graph](https://leetcode.com/tag/graph/)

## Solution 1. UnionFind

```cpp
// OJ: https://leetcode.com/problems/similar-string-groups/
// Author: github.com/lzl124631x
// Time: O(NW)
// Space: O(N)
class UnionFind {
    vector<int> id;
    int size;
public:
    UnionFind(int N) : id(N), size(N) {
        iota(begin(id), end(id), 0);
    }
    int find(int x) {
        return id[x] == x ? x : (id[x] = find(id[x]));
    }
    void connect(int x, int y) {
        int p = find(x), q = find(y);
        if (p == q) return;
        id[p] = q;
        --size;
    }
    int getSize() { return size; }
};
class Solution {
    bool similar(string &a, string &b) {
        int cnt = 0;
        for (int i = 0; i < a.size(); ++i) {
            if ((cnt += (a[i] != b[i])) > 2) return false;
        }
        return cnt == 2 || cnt == 0;
    }
public:
    int numSimilarGroups(vector<string>& A) {
        int N = A.size();
        UnionFind uf(N);
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (similar(A[i], A[j])) uf.connect(i, j);
            }
        }
        return uf.getSize();
    }
};
```