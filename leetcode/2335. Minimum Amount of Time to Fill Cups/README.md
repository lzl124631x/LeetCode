# [2335. Minimum Amount of Time to Fill Cups (Easy)](https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups)

<p>You have a water dispenser that can dispense cold, warm, and hot water. Every second, you can either fill up <code>2</code> cups with <strong>different</strong> types of water, or <code>1</code> cup of any type of water.</p>
<p>You are given a <strong>0-indexed</strong> integer array <code>amount</code> of length <code>3</code> where <code>amount[0]</code>, <code>amount[1]</code>, and <code>amount[2]</code> denote the number of cold, warm, and hot water cups you need to fill respectively. Return <em>the <strong>minimum</strong> number of seconds needed to fill up all the cups</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> amount = [1,4,2]
<strong>Output:</strong> 4
<strong>Explanation:</strong> One way to fill up the cups is:
Second 1: Fill up a cold cup and a warm cup.
Second 2: Fill up a warm cup and a hot cup.
Second 3: Fill up a warm cup and a hot cup.
Second 4: Fill up a warm cup.
It can be proven that 4 is the minimum number of seconds needed.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> amount = [5,4,4]
<strong>Output:</strong> 7
<strong>Explanation:</strong> One way to fill up the cups is:
Second 1: Fill up a cold cup, and a hot cup.
Second 2: Fill up a cold cup, and a warm cup.
Second 3: Fill up a cold cup, and a warm cup.
Second 4: Fill up a warm cup, and a hot cup.
Second 5: Fill up a cold cup, and a hot cup.
Second 6: Fill up a cold cup, and a warm cup.
Second 7: Fill up a hot cup.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> amount = [5,0,0]
<strong>Output:</strong> 5
<strong>Explanation:</strong> Every second, we fill up a cold cup.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>amount.length == 3</code></li>
	<li><code>0 &lt;= amount[i] &lt;= 100</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/)

**Similar Questions**:
* [Construct Target Array With Multiple Sums (Hard)](https://leetcode.com/problems/construct-target-array-with-multiple-sums/)
* [Maximum Score From Removing Stones (Medium)](https://leetcode.com/problems/maximum-score-from-removing-stones/)
* [Maximum Running Time of N Computers (Hard)](https://leetcode.com/problems/maximum-running-time-of-n-computers/)
* [Minimum Cost to Make Array Equal (Hard)](https://leetcode.com/problems/minimum-cost-to-make-array-equal/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int fillCups(vector<int>& A) {
        int ans = 0;
        priority_queue<int> pq;
        for (int n : A) {
            if (n) pq.push(n);
        }
        while (pq.size() >= 2) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if (a - 1 > 0) pq.push(a - 1);
            if (b - 1 > 0) pq.push(b - 1);
            ++ans;
        }
        if (pq.size()) ans += pq.top();
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/solutions/2261394/java-c-python-max-max-a-sum-a-1-2/
class Solution {
public:
    int fillCups(vector<int>& A) {
        int mx = 0, sum = 0;
        for (int n : A) {
            mx = max(mx, n);
            sum += n;
        }
        return max(mx, (sum + 1) / 2);
    }
};
```