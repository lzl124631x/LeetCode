# [1109. Corporate Flight Bookings (Medium)](https://leetcode.com/problems/corporate-flight-bookings/)

<p>There are <code>n</code> flights, and they are labeled&nbsp;from <code>1</code> to <code>n</code>.</p>

<p>We have a list of flight bookings.&nbsp; The <code>i</code>-th booking&nbsp;<code>bookings[i] = [i, j, k]</code>&nbsp;means that we booked <code>k</code> seats from flights labeled <code>i</code> to <code>j</code> inclusive.</p>

<p>Return an array <code>answer</code> of length <code>n</code>, representing the number of seats booked on each flight in order of their label.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
<strong>Output:</strong> [10,55,45,25,25]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= bookings.length &lt;= 20000</code></li>
	<li><code>1 &lt;= bookings[i][0] &lt;= bookings[i][1] &lt;= n &lt;= 20000</code></li>
	<li><code>1 &lt;= bookings[i][2] &lt;= 10000</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/)

## Solution 1. Heap

```cpp
// OJ: https://leetcode.com/problems/corporate-flight-bookings/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& A, int n) {
        vector<int> ans(n);
        sort(begin(A), end(A));
        auto cmp = [&](int a, int b) { return A[a][1] > A[b][1]; };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        for (int i = 0, j = 0, sum = 0; i < n; ++i) {
            while (q.size() && A[q.top()][1] < i + 1) {
                sum -= A[q.top()][2];
                q.pop();
            }
            while (j < A.size() && A[j][0] <= i + 1 && A[j][1] >= i + 1) {
                q.push(j);
                sum += A[j++][2];
            }
            ans[i] = sum;
        }
        return ans;
    }
};
```

## Solution 2. Diff Array

```cpp
// OJ: https://leetcode.com/problems/corporate-flight-bookings/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& A, int n) {
        vector<int> ans(n);
        for (auto &v : A) {
            ans[v[0] - 1] += v[2];
            if (v[1] < n) ans[v[1]] -= v[2];
        }
        for (int i = 1; i < n; ++i) ans[i] += ans[i - 1];
        return ans;
    }
};
```