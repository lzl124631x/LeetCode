# [1499. Max Value of Equation (Hard)](https://leetcode.com/problems/max-value-of-equation/)

<p>Given an&nbsp;array <code>points</code> containing the coordinates of points on a 2D plane,&nbsp;sorted by the x-values, where <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>&nbsp;such that&nbsp;<code>x<sub>i</sub> &lt; x<sub>j</sub></code> for all <code>1 &lt;= i &lt; j &lt;= points.length</code>. You are also given an integer&nbsp;<code>k</code>.</p>

<p>Find the <em>maximum value of the equation </em><code>y<sub>i</sub>&nbsp;+ y<sub>j</sub>&nbsp;+ |x<sub>i</sub>&nbsp;- x<sub>j</sub>|</code>&nbsp;where <code>|x<sub>i</sub>&nbsp;- x<sub>j</sub>|&nbsp;&lt;= k</code>&nbsp;and <code>1 &lt;= i &lt; j &lt;= points.length</code>. It is guaranteed that there exists at least one pair of points that satisfy the constraint <code>|x<sub>i</sub>&nbsp;- x<sub>j</sub>|&nbsp;&lt;= k</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> points = [[1,3],[2,0],[5,10],[6,-10]], k = 1
<strong>Output:</strong> 4
<strong>Explanation:</strong> The first two points satisfy the condition |x<sub>i</sub>&nbsp;- x<sub>j</sub>| &lt;= 1 and if we calculate the equation we get 3 + 0 + |1 - 2| = 4. Third and fourth points also satisfy the condition and give a value of 10 + -10 + |5 - 6| = 1.
No other pairs satisfy the condition, so we return the max of 4 and 1.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> points = [[0,0],[3,0],[9,2]], k = 3
<strong>Output:</strong> 3
<strong>Explanation: </strong>Only the first two points have an absolute difference of 3 or less in the x-values, and give the value of 0 + 0 + |0 - 3| = 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= points.length &lt;= 10^5</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-10^8&nbsp;&lt;= points[i][0], points[i][1] &lt;= 10^8</code></li>
	<li><code>0 &lt;= k &lt;= 2 * 10^8</code></li>
	<li><code>points[i][0] &lt; points[j][0]</code>&nbsp;for all&nbsp;<code>1 &lt;= i &lt; j &lt;= points.length</code></li>
	<li><code>x<sub>i</sub></code>&nbsp;form a strictly increasing sequence.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

## Solution 1. Multiset

For the equation `yi + yj + |xi - xj|`, since `j > i`, so `xj` must be greater than `xi`, so the equation is the same as `yi + yj + xj - xi = xj + yj - xi + yi`. For a given `i`, `-xi + yi` is a constant, so we just need to find the maximum `xj + yj` satisfying the `k` constraint.

Keep a sliding window `[i, j)`. The elements in the window satisfy the `k` constraint. Use a `multiset<int> s` to keep the `x + y` values in the window except for that for the `A[i]`.

For this `A[i]`, the maximum value we can get is `A[i][1] - A[i][0]` plus the maximum value in the `multiset`.

```cpp
// OJ: https://leetcode.com/problems/max-value-of-equation/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& A, int k) {
        int i = 0, j = 0, N = A.size(), ans = INT_MIN;
        multiset<int> s;
        for (; i < N; ++i) {
            for (; j < N && A[j][0] - A[i][0] <= k; ++j) s.insert(A[j][0] + A[j][1]);
            s.erase(s.find(A[i][0] + A[i][1]));
            if (s.size()) ans = max(ans, A[i][1] - A[i][0] + *s.rbegin());
        }
        return ans;
    }
};
```

## Solution 2. Monoqueue

Since we only care about the maximum value in a sliding window, we can use a descending monoqueue to keep track of the maximum value.

```cpp
// OJ: https://leetcode.com/problems/max-value-of-equation/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& A, int k) {
        int i = 0, j = 0, N = A.size(), ans = INT_MIN;
        deque<int> q; // descending monoqueue
        for (; i < N; ++i) {
            for (; j < N && A[j][0] - A[i][0] <= k; ++j) {
                int sum = A[j][0] + A[j][1];
                while (q.size() && q.back() < sum) q.pop_back();
                q.push_back(sum);
            }
            if (q.size() && q.front() == A[i][0] + A[i][1]) q.pop_front();
            if (q.size()) ans = max(ans, A[i][1] - A[i][0] + q.front());
        }
        return ans;
    }
};
```