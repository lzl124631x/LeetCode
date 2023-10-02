# [1337. The K Weakest Rows in a Matrix (Easy)](https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix)

<p>You are given an <code>m x n</code> binary matrix <code>mat</code> of <code>1</code>&#39;s (representing soldiers) and <code>0</code>&#39;s (representing civilians). The soldiers are positioned <strong>in front</strong> of the civilians. That is, all the <code>1</code>&#39;s will appear to the <strong>left</strong> of all the <code>0</code>&#39;s in each row.</p>

<p>A row <code>i</code> is <strong>weaker</strong> than a row <code>j</code> if one of the following is true:</p>

<ul>
	<li>The number of soldiers in row <code>i</code> is less than the number of soldiers in row <code>j</code>.</li>
	<li>Both rows have the same number of soldiers and <code>i &lt; j</code>.</li>
</ul>

<p>Return <em>the indices of the </em><code>k</code><em> <strong>weakest</strong> rows in the matrix ordered from weakest to strongest</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
<strong>Output:</strong> [2,0,3]
<strong>Explanation:</strong> 
The number of soldiers in each row is: 
- Row 0: 2 
- Row 1: 4 
- Row 2: 1 
- Row 3: 2 
- Row 4: 5 
The rows ordered from weakest to strongest are [2,0,3,1,4].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> mat = 
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]], 
k = 2
<strong>Output:</strong> [0,2]
<strong>Explanation:</strong> 
The number of soldiers in each row is: 
- Row 0: 1 
- Row 1: 4 
- Row 2: 1 
- Row 3: 1 
The rows ordered from weakest to strongest are [0,2,3,1].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>2 &lt;= n, m &lt;= 100</code></li>
	<li><code>1 &lt;= k &lt;= m</code></li>
	<li><code>matrix[i][j]</code> is either 0 or 1.</li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Binary Search](https://leetcode.com/tag/binary-search), [Sorting](https://leetcode.com/tag/sorting), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue), [Matrix](https://leetcode.com/tag/matrix)

## Solution 1. Binary Search (L <= R) + Sorting

```cpp
// OJ: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
// Author: github.com/lzl124631x
// Time: O(MlogN + MlogM)
// Space: O(M)
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& A, int k) {
        vector<pair<int, int>> B;
        int M = A.size(), N = A[0].size();
        for (int i = 0; i < M; ++i) {
            int L = 0, R = N - 1;
            while (L <= R) {
                int M = (L + R) / 2;
                if (A[i][M] == 1) L = M + 1;
                else R = M - 1;
            }
            B.emplace_back(R, i);
        }
        sort(begin(B), end(B));
        vector<int> ans;
        for (int i = 0; i < k; ++i) ans.push_back(B[i].second);
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix
// Author: github.com/lzl124631x
// Time: O(MlogN + MlogM)
// Space: O(M)
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& A, int k) {
        int M = A.size(), N = A[0].size();
        vector<int> cnt(M), id(M), ans(k);
        for (int i = 0; i < M; ++i) {
            int L = 0, R = N - 1;
            while (L <= R) {
                int M = (L + R) / 2;
                if (A[i][M] == 1) L = M + 1;
                else R = M - 1;
            }
            cnt[i] = L;
        }
        iota(begin(id), end(id), 0);
        sort(begin(id), end(id), [&](int a, int b) { return cnt[a] != cnt[b] ? cnt[a] < cnt[b] : a < b; });
        for (int i = 0; i < k; ++i) ans[i] = id[i];
        return ans;
    }
};
```

## Solution 2. Binary Search (L < R) + Sorting

```cpp
// OJ: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
// Author: github.com/lzl124631x
// Time: O(MlogN + MlogM)
// Space: O(M)
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& A, int k) {
        vector<pair<int, int>> B;
        int M = A.size(), N = A[0].size();
        for (int i = 0; i < M; ++i) {
            int L = 0, R = N; // Note that since we are looking for the first index of `0`, the `R` should be initialized as `N`.
            while (L < R) {
                int M = (L + R) / 2;
                if (A[i][M] == 1) L = M + 1;
                else R = M;
            }
            B.emplace_back(R, i);
        }
        sort(begin(B), end(B));
        vector<int> ans;
        for (int i = 0; i < k; ++i) ans.push_back(B[i].second);
        return ans;
    }
};
```

## Solution 3. Binary Search (L <= R) + Heap
```cpp
// OJ: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix
// Author: github.com/lzl124631x
// Time: O(M * (logN + logK))
// Space: O(K)
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& A, int k) {
        int M = A.size(), N = A[0].size();
        vector<int> ans;
        typedef pair<int, int> PII; // cnt, index
        priority_queue<PII> pq;
        for (int i = 0; i < M; ++i) {
            int L = 0, R = N - 1;
            while (L <= R) {
                int M = (L + R) / 2;
                if (A[i][M] == 1) L = M + 1;
                else R = M - 1;
            }
            pq.emplace(L, i);
            if (pq.size() > k) pq.pop();
        }
        while (pq.size()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
```