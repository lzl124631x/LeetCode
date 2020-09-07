# [835. Image Overlap (Medium)](https://leetcode.com/problems/image-overlap/)

<p>Two images <code>A</code> and <code>B</code> are given, represented as&nbsp;binary, square matrices of the same size.&nbsp; (A binary matrix has only 0s and 1s as values.)</p>

<p>We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.&nbsp; After, the <em>overlap</em> of this translation is the number of positions that have a 1 in both images.</p>

<p>(Note also that a translation does <strong>not</strong> include any kind of rotation.)</p>

<p>What is the largest possible overlap?</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>A = [[1,1,0],
            [0,1,0],
&nbsp;           [0,1,0]]
&nbsp;      B = [[0,0,0],
&nbsp;           [0,1,1],
&nbsp;           [0,0,1]]
<strong>Output: </strong>3
<strong>Explanation:</strong> We slide A to right by 1 unit and down by 1 unit.</pre>

<p><strong>Notes:</strong>&nbsp;</p>

<ol>
	<li><code>1 &lt;= A.length = A[0].length = B.length = B[0].length &lt;= 30</code></li>
	<li><code>0 &lt;=&nbsp;A[i][j], B[i][j] &lt;= 1</code></li>
</ol>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/image-overlap/
// Author: github.com/lzl124631x
// Time: O(N^4)
// Space: O(1)
class Solution {
    int overlap(vector<vector<int>> &A, vector<vector<int>> &B, int dx, int dy) {
        int N = A.size(), ans = 0;
        for (int i = 0; i + dx < N; ++i) {
            for (int j = 0; j + dy < N; ++j) {
                ans += B[i][j] == 1 && A[i + dx][j + dy] == B[i][j];
            }
        }
        return ans;
    }
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int N = A.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                ans = max({ ans, overlap(A, B, i, j), overlap(B, A, i, j) });
            }
        }
        return ans;
    }
};
```

## Solution 2. Most Common Index Distance

If the image is sparse matrix, we can save computation in the following way.

To make the problem simpler, think of two 1d arrays, we want to compute the `largestOverlap` of them. We can store the indexes of 1s into two `vector<int>` `va` and `vb`, and compute the most common distance between `va[i]` and `vb[j]`.

Example:

```
A = [1, 1, 1, 0]
B = [0, 1, 0, 1]
va = [0, 1, 2]
vb = [1, 3]
// we compute the difference between each pair of the indexes
diff = [-1, 0, 1,
        -3, -2, -1]
frequency = {
    {-3, 1},
    {-2, 1},
    {-1, 2}, // -1 appeared twice
    {0, 1},
    {1, 1}
}
// Since -1 is the most frequent difference and its frequency is 2
// The best answer is to shift `B` by `-1` and we get `2` overlaps.
```

For a 2d array, the distance becomes 2d as well. Instead of using pairs, we encode `x, y` as `100 * x + y` thus the 2d array is flattened to 1d array, and the distance becomes `100 * delta_x + delta_y`. The most common distance is the answer.

Why using `100` instead of `30`? Since the `delta_y` has range `-29 = -(N - 1)`  to `29 = (N - 1)`. So using `30` will cause ambiguous intrepretation of the distance. For example, distance `15` can be interpreted as `0 * 30 + 15` and `1 * 30 - 15`.

The minimum value of the multiplier is the size of range of `delta_y` which is `(N - 1) - -(N - 1) + 1 = 2 * N - 1`.

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