# [1998. GCD Sort of an Array (Hard)](https://leetcode.com/problems/gcd-sort-of-an-array/)

<p>You are given an integer array <code>nums</code>, and you can perform the following operation <strong>any</strong> number of times on <code>nums</code>:</p>

<ul>
	<li>Swap the positions of two elements <code>nums[i]</code> and <code>nums[j]</code> if <code>gcd(nums[i], nums[j]) &gt; 1</code> where <code>gcd(nums[i], nums[j])</code> is the <strong>greatest common divisor</strong> of <code>nums[i]</code> and <code>nums[j]</code>.</li>
</ul>

<p>Return <code>true</code> <em>if it is possible to sort </em><code>nums</code><em> in <strong>non-decreasing</strong> order using the above swap method, or </em><code>false</code><em> otherwise.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [7,21,3]
<strong>Output:</strong> true
<strong>Explanation:</strong> We can sort [7,21,3] by performing the following operations:
- Swap 7 and 21 because gcd(7,21) = 7. nums = [<u><strong>21</strong></u>,<u><strong>7</strong></u>,3]
- Swap 21 and 3 because gcd(21,3) = 3. nums = [<u><strong>3</strong></u>,7,<u><strong>21</strong></u>]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [5,2,6,2]
<strong>Output:</strong> false
<strong>Explanation:</strong> It is impossible to sort the array because 5 cannot be swapped with any other element.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [10,5,9,3,15]
<strong>Output:</strong> true
We can sort [10,5,9,3,15] by performing the following operations:
- Swap 10 and 15 because gcd(10,15) = 5. nums = [<u><strong>15</strong></u>,5,9,3,<u><strong>10</strong></u>]
- Swap 15 and 3 because gcd(15,3) = 3. nums = [<u><strong>3</strong></u>,5,9,<u><strong>15</strong></u>,10]
- Swap 10 and 15 because gcd(10,15) = 5. nums = [3,5,9,<u><strong>10</strong></u>,<u><strong>15</strong></u>]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>2 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Similar Questions**:
* [Rank Transform of a Matrix (Hard)](https://leetcode.com/problems/rank-transform-of-a-matrix/)

## Solution 1. Factorization + Sort within Union

```cpp
// OJ: https://leetcode.com/problems/gcd-sort-of-an-array/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class UnionFind {
    vector<int> id;
public:
    UnionFind(int n) : id(n) {
        iota(begin(id), end(id), 0);
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        id[x] = y;
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
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
    bool gcdSort(vector<int>& A) {
        unordered_map<int, vector<int>> m;
        int N = A.size();
        for (int i = 0; i < N; ++i) {
            auto fs = factors(A[i]);
            for (int f : fs) m[f].push_back(i);
        }
        UnionFind uf(N);
        for (auto &[f, nums] : m) {
            for (int i = 1; i < nums.size(); ++i) {
                uf.connect(nums[0], nums[i]);
            }
        }
        unordered_map<int, vector<int>> us;
        for (int i = 0; i < N; ++i) {
            us[uf.find(i)].push_back(i);
        }
        vector<int> ans(N);
        for (auto &[f, ns] : us) {
            auto cpy = ns;
            sort(begin(ns), end(ns), [&](int a, int b){ return A[a] < A[b]; });
            for (int i = 0; i < ns.size(); ++i) {
                ans[cpy[i]] = A[ns[i]];
            }
        }
        for (int i = 1; i < N; ++i) {
            if (ans[i] < ans[i - 1]) return false;
        }
        return true;
    }
};
```

## TODO

Simplify code.

Solve Similar questions:

LC 952 https://leetcode.com/problems/largest-component-size-by-common-factor/ (UnionFind + Prime Factorization)
LC 1627 https://leetcode.com/problems/graph-connectivity-with-threshold/ (UnionFind + Factorization)
LC 1735 https://leetcode.com/problems/count-ways-to-make-array-with-product/ (DP + Prime Factorization)