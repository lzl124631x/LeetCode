# [1434. Number of Ways to Wear Different Hats to Each Other (Hard)](https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/)

<p>There are&nbsp;<code>n</code> people&nbsp;and 40 types of hats labeled from 1 to 40.</p>

<p>Given a list of list of integers <code>hats</code>, where <code>hats[i]</code>&nbsp;is a list of all hats preferred&nbsp;by the <code data-stringify-type="code">i-th</code> person.</p>

<p>Return the number of ways that the n people wear different hats to each other.</p>

<p>Since the answer&nbsp;may be too large,&nbsp;return it modulo&nbsp;<code>10^9 + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> hats = [[3,4],[4,5],[5]]
<strong>Output:</strong> 1
<strong>Explanation: </strong>There is only one way to choose hats given the conditions. 
First person choose hat 3, Second person choose hat 4 and last one hat 5.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> hats = [[3,5,1],[3,5]]
<strong>Output:</strong> 4
<strong>Explanation: </strong>There are 4 ways to choose hats
(3,5), (5,3), (1,3) and (1,5)
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> hats = [[1,2,3,4],[1,2,3,4],[1,2,3,4],[1,2,3,4]]
<strong>Output:</strong> 24
<strong>Explanation: </strong>Each person can choose hats labeled from 1 to 4.
Number of Permutations of (1,2,3,4) = 24.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> hats = [[1,2,3],[2,3,5,6],[1,3,7,9],[1,8,9],[2,5,7]]
<strong>Output:</strong> 111
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == hats.length</code></li>
	<li><code>1 &lt;= n &lt;= 10</code></li>
	<li><code>1 &lt;= hats[i].length &lt;= 40</code></li>
	<li><code>1 &lt;= hats[i][j] &lt;= 40</code></li>
	<li><code>hats[i]</code> contains a list of <strong>unique</strong> integers.</li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/
// Author: github.com/lzl124631x
// Time: O(2^N * M)
// Space: O(2^N)
class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        vector<vector<int>> persons(40);
        int N = hats.size(), mod = 1e9+7;
        vector<int> masks(1 << N);
        masks[0] = 1;
        for (int i = 0; i < N; ++i) {
            for (int h : hats[i]) persons[h - 1].push_back(i);
        }
        for (int i = 0; i < 40; ++i) {
            for (int j = (1 << N) - 1; j >= 0; --j) {
                for (int p : persons[i]) {
                    if (j & (1 << p)) continue;
                    masks[j | (1 << p)] += masks[j];
                    masks[j | (1 << p)] %= mod;
                }
            }
        }
        return masks[(1 << N) - 1];
    }
};
```