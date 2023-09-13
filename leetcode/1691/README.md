# [1691. Maximum Height by Stacking Cuboids  (Hard)](https://leetcode.com/problems/maximum-height-by-stacking-cuboids/)

<p>Given <code>n</code> <code>cuboids</code> where the dimensions of the <code>i<sup>th</sup></code> cuboid is <code>cuboids[i] = [width<sub>i</sub>, length<sub>i</sub>, height<sub>i</sub>]</code> (<strong>0-indexed</strong>). Choose a <strong>subset</strong> of <code>cuboids</code> and place them on each other.</p>

<p>You can place cuboid <code>i</code> on cuboid <code>j</code> if <code>width<sub>i</sub> &lt;= width<sub>j</sub></code> and <code>length<sub>i</sub> &lt;= length<sub>j</sub></code> and <code>height<sub>i</sub> &lt;= height<sub>j</sub></code>. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.</p>

<p>Return <em>the <strong>maximum height</strong> of the stacked</em> <code>cuboids</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/10/21/image.jpg" style="width: 420px; height: 299px;"></strong></p>

<pre><strong>Input:</strong> cuboids = [[50,45,20],[95,37,53],[45,23,12]]
<strong>Output:</strong> 190
<strong>Explanation:</strong>
Cuboid 1 is placed on the bottom with the 53x37 side facing down with height 95.
Cuboid 0 is placed next with the 45x20 side facing down with height 50.
Cuboid 2 is placed next with the 23x12 side facing down with height 45.
The total height is 95 + 50 + 45 = 190.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> cuboids = [[38,25,45],[76,35,3]]
<strong>Output:</strong> 76
<strong>Explanation:</strong>
You can't place any of the cuboids on the other.
We choose cuboid 1 and rotate it so that the 35x3 side is facing down and its height is 76.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> cuboids = [[7,11,17],[7,17,11],[11,7,17],[11,17,7],[17,7,11],[17,11,7]]
<strong>Output:</strong> 102
<strong>Explanation:</strong>
After rearranging the cuboids, you can see that all cuboids have the same dimension.
You can place the 11x7 side down on all cuboids so their heights are 17.
The maximum height of stacked cuboids is 6 * 17 = 102.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == cuboids.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= width<sub>i</sub>, length<sub>i</sub>, height<sub>i</sub> &lt;= 100</code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Sort](https://leetcode.com/tag/sort/)

## Solution 1. Top-down DP

We firstly sort the edges of each cuboid in descending order so that we can use its first edge as its height. (See proof below)

We say cuboid `x` is `greaterThan` than cuboid `y` if `x[0] >= y[0] && x[1] >= y[1] && x[2] >= y[2]`.

Let `dp[i]` be the maximum height of stack we can get with `cuboids[i]` at the bottom.

```
dp[i] = cuboids[i][0] + max( dp[j] | 0 <= j < N && i != j && A[i] is greater than A[j] )
```

The answer is the maximum value of the `dp` values.

### Time complexity

Sorting the edges of all cuboids takes `O(N)` time.

For the DP part, each `0 <= i < N` is only visited once. Each visit takes `O(N)` time. So the time complexity of this top-down DP is `O(N^2)`.

So overall the time complexity is `O(N^2)`.

```cpp
// OJ: https://leetcode.com/problems/maximum-height-by-stacking-cuboids/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
    vector<int> dp;
    int N;
    bool greaterThan(vector<vector<int>> &A, int i, int j) {
        return A[i][0] >= A[j][0] && A[i][1] >= A[j][1] && A[i][2] >= A[j][2];
    }
    int dfs(vector<vector<int>> &A, int i) {
        if (dp[i] != -1) return dp[i];
        dp[i] = 0;
        int ans = 0;
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            if (greaterThan(A, i, j)) ans = max(ans, dfs(A, j));
        }
        return dp[i] = A[i][0] + ans;
    }
public:
    int maxHeight(vector<vector<int>>& A) {
        for (auto &c : A) sort(begin(c), end(c), greater<>());
        N = A.size();
        dp.assign(N, -1);
        for (int i = 0; i < N; ++i) dfs(A, i);
        return *max_element(begin(dp), end(dp));
    }
};
```

---

Is it possible that in the optimal solution, one cuboid is not placed with its longest edge as height? No, we can prove that this is impossible

Proof: assume in the optimal solution one cuboid `x` is not placed with its longest edge as height. For the cuboid `y` below `x`, all edges of `y` must be greater than `x`. So we can flip both `x` and `y` and all cuboids below such that their longest edges are placed as their height. The same for the cuboids above `x`.