# [2398. Maximum Number of Robots Within Budget (Hard)](https://leetcode.com/problems/maximum-number-of-robots-within-budget)

<p>You have <code>n</code> robots. You are given two <strong>0-indexed</strong> integer arrays, <code>chargeTimes</code> and <code>runningCosts</code>, both of length <code>n</code>. The <code>i<sup>th</sup></code> robot costs <code>chargeTimes[i]</code> units to charge and costs <code>runningCosts[i]</code> units to run. You are also given an integer <code>budget</code>.</p>
<p>The <strong>total cost</strong> of running <code>k</code> chosen robots is equal to <code>max(chargeTimes) + k * sum(runningCosts)</code>, where <code>max(chargeTimes)</code> is the largest charge cost among the <code>k</code> robots and <code>sum(runningCosts)</code> is the sum of running costs among the <code>k</code> robots.</p>
<p>Return<em> the <strong>maximum</strong> number of <strong>consecutive</strong> robots you can run such that the total cost <strong>does not</strong> exceed </em><code>budget</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> chargeTimes = [3,6,1,3,4], runningCosts = [2,1,3,4,5], budget = 25
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
It is possible to run all individual and consecutive pairs of robots within budget.
To obtain answer 3, consider the first 3 robots. The total cost will be max(3,6,1) + 3 * sum(2,1,3) = 6 + 3 * 6 = 24 which is less than 25.
It can be shown that it is not possible to run more than 3 consecutive robots within budget, so we return 3.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> chargeTimes = [11,12,19], runningCosts = [10,8,7], budget = 19
<strong>Output:</strong> 0
<strong>Explanation:</strong> No robot can be run that does not exceed the budget, so we return 0.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>chargeTimes.length == runningCosts.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= chargeTimes[i], runningCosts[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= budget &lt;= 10<sup>15</sup></code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Queue](https://leetcode.com/tag/queue/), [Sliding Window](https://leetcode.com/tag/sliding-window/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Sliding Window Maximum (Hard)](https://leetcode.com/problems/sliding-window-maximum/)
* [Kth Smallest Product of Two Sorted Arrays (Hard)](https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/)
* [Maximum Number of Tasks You Can Assign (Hard)](https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/)
* [Minimized Maximum of Products Distributed to Any Store (Medium)](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/)
* [Minimum Time to Complete Trips (Medium)](https://leetcode.com/problems/minimum-time-to-complete-trips/)

## Solution 1. Find Maximum Sliding Window + Monotonic Dequeue

Shrinkable template:

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-robots-within-budget
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maximumRobots(vector<int>& C, vector<int>& R, long long budget) {
        long long ans = 0, N = C.size(), i = 0, j = 0, sum = 0;
        deque<int> q;
        for (; j < N; ++j) {
            sum += R[j];
            while (q.size() && C[q.back()] <= C[j]) q.pop_back();
            q.push_back(j);
            while (i <= j && C[q.front()] + (j - i + 1) * sum > budget) {
                sum -= R[i];
                if (q.front() == i) q.pop_front();
                ++i;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
```

Or Non-shrinkable template:

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-robots-within-budget
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maximumRobots(vector<int>& C, vector<int>& R, long long budget) {
        long long ans = 0, N = C.size(), i = 0, j = 0, sum = 0;
        deque<int> q;
        for (; j < N; ++j) {
            sum += R[j];
            while (q.size() && C[q.back()] <= C[j]) q.pop_back();
            q.push_back(j);
            if (i <= j && C[q.front()] + (j - i + 1) * sum > budget) {
                sum -= R[i];
                if (q.front() == i) q.pop_front();
                ++i;
            }
        }
        return j - i;
    }
};
```