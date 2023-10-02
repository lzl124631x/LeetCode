# [1705. Maximum Number of Eaten Apples (Medium)](https://leetcode.com/problems/maximum-number-of-eaten-apples/)

<p>There is a special kind of apple tree that grows apples every day for <code>n</code> days. On the <code>i<sup>th</sup></code> day, the tree grows <code>apples[i]</code> apples that will rot after <code>days[i]</code> days, that is on day <code>i + days[i]</code> the apples will be rotten and cannot be eaten. On some days, the apple tree does not grow any apples, which are denoted by <code>apples[i] == 0</code> and <code>days[i] == 0</code>.</p>

<p>You decided to eat <strong>at most</strong> one apple a day (to keep the doctors away). Note that you can keep eating after the first <code>n</code> days.</p>

<p>Given two integer arrays <code>days</code> and <code>apples</code> of length <code>n</code>, return <em>the maximum number of apples you can eat.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> apples = [1,2,3,5,2], days = [3,2,1,4,2]
<strong>Output:</strong> 7
<strong>Explanation:</strong> You can eat 7 apples:
- On the first day, you eat an apple that grew on the first day.
- On the second day, you eat an apple that grew on the second day.
- On the third day, you eat an apple that grew on the second day. After this day, the apples that grew on the third day rot.
- On the fourth to the seventh days, you eat apples that grew on the fourth day.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> apples = [3,0,0,0,0,2], days = [3,0,0,0,0,2]
<strong>Output:</strong> 5
<strong>Explanation:</strong> You can eat 5 apples:
- On the first to the third day you eat apples that grew on the first day.
- Do nothing on the fouth and fifth days.
- On the sixth and seventh days you eat apples that grew on the sixth day.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>apples.length == n</code></li>
	<li><code>days.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= apples[i], days[i] &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>days[i] = 0</code> if and only if <code>apples[i] = 0</code>.</li>
</ul>


**Related Topics**:  
[Heap](https://leetcode.com/tag/heap/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

We greedily pick the apples with smallest end time.

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-eaten-apples/
// Author: github.com/lzl124631x
// Time: O(SUM(A) * logN)
// Space: O(N)
class Solution {
public:
    int eatenApples(vector<int>& A, vector<int>& D) {
        int N = A.size(), ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // end time, cnt
        for (int i = 0; i < N || pq.size(); ++i) {
            while (pq.size()) {
                auto [end, cnt] = pq.top(); // remove rotten apples
                if (end <= i) pq.pop();
                else break;
            }
            if (i < N && A[i] != 0) pq.emplace(i + D[i], A[i]);
            if (pq.size()) { // greedily use the one with the smallest end time
                auto [end, cnt] = pq.top();
                pq.pop();
                ++ans;
                if (cnt - 1 > 0) pq.emplace(end, cnt - 1);
            }
        }
        return ans;
    }
};
```

When `i >= N`, we don't need to pick the apples one by one. Instead, we can take all the apples in ascending order of the end time as long as it's not rotten.

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-eaten-apples/
// Author: github.com/lzl124631x
// Time: O(SUM(A) * logN)
// Space: O(N)
class Solution {
public:
    int eatenApples(vector<int>& A, vector<int>& D) {
        int N = A.size(), day = N, ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // end time, cnt
        for (int i = 0; i < N; ++i) {
            while (pq.size()) {
                auto [end, cnt] = pq.top(); // remove rotten apples
                if (end <= i) pq.pop();
                else break;
            }
            if (i < N && A[i] != 0) pq.emplace(i + D[i], A[i]);
            if (pq.size()) { // greedily use the one with the smallest end time
                auto [end, cnt] = pq.top();
                pq.pop();
                ++ans;
                if (cnt - 1 > 0) pq.emplace(end, cnt - 1);
            }
        }
        while (pq.size()) {
            auto [end, cnt] = pq.top();
            pq.pop();
            if (end <= day) continue;
            int c = min(cnt, end - day);
            ans += c;
            day += c;
        }
        return ans;
    }
};
```