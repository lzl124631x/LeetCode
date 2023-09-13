# [2432. The Employee That Worked on the Longest Task (Easy)](https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task)

<p>There are <code>n</code> employees, each with a unique id from <code>0</code> to <code>n - 1</code>.</p>
<p>You are given a 2D integer array <code>logs</code> where <code>logs[i] = [id<sub>i</sub>, leaveTime<sub>i</sub>]</code> where:</p>
<ul>
	<li><code>id<sub>i</sub></code> is the id of the employee that worked on the <code>i<sup>th</sup></code> task, and</li>
	<li><code>leaveTime<sub>i</sub></code> is the time at which the employee finished the <code>i<sup>th</sup></code> task. All the values <code>leaveTime<sub>i</sub></code> are <strong>unique</strong>.</li>
</ul>
<p>Note that the <code>i<sup>th</sup></code> task starts the moment right after the <code>(i - 1)<sup>th</sup></code> task ends, and the <code>0<sup>th</sup></code> task starts at time <code>0</code>.</p>
<p>Return <em>the id of the employee that worked the task with the longest time.</em> If there is a tie between two or more employees, return<em> the <strong>smallest</strong> id among them</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> n = 10, logs = [[0,3],[2,5],[0,9],[1,15]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
Task 0 started at 0 and ended at 3 with 3 units of times.
Task 1 started at 3 and ended at 5 with 2 units of times.
Task 2 started at 5 and ended at 9 with 4 units of times.
Task 3 started at 9 and ended at 15 with 6 units of times.
The task with the longest time is task 3 and the employee with id 1 is the one that worked on it, so we return 1.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> n = 26, logs = [[1,1],[3,7],[2,12],[7,17]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
Task 0 started at 0 and ended at 1 with 1 unit of times.
Task 1 started at 1 and ended at 7 with 6 units of times.
Task 2 started at 7 and ended at 12 with 5 units of times.
Task 3 started at 12 and ended at 17 with 5 units of times.
The tasks with the longest time is task 1. The employee that worked on it is 3, so we return 3.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> n = 2, logs = [[0,10],[1,20]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> 
Task 0 started at 0 and ended at 10 with 10 units of times.
Task 1 started at 10 and ended at 20 with 10 units of times.
The tasks with the longest time are tasks 0 and 1. The employees that worked on them are 0 and 1, so we return the smallest id 0.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>2 &lt;= n &lt;= 500</code></li>
	<li><code>1 &lt;= logs.length &lt;= 500</code></li>
	<li><code>logs[i].length == 2</code></li>
	<li><code>0 &lt;= id<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>1 &lt;= leaveTime<sub>i</sub> &lt;= 500</code></li>
	<li><code>id<sub>i</sub> != id<sub>i+1</sub></code></li>
	<li><code>leaveTime<sub>i</sub></code> are sorted in a strictly increasing order.</li>
</ul>

**Companies**:
[Morgan Stanley](https://leetcode.com/company/morgan-stanley)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& A) {
        int t = 0, ans = A[0][0], longest = 0;
        for (auto &v : A) {
            int time = v[1] - t;
            if (time > longest || (time == longest && v[0] < ans)) longest = time, ans = v[0];
            t = v[1];
        }
        return ans;
    }
};
```