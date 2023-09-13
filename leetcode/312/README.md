# [312. Burst Balloons (Hard)](https://leetcode.com/problems/burst-balloons/)

<p>Given <code>n</code> balloons, indexed from <code>0</code> to <code>n-1</code>. Each balloon is painted with a number on it represented by array <code>nums</code>. You are asked to burst all the balloons. If the you burst balloon <code>i</code> you will get <code>nums[left] * nums[i] * nums[right]</code> coins. Here <code>left</code> and <code>right</code> are adjacent indices of <code>i</code>. After the burst, the <code>left</code> and <code>right</code> then becomes adjacent.</p>

<p>Find the maximum coins you can collect by bursting the balloons wisely.</p>

<p><b>Note:</b></p>

<ul>
	<li>You may imagine <code>nums[-1] = nums[n] = 1</code>. They are not real therefore you can not burst them.</li>
	<li>0 ≤ <code>n</code> ≤ 500, 0 ≤ <code>nums[i]</code> ≤ 100</li>
</ul>

<p><b>Example:</b></p>

<pre><b>Input:</b> <code>[3,1,5,8]</code>
<b>Output:</b> <code>167 
<strong>Explanation: </strong></code>nums = [3,1,5,8] --&gt; [3,5,8] --&gt;   [3,8]   --&gt;  [8]  --&gt; []
&nbsp;            coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
</pre>

**Related Topics**:  
[Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Minimum Cost to Merge Stones (Hard)](https://leetcode.com/problems/minimum-cost-to-merge-stones/)

## Solution 1. DP

Let `dp[i][j]` be the result of the subproblem in range `A[i..j]` and balloons out side of this range are untouched.

If we think in the forward manner, i.e. picking which balloon to burst first, we won't be able to reuse the result of the subproblem.

For example, for `A[i..j]`, if we try bursting `A[i]`, then the balloon to the left of `A[i+1]` becomes `A[i-1]`, but `dp[i+1][j]` is computed assuming `A[i]` is in front of `A[i+1]`.

In order to reuse the result of subproblem, we try to think backwards.

For `A[i..j]`, pick one that we burst lastly.

Assume we pick some `i <= k <= j`, and the array is separated into `A[i][k-1]` and `A[k+1][j]`. And for these two subproblems we can safely use `dp[i][k-1]` and `dp[k+1][j]`, because `A[i-1]`, `A[k]` and `A[j+1]` are guaranteed to be bursted after balloons in those two subarrays.

```
dp[i][j] = max( dp[i][k-1] + A[i-1]*A[k]*A[j+1] + dp[k+1][j] | i <= k <= j )
```

The answer is `dp[0][N - 1]`

```cpp
// OJ: https://leetcode.com/problems/burst-balloons/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
    int maxCoins(vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size();
        vector<vector<int>> dp(N, vector<int>(N));
        for (int i = 0; i < N; ++i) dp[i][i] = (i - 1 < 0 ? 1 : A[i - 1]) * A[i] * (i + 1 >= N ? 1 : A[i + 1]);
        for (int i = N - 2; i >= 0; --i) {
            for (int j = i + 1; j < N; ++j) {
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j],
                                   (k - 1 < i ? 0 : dp[i][k - 1])
                                   + (i - 1 < 0 ? 1 : A[i - 1]) * A[k] * (j + 1 >= N ? 1 : A[j + 1])
                                   + (k + 1 > j ? 0 : dp[k + 1][j]));
                }
            }
        }
        return dp[0][N - 1];
    }
};
```

## Solution 2. DP

Same idea as Solution 1, expect that we add `1` to both sides of `A`.

Then we can define `dp[i][j]` be the answer of the subproblem in range `A[(i+1)..(j-1)]`, i.e. not bursting `A[i]` and `A[j]`.

In this way we can simplify the code.

```cpp
// OJ: https://leetcode.com/problems/burst-balloons/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
    int maxCoins(vector<int>& A) {
        A.insert(A.begin(), 1);
        A.push_back(1);
        int N = A.size();
        vector<vector<int>> dp(N, vector<int>(N));
        for (int i = N - 2; i >= 0; --i) {
            for (int j = i + 1; j < N; ++j) {
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + A[i] * A[k] * A[j] + dp[k][j]);
                }
            }
        }
        return dp[0][N - 1];
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/burst-balloons/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
    int maxCoins(vector<int>& A) {
        A.insert(begin(A), 1);
        A.push_back(1);
        int N = A.size();
        vector<vector<int>> dp(N, vector<int>(N));
        for (int len = 1; len <= N; ++len) {
            for (int i = 1; i < N - len; ++i) {
                int j = i + len - 1;
                for (int k = i; k <= j; ++k) dp[i][j] = max(dp[i][j], A[i - 1] * A[k] * A[j + 1] + dp[i][k - 1] + dp[k + 1][j]);
            }
        }
        return dp[1][N - 2];
    }
};
``