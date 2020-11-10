# [832. Flipping an Image (Easy)](https://leetcode.com/problems/flipping-an-image/)

Given a binary matrix `A`, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For example, flipping `[1, 1, 0]` horizontally results in `[0, 1, 1]`.

To invert an image means that each `0` is replaced by `1`, and each `1` is replaced by `0`. For example, inverting `[0, 1, 1]` results in `[1, 0, 0]`.

**Example 1:**

**Input:** \[\[1,1,0\],\[1,0,1\],\[0,0,0\]\]  
**Output:** \[\[1,0,0\],\[0,1,0\],\[1,1,1\]\]  
**Explanation:** First reverse each row: \[\[0,1,1\],\[1,0,1\],\[0,0,0\]\].  
Then, invert the image: \[\[1,0,0\],\[0,1,0\],\[1,1,1\]\]

**Example 2:**

**Input:** \[\[1,1,0,0\],\[1,0,0,1\],\[0,1,1,1\],\[1,0,1,0\]\]  
**Output:** \[\[1,1,0,0\],\[0,1,1,0\],\[0,0,0,1\],\[1,0,1,0\]\]  
**Explanation:** First reverse each row: \[\[0,0,1,1\],\[1,0,0,1\],\[1,1,1,0\],\[0,1,0,1\]\].  
Then invert the image: \[\[1,1,0,0\],\[0,1,1,0\],\[0,0,0,1\],\[1,0,1,0\]\]

**Notes:**

*   `1 <= A.length = A[0].length <= 20`
*   `0 <= A[i][j] <= 1`

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/flipping-an-image/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if (A.empty() || A[0].empty()) return {};
        int M = A.size(), N = A[0].size();
        vector<vector<int>> ans(M, vector<int>(N));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                ans[i][N - j - 1] = 1 - A[i][j];
            }
        }
        return ans;
    }
};
```

Or do it in-place

```cpp
// OJ: https://leetcode.com/problems/flipping-an-image/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        for (int i = 0; i < M; ++i) {
            for (int j = 0, k = N - 1; j <= k; ++j, --k) {
                A[i][j] = 1 - A[i][j];
                if (j != k) {
                    A[i][k] = 1 - A[i][k];
                    swap(A[i][j], A[i][k]);
                }
            }
        }
        return A;
    }
};
```