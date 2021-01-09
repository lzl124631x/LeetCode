# [646. Maximum Length of Pair Chain (Medium)](https://leetcode.com/problems/maximum-length-of-pair-chain/)

<p>
You are given <code>n</code> pairs of numbers. In every pair, the first number is always smaller than the second number.
</p>

<p>
Now, we define a pair <code>(c, d)</code> can follow another pair <code>(a, b)</code> if and only if <code>b &lt; c</code>. Chain of pairs can be formed in this fashion. 
</p>

<p>
Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.
</p>


<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> [[1,2], [2,3], [3,4]]
<b>Output:</b> 2
<b>Explanation:</b> The longest chain is [1,2] -&gt; [3,4]
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>The number of given pairs will be in the range [1, 1000].</li>
</ol>
<p></p>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/longest-increasing-subsequence/)
* [Increasing Subsequences (Medium)](https://leetcode.com/problems/increasing-subsequences/)

## Solution 1. DP

First sort the array in ascending order.

Let `dp[i]` be the length of maximum chain formed using a subsequence of `A[0..i]` where `A[i]` must be used.

```
dp[i] = max(1, max(1 + dp[j] | pair j can go after pair i ))
```

```cpp
// OJ: https://leetcode.com/problems/maximum-length-of-pair-chain/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int findLongestChain(vector<vector<int>>& A) {
        sort(begin(A), end(A));
        int N = A.size();
        vector<int> dp(N, 1);
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (A[j][1] >= A[i][0]) continue;
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        return *max_element(begin(dp), end(dp));
    }
};
```

## Solution 3. Interval Scheduling Maximization (ISM)

```cpp
// OJ: https://leetcode.com/problems/maximum-length-of-pair-chain/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int findLongestChain(vector<vector<int>>& A) {
        sort(begin(A), end(A), [](auto &a, auto &b) { return a[1] < b[1]; });
        int e = INT_MIN, ans = 0;
        for (auto &v : A) {
            if (e >= v[0]) continue;
            e = v[1];
            ++ans;
        }
        return ans;
    }
};
```