# [1997. First Day Where You Have Been in All the Rooms (Medium)](https://leetcode.com/problems/first-day-where-you-have-been-in-all-the-rooms/)

<p>There are <code>n</code> rooms you need to visit, labeled from <code>0</code> to <code>n - 1</code>. Each day is labeled, starting from <code>0</code>. You will go in and visit one room a day.</p>

<p>Initially on day <code>0</code>, you visit room <code>0</code>. The <strong>order</strong> you visit the rooms for the coming days is determined by the following <strong>rules</strong> and a given <strong>0-indexed</strong> array <code>nextVisit</code> of length <code>n</code>:</p>

<ul>
	<li>Assuming that on a day, you visit room <code>i</code>,</li>
	<li>if you have been in room <code>i</code> an <strong>odd</strong> number of times (<strong>including</strong> the current visit), on the <strong>next</strong> day you will visit the room specified by <code>nextVisit[i]</code> where <code>0 &lt;= nextVisit[i] &lt;= i</code>;</li>
	<li>if you have been in room <code>i</code> an <strong>even</strong> number of times (<strong>including</strong> the current visit), on the <strong>next</strong> day you will visit room <code>(i + 1) mod n</code>.</li>
</ul>

<p>Return <em>the label of the <strong>first</strong> day where you have been in <strong>all</strong> the rooms</em>. It can be shown that such a day exists. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nextVisit = [0,0]
<strong>Output:</strong> 2
<strong>Explanation:</strong>
- On day 0, you visit room 0. The total times you have been in room 0 is 1, which is odd.
&nbsp; On the next day you will visit room nextVisit[0] = 0
- On day 1, you visit room 0, The total times you have been in room 0 is 2, which is even.
&nbsp; On the next day you will visit room (0 + 1) mod 2 = 1
- On day 2, you visit room 1. This is the first day where you have been in all the rooms.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nextVisit = [0,0,2]
<strong>Output:</strong> 6
<strong>Explanation:</strong>
Your room visiting order for each day is: [0,0,1,0,0,1,2,...].
Day 6 is the first day where you have been in all the rooms.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nextVisit = [0,1,2,0]
<strong>Output:</strong> 6
<strong>Explanation:</strong>
Your room visiting order for each day is: [0,0,1,1,2,2,3,...].
Day 6 is the first day where you have been in all the rooms.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nextVisit.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nextVisit[i] &lt;= i</code></li>
</ul>


## Solution 1. DP

Let `dp[i]` be the number of days needed to jump from room `0` to room `i`. The answer is `dp[N - 1]`.

For `dp[i]`, on top of the days needed for reaching room `i-1`, i.e. `dp[i-1]`, we need these extra days to go from room `i-1` to room `i`.

* If `A[i-1] == i-1`, we just need 2 days
* Otherwise, we need to jump to room `A[i-1]` first, taking 1 day. Then spent `dp[i-1] - dp[A[i-1]]` days to go from room `A[i-1]` to room `i-1` again. Lastly, take 1 day to go from room `i-1` to room `i`. So in total, we need extra `2 + dp[i-1] - dp[A[i-1]]` days.

After some simplification, we get the following:
```
dp[i] = dp[i-1]                           // days needed to reach room i - 1
          + 2 + dp[i-1] - dp[A[i-1]]      // days needed to go from room i - 1 to room i
      = 2 + 2 * dp[i-1] - dp[A[i-1]]
               where 0 <= i < N - 1
dp[0] = 0
```

```cpp
// OJ: https://leetcode.com/problems/first-day-where-you-have-been-in-all-the-rooms/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& A) {
        long mod = 1e9 + 7, N = A.size();
        vector<int> dp(N + 1);
        for (int i = 1; i < N; ++i) {
            dp[i] = ((long)2 + 2 * dp[i - 1] - dp[A[i - 1]] + mod) % mod;
        }
        return dp[N - 1];
    }
};
```


## Discuss

https://leetcode.com/problems/first-day-where-you-have-been-in-all-the-rooms/discuss/1445156/C%2B%2B-DP