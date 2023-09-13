# [1840. Maximum Building Height (Hard)](https://leetcode.com/problems/maximum-building-height/)

<p>You want to build <code>n</code> new buildings in a city. The new buildings will be built in a line and are labeled from <code>1</code> to <code>n</code>.</p>

<p>However, there are city restrictions on the heights of the new buildings:</p>

<ul>
	<li>The height of each building must be a non-negative integer.</li>
	<li>The height of the first building <strong>must</strong> be <code>0</code>.</li>
	<li>The height difference between any two adjacent buildings <strong>cannot exceed</strong> <code>1</code>.</li>
</ul>

<p>Additionally, there are city restrictions on the maximum height of specific buildings. These restrictions are given as a 2D integer array <code>restrictions</code> where <code>restrictions[i] = [id<sub>i</sub>, maxHeight<sub>i</sub>]</code> indicates that building <code>id<sub>i</sub></code> must have a height <strong>less than or equal to</strong> <code>maxHeight<sub>i</sub></code>.</p>

<p>It is guaranteed that each building will appear <strong>at most once</strong> in <code>restrictions</code>, and building <code>1</code> will <strong>not</strong> be in <code>restrictions</code>.</p>

<p>Return <em>the <strong>maximum possible height</strong> of the <strong>tallest</strong> building</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/08/ic236-q4-ex1-1.png" style="width: 400px; height: 253px;">
<pre><strong>Input:</strong> n = 5, restrictions = [[2,1],[4,1]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The green area in the image indicates the maximum allowed height for each building.
We can build the buildings with heights [0,1,2,1,2], and the tallest building has a height of 2.</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/08/ic236-q4-ex2.png" style="width: 500px; height: 269px;">
<pre><strong>Input:</strong> n = 6, restrictions = []
<strong>Output:</strong> 5
<strong>Explanation:</strong> The green area in the image indicates the maximum allowed height for each building.
We can build the buildings with heights [0,1,2,3,4,5], and the tallest building has a height of 5.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/08/ic236-q4-ex3.png" style="width: 500px; height: 187px;">
<pre><strong>Input:</strong> n = 10, restrictions = [[5,3],[2,5],[7,4],[10,3]]
<strong>Output:</strong> 5
<strong>Explanation:</strong> The green area in the image indicates the maximum allowed height for each building.
We can build the buildings with heights [0,1,2,3,3,4,4,5,4,3], and the tallest building has a height of 5.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= restrictions.length &lt;= min(n - 1, 10<sup>5</sup>)</code></li>
	<li><code>2 &lt;= id<sub>i</sub> &lt;= n</code></li>
	<li><code>id<sub>i</sub></code>&nbsp;is <strong>unique</strong>.</li>
	<li><code>0 &lt;= maxHeight<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
</ul>


**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. Filter Critical Restrictions

We should remove the useless restrictions and only keep the critical ones.

### Step 1. Remove Useless Restrictions

Put all the restrictions into a `m` which is a map from the `x` value to the height restriction. Note that `m[1] = 0` should also be added.

Scan from left to right, assume two consecutive restrictions are `a = [x1, h1]` and `b = [x2, h2]` (`x1 < x2`). If `h2 >= h1 + x2 - x1`, `b` is useless and should be removed.

Scan from right to left, assume two consecutive restrictions are `a = [x1, h1]` and `b = [x2, h2]` (`x1 < x2`). If `h1 >= h2 + x2 - x1`, `a` is useless and should be removed.

### Step 2. Calculate the max heights we can get between two consecutive restrictions

For two consecutive restrictions are `a = [x1, h1]` and `b = [x2, h2]` (`x1 < x2`), assume the tallest building between them is at position `x`, then one of the following is is true:

* When there is only one tallest building, `h1 + x - x1 == h2 + x2 - x`, so `2 * x = h2 - h1 + x1 + x2`
* When there are two tallest buildings, `h1 + x - x1 == h2 + x2 - x - 1`, so `2 * x = h2 - h1 + x1 + x2 - 1`.

So `x = ceil( (h2 - h1 + x1 + x2) / 2 )`, and the corresponding height is `h1 + x - x1`.

One special case is the last restriction `[x, h]`. The height we can get using it is `h + n - x`.

```cpp
// OJ: https://leetcode.com/problems/maximum-building-height/
// Author: github.com/lzl124631x
// Time: O(RlogR)
// Space: O(R)
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& A) {
        map<long, long> m{{1,0}};
        for (auto &v : A) m[v[0]] = v[1];
        long ans = 0;
        for (auto it = next(begin(m)); it != end(m);) {
            auto [x1, h1] = *prev(it);
            auto [x2, h2] = *it;
            if (h2 >= h1 + x2 - x1) {
                it = m.erase(it);
            } else {
                it = next(it);
            }
        }
        for (auto it = prev(end(m)); it != begin(m);) {
            auto [x1, h1] = *prev(it);
            auto [x2, h2] = *it;
            if (h1 >= h2 + x2 - x1) {
                m.erase(prev(it));
            } else {
                it = prev(it);
            }
        }
        for (auto it = next(begin(m)); it != end(m); ++it) {
            auto [x1, h1] = *prev(it);
            auto [x2, h2] = *it;
            long x = (h2 - h1 + x1 + x2) / 2;
            ans = max(ans, h1 + x - x1);
        }
        auto [x, h] = *rbegin(m);
        ans = max(ans, h + n - x);
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/maximum-building-height/
// Author: github.com/lzl124631x
// Time: O(RlogR)
// Space: O(1)
// Ref: https://leetcode.com/problems/maximum-building-height/discuss/1175047/PythonC%2B%2B-greedy-solution-with-visual-explanation-O(MlogM)
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& A) {
        A.push_back({1, 0});
        sort(begin(A), end(A));
        int N = A.size(), ans = 0;
        for (int i = 1; i < N; ++i) {
            int x1 = A[i - 1][0], h1 = A[i - 1][1];
            int x2 = A[i][0], &h2 = A[i][1];
            h2 = min(h2, h1 + x2 - x1);
        }
        for (int i = N - 2; i >= 0; --i) {
            int x1 = A[i][0], &h1 = A[i][1];
            int x2 = A[i + 1][0], h2 = A[i + 1][1];
            h1 = min(h1, h2 + x2 - x1);
            int mid = (h2 - h1 + x1 + x2) / 2;
            ans = max(ans, h1 + mid - x1);
        }
        return max(ans, A.back()[1] + n - A.back()[0]);
    }
};
```