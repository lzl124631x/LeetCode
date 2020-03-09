# [213. House Robber II (Medium)](https://leetcode.com/problems/house-robber-ii/)

<p>You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are <strong>arranged in a circle.</strong> That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and&nbsp;<b>it will automatically contact the police if two adjacent houses were broken into on the same night</b>.</p>

<p>Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight <strong>without alerting the police</strong>.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [2,3,2]
<strong>Output:</strong> 3
<strong>Explanation:</strong> You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
&nbsp;            because they are adjacent houses.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [1,2,3,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Rob house 1 (money = 1) and then rob house 3 (money = 3).
&nbsp;            Total amount you can rob = 1 + 3 = 4.</pre>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [House Robber (Easy)](https://leetcode.com/problems/house-robber/)
* [Paint House (Easy)](https://leetcode.com/problems/paint-house/)
* [Paint Fence (Easy)](https://leetcode.com/problems/paint-fence/)
* [House Robber III (Medium)](https://leetcode.com/problems/house-robber-iii/)
* [Non-negative Integers without Consecutive Ones (Hard)](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/)
* [Coin Path (Hard)](https://leetcode.com/problems/coin-path/)

## Solution 1. DP

In this problem we can't directly use the solution of [198. House Robber (Easy)](https://leetcode.com/problems/house-robber/) becase the choice of robbing the first house could determine whether we can rob the last house.

We can break the problem into two situations.

1. We skip the first house. Then we can safely try robbing from house `1` to house `N - 1`.
1. We rob the first house. Then we can safely try robbing from house `0` to house `N - 2`.

```cpp
// OJ: https://leetcode.com/problems/house-robber-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    int rob(vector<int>& A, int start, int end) {
        if (start == end) return 0;
        if (start + 1 == end) return A[start];
        int prev2 = 0, prev = 0;
        for (int i = start; i < end; ++i) {
            int cur = max(prev, A[i] + prev2);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
public:
    int rob(vector<int>& A) {
        if (A.size() == 1) return A[0];
        return max(rob(A, 1, A.size()), rob(A, 0, A.size() - 1));
    }
};
```