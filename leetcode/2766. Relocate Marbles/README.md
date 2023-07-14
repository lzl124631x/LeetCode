# [2766. Relocate Marbles (Medium)](https://leetcode.com/problems/relocate-marbles)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> representing the initial positions of some marbles. You are also given two <strong>0-indexed </strong>integer arrays <code>moveFrom</code> and <code>moveTo</code> of <strong>equal</strong> length.</p>
<p>Throughout <code>moveFrom.length</code> steps, you will change the positions of the marbles. On the <code>i<sup>th</sup></code> step, you will move <strong>all</strong> marbles at position <code>moveFrom[i]</code> to position <code>moveTo[i]</code>.</p>
<p>After completing all the steps, return <em>the sorted list of <strong>occupied</strong> positions</em>.</p>
<p><strong>Notes:</strong></p>
<ul>
	<li>We call a position <strong>occupied</strong> if there is at least one marble in that position.</li>
	<li>There may be multiple marbles in a single position.</li>
</ul>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,6,7,8], moveFrom = [1,7,2], moveTo = [2,9,5]
<strong>Output:</strong> [5,6,8,9]
<strong>Explanation:</strong> Initially, the marbles are at positions 1,6,7,8.
At the i = 0th step, we move the marbles at position 1 to position 2. Then, positions 2,6,7,8 are occupied.
At the i = 1st step, we move the marbles at position 7 to position 9. Then, positions 2,6,8,9 are occupied.
At the i = 2nd step, we move the marbles at position 2 to position 5. Then, positions 5,6,8,9 are occupied.
At the end, the final positions containing at least one marbles are [5,6,8,9].</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,1,3,3], moveFrom = [1,3], moveTo = [2,2]
<strong>Output:</strong> [2]
<strong>Explanation:</strong> Initially, the marbles are at positions [1,1,3,3].
At the i = 0th step, we move all the marbles at position 1 to position 2. Then, the marbles are at positions [2,2,3,3].
At the i = 1st step, we move all the marbles at position 3 to position 2. Then, the marbles are at positions [2,2,2,2].
Since 2 is the only occupied position, we return [2].
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= moveFrom.length &lt;= 10<sup>5</sup></code></li>
	<li><code>moveFrom.length == moveTo.length</code></li>
	<li><code>1 &lt;= nums[i], moveFrom[i], moveTo[i] &lt;= 10<sup>9</sup></code></li>
	<li>The test cases are generated such that there is at least a marble in&nbsp;<code>moveFrom[i]</code>&nbsp;at the moment we want to apply&nbsp;the <code>i<sup>th</sup></code>&nbsp;move.</li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Sorting](https://leetcode.com/tag/sorting/), [Simulation](https://leetcode.com/tag/simulation/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/relocate-marbles
// Author: github.com/lzl124631x
// Time: O((N + M) * logN)
// Space: O(N)
class Solution {
public:
    vector<int> relocateMarbles(vector<int>& A, vector<int>& from, vector<int>& to) {
        set<int> s(begin(A), end(A));
        for (int i = 0; i < from.size(); ++i) {
            s.erase(from[i]);
            s.insert(to[i]);
        }
        return vector<int>(begin(s), end(s));
    }
};
```