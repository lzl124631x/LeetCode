# [1743. Restore the Array From Adjacent Pairs (Medium)](https://leetcode.com/problems/restore-the-array-from-adjacent-pairs)

<p>There is an integer array <code>nums</code> that consists of <code>n</code> <strong>unique </strong>elements, but you have forgotten it. However, you do remember every pair of adjacent elements in <code>nums</code>.</p>

<p>You are given a 2D integer array <code>adjacentPairs</code> of size <code>n - 1</code> where each <code>adjacentPairs[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> indicates that the elements <code>u<sub>i</sub></code> and <code>v<sub>i</sub></code> are adjacent in <code>nums</code>.</p>

<p>It is guaranteed that every adjacent pair of elements <code>nums[i]</code> and <code>nums[i+1]</code> will exist in <code>adjacentPairs</code>, either as <code>[nums[i], nums[i+1]]</code> or <code>[nums[i+1], nums[i]]</code>. The pairs can appear <strong>in any order</strong>.</p>

<p>Return <em>the original array </em><code>nums</code><em>. If there are multiple solutions, return <strong>any of them</strong></em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> adjacentPairs = [[2,1],[3,4],[3,2]]
<strong>Output:</strong> [1,2,3,4]
<strong>Explanation:</strong> This array has all its adjacent pairs in adjacentPairs.
Notice that adjacentPairs[i] may not be in left-to-right order.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> adjacentPairs = [[4,-2],[1,4],[-3,1]]
<strong>Output:</strong> [-2,4,1,-3]
<strong>Explanation:</strong> There can be negative numbers.
Another solution is [-3,1,4,-2], which would also be accepted.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> adjacentPairs = [[100000,-100000]]
<strong>Output:</strong> [100000,-100000]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>nums.length == n</code></li>
	<li><code>adjacentPairs.length == n - 1</code></li>
	<li><code>adjacentPairs[i].length == 2</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i], u<sub>i</sub>, v<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li>There exists some <code>nums</code> that has <code>adjacentPairs</code> as its pairs.</li>
</ul>


**Companies**:
[Uber](https://leetcode.com/company/uber), [Capital One](https://leetcode.com/company/capital-one), [Microsoft](https://leetcode.com/company/microsoft), [Robinhood](https://leetcode.com/company/robinhood)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Hash Table](https://leetcode.com/tag/hash-table)

**Hints**:
* Find the first element of nums - it will only appear once in adjacentPairs.
* The adjacent pairs are like edges of a graph. Perform a depth-first search from the first element.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/restore-the-array-from-adjacent-pairs
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& A) {
        int N = A.size() + 1, first = -1;
        unordered_map<int, vector<int>> G;
        for (auto &p : A) { // build graph
            int u = p[0], v = p[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<int> ans;
        for (auto &[n, v] : G) { // find an edge node
            if (v.size() == 1) {
                ans.push_back(n);
                ans.push_back(v[0]);
                break;
            }
        }
        while (ans.size() < N) { // keep finding the next node
            int n = ans.back(), prev = ans[ans.size() - 2];
            if (G[n][0] != prev) ans.push_back(G[n][0]);
            else ans.push_back(G[n][1]);
        }
        return ans;
    }
};
```