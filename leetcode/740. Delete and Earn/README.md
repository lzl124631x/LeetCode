# [740. Delete and Earn (Medium)](https://leetcode.com/problems/delete-and-earn/)

<p>Given an array <code>nums</code> of integers, you can perform operations on the array.</p>

<p>In each operation, you pick any <code>nums[i]</code> and delete it to earn <code>nums[i]</code> points. After, you must delete <b>every</b> element equal to <code>nums[i] - 1</code> or <code>nums[i] + 1</code>.</p>

<p>You start with 0 points. Return the maximum number of points you can earn by applying such operations.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> nums = [3, 4, 2]
<b>Output:</b> 6
<b>Explanation:</b> 
Delete 4 to earn 4 points, consequently 3 is also deleted.
Then, delete 2 to earn 2 points. 6 total points are earned.
</pre>

<p>&nbsp;</p>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> nums = [2, 2, 3, 3, 3, 4]
<b>Output:</b> 9
<b>Explanation:</b> 
Delete 3 to earn 3 points, deleting both 2's and the 4.
Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
9 total points are earned.
</pre>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<ul>
	<li>The length of <code>nums</code> is at most <code>20000</code>.</li>
	<li>Each element <code>nums[i]</code> is an integer in the range <code>[1, 10000]</code>.</li>
</ul>

<p>&nbsp;</p>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [House Robber (Easy)](https://leetcode.com/problems/house-robber/)

## Solution 1. DP

Firstly, to avoid duplicate, store the data in a map from the number to its count.

Let `dp[i]` be the max point you can get at point `i`.

If `num != prevNum + 1`, we can freely pick `num`, then `dp[i] = dp[i-1] + num * count`.

Otherwise, if we don't pick `num`, `dp[i] = dp[i-1]`.

Otherwise, we pick `num`, `dp[i] = dp[i-2] + num * count`.

So in sum:

```
dp[i] = num == prevNum ? max(dp[i-1], dp[i-2] + num * count) : (dp[i-1] + num * count)
```

```cpp
// OJ: https://leetcode.com/problems/delete-and-earn/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> m;
        for (int n : nums) m[n]++;
        int prev = 0, prev2 = 0, num = INT_MIN;
        for (auto &p : m) {
            int cur = p.first == num + 1 ? max(prev, prev2 + p.first * p.second) : (prev + p.first * p.second);
            prev2 = prev;
            prev = cur;
            num = p.first;
        }
        return prev;
    }
};
```