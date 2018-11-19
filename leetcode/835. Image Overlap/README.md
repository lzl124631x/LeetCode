# [835. Image Overlap (Medium)](https://leetcode.com/problems/image-overlap/)

Two images `A` and `B` are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the _overlap_ of this translation is the number of positions that have a 1 in both images.

(Note also that a translation does **not** include any kind of rotation.)

What is the largest possible overlap?

**Example 1:**

**Input:**
```
A = [[1,1,0],
     [0,1,0],
     [0,1,0]]
B = [[0,0,0],
     [0,1,1],
     [0,0,1]]
```

**Output:** 3  
**Explanation:** We slide A to right by 1 unit and down by 1 unit.

**Notes:** 

1.  `1 <= A.length = A[0].length = B.length = B[0].length <= 30`
2.  `0 <= A[i][j], B[i][j] <= 1`

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/image-overlap/
// Author: github.com/lzl124631x
// Time: O(N^4)
// Space: O(1)
class Solution {
private:
    int N;
    int overlap(vector<vector<int>>& A, vector<vector<int>>& B, int x, int y) {
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            if ((i + x) < 0 || (i + x) >= N) continue;
            for (int j = 0; j < N; ++j) {
                if ((j + y) >= 0 && (j + y) < N
                    && A[i + x][j + y] && B[i][j]) ++cnt;
            }
        }
        return cnt;
    }
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        N = A.size();
        int ans = 0;
        for (int x = -N + 1; x < N; ++x) {
            for (int y = -N + 1; y < N; ++y) {
                ans = max(ans, overlap(A, B, x, y));
            }
        }
        return ans;
    }
};
```

## Solution 2. Most Common Index Distance.

If the image is sparse matrix, we can save computation in the following way.

To make the problem simpler, think of two 1d arrays, we want to compute the `largestOverlap` of them. We can store the indexes of 1s into `va` and `vb`, and compute the most common distance between `va[i]` and `vb[j]`.

For the 2d arrays, the distance becomes 2d as well. Instead of using pairs, we encode `x, y` into `100 * x + y`, and the distance becomes `100 * delta_x + delta_y`. The most common distance is the answer.

```cpp
// OJ: https://leetcode.com/problems/image-overlap/
// Author: github.com/lzl124631x
// Time: O(N^2+AB) where A and B are the counts of 1s in image `A` and `B`.
// Space: O(N^2+AB)
// Ref: https://leetcode.com/problems/image-overlap/discuss/130623/C%2B%2BJavaPython-Straight-Forward
class Solution {
private:
    vector<int> flatten(vector<vector<int>>& A) {
        int N = A.size();
        vector<int> ans;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 1) ans.push_back(i * 100 + j);
            }
        }
        return ans;
    }
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        auto va = flatten(A), vb = flatten(B);
        unordered_map<int, int> m;
        for (int i : va) {
            for (int j : vb) {
                m[i - j]++;
            }
        }
        int ans = 0;
        for (auto p : m) ans = max(ans, p.second);
        return ans;
    }
};
```