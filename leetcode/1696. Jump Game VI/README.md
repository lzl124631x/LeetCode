# [ (Medium)](https://leetcode.com/problems/jump-game-vi)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> and an integer <code>k</code>.</p>
<p>You are initially standing at index <code>0</code>. In one move, you can jump at most <code>k</code> steps forward without going outside the boundaries of the array. That is, you can jump from index <code>i</code> to any index in the range <code>[i + 1, min(n - 1, i + k)]</code> <strong>inclusive</strong>.</p>
<p>You want to reach the last index of the array (index <code>n - 1</code>). Your <strong>score</strong> is the <strong>sum</strong> of all <code>nums[j]</code> for each index <code>j</code> you visited in the array.</p>
<p>Return <em>the <strong>maximum score</strong> you can get</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [<u>1</u>,<u>-1</u>,-2,<u>4</u>,-7,<u>3</u>], k = 2
<strong>Output:</strong> 7
<strong>Explanation:</strong> You can choose your jumps forming the subsequence [1,-1,4,3] (underlined above). The sum is 7.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [<u>10</u>,-5,-2,<u>4</u>,0,<u>3</u>], k = 3
<strong>Output:</strong> 17
<strong>Explanation:</strong> You can choose your jumps forming the subsequence [10,4,3] (underlined above). The sum is 17.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
<strong>Output:</strong> 0
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length, k &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

**Companies**:
[MathWorks](https://leetcode.com/company/mathworks), [Apple](https://leetcode.com/company/apple), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Queue](https://leetcode.com/tag/queue/), [Sliding Window](https://leetcode.com/tag/sliding-window/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Monotonic Queue](https://leetcode.com/tag/monotonic-queue/)

**Similar Questions**:
* [Sliding Window Maximum (Hard)](https://leetcode.com/problems/sliding-window-maximum/)
* [Jump Game VII (Medium)](https://leetcode.com/problems/jump-game-vii/)
* [Jump Game VIII (Medium)](https://leetcode.com/problems/jump-game-viii/)

## Solution 1. Mono-queue + DP

Let `dp[i]` be the greatest score we can get using `A[0 .. i]`.

To get `dp[i]`, we pick the greatest `dp[j]` (`i - k <= j < i`) and add `A[i]` to it.

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
        vector<int> dp(N);
        dp[0] = A[0];
        deque<int> q{0};
        for (int i = 1; i < N; ++i) {
            if (q.front() < i - k) q.pop_front(); // pop the front element if it goes out of range
            dp[i] = A[i] + dp[q.front()]; // dp[q.front()] is the maximum dp value in range.
            while (q.size() && dp[q.back()] <= dp[i]) q.pop_back(); // pop the elements that are smaller than or equal to dp[i] out of the queue.
            q.push_back(i);
        }
        return dp[N - 1];
    }
};
```

Or store the scores in the mono-queue to reduce space complexity to `O(K)`.

```cpp
// OJ: https://leetcode.com/problems/jump-game-vi
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(K)
class Solution {
public:
    int maxResult(vector<int>& A, int k) {
        deque<pair<int, int>> q; // index, score
        int N = A.size();
        for (int i = 0; i < N; ++i) {
            if (i - k - 1 >= 0 && q.front().first == i - k - 1) q.pop_front();
            int score = A[i];
            if (q.size()) score += q.front().second;
            while (q.size() && q.back().second <= score) q.pop_back();
            q.emplace_back(i, score);
        }
        return q.back().second;
    }
};
```