# [1504. Count Submatrices With All Ones (Medium)](https://leetcode.com/problems/count-submatrices-with-all-ones/)

<p>Given a&nbsp;<code>rows * columns</code>&nbsp;matrix <code>mat</code> of ones and zeros, return how many&nbsp;<strong>submatrices</strong> have all ones.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> mat = [[1,0,1],
&nbsp;             [1,1,0],
&nbsp;             [1,1,0]]
<strong>Output:</strong> 13
<strong>Explanation:
</strong>There are <b>6</b> rectangles of side 1x1.
There are <b>2</b> rectangles of side 1x2.
There are <b>3</b> rectangles of side 2x1.
There is <b>1</b> rectangle of side 2x2. 
There is <b>1</b> rectangle of side 3x1.
Total number of rectangles = 6 + 2 + 3 + 1 + 1 = <strong>13.</strong>
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> mat = [[0,1,1,0],
&nbsp;             [0,1,1,1],
&nbsp;             [1,1,1,0]]
<strong>Output:</strong> 24
<strong>Explanation:</strong>
There are <b>8</b> rectangles of side 1x1.
There are <b>5</b> rectangles of side 1x2.
There are <b>2</b> rectangles of side 1x3. 
There are <b>4</b> rectangles of side 2x1.
There are <b>2</b> rectangles of side 2x2. 
There are <b>2</b> rectangles of side 3x1. 
There is <b>1</b> rectangle of side 3x2. 
Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24<strong>.</strong>
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> mat = [[1,1,1,1,1,1]]
<strong>Output:</strong> 21
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> mat = [[1,0,1],[0,1,0],[1,0,1]]
<strong>Output:</strong> 5
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= rows&nbsp;&lt;= 150</code></li>
	<li><code>1 &lt;= columns&nbsp;&lt;= 150</code></li>
	<li><code>0 &lt;= mat[i][j] &lt;= 1</code></li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1.

For the `i`th row, regard the cells with ones in and above this row as histograms.

`H[j]` is the height of the histogram at column `j`.

For each `0 <= j < N`, count how many all-one rectangles are there with `A[i][j]` being the bottom-right element. `h` is the height of the rectangle and `k` is the index of the left edge column.

```cpp
// OJ: https://leetcode.com/problems/count-submatrices-with-all-ones/
// Author: github.com/lzl124631x
// Time: O(M * N^2)
// Space: O(N)
class Solution {
public:
    int numSubmat(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<int> H(N);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) H[j] = A[i][j] ? 1 + H[j] : 0;
            for (int j = 0; j < N; ++j) {
                int h = H[j];
                for (int k = j; k >= 0; --k) {
                    h = min(h, H[k]);
                    ans += h;
                }
            }
        }
        return ans;
    }
};
```

## Solution 2. Monostack

```cpp
// OJ: https://leetcode.com/problems/count-submatrices-with-all-ones/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int numSubmat(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<int> H(N);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) H[j] = A[i][j] ? 1 + H[j] : 0;
            stack<pair<int, int>> s; // index, height
            int cnt = 0;
            for (int j = 0; j < N; ++j) {
                int prev = j;
                while (s.size() && s.top().second > H[j]) {
                    cnt -= (prev - s.top().first) * (s.top().second - H[j]);
                    prev = s.top().first;
                    s.pop();
                }
                if (s.empty() || s.top().second < H[j]) s.emplace(prev, H[j]);
                cnt += s.top().second;
                ans += cnt;
            }
        }
        return ans;
    }
};
```

Another variation.

```cpp
// OJ: https://leetcode.com/problems/count-submatrices-with-all-ones/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int numSubmat(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<int> H(N);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) H[j] = A[i][j] ? 1 + H[j] : 0;
            vector<int> sum(N);
            stack<int> s;
            for (int j = 0; j < N; ++j) {
                while (s.size() && H[s.top()] >= H[j]) s.pop();
                sum[j] = (s.size() ? sum[s.top()] : 0) + (j - (s.size() ? s.top() : -1)) * H[j];
                ans += sum[j];
                s.push(j);
            }
        }
        return ans;
    }
};
```