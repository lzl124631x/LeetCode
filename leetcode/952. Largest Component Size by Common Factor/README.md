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

## TLE Solution

The idea is to use union find. But I compared every pair in the vector `A`, which resulted in `O(N^2)` time complexity and get TLE.

```cpp
// OJ: https://leetcode.com/problems/largest-component-size-by-common-factor/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class UnionFind {
private:
  vector<int> id, rank, size;
public:
  UnionFind(int cnt) {
    id = vector<int>(cnt);
    rank = vector<int>(cnt, 0);
      size=vector<int>(cnt, 1);
    for (int i = 0; i < cnt; ++i) id[i] = i;
  }
  int find(int p) {
      if (id[p] == p) return p;
      return id[p] = find(id[p]);
  }
  bool connected(int p, int q) { return find(p) == find(q); }
  void connect(int p, int q) {
    int i = find(p), j = find(q);
    if (i == j) return;
    if (rank[i] < rank[j]) {
        id[i] = j;
        size[j] += size[i];
    }
    else {
      id[j] = i;
        size[i] += size[j];
      if (rank[i] == rank[j]) rank[j]++;
    }
  }
  int maxSize() {
      int ans = 1;
      for (int r : size) ans = max(ans, r);
      return ans;
  }
};
class Solution {
private:
    bool shareCommonFactor(int a, int b) {
        if (b > a) swap(a, b);
        while (b) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a != 1;
    }
public:
    int largestComponentSize(vector<int>& A) {
        int N = A.size();
        UnionFind uf(N);
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (uf.connected(i, j)) continue;
                if (shareCommonFactor(A[i], A[j])) uf.connect(i, j);
            }
        }
        return uf.maxSize();
    }
};
```

## Solution 1. Union Find + Factor

The number of elements is big. Can we reduce the scale? Consider all the primes that are factors of numbers in `A`.

For each number `A[i]`, we union all the factors of `A[i]`. In this way, `A[i]`s are grouped according to factors. The size of the biggest group is the result.

```cpp
// OJ: https://leetcode.com/problems/largest-component-size-by-common-factor/
// Author: github.com/lzl124631x
// Time: O(N * sqrt(W)) where N is length of A, W is max(A[i])
// Space: O(N)
class UnionFind {
private:
  vector<int> id, rank, size;
public:
  UnionFind(int cnt) {
    id = vector<int>(cnt);
    rank = vector<int>(cnt, 0);
    for (int i = 0; i < cnt; ++i) id[i] = i;
  }
  int find(int p) {
      if (id[p] == p) return p;
      return id[p] = find(id[p]);
  }
  bool connected(int p, int q) { return find(p) == find(q); }
  void connect(int p, int q) {
    int i = find(p), j = find(q);
    if (i == j) return;
    if (rank[i] < rank[j]) {
        id[i] = j;
    }
    else {
      id[j] = i;
      if (rank[i] == rank[j]) rank[j]++;
    }
  }
};
class Solution {
private:
    vector<int> getFactors(int N) {
        int d = 2;
        vector<int> factors;
        for (int d = 2; d * d <= N; ++d) {
            if (N % d) continue;
            while (N % d == 0) N /= d;
            factors.push_back(d);
        }
        if (N > 1 || factors.empty()) factors.push_back(N);
        return factors;
    }
public:
    int largestComponentSize(vector<int>& A) {
        int N = A.size();
        vector<vector<int>> factors(N);
        for (int i = 0; i < N; ++i) {
            factors[i] = getFactors(A[i]);
        }
        unordered_set<int> primeSet;
        for (auto &fs : factors) {
            for (int f : fs) primeSet.insert(f);
        }
        vector<int> primes(primeSet.begin(), primeSet.end());
        unordered_map<int, int> primeToIndex;
        for (int i = 0; i < primes.size(); ++i) primeToIndex[primes[i]] = i;
        UnionFind uf(primes.size());
        for (auto &fs : factors) {
            for (int f : fs) uf.connect(primeToIndex[fs.front()], primeToIndex[f]);
        }
        vector<int> count(primes.size(), 0);
        for (auto &fs : factors) count[uf.find(primeToIndex[fs[0]])]++;
        return *max_element(count.begin(), count.end());
    }
};
```