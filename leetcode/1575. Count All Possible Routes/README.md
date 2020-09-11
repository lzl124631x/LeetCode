# [1575. Count All Possible Routes (Hard)](https://leetcode.com/problems/count-all-possible-routes/)

<p>You are given an array of <strong>distinct</strong> positive integers locations&nbsp;where <code>locations[i]</code> represents the position of city <code>i</code>. You are also given&nbsp;integers&nbsp;<code>start</code>,&nbsp;<code>finish</code>&nbsp;and&nbsp;<code>fuel</code>&nbsp;representing the starting city, ending city, and the initial amount of fuel you have, respectively.</p>

<p>At each step, if you are at city&nbsp;<code>i</code>, you can pick any city&nbsp;<code>j</code>&nbsp;such that <code>j != i</code>&nbsp;and&nbsp;<code>0 &lt;= j &lt; locations.length</code>&nbsp;and move to city <code>j</code>.&nbsp;Moving from city <code>i</code> to city <code>j</code> reduces the amount of fuel you have by&nbsp;<code>|locations[i] - locations[j]|</code>.&nbsp;Please notice that <code>|x|</code>&nbsp;denotes the absolute value of <code>x</code>.</p>

<p>Notice that&nbsp;<code>fuel</code>&nbsp;<strong>cannot</strong> become negative at any point in time, and that you are <strong>allowed</strong> to visit any city more than once (including <code>start</code>&nbsp;and&nbsp;<code>finish</code>).</p>

<p>Return <em>the count of all possible routes from&nbsp;</em><code>start</code>&nbsp;<em>to</em>&nbsp;<code>finish</code>.</p>

<p>Since the answer&nbsp;may be too large,&nbsp;return it modulo&nbsp;<code>10^9 + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> locations = [2,3,6,8,4], start = 1, finish = 3, fuel = 5
<strong>Output:</strong> 4
<strong>Explanation:</strong>&nbsp;The following are all possible routes, each uses 5 units of fuel:
1 -&gt; 3
1 -&gt; 2 -&gt; 3
1 -&gt; 4 -&gt; 3
1 -&gt; 4 -&gt; 2 -&gt; 3
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> locations = [4,3,1], start = 1, finish = 0, fuel = 6
<strong>Output:</strong> 5
<strong>Explanation: </strong>The following are all possible routes:
1 -&gt; 0, used fuel = 1
1 -&gt; 2 -&gt; 0, used fuel = 5
1 -&gt; 2 -&gt; 1 -&gt; 0, used fuel = 5
1 -&gt; 0 -&gt; 1 -&gt; 0, used fuel = 3
1 -&gt; 0 -&gt; 1 -&gt; 0 -&gt; 1 -&gt; 0, used fuel = 5
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> locations = [5,2,1], start = 0, finish = 2, fuel = 3
<strong>Output:</strong> 0
<b>Explanation: </b>It's impossible to get from 0 to 2 using only 3 units of fuel since the shortest route needs 4 units of fuel.</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> locations = [2,1,5], start = 0, finish = 0, fuel = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong>&nbsp;There are two possible routes, 0 and 0 -&gt; 1 -&gt; 0.</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> locations = [1,2,3], start = 0, finish = 2, fuel = 40
<strong>Output:</strong> 615088286
<strong>Explanation: </strong>The total number of possible routes is 2615088300. Taking this number modulo 10^9 + 7 gives us 615088286.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= locations.length &lt;= 100</code></li>
	<li><code>1 &lt;= locations[i] &lt;= 10^9</code></li>
	<li>All integers in&nbsp;<code>locations</code>&nbsp;are&nbsp;<strong>distinct</strong>.</li>
	<li><code>0 &lt;= start, finish &lt;&nbsp;locations.length</code></li>
	<li><code><font face="monospace">1 &lt;= fuel &lt;= 200</font></code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. Top-down DP

Let `dp[i][j]` be the count of all possible routes from city `i` with `j` fuel to city `finish`.

The initial state is `dp[start][fuel]`.

Assume we can go from city `i` to city `k`, `dp[i][j] += dp[k][j - dist(i, k)]`.

When `i == finish` and `j >= 0`, we should add `1` to `dp[i][j]`.

```
dp[i][j] = sum( dp[k][j - dist[i, k]] | j - dist[i, k] >= 0 )
            + (i == start ? 1 : 0)
```

