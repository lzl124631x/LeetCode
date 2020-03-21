# [1386. Cinema Seat Allocation (Medium)](https://leetcode.com/problems/cinema-seat-allocation/)

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/02/14/cinema_seats_1.png" style="width: 400px; height: 149px;"></p>

<p>A cinema&nbsp;has <code>n</code>&nbsp;rows of seats, numbered from 1 to <code>n</code>&nbsp;and there are ten&nbsp;seats in each row, labelled from 1&nbsp;to 10&nbsp;as shown in the figure above.</p>

<p>Given the array <code>reservedSeats</code> containing the numbers of seats already reserved, for example, <code>reservedSeats[i]=[3,8]</code>&nbsp;means the seat located in row <strong>3</strong> and labelled with <b>8</b>&nbsp;is already reserved.&nbsp;</p>

<p><em>Return the maximum number of four-person families you can allocate on the cinema&nbsp;seats.</em> A four-person family occupies fours seats <strong>in one row</strong>, that are <strong>next to each other</strong>. Seats across an aisle (such as [3,3]&nbsp;and [3,4]) are not considered to be next to each other, however, It is permissible for the four-person family to be separated by an aisle, but in that case, <strong>exactly two people</strong> have to sit on each side of the aisle.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/02/14/cinema_seats_3.png" style="width: 400px; height: 96px;"></p>

<pre><strong>Input:</strong> n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The figure above shows the optimal allocation for four families, where seats mark with blue are already reserved and contiguous seats mark with orange are for one family.&nbsp;
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
<strong>Output:</strong> 2
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^9</code></li>
	<li><code>1 &lt;=&nbsp;reservedSeats.length &lt;= min(10*n, 10^4)</code></li>
	<li><code>reservedSeats[i].length == 2</code></li>
	<li><code>1&nbsp;&lt;=&nbsp;reservedSeats[i][0] &lt;= n</code></li>
	<li><code>1 &lt;=&nbsp;reservedSeats[i][1] &lt;= 10</code></li>
	<li>All <code>reservedSeats[i]</code> are distinct.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/cinema-seat-allocation/
// Author: github.com/lzl124631x
// Time: O(SlogS)
// Space: O(1)
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& A) {
        sort(A.begin(), A.end());
        int ans = 2 * n, i = 0, N = A.size();
        while (i < N) {
            vector<int> v(4,1);
            int j = i;
            for (;j < N && A[i][0] == A[j][0];++j) {
                if (A[j][1] == 1 || A[j][1] == 10) continue;
                v[A[j][1]/2-1] = 0;
            }
            int c = 0;
            if (v[0] && v[1]) ++c;
            if (v[2] && v[3]) ++c;
            if (!c && v[1] && v[2]) ++c;
            i = j;
            ans -= 2 - c;
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/cinema-seat-allocation/
// Author: github.com/lzl124631x
// Time: O(S)
// Space: O(S)
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& A) {
        int ans = 2 * n;
        unordered_map<int, char> m;
        for (auto &s : A) {
            if (s[1] == 1 || s[1] == 10) continue;
            m[s[0]] |= 1 << (s[1] - 2);
        }
        for (auto &p : m) {
            bool a = !(p.second & 0b11110000);
            bool b = !(p.second & 0b00111100);
            bool c = !(p.second & 0b00001111);
            if (a && c) continue;
            if (a || b || c) --ans;
            else ans -= 2;
        }
        return ans;
    }
};
```