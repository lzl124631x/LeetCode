# [952. Largest Component Size by Common Factor (Hard)](https://leetcode.com/problems/largest-component-size-by-common-factor/)

<p>You are given an integer array of unique positive integers <code>nums</code>. Consider the following graph:</p>

<ul>
	<li>There are <code>nums.length</code> nodes, labeled <code>nums[0]</code> to <code>nums[nums.length - 1]</code>,</li>
	<li>There is an undirected edge between <code>nums[i]</code> and <code>nums[j]</code> if <code>nums[i]</code> and <code>nums[j]</code> share a common factor greater than <code>1</code>.</li>
</ul>

<p>Return <em>the size of the largest connected component in the graph</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/01/ex1.png" style="width: 500px; height: 97px;">
<pre><strong>Input:</strong> nums = [4,6,15,35]
<strong>Output:</strong> 4
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/01/ex2.png" style="width: 500px; height: 85px;">
<pre><strong>Input:</strong> nums = [20,50,9,63]
<strong>Output:</strong> 2
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/01/ex3.png" style="width: 500px; height: 260px;">
<pre><strong>Input:</strong> nums = [2,3,6,7,4,12,21,39]
<strong>Output:</strong> 8
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li>All the values of <code>nums</code> are <strong>unique</strong>.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Union Find](https://leetcode.com/tag/union-find/)

## Solution 1. Union Find + Factorization

1. Factorize each numbers in `A`, and group the numbers by factors.
2. Use UnionFind to union the numbers in the same group
3. Return the size of the largest union.

* Step 1 takes `O(N * sqrt(M))` time (factorizing a number takes `O(sqrt(M))` time) and `O(N * sqrt(M))` space where `M` is the maximum number in `A`.
* Step 2 takes `O(N * sqrt(M))` time (in the worst case, `sqrt(M)` factors/groups and each group has `N` elements) and `O(N)` space (due to UnionFind).
* Step 3 takes `O(N)` time and `O(1)` space.

So overall this solution takes `O(N * sqrt(M))` time and `O(N * sqrt(M))` space.

```cpp
// OJ: https://leetcode.com/problems/largest-component-size-by-common-factor/
// Author: github.com/lzl124631x
// Time: O(N * sqrt(M)) where `N` is the length of `A`, and `M` is the maximum number in `A`.
// Space: O(N * sqrt(M))
class UnionFind {
    vector<int> id, size;
public:
    UnionFind(int N) : id(N), size(N, 1) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        int p = find(a), q = find(b);
        if (p == q) return;
        id[p] = q;
        size[q] += size[p];
    }
    int getSize(int a) { return size[find(a)]; }
};
class Solution {
    vector<int> factors(int n) {
        vector<int> ans;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) ans.push_back(i);
            while (n % i == 0) n /= i;
        }
        if (n > 1) ans.push_back(n);
        return ans;
    }
public:
    int largestComponentSize(vector<int>& A) {
        int N = A.size(), ans = 0;
        UnionFind uf(N);
        unordered_map<int, vector<int>> m; // prime factor -> all indexes of numbers with this factor
        for (int i = 0; i < N; ++i) {
            for (int &f : factors(A[i])) m[f].push_back(i);
        }
        for (auto &[f, indices] : m) {
            for (int i = 1; i < indices.size(); ++i) uf.connect(indices[0], indices[i]);
        }
        for (int i = 0; i < N; ++i) ans = max(ans, uf.getSize(i));
        return ans;
    }
};
```

Or we can merge step 1 and step 2 together by only storing a representative number for each factor in the map. For all subsequent numbers with the same factor, we just need to union it with the representative number. In this way, reduce the space complexity from `O(N * sqrt(M))` to `O(N + sqrt(M))`.

```cpp
// OJ: https://leetcode.com/problems/largest-component-size-by-common-factor/
// Author: github.com/lzl124631x
// Time: O(N * sqrt(M))
// Space: O(N + sqrt(M))
class UnionFind {
    vector<int> id, size;
public:
    UnionFind(int N) : id(N), size(N, 1) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        int p = find(a), q = find(b);
        if (p == q) return;
        id[p] = q;
        size[q] += size[p];
    }
    int getSize(int a) { return size[find(a)]; }
};
class Solution {
    vector<int> factors(int n) {
        vector<int> ans;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) ans.push_back(i);
            while (n % i == 0) n /= i;
        }
        if (n > 1) ans.push_back(n);
        return ans;
    }
public:
    int largestComponentSize(vector<int>& A) {
        int N = A.size(), ans = 0;
        UnionFind uf(N);
        unordered_map<int, int> m;  // primce factor -> a representative (the first) number with this factor
        for (int i = 0; i < N; ++i) {
            for (int &f : factors(A[i])) { 
                if (m.count(f)) uf.connect(i, m[f]);
                else m[f] = i;
            }
        }
        for (int i = 0; i < N; ++i) ans = max(ans, uf.getSize(i));
        return ans;
    }
};
```