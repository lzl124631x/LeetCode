# [2100. Find Good Days to Rob the Bank (Medium)](https://leetcode.com/problems/find-good-days-to-rob-the-bank/)

<p>You and a gang of thieves are planning on robbing a bank. You are given a <strong>0-indexed</strong> integer array <code>security</code>, where <code>security[i]</code> is the number of guards on duty on the <code>i<sup>th</sup></code> day. The days are numbered starting from <code>0</code>. You are also given an integer <code>time</code>.</p>

<p>The <code>i<sup>th</sup></code> day is a good day to rob the bank if:</p>

<ul>
	<li>There are at least <code>time</code> days before and after the <code>i<sup>th</sup></code> day,</li>
	<li>The number of guards at the bank for the <code>time</code> days <strong>before</strong> <code>i</code> are <strong>non-increasing</strong>, and</li>
	<li>The number of guards at the bank for the <code>time</code> days <strong>after</strong> <code>i</code> are <strong>non-decreasing</strong>.</li>
</ul>

<p>More formally, this means day <code>i</code> is a good day to rob the bank if and only if <code>security[i - time] &gt;= security[i - time + 1] &gt;= ... &gt;= security[i] &lt;= ... &lt;= security[i + time - 1] &lt;= security[i + time]</code>.</p>

<p>Return <em>a list of <strong>all</strong> days <strong>(0-indexed) </strong>that are good days to rob the bank</em>.<em> The order that the days are returned in does<strong> </strong><strong>not</strong> matter.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> security = [5,3,3,3,5,6,2], time = 2
<strong>Output:</strong> [2,3]
<strong>Explanation:</strong>
On day 2, we have security[0] &gt;= security[1] &gt;= security[2] &lt;= security[3] &lt;= security[4].
On day 3, we have security[1] &gt;= security[2] &gt;= security[3] &lt;= security[4] &lt;= security[5].
No other days satisfy this condition, so days 2 and 3 are the only good days to rob the bank.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> security = [1,1,1,1,1], time = 0
<strong>Output:</strong> [0,1,2,3,4]
<strong>Explanation:</strong>
Since time equals 0, every day is a good day to rob the bank, so return every day.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> security = [1,2,3,4,5,6], time = 2
<strong>Output:</strong> []
<strong>Explanation:</strong>
No day has 2 days before it that have a non-increasing number of guards.
Thus, no day is a good day to rob the bank, so return an empty list.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> security = [1], time = 5
<strong>Output:</strong> []
<strong>Explanation:</strong>
No day has 5 days before and after it.
Thus, no day is a good day to rob the bank, so return an empty list.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= security.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= security[i], time &lt;= 10<sup>5</sup></code></li>
</ul>


**Similar Questions**:
* [Non-decreasing Array (Medium)](https://leetcode.com/problems/non-decreasing-array/)
* [Longest Mountain in Array (Medium)](https://leetcode.com/problems/longest-mountain-in-array/)
* [Find in Mountain Array (Hard)](https://leetcode.com/problems/find-in-mountain-array/)
* [Maximum Ascending Subarray Sum (Easy)](https://leetcode.com/problems/maximum-ascending-subarray-sum/)

## Solution 1. Monotonic Deque

For a window `[i - time, i + time]`, use two monotonic deques `a` and `b` to track the numbers in the first half `[i - time, i]` and second half `[i, i + time]` of the window.

Keep `a` monotonic non-increasing and `b` monotonic non-decreasing.

If both `a.size()` and `b.size()` equal `time + 1`, we add the current index `i` into the answer.

```cpp
// OJ: https://leetcode.com/problems/find-good-days-to-rob-the-bank/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(T)
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& A, int time) {
        deque<int> a, b;
        vector<int> ans;
        for (int i = 0; i + time < A.size(); ++i) {
            while (a.size() && A[a.back()] < A[i]) a.pop_back(); // Before pushing `i`, pop the indexes at the back of the deque whose corresponding value `< A[i]`
            a.push_back(i);
            if (a.front() < i - time) a.pop_front(); // Pop index if it's out of window
            while (b.size() && A[b.back()] > A[i + time]) b.pop_back(); // Before pusing `i+time`, pop the indexes at the back of the deque whose corresponding value `> A[i+time]`
            b.push_back(i + time);
            if (b.front() < i) b.pop_front(); // Pop index if it's out of window
            if (a.size() == time + 1 && b.size() == time + 1) ans.push_back(i);
        }
        return ans;
    }
};
```

## Solution 2. DP

```cpp
// OJ: https://leetcode.com/problems/find-good-days-to-rob-the-bank/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& A, int time) {
        int N = A.size(), left = 1;
        vector<int> right(N, 1), ans;
        for (int i = N - 2; i >= 0; --i) {
            if (A[i] <= A[i + 1]) right[i] += right[i + 1];
        }
        for (int i = 0; i + time < N; ++i) {
            if (i - 1 >= 0 && A[i] <= A[i - 1]) left++;
            else left = 1;
            if (left > time && right[i] > time) ans.push_back(i);
        }
        return ans;
    }
};
```