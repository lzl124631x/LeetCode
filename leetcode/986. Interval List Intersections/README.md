# [986. Interval List Intersections (Medium)](https://leetcode.com/problems/interval-list-intersections/)

<p>Given two lists&nbsp;of <strong>closed</strong> intervals, each list of intervals is pairwise disjoint and in sorted order.</p>

<p>Return the intersection of these two interval lists.</p>

<p><em>(Formally, a closed interval <code>[a, b]</code> (with <code>a &lt;= b</code>) denotes&nbsp;the set of real numbers <code>x</code> with <code>a &lt;= x &lt;= b</code>.&nbsp; The&nbsp;intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.&nbsp; For example, the intersection of [1, 3] and [2, 4] is [2, 3].)</em></p>

<div>
<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/01/30/interval1.png" style="width: 506px; height: 140px;"></strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-1-1">[[0,2],[5,10],[13,23],[24,25]]</span>, B = <span id="example-input-1-2">[[1,5],[8,12],[15,24],[25,26]]</span>
<strong>Output: </strong><span id="example-output-1">[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]</span>
<strong>Reminder: </strong>The inputs and the desired output are lists of Interval&nbsp;objects, and not arrays or lists.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>0 &lt;= A.length &lt; 1000</code></li>
	<li><code>0 &lt;= B.length &lt; 1000</code></li>
	<li><code>0 &lt;= A[i].start, A[i].end, B[i].start, B[i].end &lt; 10^9</code></li>
</ol>
</div>

**Companies**:  
[Uber](https://leetcode.com/company/uber), [Facebook](https://leetcode.com/company/facebook), [DoorDash](https://leetcode.com/company/doordash)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [Merge Intervals (Medium)](https://leetcode.com/problems/merge-intervals/)
* [Merge Sorted Array (Easy)](https://leetcode.com/problems/merge-sorted-array/)
* [Employee Free Time (Hard)](https://leetcode.com/problems/employee-free-time/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/interval-list-intersections/
// Author: github.com/lzl124631x
// Time: O(M+N)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int M = A.size(), N = B.size();
        vector<vector<int>> ans;
        for (int i = 0, j = 0; i < M && j < N; ) {
            int s = max(A[i][0], B[j][0]), e = min(A[i][1], B[j][1]);
            if (s <= e) ans.push_back({ s, e });
            if (A[i][1] < B[j][1]) ++i;
            else ++j;
        }
        return ans;
    }
};
```