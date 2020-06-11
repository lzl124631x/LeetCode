# [85. Maximal Rectangle (Hard)](https://leetcode.com/problems/maximal-rectangle/)

<p>Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong>
[
  ["1","0","1","0","0"],
  ["1","0","<strong>1</strong>","<strong>1</strong>","<strong>1</strong>"],
  ["1","1","<strong>1</strong>","<strong>1</strong>","<strong>1</strong>"],
  ["1","0","0","1","0"]
]
<strong>Output:</strong> 6
</pre>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Stack](https://leetcode.com/tag/stack/)

**Similar Questions**:
* [Largest Rectangle in Histogram (Hard)](https://leetcode.com/problems/largest-rectangle-in-histogram/)
* [Maximal Square (Medium)](https://leetcode.com/problems/maximal-square/)

## Solution 1. Monotonic Stack

We can reuse the solution for [84. Largest Rectangle in Histogram (Hard)](https://leetcode.com/problems/largest-rectangle-in-histogram/).

```cpp
// OJ: https://leetcode.com/problems/maximal-rectangle/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<int> H(N + 1);
        for (int i = 0; i < M; ++i) {
            stack<int> s;
            for (int j = 0; j <= N; ++j) {
                H[j] = j < N && A[i][j] == '1' ? H[j] + 1 : 0;
                while (s.size() && H[s.top()] >= H[j]) {
                    int h = H[s.top()];
                    s.pop();
                    int w = s.size() ? (j - s.top() - 1) : j;
                    ans = max(ans, w * h);
                }
                s.push(j);
            }
        }
        return ans;
    }
};
```

## Solution 2. DP

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