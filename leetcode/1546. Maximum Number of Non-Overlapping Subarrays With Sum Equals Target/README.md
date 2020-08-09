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

## Solution 1. Hash Map + ISMP

1. Get all the ranges whose sums are `target`.
2. The problem becomes a *Interval Scheduling Maximization Problem (ISMP)* -- find the maximum size of non-overlapping ranges given a set of ranges.

For problem 1, we can compute the prefix sum of the array, and use an `unordered_map<int, int> m` to store the last-seen index of a prefix sum.

Assume the current prefix sum at index `i` is `sum`, then we'd like to find another prefix sum `sum - target`. If we've seen it before, then `m[sum - target]` is the last-seen index of the prefix sum. So `{ m[sum - target] + 1, i }` forms a valid range.

Now that we've found all the ranges whose sums are `target`. We can apply the solution to *Interval Scheduling Maximization Problem (ISMP)* to find the maximum size of non-overlapping ranges.

We just need to sort the ranges in ascending order of the ending index, and then greedily pick the non-overlapping ranges which end first.

```cpp
// OJ: https://leetcode.com/contest/weekly-contest-201/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/
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

## Solution 2. Greedy

In fact, in Solution 1, when a range has sum as `target`, as long as it doesn't overlap with previously selected range, we can select this range.

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