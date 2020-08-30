# [952. Largest Component Size by Common Factor (Hard)](https://leetcode.com/problems/largest-component-size-by-common-factor/)

<p>Given a non-empty&nbsp;array of unique positive integers <code>A</code>, consider the following graph:</p>

<ul>
	<li>There are <code>A.length</code> nodes, labelled <code>A[0]</code> to <code>A[A.length - 1];</code></li>
	<li>There is an edge between <code>A[i]</code> and <code>A[j]</code>&nbsp;if and only if&nbsp;<code>A[i]</code> and <code>A[j]</code> share a common factor greater than 1.</li>
</ul>

<p>Return the size of the largest connected component in the graph.</p>

<p>&nbsp;</p>

<ol>
</ol>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[4,6,15,35]</span>
<strong>Output: </strong><span id="example-output-1">4</span>
<span><img alt="" src="https://assets.leetcode.com/uploads/2018/12/01/ex1.png" style="width: 257px; height: 50px;"></span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[20,50,9,63]</span>
<strong>Output: </strong><span id="example-output-2">2</span>
<span><img alt="" src="https://assets.leetcode.com/uploads/2018/12/01/ex2.png" style="width: 293px; height: 50px;"></span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">[2,3,6,7,4,12,21,39]</span>
<strong>Output: </strong><span id="example-output-3">8</span>
<span><img alt="" src="https://assets.leetcode.com/uploads/2018/12/01/ex3.png" style="width: 346px; height: 180px;"></span>
</pre>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 20000</code></li>
	<li><code>1 &lt;= A[i] &lt;= 100000</code></li>
</ol>
</div>
</div>
</div>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Union Find](https://leetcode.com/tag/union-find/)

## Solution 1. Union Find + Factor

The number of elements is big. Can we reduce the scale? Consider all the primes that are factors of numbers in `A`.

For each number `A[i]`, we union all the factors of `A[i]`. In this way, `A[i]`s are grouped according to factors. The size of the biggest group is the result.

```cpp
// OJ: https://leetcode.com/problems/largest-component-size-by-common-factor/
// Author: github.com/lzl124631x
// Time: O(N * sqrt(W)) where N is length of A, W is max(A[i])
// Space: O(N)
class UnionFind {
    vector<int> id;
public:
    UnionFind(int N) : id(N) {
        iota(begin(id), end(id), 0);
    }    
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        int p = find(a), q = find(b);
        if (p == q) return;
        id[p] = q;
    }
};
class Solution {
    vector<int> factors(int n) {
        vector<int> ans;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i) continue;
            ans.push_back(i);
            while (n % i == 0) n /= i;
        }
        if (n > 1 || ans.empty()) ans.push_back(n);
        return ans;
    }
public:
    int largestComponentSize(vector<int>& A) {
        vector<vector<int>> F;
        unordered_map<int, int> m;
        int i = 0, ans = 0;
        for (int n : A) {
            auto f = factors(n);
            F.push_back(f);
            for (int x : f) {
                if (!m.count(x)) m[x] = i++;
            }
        }
        UnionFind uf(m.size());
        for (auto &f : F) {
            for (int x : f) uf.connect(m[f[0]], m[x]);
        }
        vector<int> cnt(m.size());
        for (auto &f : F) ans = max(ans, ++cnt[uf.find(m[f[0]])]);
        return ans;
    }
};
```