# [2742. Painting the Walls (Hard)](https://leetcode.com/problems/painting-the-walls)

<p>You are given two <strong>0-indexed</strong> integer arrays,&nbsp;<code>cost</code> and <code>time</code>, of size <code>n</code> representing the costs and the time taken to paint <code>n</code> different walls respectively. There are two painters available:</p>

<ul>
	<li>A<strong>&nbsp;paid painter</strong>&nbsp;that paints the <code>i<sup>th</sup></code> wall in <code>time[i]</code> units of time and takes <code>cost[i]</code> units of money.</li>
	<li>A<strong>&nbsp;free painter</strong> that paints&nbsp;<strong>any</strong> wall in <code>1</code> unit of time at a cost of <code>0</code>. But the&nbsp;free painter can only be used if the paid painter is already <strong>occupied</strong>.</li>
</ul>

<p>Return <em>the minimum amount of money required to paint the </em><code>n</code><em>&nbsp;walls.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> cost = [1,2,3,2], time = [1,2,3,2]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The walls at index 0 and 1 will be painted by the paid painter, and it will take 3 units of time; meanwhile, the free painter will paint the walls at index 2 and 3, free of cost in 2 units of time. Thus, the total cost is 1 + 2 = 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> cost = [2,3,4,2], time = [1,1,1,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The walls at index 0 and 3 will be painted by the paid painter, and it will take 2 units of time; meanwhile, the free painter will paint the walls at index 1 and 2, free of cost in 2 units of time. Thus, the total cost is 2 + 2 = 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= cost.length &lt;= 500</code></li>
	<li><code>cost.length == time.length</code></li>
	<li><code>1 &lt;= cost[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= time[i] &lt;= 500</code></li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Adobe](https://leetcode.com/company/adobe), [Snowflake](https://leetcode.com/company/snowflake), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming)

**Hints**:
* Can we break the problem down into smaller subproblems and use DP?
* Paid painters will be used for a maximum of N/2 units of time. There is no need to use paid painter for a time greater than this.

## Solution 1.

Let `dp[k]` be the minimum cost to finish `k` walls. 

Initially
```
dp[0] = 0
dp[k>0] = inf
```

For `i`th wall, we update `dp[j]` with this dp equation

```
dp[j] = min(dp[j], dp[max(j - time[i] - 1, 0)] + cost[i])
```

If we paint `i`th wall, we increase cost by `cost[i]`, and we can paint `time[i]` more walls with free painters. So, we can paint `time[i] + 1` walls with this choice. Thus, we can try to use `dp[max(j - time[i] - 1, 0)] + cost[i]` to update `dp[j]`.

```cpp
// OJ: https://leetcode.com/problems/painting-the-walls
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
// Ref: https://leetcode.com/problems/painting-the-walls/solutions/3650707/java-c-python-7-lines-knapsack-dp/
class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;
        for (int i = 0; i < n; ++i)
            for (int j = n; j > 0; --j)
                dp[j] = min(dp[j], dp[max(j - time[i] - 1, 0)] + cost[i]);
        return dp[n];
    }
};
```