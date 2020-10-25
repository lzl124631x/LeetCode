# [1546. Maximum Number of Non-Overlapping Subarrays With Sum Equals Target (Medium)](https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/)

<p>Given an array <code>nums</code> and an integer <code><font face="monospace">target</font></code>.</p>

<p>Return the maximum number of <strong>non-empty</strong>&nbsp;<strong>non-overlapping</strong> subarrays such that the sum of values in each subarray is equal to <code><font face="monospace">target</font></code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,1,1,1], target = 2
<strong>Output:</strong> 2
<strong>Explanation: </strong>There are 2 non-overlapping subarrays [<strong>1,1</strong>,1,<strong>1,1</strong>] with sum equals to target(2).
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [-1,3,5,1,4,2,-9], target = 6
<strong>Output:</strong> 2
<strong>Explanation: </strong>There are 3 subarrays with sum equal to 6.
([5,1], [4,2], [3,5,1,4,2,-9]) but only the first 2 are non-overlapping.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [-2,6,6,3,5,4,1,2,8], target = 10
<strong>Output:</strong> 3
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> nums = [0,0,0], target = 0
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;=&nbsp;10^5</code></li>
	<li><code>-10^4 &lt;= nums[i] &lt;=&nbsp;10^4</code></li>
	<li><code>0 &lt;= target &lt;= 10^6</code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. Prefix State Map + ISMP

1. Get all the ranges whose sums are `target`.
2. The problem becomes a *Interval Scheduling Maximization Problem (ISMP)* -- find the maximum size of non-overlapping ranges given a set of ranges.

For problem 1, we can compute the prefix sum of the array, and use an `unordered_map<int, int> m` to store the last-seen index of a prefix sum.

Assume the current prefix sum at index `i` is `sum`, then we'd like to find another prefix sum `sum - target`. If we've seen it before, then `m[sum - target]` is the last-seen index of the prefix sum. So `{ m[sum - target] + 1, i }` forms a valid range.

Now that we've found all the ranges whose sums are `target`. We can apply the solution to *Interval Scheduling Maximization Problem (ISMP)* to find the maximum size of non-overlapping ranges.

We just need to sort the ranges in ascending order of the ending index, and then greedily pick the non-overlapping ranges which end first.

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target//
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int maxNonOverlapping(vector<int>& A, int target) {
        vector<vector<int>> v;
        unordered_map<int, int> m{{0, -1}};
        int sum = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum += A[i]; // prefix sum
            if (m.count(sum - target)) v.push_back({i, m[sum - target] + 1}); // {m[sum - target + 1], i} is a valid range. Here we put the ending index first.
            m[sum] = i; // Update the last-seen ending index corresponding to this prefix sum
        }
        sort(begin(v), end(v)); // sort in ascending order of the ending index
        int ans = 0, last = -1;
        for (auto &p : v) {
            if (p[1] <= last) continue; // the start index is smaller or equal to the `last`, which means that this range overlaps with a previously selected range. Skip
            ++ans;
            last = p[0]; // select this range and update the `last` to be the ending index
        }
        return ans;
    }
};
```

## Solution 2. Prefix State Map + DP

Let `dp[i+1]` be the answer to the subproblem on subarray `A[0..i]`. Again we use prefix state map to store the last-seen index of the prefix sum.

For `dp[i+1]`, we have two options:
1. skip `A[i]`. So `dp[i+1]=dp[i]`
2. If we've seen prefix sum `sum - target`, then `{m[sum - target] + 1, i}` is a valid range. `dp[i+1] = 1 + dp[m[sum - target] + 1]`.

`dp[N]` is the answer.

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxNonOverlapping(vector<int>& A, int target) {
        unordered_map<int, int> m{{0, -1}};
        int N = A.size(), sum = 0;
        vector<int> dp(N + 1);
        for (int i = 0; i < N; ++i) {
            sum += A[i];
            dp[i + 1] = dp[i];
            if (m.count(sum - target)) dp[i + 1] = max(dp[i + 1], 1 + dp[m[sum - target] + 1]);
            m[sum] = i;
        }
        return dp[N];
    }
};
```

## Solution 3. Prefix State Map + Greedy

In fact, with the prefix state map, when we find a range having sum as `target`, we can greedily select this range as long as it doesn't overlap with previously selected range.

This greedy solution works because in the greedy solution to the ISMP, we need to sort the intervals in ascending order of the end time; here we naturally visit the end time in asending order.

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxNonOverlapping(vector<int>& A, int target) {
        unordered_map<int, int> m{{0, -1}};
        int sum = 0, last = -1, ans = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum += A[i];
            int x = sum - target;
            if (m.count(x) && m[x] + 1 > last) {
                ++ans;
                last = i;
            }
            m[sum] = i;
        }
        return ans;
    }
};
```

## Solution 4. Prefix State Map + Greedy

Now the prefix state map `m` stores the mapping from a prefix sum to the maximum count of compliant subarrays we've seen thus far.

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/discuss/780887/Java-Detailed-Explanation-DPMapPrefix-O(N)
class Solution {
public:
    int maxNonOverlapping(vector<int>& A, int target) {
        unordered_map<int, int> m{{0, 0}};
        int N = A.size(), sum = 0, ans = 0;
        for (int i = 0; i < N; ++i) {
            sum += A[i];
            if (m.count(sum - target)) ans = max(ans, m[sum - target] + 1);
            m[sum] = ans;
        }
        return ans;
    }
};
```