# [2071. Maximum Number of Tasks You Can Assign (Hard)](https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/)

<p>You have <code>n</code> tasks and <code>m</code> workers. Each task has a strength requirement stored in a <strong>0-indexed</strong> integer array <code>tasks</code>, with the <code>i<sup>th</sup></code> task requiring <code>tasks[i]</code> strength to complete. The strength of each worker is stored in a <strong>0-indexed</strong> integer array <code>workers</code>, with the <code>j<sup>th</sup></code> worker having <code>workers[j]</code> strength. Each worker can only be assigned to a <strong>single</strong> task and must have a strength <strong>greater than or equal</strong> to the task's strength requirement (i.e., <code>workers[j] &gt;= tasks[i]</code>).</p>

<p>Additionally, you have <code>pills</code> magical pills that will <strong>increase a worker's strength</strong> by <code>strength</code>. You can decide which workers receive the magical pills, however, you may only give each worker <strong>at most one</strong> magical pill.</p>

<p>Given the <strong>0-indexed </strong>integer arrays <code>tasks</code> and <code>workers</code> and the integers <code>pills</code> and <code>strength</code>, return <em>the <strong>maximum</strong> number of tasks that can be completed.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> tasks = [<u><strong>3</strong></u>,<u><strong>2</strong></u>,<u><strong>1</strong></u>], workers = [<u><strong>0</strong></u>,<u><strong>3</strong></u>,<u><strong>3</strong></u>], pills = 1, strength = 1
<strong>Output:</strong> 3
<strong>Explanation:</strong>
We can assign the magical pill and tasks as follows:
- Give the magical pill to worker 0.
- Assign worker 0 to task 2 (0 + 1 &gt;= 1)
- Assign worker 1 to task 1 (3 &gt;= 2)
- Assign worker 2 to task 0 (3 &gt;= 3)
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> tasks = [<u><strong>5</strong></u>,4], workers = [<u><strong>0</strong></u>,0,0], pills = 1, strength = 5
<strong>Output:</strong> 1
<strong>Explanation:</strong>
We can assign the magical pill and tasks as follows:
- Give the magical pill to worker 0.
- Assign worker 0 to task 0 (0 + 5 &gt;= 5)
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> tasks = [<u><strong>10</strong></u>,<u><strong>15</strong></u>,30], workers = [<u><strong>0</strong></u>,<u><strong>10</strong></u>,10,10,10], pills = 3, strength = 10
<strong>Output:</strong> 2
<strong>Explanation:</strong>
We can assign the magical pills and tasks as follows:
- Give the magical pill to worker 0 and worker 1.
- Assign worker 0 to task 0 (0 + 10 &gt;= 10)
- Assign worker 1 to task 1 (10 + 10 &gt;= 15)
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> tasks = [<u><strong>5</strong></u>,9,<u><strong>8</strong></u>,<u><strong>5</strong></u>,9], workers = [1,<strong><u>6</u></strong>,<u><strong>4</strong></u>,2,<u><strong>6</strong></u>], pills = 1, strength = 5
<strong>Output:</strong> 3
<strong>Explanation:</strong>
We can assign the magical pill and tasks as follows:
- Give the magical pill to worker 2.
- Assign worker 1 to task 0 (6 &gt;= 5)
- Assign worker 2 to task 2 (4 + 5 &gt;= 8)
- Assign worker 4 to task 3 (6 &gt;= 5)
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == tasks.length</code></li>
	<li><code>m == workers.length</code></li>
	<li><code>1 &lt;= n, m &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= pills &lt;= m</code></li>
	<li><code>0 &lt;= tasks[i], workers[j], strength &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Greedy](https://leetcode.com/tag/greedy/), [Queue](https://leetcode.com/tag/queue/), [Sorting](https://leetcode.com/tag/sorting/), [Monotonic Queue](https://leetcode.com/tag/monotonic-queue/)

**Similar Questions**:
* [Most Profit Assigning Work (Medium)](https://leetcode.com/problems/most-profit-assigning-work/)

## Solution 1. Binary Answer

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/
// Author: github.com/lzl124631x
// Time: O(log(min(T, W)) * WlogW)
// Space: O(W)
// Ref: https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/discuss/1575887/C%2B%2B-or-Binary-Search-%2B-Intuitive-Greedy-Idea-or-Detailed-Explanation-%2B-Comments
class Solution {
public:
    int maxTaskAssign(vector<int>& T, vector<int>& W, int P, int S) {
        sort(begin(T), end(T));
        sort(begin(W), end(W));
        auto valid = [&](int cnt) {
            multiset<int> s(begin(W), end(W));
            int match = 0;
            bool ans = true;
            for (int i = cnt - 1; i >= 0; --i) {
                if (T[i] <= *s.rbegin()) {
                    s.erase(prev(s.end()));
                } else {
                    auto it = s.lower_bound(T[i] - S);
                    if (it != s.end()) {
                        ++match;
                        s.erase(it);
                    } else {
                        ans = false;
                        break;
                    }
                }
                if (match > P) {
                    ans = false;
                    break;
                }
            }
            return ans;
        };
        int L = 0, R = min(T.size(), W.size());
        while (L <= R) {
            int M = (L + R) / 2;
            if (valid(M)) L = M + 1;
            else R = M - 1;
        }
        return R;
    }
};
```