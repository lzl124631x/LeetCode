# [1893. Check if All the Integers in a Range Are Covered (Easy)](https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/)

<p>You are given a 2D integer array <code>ranges</code> and two integers <code>left</code> and <code>right</code>. Each <code>ranges[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> represents an <strong>inclusive</strong> interval between <code>start<sub>i</sub></code> and <code>end<sub>i</sub></code>.</p>

<p>Return <code>true</code> <em>if each integer in the inclusive range</em> <code>[left, right]</code> <em>is covered by <strong>at least one</strong> interval in</em> <code>ranges</code>. Return <code>false</code> <em>otherwise</em>.</p>

<p>An integer <code>x</code> is covered by an interval <code>ranges[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> if <code>start<sub>i</sub> &lt;= x &lt;= end<sub>i</sub></code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> ranges = [[1,2],[3,4],[5,6]], left = 2, right = 5
<strong>Output:</strong> true
<strong>Explanation:</strong> Every integer between 2 and 5 is covered:
- 2 is covered by the first range.
- 3 and 4 are covered by the second range.
- 5 is covered by the third range.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> ranges = [[1,10],[10,20]], left = 21, right = 21
<strong>Output:</strong> false
<strong>Explanation:</strong> 21 is not covered by any range.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= ranges.length &lt;= 50</code></li>
	<li><code>1 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt;= 50</code></li>
	<li><code>1 &lt;= left &lt;= right &lt;= 50</code></li>
</ul>


**Companies**:  
[Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool isCovered(vector<vector<int>>& A, int left, int right) {
        unordered_set<int> s;
        for (auto &v : A) {
            for (int i = max(left,v[0]); i <= min(right,v[1]); ++i) {
                s.insert(i);
            }
        }
        return s.size() == right - left + 1;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    bool isCovered(vector<vector<int>>& A, int left, int right) {
        sort(begin(A), end(A));
        if (A[0][0] > left) return false;
        int i = 0, j = A[0][0];
        while (i < A.size()) {
            if (j < A[i][0] - 1) return false;
            j = max(j, A[i][1]);
            ++i;
            if (j >= right) return true;
        }
        return false;
    }
};
```