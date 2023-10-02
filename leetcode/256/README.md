# [256. Paint House (Easy)](https://leetcode.com/problems/paint-house/)

<p>There are a row of <i>n</i> houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.</p>

<p>The cost of painting each house with a certain color is represented by a <code><i>n</i> x <i>3</i></code> cost matrix. For example, <code>costs[0][0]</code> is the cost of painting house 0 with color red; <code>costs[1][2]</code> is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.</p>

<p><b>Note:</b><br>
All costs are positive integers.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> [[17,2,17],[16,16,5],[14,3,19]]
<strong>Output:</strong> 10
<strong>Explanation: </strong>Paint house 0 into blue, paint house 1 into green, paint house 2 into blue. 
&nbsp;            Minimum cost: 2 + 5 + 3 = 10.
</pre>


**Companies**:  
[LinkedIn](https://leetcode.com/company/linkedin)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [House Robber (Easy)](https://leetcode.com/problems/house-robber/)
* [House Robber II (Medium)](https://leetcode.com/problems/house-robber-ii/)
* [Paint House II (Hard)](https://leetcode.com/problems/paint-house-ii/)
* [Paint Fence (Easy)](https://leetcode.com/problems/paint-fence/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/paint-house/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        for (int i = 1; i < costs.size(); ++i) {
            for (int j = 0; j < 3; ++j) costs[i][j] += min(costs[i - 1][(j + 1) % 3], costs[i - 1][(j + 2) % 3]);
        }
        return *min_element(costs.back().begin(), costs.back().end());
    }
};
```