`dp[start][fuel]` is the answer.

```cpp
// OJ: https://leetcode.com/problems/count-all-possible-routes/
// Author: github.com/lzl124631x
// Time: O(N^2 * F)
// Space: O(NF)
class Solution {
    long dp[101][201] = {}, mod = 1e9+7, finish;
    int dist(vector<int> &A, int a, int b) {
        return abs(A[a] - A[b]);
    }
    int dfs(vector<int> &A, int start, int fuel) {
        if (dp[start][fuel]) return dp[start][fuel];
        long ans = 0;
        if (start == finish) ans++;
        for (int i = 0; i < A.size(); ++i) {
            if (i == start || dist(A, start, i) + dist(A, i, finish) > fuel) continue;
            ans = (ans + dfs(A, i, fuel - dist(A, i, start))) % mod;
        }
        return dp[start][fuel] = ans;
    }
public:
    int countRoutes(vector<int>& A, int start, int finish, int fuel) {
        this->finish = finish;
        return dfs(A, start, fuel);
    }
};
```

## Solution 2.

`left[i][f]`: the count of routes whose last move is leftwards to location `i` with `f` fuel

`right[i][f]`: the count of routes whose last move is rightwards to location `i` with `f` fuel

```
left[j][f] = left[j+1][f-d(j, j+1)] + right[j+1][f-d(j, j+1)] // go to j + 1 first then j
            + left[j+2][f-d(j, j+2)] + right[j+2][f-d(j, j+2)] // go to j + 2 first then j
            + ...
            + left[j+k][f-d(j, j+k)] + right[j+k][f-d(j, j+2)] // go to j + k first then j
```

We can apply this equation recursively so that all the `left` are replaced with `right` in the right side of the equation.

```
left[j][f] = right[j+1][f-d(j, j+1)]
            + 2 * right[j+2][f-d(j, j+2)]
            + ...
            + 2^(k-1) * right[j+k][f-d(j, j+k)]
```

In the righthand-side, the 2nd to last terms can be expressed as `2 * left[j+1][f-d(j, j+1)]` because

```
left[j+1][f] = right[j+2][f-d(j+1, j+2)]
              + 2 * right[j+3][f-d(j+1, j+3)]
              + ...
              + 2^(k-2) * right[j+1+k-1][f-d(j+1, j+1+k-1)]

left[j+1][f-d(j, j+1)] = right[j+2][f-d(j, j+2)]
                        + 2 * right[j+3][f-d(j, j+3)]
                        + ...
                        + 2^(k-2) * right[j+k][f-d(j, j+k)]
```

So we have this equation
```
left[j][f] = right[j+1][f-d(j, j+1)] + 2 * left[j+1][f-d(j, j+1)]
```

Symmetrically, we have

```
right[j][f] = left[j-1][f-d(j, j-1)] + 2 * right[j-1][f-d(j, j-1)]
```

```cpp
// OJ: https://leetcode.com/problems/count-all-possible-routes/
// Author: github.com/lzl124631x
// Time: O(NlogN + NF)
// Space: O(NF)
class Solution {
public:
    int countRoutes(vector<int>& A, int start, int finish, int fuel) {
        int mod = 1e9+7, s = A[start], f = A[finish];
        sort(begin(A), end(A));
        start = lower_bound(begin(A), end(A), s) - begin(A);
        finish = lower_bound(begin(A), end(A), f) - begin(A);
        vector<vector<int>> left(A.size(), vector<int>(fuel + 1));
        vector<vector<int>> right(A.size(), vector<int>(fuel + 1));
        for (int f = 1; f <= fuel; ++f) {
            for (int j = 0; j < A.size() - 1; ++j) {
                int d = A[j + 1] - A[j];
                if (f > d) left[j][f] = (right[j + 1][f - d] + 2 * left[j + 1][f - d] % mod) % mod;
                else if (f == d) left[j][f] = j + 1 == start;
            }
            for (int j = 1; j < A.size(); ++j) {
                int d = A[j] - A[j - 1];
                if (f > d) right[j][f] = (left[j - 1][f - d] + 2 * right[j - 1][f - d] % mod) % mod;
                else if (f == d) right[j][f] = j - 1 == start;
            }
        }
        int ans = start == finish;
        for (int f = 1; f <= fuel; ++f) ans = ((ans + left[finish][f]) % mod + right[finish][f]) % mod;
        return ans;
    }
};
```