# [573. Squirrel Simulation (Medium)](https://leetcode.com/problems/squirrel-simulation/)

<p>You are given two integers <code>height</code> and <code>width</code> representing a garden of size <code>height x width</code>. You are also given:</p>

<ul>
	<li>an array <code>tree</code> where <code>tree = [tree<sub>r</sub>, tree<sub>c</sub>]</code> is the position of the tree in the garden,</li>
	<li>an array <code>squirrel</code> where <code>squirrel = [squirrel<sub>r</sub>, squirrel<sub>c</sub>]</code> is the position of the squirrel in the garden,</li>
	<li>and an array <code>nuts</code> where <code>nuts[i] = [nut<sub>i<sub>r</sub></sub>, nut<sub>i<sub>c</sub></sub>]</code> is the position of the <code>i<sup>th</sup></code> nut in the garden.</li>
</ul>

<p>The squirrel can only take at most one nut at one time and can move in four directions: up, down, left, and right, to the adjacent cell.</p>

<p>Return <em>the <strong>minimal distance</strong> for the squirrel to collect all the nuts and put them under the tree one by one</em>.</p>

<p>The <strong>distance</strong> is the number of moves.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/squirrel1-grid.jpg" style="width: 573px; height: 413px;">
<pre><strong>Input:</strong> height = 5, width = 7, tree = [2,2], squirrel = [4,4], nuts = [[3,0], [2,5]]
<strong>Output:</strong> 12
<strong>Explanation:</strong> The squirrel should go to the nut at [2, 5] first to achieve a minimal distance.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/squirrel2-grid.jpg" style="width: 253px; height: 93px;">
<pre><strong>Input:</strong> height = 1, width = 3, tree = [0,1], squirrel = [0,0], nuts = [[0,2]]
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= height, width &lt;= 100</code></li>
	<li><code>tree.length == 2</code></li>
	<li><code>squirrel.length == 2</code></li>
	<li><code>1 &lt;= nuts.length &lt;= 5000</code></li>
	<li><code>nuts[i].length == 2</code></li>
	<li><code>0 &lt;= tree<sub>r</sub>, squirrel<sub>r</sub>, nut<sub>i<sub>r</sub></sub> &lt;= height</code></li>
	<li><code>0 &lt;= tree<sub>c</sub>, squirrel<sub>c</sub>, nut<sub>i<sub>c</sub></sub> &lt;= width</code></li>
</ul>


**Companies**:  
[Square](https://leetcode.com/company/square)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/)

## Solution 1.

Assume we have 2 nuts, n1, n2. Their distances to the tree are `a` and `b` respectively, and their distances to the squirrel are `sa`, `sb` respectively.

If we go to n1 first then n2, the total distance is `sa + a + 2b = 2*(a+b) + (sa-a)`.

If we go to n2 first then n1, the total distance is `2a + sb + b = 2*(a+b) + (sb-b)`.

So, we just need to compute `a+b` and the minimum value of `sa-a` and `sb-b`.

Generally, we need to compute the sum of distances between each nut and the tree, and find the minimum value of `{squirrel nut distance} - {tree nut distance}`.

```cpp
// OJ: https://leetcode.com/problems/squirrel-simulation/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    int dist(vector<int> &a, vector<int> &b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int sum = 0, mn = INT_MAX;
        for (auto &n : nuts) {
            sum += dist(tree, n);
            mn = min(mn, dist(squirrel, n) - dist(tree, n));
        }
        return 2 * sum + mn;
    }
};
```