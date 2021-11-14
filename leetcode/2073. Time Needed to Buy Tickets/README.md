# [2073. Time Needed to Buy Tickets (Easy)](https://leetcode.com/problems/time-needed-to-buy-tickets/)

<p>There are <code>n</code> people in a line queuing to buy tickets, where the <code>0<sup>th</sup></code> person is at the <strong>front</strong> of the line and the <code>(n - 1)<sup>th</sup></code> person is at the <strong>back</strong> of the line.</p>

<p>You are given a <strong>0-indexed</strong> integer array <code>tickets</code> of length <code>n</code> where the number of tickets that the <code>i<sup>th</sup></code> person would like to buy is <code>tickets[i]</code>.</p>

<p>Each person takes <strong>exactly 1 second</strong> to buy a ticket. A person can only buy <strong>1 ticket at a time</strong> and has to go back to <strong>the end</strong> of the line (which happens <strong>instantaneously</strong>) in order to buy more tickets. If a person does not have any tickets left to buy, the person will <strong>leave </strong>the line.</p>

<p>Return <em>the <strong>time taken</strong> for the person at position </em><code>k</code><em>&nbsp;</em><strong><em>(0-indexed)</em>&nbsp;</strong><em>to finish buying tickets</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> tickets = [2,3,2], k = 2
<strong>Output:</strong> 6
<strong>Explanation:</strong> 
- In the first pass, everyone in the line buys a ticket and the line becomes [1, 2, 1].
- In the second pass, everyone in the line buys a ticket and the line becomes [0, 1, 0].
The person at&nbsp;position 2 has successfully bought 2 tickets and it took 3 + 3 = 6 seconds.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> tickets = [5,1,1,1], k = 0
<strong>Output:</strong> 8
<strong>Explanation:</strong>
- In the first pass, everyone in the line buys a ticket and the line becomes [4, 0, 0, 0].
- In the next 4 passes, only the person in position 0 is buying tickets.
The person at&nbsp;position 0 has successfully bought 5 tickets and it took 4 + 1 + 1 + 1 + 1 = 8 seconds.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == tickets.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= tickets[i] &lt;= 100</code></li>
	<li><code>0 &lt;= k &lt; n</code></li>
</ul>


**Similar Questions**:
* [Number of Students Unable to Eat Lunch (Easy)](https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/)

## Solution 1. Brute Force Simulation

```cpp
// OJ: https://leetcode.com/problems/time-needed-to-buy-tickets/
// Author: github.com/lzl124631x
// Time: O(SUM(A))
// Space: O(1)
class Solution {
public:
    int timeRequiredToBuy(vector<int>& A, int k) {
        int step = 0;
        while (true) {
            for (int i = 0; i < A.size(); ++i) {
                if (A[i] == 0) continue;
                A[i]--;
                ++step;
                if (A[k] == 0) return step;
            }
        }
    }
};
```

## Solution 2. One Pass

For `i <= k`, `A[i]` contributes `min(A[k], A[i])` steps.

For `i > k`, `A[i]` contributes `min(A[k] - 1, A[i])` steps.

```cpp
// OJ: https://leetcode.com/problems/time-needed-to-buy-tickets/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int timeRequiredToBuy(vector<int>& A, int k) {
        int ans = 0;
        for (int i = 0; i < A.size(); ++i) {
            ans += min(A[k] - (i > k), A[i]);
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/time-needed-to-buy-tickets/discuss/1576932/C%2B%2B-One-Pass