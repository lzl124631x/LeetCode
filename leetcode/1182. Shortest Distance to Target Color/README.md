# [1182. Shortest Distance to Target Color (Medium)](https://leetcode.com/problems/shortest-distance-to-target-color/)

<p>You are given an array <code>colors</code>, in which there are three colors: <code>1</code>, <code>2</code> and&nbsp;<code>3</code>.</p>

<p>You are also given some queries. Each query consists of two integers <code>i</code>&nbsp;and <code>c</code>, return&nbsp;the shortest distance between the given index&nbsp;<code>i</code> and the target color <code>c</code>. If there is no solution return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> colors = [1,1,2,1,3,2,2,3,3], queries = [[1,3],[2,2],[6,1]]
<strong>Output:</strong> [3,0,3]
<strong>Explanation: </strong>
The nearest 3 from index 1 is at index 4 (3 steps away).
The nearest 2 from index 2 is at index 2 itself (0 steps away).
The nearest 1 from index 6 is at index 3 (3 steps away).
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> colors = [1,2], queries = [[0,3]]
<strong>Output:</strong> [-1]
<strong>Explanation: </strong>There is no 3 in the array.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= colors.length &lt;= 5*10^4</code></li>
	<li><code>1 &lt;= colors[i] &lt;= 3</code></li>
	<li><code>1&nbsp;&lt;= queries.length &lt;= 5*10^4</code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>0 &lt;= queries[i][0] &lt;&nbsp;colors.length</code></li>
	<li><code>1 &lt;= queries[i][1] &lt;= 3</code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/)

## Solution 1. Offline Query

```cpp
// OJ: https://leetcode.com/problems/shortest-distance-to-target-color/
// Author: github.com/lzl124631x
// Time: O(QlogQ + C + Q)
// Space: O(C)
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& C, vector<vector<int>>& Q) {
        vector<int> ans(Q.size(), -1);
        for (int i = 0; i < Q.size(); ++i) Q[i].push_back(i);
        sort(begin(Q), end(Q));
        unordered_map<int, int> m;
        for (int i = 0, j = 0; i < C.size() && j < Q.size(); ++i) {
            m[C[i]] = i;
            while (j < Q.size() && Q[j][0] == i) {
                if (m.count(Q[j][1])) ans[Q[j][2]] = i - m[Q[j][1]];
                ++j;
            }
        }
        m.clear();
        for (int i = C.size() - 1, j = Q.size() - 1; i >= 0 && j >= 0; --i) {
            m[C[i]] = i;
            while (j >= 0 && Q[j][0] == i) {
                if (m.count(Q[j][1]) && (ans[Q[j][2]] == -1 || m[Q[j][1]] - i < ans[Q[j][2]])) {
                    ans[Q[j][2]] = m[Q[j][1]] - i;
                }
                --j;
            }
        }
        return ans;
    }
};
```


## TODO

https://leetcode.com/problems/shortest-distance-to-target-color/solution/