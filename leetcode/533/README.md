# [533. Lonely Pixel II (Medium)](https://leetcode.com/problems/lonely-pixel-ii)

<p>Given an <code>m x n</code> <code>picture</code> consisting of black <code>&#39;B&#39;</code> and white <code>&#39;W&#39;</code> pixels and an integer target, return <em>the number of <b>black</b> lonely pixels</em>.</p>

<p>A black lonely pixel is a character <code>&#39;B&#39;</code> that located at a specific position <code>(r, c)</code> where:</p>

<ul>
	<li>Row <code>r</code> and column <code>c</code> both contain exactly <code>target</code> black pixels.</li>
	<li>For all rows that have a black pixel at column <code>c</code>, they should be exactly the same as row <code>r</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/pixel2-1-grid.jpg" style="width: 493px; height: 333px;" />
<pre>
<strong>Input:</strong> picture = [[&quot;W&quot;,&quot;B&quot;,&quot;W&quot;,&quot;B&quot;,&quot;B&quot;,&quot;W&quot;],[&quot;W&quot;,&quot;B&quot;,&quot;W&quot;,&quot;B&quot;,&quot;B&quot;,&quot;W&quot;],[&quot;W&quot;,&quot;B&quot;,&quot;W&quot;,&quot;B&quot;,&quot;B&quot;,&quot;W&quot;],[&quot;W&quot;,&quot;W&quot;,&quot;B&quot;,&quot;W&quot;,&quot;B&quot;,&quot;W&quot;]], target = 3
<strong>Output:</strong> 6
<strong>Explanation:</strong> All the green &#39;B&#39; are the black pixels we need (all &#39;B&#39;s at column 1 and 3).
Take &#39;B&#39; at row r = 0 and column c = 1 as an example:
 - Rule 1, row r = 0 and column c = 1 both have exactly target = 3 black pixels. 
 - Rule 2, the rows have black pixel at column c = 1 are row 0, row 1 and row 2. They are exactly the same as row r = 0.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/pixel2-2-grid.jpg" style="width: 253px; height: 253px;" />
<pre>
<strong>Input:</strong> picture = [[&quot;W&quot;,&quot;W&quot;,&quot;B&quot;],[&quot;W&quot;,&quot;W&quot;,&quot;B&quot;],[&quot;W&quot;,&quot;W&quot;,&quot;B&quot;]], target = 1
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m ==&nbsp;picture.length</code></li>
	<li><code>n ==&nbsp;picture[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>picture[i][j]</code> is <code>&#39;W&#39;</code> or <code>&#39;B&#39;</code>.</li>
	<li><code>1 &lt;= target &lt;= min(m, n)</code></li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Hash Table](https://leetcode.com/tag/hash-table), [Matrix](https://leetcode.com/tag/matrix)

**Similar Questions**:
* [Lonely Pixel I (Medium)](https://leetcode.com/problems/lonely-pixel-i)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/lonely-pixel-ii
// Author: github.com/lzl124631x
// Time: O(M^2 * N)
// Space: O(MN)
class Solution {
public:
    int findBlackPixel(vector<vector<char>>& A, int target) {
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<vector<bool>> same(M, vector<bool>(M));
        vector<int> row(M), col(N);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 'W') continue;
                row[i]++;
                col[j]++;
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = i + 1; j < M; ++j) {
                int k = 0;
                for (; k < N; ++k) {
                    if (A[i][k] != A[j][k]) break;
                }
                same[i][j] = same[j][i] = k == N;
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 'W' || row[i] != target || col[j] != target) continue;
                int k = 0;
                for (; k < M; ++k) {
                    if (k == i || A[k][j] == 'W') continue;
                    if (!same[i][k]) break;
                }
                ans += k == M;
            }
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/lonely-pixel-ii
// Author: github.com/lzl124631x
// Time: O(M * N^2)
// Space: O(MN)
class Solution {
public:
    int findBlackPixel(vector<vector<char>>& A, int target) {
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<string> B;
        for (auto &r : A) B.emplace_back(begin(r), end(r));
        vector<int> row(M), col(N);
        unordered_map<string, int> m;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (B[i][j] == 'W') continue;
                ++row[i];
                ++col[j];
            }
            ++m[B[i]];
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (B[i][j] == 'W' || row[i] != target || col[j] != target || m[B[i]] != target) continue;
                ++ans;
            }
        }
        return ans;
    }
};
```