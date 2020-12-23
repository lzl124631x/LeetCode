# [1696. Jump Game VI (Medium)](https://leetcode.com/problems/jump-game-vi/)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> and an integer <code>k</code>.</p>

<p>You are initially standing at index <code>0</code>. In one move, you can jump at most <code>k</code> steps forward without going outside the boundaries of the array. That is, you can jump from index <code>i</code> to any index in the range <code>[i + 1, min(n - 1, i + k)]</code> <strong>inclusive</strong>.</p>

<p>You want to reach the last index of the array (index <code>n - 1</code>). Your <strong>score</strong> is the <strong>sum</strong> of all <code>nums[j]</code> for each index <code>j</code> you visited in the array.</p>

<p>Return <em>the <strong>maximum score</strong> you can get</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [<u>1</u>,<u>-1</u>,-2,<u>4</u>,-7,<u>3</u>], k = 2
<strong>Output:</strong> 7
<strong>Explanation:</strong> You can choose your jumps forming the subsequence [1,-1,4,3] (underlined above). The sum is 7.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [<u>10</u>,-5,-2,<u>4</u>,0,<u>3</u>], k = 3
<strong>Output:</strong> 17
<strong>Explanation:</strong> You can choose your jumps forming the subsequence [10,4,3] (underlined above). The sum is 17.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>&nbsp;<code>1 &lt;= nums.length, k &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup>&nbsp;&lt;= nums[i]&nbsp;&lt;= 10<sup>4</sup></code></li>
</ul>


**Related Topics**:  
[Dequeue](https://leetcode.com/tag/dequeue/)

**Similar Questions**:
* [Sliding Window Maximum (Hard)](https://leetcode.com/problems/sliding-window-maximum/)

## Solution 1. Mono-queue + DP

For `A[i]`, we can choose the greatest value we can get among `A[j]` where `max(0, i - k) <= j < i`. 

So we can memoize the results using a `dp` array where `dp[i]` is the maximum score we can get jumping from `A[0]` to `A[i]`.

```
dp[i] = A[i] + max( dp[j] | max(0, i - k) <= j < i )
dp[0] = A[0]
```

For the part calculating `max` value, doing it in a brute force manner will take `O(K)` time and result in TLE. We can use mono-queue to reduce the time complexity to amortized `O(1)`.

Since we are looking for the maximum value in a range, we can use a decreasing mono-queue.

```cpp
// OJ: https://leetcode.com/problems/jump-game-vi/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxResult(vector<int>& A, int k) {
        int N = A.size();
        vector<long> dp(N, INT_MIN);
        dp[0] = A[0];
        deque<int> q;
        q.push_back(0);
        for (int i = 1; i < N; ++i) {
            dp[i] = A[i] + dp[q.front()]; // dp[q.front()] is the maximum dp value in range.
            if (q.size() && q.front() <= i - k) q.pop_front(); // pop the front element because it goes out of range.
            while (q.size() && dp[q.back()] <= dp[i]) q.pop_back(); // pop the elements that are smaller than or equal to dp[i] out of the queue.
            q.push_back(i);
        }
        return dp[N - 1];
    }
};
```