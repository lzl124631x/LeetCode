# [45. Jump Game II (Medium)](https://leetcode.com/problems/jump-game-ii/)

<p>Given an array of non-negative integers <code>nums</code>, you are initially positioned at the first index of the array.</p>

<p>Each element in the array represents your maximum jump length at that position.</p>

<p>Your goal is to reach the last index in the minimum number of jumps.</p>

<p>You can assume that you can always reach the last index.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,3,1,1,4]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,3,0,1,4]
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple), [tcs](https://leetcode.com/company/tcs)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Jump Game (Medium)](https://leetcode.com/problems/jump-game/)
* [Jump Game III (Medium)](https://leetcode.com/problems/jump-game-iii/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/jump-game-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int jump(vector<int>& A) {
        int N = A.size();
        vector<int> dp(N, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j <= A[i] && i + j < N; ++j) {
                dp[i + j] = min(dp[i + j], 1 + dp[i]);
            }
        }
        return dp[N - 1];
    }
};
```

## Solution 2.

**Intuition**:

This problem is asking for **the shortest distance**, so **BFS** should be the first solution we come up with.

The following solutions are variants of BFS.

Normally we use `queue` to keep track of the active indexes. But for this problem, we just need to track the **furthest index we can reach**.

**Algorithm**:

Use `vector<int> endsAt` to store the furthest index we can go. `endsAt[i]` means we can reach `endsAt[i]` given `i` steps. It starts with a single 0 at position 0, and will be strictly ascending.

For index `i` &isin; `[0, N - 2]`, use binary search to find the minimum step needed to get to index `i`. Try to use `i + nums[i]` to update `endsAt`.

Eventually, use binary search again to find the minimum step needed to get to `N - 1`.

```cpp
// OJ: https://leetcode.com/problems/jump-game-ii/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> endsAt(1, 0);
        for (int i = 0; i < nums.size() - 1; ++i) {
            int step = lower_bound(endsAt.begin(), endsAt.end(), i) - endsAt.begin();
            int next = i + nums[i];
            if (step == endsAt.size() - 1) {
                if (next > endsAt[step]) endsAt.push_back(next);
            } else {
                 if (next > endsAt[step + 1]) endsAt[step + 1] = next;
            }
        }
        return lower_bound(endsAt.begin(), endsAt.end(), nums.size() - 1) - endsAt.begin();
    }
};
```

## Solution 3. BFS + Greedy

In essense, this solution is BFS. It's separating the points into groups that can be reached given different steps.

Let's say given `jumps` jumps, we can reach at most index `jumpsEnd`.

Once the current point reaches `jumpsEnd`, we have to trigger another jump to extend `jumpsEnd`. And `jumpsEnd` should extend to `furthest` which is the fursthest index we can jump to given the points between index `0` and `jumpsEnd`.

Keep the above steps for points `[0..(N - 1)]`:

```cpp
// OJ: https://leetcode.com/problems/jump-game-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/jump-game-ii/discuss/18014/Concise-O(n)-one-loop-JAVA-solution-based-on-Greedy
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, jumpsEnd = 0, furthest = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            furthest = max(furthest, i + nums[i]);
            if (i == jumpsEnd) {
                ++jumps;
                jumpsEnd = furthest;
            }
        }
        return jumps;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/jump-game-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int jump(vector<int>& A) {
        int last = 0, next = 0, step = 0;
        for (int i = 0; i < A.size() && last < A.size() - 1; ++i) {
            if (i > last) {
                ++step;
                last = next;
            }
            next = max(next, i + A[i]);
        }
        return step;
    }
};
```

Assume `A = [0,2,4,...]`. Starting from `A[0]`, we can only visit `A[1], A[2]`. Which one should we pick? Must be the one that allows us to travel the furthest.

Since `A[1]` can take us to `1+2=3` at most, and `A[2]` can take us to `2+4=6` at most, picking `A[2]` is always better than picking `A[1]` because the range of `A[2]`'s reach covers the range of `A[1]`'s reach.

So we can define our strategy as follows:

Assume we are currently at `A[i]` and the furthest reach is `A[end]`, we greedily pick the `A[j] (i < j <= end)` with the furthest reach `j + A[j]`.