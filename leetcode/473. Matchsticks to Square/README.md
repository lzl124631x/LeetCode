# [473. Matchsticks to Square (Medium)](https://leetcode.com/problems/matchsticks-to-square/)

<p>Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks. You should not break any stick, but you can link them up, and each matchstick must be used <b>exactly</b> one time.</p>

<p> Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> [1,1,2,2,2]
<b>Output:</b> true

<b>Explanation:</b> You can form a square with length 2, one side of the square came two sticks with length 1.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> [3,3,3,3,4]
<b>Output:</b> false

<b>Explanation:</b> You cannot find a way to form a square with all the matchsticks.
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>The length sum of the given matchsticks is in the range of <code>0</code> to <code>10^9</code>.
</li><li>The length of the given matchstick array will not exceed <code>15</code>.</li>
</ol>
<p></p>

**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/)

## Solution 1. Dynamic Programming on Subsets

```cpp
// OJ: https://leetcode.com/problems/matchsticks-to-square/
// Author: github.com/lzl124631x
// Time: O(N * 2^N)
// Space: O(2^N)
class Solution {
    vector<int> dp;
    bool dfs(vector<int> &A, int used, int todo, int target) {
        if (dp[used] != -1) return dp[used];
        dp[used] = 0;
        int mx = todo % target;
        if (mx == 0) mx = target;
        for (int i = 0; i < A.size() && !dp[used]; ++i) {
            dp[used] = ((used >> i) & 1) == 0 && A[i] <= mx && dfs(A, used | (1 << i), todo - A[i], target);
        }
        return dp[used];
    }
public:
    bool makesquare(vector<int>& A) {
        if (A.empty()) return false;
        int len = accumulate(begin(A), end(A), 0);
        if (len % 4 || *max_element(begin(A), end(A)) > len / 4) return false;
        dp.assign(1 << A.size(), -1);
        dp[(1 << A.size()) - 1] = 1;
        return dfs(A, 0, len, len / 4);
    }
};
```