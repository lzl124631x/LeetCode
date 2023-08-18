# [2365. Task Scheduler II (Medium)](https://leetcode.com/problems/task-scheduler-ii)

<p>You are given a <strong>0-indexed</strong> array of positive integers <code>tasks</code>, representing tasks that need to be completed <strong>in order</strong>, where <code>tasks[i]</code> represents the <strong>type</strong> of the <code>i<sup>th</sup></code> task.</p>
<p>You are also given a positive integer <code>space</code>, which represents the <strong>minimum</strong> number of days that must pass <strong>after</strong> the completion of a task before another task of the <strong>same</strong> type can be performed.</p>
<p>Each day, until all tasks have been completed, you must either:</p>
<ul>
	<li>Complete the next task from <code>tasks</code>, or</li>
	<li>Take a break.</li>
</ul>
<p>Return<em> the <strong>minimum</strong> number of days needed to complete all tasks</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> tasks = [1,2,1,2,3,1], space = 3
<strong>Output:</strong> 9
<strong>Explanation:</strong>
One way to complete all tasks in 9 days is as follows:
Day 1: Complete the 0th task.
Day 2: Complete the 1st task.
Day 3: Take a break.
Day 4: Take a break.
Day 5: Complete the 2nd task.
Day 6: Complete the 3rd task.
Day 7: Take a break.
Day 8: Complete the 4th task.
Day 9: Complete the 5th task.
It can be shown that the tasks cannot be completed in less than 9 days.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> tasks = [5,8,8,5], space = 2
<strong>Output:</strong> 6
<strong>Explanation:</strong>
One way to complete all tasks in 6 days is as follows:
Day 1: Complete the 0th task.
Day 2: Complete the 1st task.
Day 3: Take a break.
Day 4: Take a break.
Day 5: Complete the 2nd task.
Day 6: Complete the 3rd task.
It can be shown that the tasks cannot be completed in less than 6 days.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= tasks.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= tasks[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= space &lt;= tasks.length</code></li>
</ul>

**Companies**:
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Simulation](https://leetcode.com/tag/simulation/)

**Similar Questions**:
* [Task Scheduler (Medium)](https://leetcode.com/problems/task-scheduler/)
* [Maximize Distance to Closest Person (Medium)](https://leetcode.com/problems/maximize-distance-to-closest-person/)
* [Check If All 1's Are at Least Length K Places Away (Easy)](https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/task-scheduler-ii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(T) where T is the number of unique tasks
class Solution {
public:
    long long taskSchedulerII(vector<int>& A, int space) {
        long long i = 0, N = A.size();
        unordered_map<int, long long> prev; // task ID -> previous occurrence's index
        for (int n : A) {
            if (prev.count(n)) {
                i += max(0LL, space - i + prev[n] + 1); // currently at `i`. There are `i-prev[n]-1` space between `i` and the previous occurrence. If `i-prev[n]-1 < space`, we need to pad `space-(i-prev[n]-1)`.
            }
            prev[n] = i;
            ++i;
        }
        return i;
    }
};
```