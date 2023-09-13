# [403. Frog Jump (Hard)](https://leetcode.com/problems/frog-jump)

<p>A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.</p>
<p>Given a list of <code>stones</code>' positions (in units) in sorted <strong>ascending order</strong>, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be <code>1</code> unit.</p>
<p>If the frog's last jump was <code>k</code> units, its next jump must be either <code>k - 1</code>, <code>k</code>, or <code>k + 1</code> units. The frog can only jump in the forward direction.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> stones = [0,1,3,5,6,8,12,17]
<strong>Output:</strong> true
<strong>Explanation:</strong> The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> stones = [0,1,2,3,4,8,9,11]
<strong>Output:</strong> false
<strong>Explanation:</strong> There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>2 &lt;= stones.length &lt;= 2000</code></li>
	<li><code>0 &lt;= stones[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>stones[0] == 0</code></li>
	<li><code>stones</code>&nbsp;is sorted in a strictly increasing order.</li>
</ul>

**Companies**:
[PhonePe](https://leetcode.com/company/phonepe), [Adobe](https://leetcode.com/company/adobe), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Minimum Sideway Jumps (Medium)](https://leetcode.com/problems/minimum-sideway-jumps/)
* [Solving Questions With Brainpower (Medium)](https://leetcode.com/problems/solving-questions-with-brainpower/)
* [Maximum Number of Jumps to Reach the Last Index (Medium)](https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/)

## Solution 1. DP Top-down

Let `dp[i][k]` be whether we can reach `A[N-1]` from `A[i]` with `k` as the units of the last jump

```
dp[i][k] = OR( dp[f(i, k+j)][k+j] )
        where j = -1,0,1 for i > 0; j = 0 for i == 0
        where f(i, k) is the index that satisfies A[f(i,k)] = A[i] + k

dp[N-1][k] = true
```

The answer is `dp[0][1]`.

We just need to memoize the unreachable states.

```cpp
// OJ: https://leetcode.com/problems/frog-jump/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    bool canCross(vector<int>& A) {
        int N = A.size();
        vector<unordered_set<int>> m(N);
        function<bool(int, int)> dp = [&](int i, int k) {
            if (i == N - 1) return true;
            if (m[i].count(k)) return false;
            int from = i == 0 ? 1 : k - 1, to = i == 0 ? 1 : k + 1;
            for (int j = from; j <= to; ++j) {
                int index = lower_bound(begin(A) + i + 1, end(A), A[i] + j) - begin(A);
                if (index < N && A[index] == A[i] + j) {
                    if (dp(index, j)) return true;
                }
            }
            m[i].insert(k);
            return false;
        };
        return dp(0, 1);
    }
};
```