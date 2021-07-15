# [370. Range Addition (Medium)](https://leetcode.com/problems/range-addition/)

<p>You are given an integer <code>length</code> and an array <code>updates</code> where <code>updates[i] = [startIdx<sub>i</sub>, endIdx<sub>i</sub>, inc<sub>i</sub>]</code>.</p>

<p>You have an array <code>arr</code> of length <code>length</code> with all zeros, and you have some operation to apply on <code>arr</code>. In the <code>i<sup>th</sup></code> operation, you should increment all the elements <code>arr[startIdx<sub>i</sub>], arr[startIdx<sub>i</sub> + 1], ..., arr[endIdx<sub>i</sub>]</code> by <code>inc<sub>i</sub></code>.</p>

<p>Return <code>arr</code> <em>after applying all the</em> <code>updates</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/27/rangeadd-grid.jpg" style="width: 413px; height: 573px;">
<pre><strong>Input:</strong> length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
<strong>Output:</strong> [-2,0,3,5,3]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> length = 10, updates = [[2,4,6],[5,6,8],[1,9,-4]]
<strong>Output:</strong> [0,-4,2,2,2,4,4,-4,-4,-4]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= updates.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= startIdx<sub>i</sub> &lt;= endIdx<sub>i</sub> &lt; length</code></li>
	<li><code>-1000 &lt;= inc<sub>i</sub> &lt;= 1000</code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Range Addition II (Easy)](https://leetcode.com/problems/range-addition-ii/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/range-addition/
// Author: github.com/lzl124631x
// Time: O(N + U)
// Space: O(1)
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& A) {
        vector<int> ans(length);
        for (auto &v : A) {
            int start = v[0], end = v[1], diff = v[2];
            ans[start] += diff;
            if (end + 1 < length) ans[end + 1] -= diff;
        }
        int sum = 0;
        for (auto &n : ans) n = sum += n;
        return ans;
    }
};
```

Or use `partial_sum`.

```cpp
// OJ: https://leetcode.com/problems/range-addition/
// Author: github.com/lzl124631x
// Time: O(N + U)
// Space: O(1)
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ans(length, 0);
        for (auto &u : updates) {
            int start = u[0], end = u[1], val = u[2];
            ans[start] += val;
            if (end + 1 < length) ans[end + 1] -= val;
        }
        partial_sum(ans.begin(), ans.end(), ans.begin());
        return ans;
    }
};
```