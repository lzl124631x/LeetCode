# [1959. Minimum Total Space Wasted With K Resizing Operations (Medium)](https://leetcode.com/problems/minimum-total-space-wasted-with-k-resizing-operations/)

<p>You are currently designing a dynamic array. You are given a <strong>0-indexed</strong> integer array <code>nums</code>, where <code>nums[i]</code> is the number of elements that will be in the array at time <code>i</code>. In addition, you are given an integer <code>k</code>, the <strong>maximum</strong> number of times you can <strong>resize</strong> the array (to<strong> any</strong> size).</p>

<p>The size of the array at time <code>t</code>, <code>size<sub>t</sub></code>, must be at least <code>nums[t]</code> because there needs to be enough space in the array to hold all the elements. The <strong>space wasted</strong> at&nbsp;time <code>t</code> is defined as <code>size<sub>t</sub> - nums[t]</code>, and the <strong>total</strong> space wasted is the <strong>sum</strong> of the space wasted across every time <code>t</code> where <code>0 &lt;= t &lt; nums.length</code>.</p>

<p>Return <em>the <strong>minimum</strong> <strong>total space wasted</strong> if you can resize the array at most</em> <code>k</code> <em>times</em>.</p>

<p><strong>Note:</strong> The array can have <strong>any size</strong> at the start and does<strong> not </strong>count towards the number of resizing operations.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [10,20], k = 0
<strong>Output:</strong> 10
<strong>Explanation:</strong> size = [20,20].
We can set the initial size to be 20.
The total wasted space is (20 - 10) + (20 - 20) = 10.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [10,20,30], k = 1
<strong>Output:</strong> 10
<strong>Explanation:</strong> size = [20,20,30].
We can set the initial size to be 20 and resize to 30 at time 2. 
The total wasted space is (20 - 10) + (20 - 20) + (30 - 30) = 10.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [10,20,15,30,20], k = 2
<strong>Output:</strong> 15
<strong>Explanation:</strong> size = [10,20,20,30,30].
We can set the initial size to 10, resize to 20 at time 1, and resize to 30 at time 3.
The total wasted space is (10 - 10) + (20 - 20) + (20 - 15) + (30 - 30) + (30 - 20) = 15.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 200</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>0 &lt;= k &lt;= nums.length - 1</code></li>
</ul>


