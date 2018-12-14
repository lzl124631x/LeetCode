# [746. Min Cost Climbing Stairs (Easy)](https://leetcode.com/problems/min-cost-climbing-stairs/)

<p>
On a staircase, the <code>i</code>-th step has some non-negative cost <code>cost[i]</code> assigned (0 indexed).
</p><p>
Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> cost = [10, 15, 20]
<b>Output:</b> 15
<b>Explanation:</b> Cheapest is start on cost[1], pay that cost and go to the top.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
<b>Output:</b> 6
<b>Explanation:</b> Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li><code>cost</code> will have a length in the range <code>[2, 1000]</code>.</li>
<li>Every <code>cost[i]</code> will be an integer in the range <code>[0, 999]</code>.</li>
</ol>
<p></p>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Climbing Stairs (Easy)](https://leetcode.com/problems/climbing-stairs/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/min-cost-climbing-stairs/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev = 0, cur = 0;
        for (int i = 2; i <= cost.size(); ++i) {
            int newCur = min(cur + cost[i - 1], prev + cost[i - 2]);
            prev = cur;
            cur = newCur;
        }
        return cur;
    }
};
```