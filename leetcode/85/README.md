# [85. Maximal Rectangle (Hard)](https://leetcode.com/problems/maximal-rectangle/)

<p>Given a <code>rows x cols</code>&nbsp;binary <code>matrix</code> filled with <code>0</code>'s and <code>1</code>'s, find the largest rectangle containing only <code>1</code>'s and return <em>its area</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/14/maximal.jpg" style="width: 402px; height: 322px;">
<pre><strong>Input:</strong> matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The maximal rectangle is shown in the above picture.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> matrix = [["0"]]
<strong>Output:</strong> 0
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> matrix = [["1"]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>rows == matrix.length</code></li>
	<li><code>cols == matrix[i].length</code></li>
	<li><code>1 &lt;= row, cols &lt;= 200</code></li>
	<li><code>matrix[i][j]</code> is <code>'0'</code> or <code>'1'</code>.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple), [Dunzo](https://leetcode.com/company/dunzo), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Stack](https://leetcode.com/tag/stack/), [Matrix](https://leetcode.com/tag/matrix/), [Monotonic Stack](https://leetcode.com/tag/monotonic-stack/)

**Similar Questions**:
* [Largest Rectangle in Histogram (Hard)](https://leetcode.com/problems/largest-rectangle-in-histogram/)
* [Maximal Square (Medium)](https://leetcode.com/problems/maximal-square/)

## Solution 1. Monotonic Stack

For each row:
* Calculate an `h` array where `h[j]` is the height of `1`s from `A[i][j]` upwards.
* Calculate `nextSmaller` and `prevSmaller` using Monotonic Stack where `nextSmaller`/`prevSmaller` is the index of the next/previous smaller element in `h` array. (Refer to [496. Next Greater Element I (Easy)](https://leetcode.com/problems/next-greater-element-i/discuss/97613/C%2B%2B-stack-%2B-unordered_map))
* The answer is the maximum of `(nextSmaller - prevSmaller - 1) * h[j]`.

```cpp
// OJ: https://leetcode.com/problems/maximal-rectangle/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& A) {
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<int> h(N), nextSmaller(N);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                h[j] = A[i][j] == '0' ? 0 : (h[j] + 1);
            }
            stack<int> s;
            for (int j = N - 1; j >= 0; --j) {
                while (s.size() && h[j] <= h[s.top()]) s.pop();
                nextSmaller[j] = s.size() ? s.top() : N;
                s.push(j);
            }
            s = {};
            for (int j = 0; j < N; ++j) {
                while (s.size() && h[j] <= h[s.top()]) s.pop();
                int prevSmaller = s.size() ? s.top() : -1;
                ans = max(ans, (nextSmaller[j] - prevSmaller - 1) * h[j]);
                s.push(j);
            }
        }
        return ans;
    }
};
```

## Solution 2. Monotonic Stack

We can reuse the solution for [84. Largest Rectangle in Histogram (Hard)](https://leetcode.com/problems/largest-rectangle-in-histogram/).

```cpp
// OJ: https://leetcode.com/problems/maximal-rectangle/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& A) {
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<int> h(N + 1);
        for (int i = 0; i < M; ++i) {
            stack<int> s;
            for (int j = 0; j <= N; ++j) {
                h[j] = j < N && A[i][j] == '1' ? (h[j] + 1) : 0;
                while (s.size() && h[j] <= h[s.top()]) {
                    int height = h[s.top()];
                    s.pop();
                    int left = s.size() ? s.top() : -1;
                    ans = max(ans, (j - left - 1) * height);
                }
                s.push(j);
            }
        }
        return ans;
    }
};
```

## Solution 3. DP

```cpp
// OJ: https://leetcode.com/problems/maximal-rectangle/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& A) {
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<int> h(N), prevSmaller(N, -1), nextSmaller(N, N);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) h[j] = A[i][j] == '1' ? h[j] + 1 : 0;
            for (int j = N - 2; j >= 0; --j) {
                int k = j + 1;
                while (k < N && h[k] >= h[j]) k = nextSmaller[k];
                nextSmaller[j] = k;
            }
            for (int j = 1; j < N; ++j) {
                int k = j - 1;
                while (k >= 0 && h[k] >= h[j]) k = prevSmaller[k];
                prevSmaller[j] = k;
            }
            for (int j = 0; j < N; ++j) ans = max(ans, (nextSmaller[j] - prevSmaller[j] - 1) * h[j]);
        }
        return ans;
    }
};
```

## Solution 4. DP

Let `height[i][j]` be the height of the bar from `A[i][j]` to `A[0][j]`.

Let `left[i][j]` be the index of the leftmost column such that the bar at `A[i][k]` has height at least `height[i][j]` for all `left[i][j] <= k <= j`.

Let `right[i][j]` be the index of the rightmost column such that the bar at `A[i][k]` has height at least `height[i][j]` for all `j <= k < right[i][j]`.

So the answer is the max `(right[i][j] - left[i][j]) * height[i][j]`.

We can use the following equations to get the values.

```
height[i][j] = A[i][j] == '1' ? height[i - 1][j] + 1 : 0

left[i][j] = max(left[i - 1][j], curLeft)         // If A[i][j] == '1'
           = 0                                    // If A[i][j] == '0'
where curLeft is the index of the leftmost column such that A[i][k] are all ones for `curLeft <= k <= j`

right[i][j] = min(right[i - 1][j], curRight)      // If A[i][j] == '1'
            = N                                   // If A[i][j] == '0'
where curRight is the index of the rightmost column such that A[i][k] are all ones for all `j <= k < curRight`
```

Since `height[i][j]`, `left[i][j]` and `right[i][j]` are only dependent on the value at the same column in the previous row, we can simply use 1D arrays to store those values.

```cpp
// OJ: https://leetcode.com/problems/maximal-rectangle/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        int ans = 0, M = A.size(), N = A[0].size();
        vector<int> left(N, 0), right(N, N), height(N, 0);
        for (int i = 0; i < M; ++i) {
            int curLeft = 0, curRight = N;
            for (int j = 0; j < N; ++j) height[j] = A[i][j] == '1' ? height[j] + 1 : 0;
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == '1') left[j] = max(left[j], curLeft);
                else {
                    left[j] = 0;
                    curLeft = j + 1;
                }
            }
            for (int j = N - 1; j >= 0; --j) {
                if (A[i][j] == '1') right[j] = min(right[j], curRight);
                else {
                    right[j] = N;
                    curRight = j;
                }
            }
            for (int j = 0; j < N; ++j) ans = max(ans, (right[j] - left[j]) * height[j]);
        }
        return ans;
    }
};
```