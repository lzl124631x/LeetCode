# [867. Transpose Matrix (Easy)](https://leetcode.com/problems/transpose-matrix/)

Given a matrix `A`, return the transpose of `A`.

The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.

**Example 1:**

**Input:** \[\[1,2,3\],\[4,5,6\],\[7,8,9\]\]  
**Output:** \[\[1,4,7\],\[2,5,8\],\[3,6,9\]\]

**Example 2:**

**Input:** \[\[1,2,3\],\[4,5,6\]\]  
**Output:** \[\[1,4\],\[2,5\],\[3,6\]\]

**Note:**

1.  `1 <= A.length <= 1000`
2.  `1 <= A[0].length <= 1000`

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/transpose-matrix/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        if (A.empty() || A[0].empty()) return {};
        int M = A.size(), N = A[0].size();
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                v[j][i] = A[i][j];
            }
        }
        return v;
    }
};
```