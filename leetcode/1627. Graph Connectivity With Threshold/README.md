# [1627. Graph Connectivity With Threshold (Hard)](https://leetcode.com/problems/graph-connectivity-with-threshold/)

<p>We have <code>n</code> cities labeled from <code>1</code> to <code>n</code>. Two different cities with labels <code>x</code> and <code>y</code> are directly connected by a bidirectional road if and only if <code>x</code> and <code>y</code> share a common divisor <strong>strictly greater</strong> than some <code>threshold</code>. More formally, cities with labels <code>x</code> and <code>y</code> have a road between them if there exists an integer <code>z</code> such that all of the following are true:</p>

<ul>
	<li><code>x % z == 0</code>,</li>
	<li><code>y % z == 0</code>, and</li>
	<li><code>z &gt; threshold</code>.</li>
</ul>

<p>Given the two integers, <code>n</code> and <code>threshold</code>, and an array of <code>queries</code>, you must determine for each <code>queries[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> if cities <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code> are connected (i.e. there is some path between them).</p>

<p>Return <em>an array </em><code>answer</code><em>, where </em><code>answer.length == queries.length</code><em> and </em><code>answer[i]</code><em> is </em><code>true</code><em> if for the </em><code>i<sup>th</sup></code><em> query, there is a path between </em><code>a<sub>i</sub></code><em> and </em><code>b<sub>i</sub></code><em>, or </em><code>answer[i]</code><em> is </em><code>false</code><em> if there is no path.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/09/ex1.jpg" style="width: 382px; height: 181px;">
<pre><strong>Input:</strong> n = 6, threshold = 2, queries = [[1,4],[2,5],[3,6]]
<strong>Output:</strong> [false,false,true]
<strong>Explanation:</strong> The divisors for each number:
1:   1
2:   1, 2
3:   1, <u>3</u>
4:   1, 2, <u>4</u>
5:   1, <u>5</u>
6:   1, 2, <u>3</u>, <u>6</u>
Using the underlined divisors above the threshold, only cities 3 and 6 share a common divisor, so they are the
only ones directly connected. The result of each query:
[1,4]   1 is not connected to 4
[2,5]   2 is not connected to 5
[3,6]   3 is connected to 6 through path 3--6
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/10/tmp.jpg" style="width: 532px; height: 302px;">
<pre><strong>Input:</strong> n = 6, threshold = 0, queries = [[4,5],[3,4],[3,2],[2,6],[1,3]]
<strong>Output:</strong> [true,true,true,true,true]
<strong>Explanation:</strong> The divisors for each number are the same as the previous example. However, since the threshold is 0,
all divisors can be used. Since all numbers share 1 as a divisor, all cities are connected.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/17/ex3.jpg" style="width: 282px; height: 282px;">
<pre><strong>Input:</strong> n = 5, threshold = 1, queries = [[4,5],[4,5],[3,2],[2,3],[3,4]]
<strong>Output:</strong> [false,false,false,false,false]
<strong>Explanation:</strong> Only cities 2 and 4 share a common divisor 2 which is strictly greater than the threshold 1, so they are the only ones directly connected.
Please notice that there can be multiple queries for the same pair of nodes [x, y], and that the query [x, y] is equivalent to the query [y, x].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= threshold &lt;= n</code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>1 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= cities</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Union Find](https://leetcode.com/tag/union-find/)

## Solution 1. Union Find

```cpp
// OJ: https://leetcode.com/problems/graph-connectivity-with-threshold/
// Author: github.com/lzl124631x
// Time: O(NlogN + Q)
// Space: O(N)
// Ref: https://leetcode.com/problems/graph-connectivity-with-threshold/discuss/899595/C%2B%2BJavaPython-Union-Find-O(N-*-logN-%2B-q)
class UnionFind {
    vector<int> id;
public:
    UnionFind(int n) : id(n) {
        iota(begin(id), end(id), 0);
    }
    int find(int x) {
        return id[x] == x ? x : (id[x] = find(id[x]));
    }
    void connect(int a, int b) {
        int p = find(a), q = find(b);
        if (p == q) return;
        id[p] = q;
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};
class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& Q) {
        unordered_map<int, int> m;
        UnionFind uf(n);
        for (int i = 1; i <= n; ++i) {
            for (int j = 2 * i; j <= n; j += i) {
                if (i > threshold) uf.connect(i - 1, j - 1);
            }
        }
        vector<bool> ans;
        for (auto &q : Q) ans.push_back(uf.connected(q[0] - 1, q[1] - 1));
        return ans;
    }
};
```