**Companies**:  
[Media.net](https://leetcode.com/company/medianet)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. Bottom-up DP

First, consider the case where we can't use any resize. The array must be initialized with size `max(A, i, j)`, where `max(A, i, j) = max( A[i], A[i+1], ..., A[j] )`.

Let `wasted[i][j]` be the min space wasted on `A[i..j]` without any resize. (`0 <= i <= j < N`)

```
wasted[i][j] = max(A, i, j) * (j - i + 1) - sum(A, i, j) 
        where max(A, i, j) = max(A[i], A[i+1], ..., A[j]) and sum(A, i, j) = A[i] + A[i+1] + ... + A[j]
```

Now, consider the normal case:

Let `dp[k][i+1]` be the min space wasted on `A[0..i]` and `k` resize used (`0 <= i < N, 0 <= k <= K`)

For `k = 0` and `0 <= i < N`, `dp[0][i+1] = wasted[0][i]`

For `1 <= k <= K` and `0 <= i < N`:
```
dp[k][i+1] = min( dp[k-1][t] + wasted[t][i] | 0 <= t <= i )
dp[k][0] = 0
```
  
The answer is `dp[K][N]`.

```cpp
// OJ: https://leetcode.com/problems/minimum-total-space-wasted-with-k-resizing-operations/
// Author: github.com/lzl124631x
// Time: O(N^2 * K)
// Space: O(N^2 + NK)
class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& A, int K) {
        int N = A.size(), wasted[201][201] = {}, dp[201][201] = {};
        memset(dp, 0x3f, sizeof(dp));
        for (int i = 0; i < N; ++i) {
            int mx = 0, sum = 0;
            for (int j = i; j < N; ++j) {
                mx = max(mx, A[j]);
                sum += A[j];
                wasted[i][j] = mx * (j - i + 1) - sum;
            }
            dp[0][i + 1] = wasted[0][i];
        }
        for (int k = 0; k <= K; ++k) dp[k][0] = 0;
        for (int k = 1; k <= K; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int t = 0; t <= i; ++t) {
                    dp[k][i + 1] = min(dp[k][i + 1], dp[k - 1][t] + wasted[t][i]);
                }
            }
        }
        return dp[K][N];
    }
};
```

## Solution 2. Bottom-up DP with Space Optimization

Since `dp[k][i+1]` only depends on value in the previous row, we can reduce space of `dp` from `O(NK)` to `O(N)`.

```cpp
// OJ: https://leetcode.com/problems/minimum-total-space-wasted-with-k-resizing-operations/
// Author: github.com/lzl124631x
// Time: O(N^2 * K)
// Space: O(N^2)
class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& A, int K) {
        int N = A.size(), wasted[201][201] = {}, dp[201] = {};
        for (int i = 0; i < N; ++i) {
            int mx = 0, sum = 0;
            for (int j = i; j < N; ++j) {
                mx = max(mx, A[j]);
                sum += A[j];
                wasted[i][j] = mx * (j - i + 1) - sum;
            }
            dp[i + 1] = wasted[0][i];
        }
        for (int k = 1; k <= K; ++k) {
            for (int i = N - 1; i >= 0; --i) {
                for (int t = i; t >= 0; --t) {
                    dp[i + 1] = min(dp[i + 1], dp[t] + wasted[t][i]);
                }
            }
        }
        return dp[N];
    }
};
```

Also, we can calculate `wasted` values on the fly to save space.

```cpp
// OJ: https://leetcode.com/problems/minimum-total-space-wasted-with-k-resizing-operations/
// Author: github.com/lzl124631x
// Time: O(N^2 * K)
// Space: O(N)
class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& A, int K) {
        int N = A.size(), dp[201] = {};
        for (int k = 0; k <= K; ++k) {
            for (int i = N - 1; i >= 0; --i) {
                int mx = 0, sum = 0, wasted = 0;
                for (int t = i; t >= 0; --t) {
                    mx = max(mx, A[t]);
                    sum += A[t];
                    wasted = mx * (i - t + 1) - sum;
                    if (k > 0) dp[i + 1] = min(dp[i + 1], dp[t] + wasted);
                }
                if (k == 0) dp[i + 1] = wasted;
            }
        }
        return dp[N];
    }
};
```

## Solution 3. Top-down DP

Let `dp[i][k]` be the min space wasted on `A[i..(N-1)]` and `k` resizes available.

```cpp
// OJ: https://leetcode.com/problems/minimum-total-space-wasted-with-k-resizing-operations/
// Author: github.com/lzl124631x
// Time: O(N^2 * K)
// Space: O(NK)
class Solution {
    int m[201][201] = {}, N, INF = 0x3f3f3f3f;
    int dp(vector<int> &A, int i, int k) {
        if (i == N) return 0;
        if (k < 0) return INF; 
        if (m[i][k] != -1) return m[i][k];
        int mx = 0, sum = 0, val = INF;
        for (int j = i; j < N; ++j) {
            mx = max(mx, A[j]);
            sum += A[j];
            int wasted = mx * (j - i + 1) - sum;
            val = min(val, wasted + dp(A, j + 1, k - 1));
        }
        return m[i][k] = val;
    }
public:
    int minSpaceWastedKResizing(vector<int>& A, int k) {
        N = A.size();
        memset(m, -1, sizeof(m));
        return dp(A, 0, k);
    }
};
```

Or let `dp[i][k]` be the min space wasted on `A[0..(i-1)]` and `k` resizes available

```cpp
// OJ: https://leetcode.com/problems/minimum-total-space-wasted-with-k-resizing-operations/
// Author: github.com/lzl124631x
// Time: O(N^2 * K)
// Space: O(NK)
class Solution {
    int m[201][201] = {}, N, INF = 0x3f3f3f3f;
    int dp(vector<int> &A, int i, int k) {
        if (i == 0) return 0;
        if (k < 0) return INF; 
        if (m[i][k] != -1) return m[i][k];
        int mx = 0, sum = 0, val = INF;
        for (int j = i - 1; j >= 0; --j) {
            mx = max(mx, A[j]);
            sum += A[j];
            int wasted = mx * (i - j) - sum;
            val = min(val, dp(A, j, k - 1) + wasted);
        }
        return m[i][k] = val;
    }
public:
    int minSpaceWastedKResizing(vector<int>& A, int k) {
        N = A.size();
        memset(m, -1, sizeof(m));
        return dp(A, N, k);
    }
};
```