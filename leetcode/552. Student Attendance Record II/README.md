# [552. Student Attendance Record II (Hard)](https://leetcode.com/problems/student-attendance-record-ii/)

<p>Given a positive integer <b>n</b>, return the number of all possible attendance records with length n, which will be regarded as rewardable. The answer may be very large, return it after mod 10<sup>9</sup> + 7.</p>

<p>A student attendance record is a string that only contains the following three characters:</p>

<p>
</p><ol>
<li><b>'A'</b> : Absent. </li>
<li><b>'L'</b> : Late.</li>
<li> <b>'P'</b> : Present. </li>
</ol>
<p></p>

<p>
A record is regarded as rewardable if it doesn't contain <b>more than one 'A' (absent)</b> or <b>more than two continuous 'L' (late)</b>.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> n = 2
<b>Output:</b> 8 
<b>Explanation:</b>
There are 8 records with length 2 will be regarded as rewardable:
"PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
Only "AA" won't be regarded as rewardable owing to more than one absent times. 
</pre>
<p></p>

<p><b>Note:</b>
The value of <b>n</b> won't exceed 100,000.
</p>




**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Student Attendance Record I (Easy)](https://leetcode.com/problems/student-attendance-record-i/)

## Solution 1. Simulation

At each step, we have 3 options, append 'A', 'L', or 'P'.

Let `v[i][A][L]` is the number of all possible records that have `i + 1` charactors and only have `A` 'A's and consecutive `L` 'L's.

Assume we are visiting `v[i][A][L]` and `v[i][A][L] = val`.

If we append 'A', then the next state will be `[i + 1][A + 1][0]`, so `v[i + 1][A + 1][0] += val`. Note that we can't do this if `A == 1`.

If we append 'L', then the next state will be `[i + 1][A][L + 1]`, so `v[i + 1][A][L + 1] += val`. Note that we can't do this if `L == 2`.

If we append 'P', then the next state will be `[i + 1][A][0]`, so `v[i + 1][A][0] += val`.

```cpp
// OJ: https://leetcode.com/problems/student-attendance-record-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int checkRecord(int n) {
        auto v = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(2, vector<int>(3)));
        long long ans = 0, mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            for (int A = 0; A <= 1; ++A) {
                for (int L = 0; L <= 2; ++L) {
                    if (A + L > i + 1) continue;
                    int val = i == 0 ? 1 : v[i][A][L];
                    if (A != 1) v[i + 1][A + 1][0] = (v[i + 1][A + 1][0] + val) % mod;
                    if (L != 2) v[i + 1][A][L + 1] = (v[i + 1][A][L + 1] + val) % mod;
                    v[i + 1][A][0] = (v[i + 1][A][0] + val) % mod;
                    if (i == n - 1) ans = (ans + val) % mod;
                }
            }
        }
        return ans;
    }
};
```

## Solution 2. Simulation + Space Optimization

Since only two layers are related (`i` and `i + 1`), we can reduce the array from `N * 2 * 3` to `2 * 2 * 3`.

```cpp
// OJ: https://leetcode.com/problems/student-attendance-record-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int checkRecord(int n) {
        auto v = vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(3)));
        long long ans = 0, mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            for (int A = 0; A <= 1; ++A) {
                for (int L = 0; L <= 2; ++L) {
                    v[(i + 1) % 2][A][L] = 0;
                }
            }
            for (int A = 0; A <= 1; ++A) {
                for (int L = 0; L <= 2; ++L) {
                    if (A + L > i + 1) continue;
                    int val = i == 0 ? 1 : v[i % 2][A][L];
                    if (A != 1) v[(i + 1) % 2][A + 1][0] = (v[(i + 1) % 2][A + 1][0] + val) % mod;
                    if (L != 2) v[(i + 1) % 2][A][L + 1] = (v[(i + 1) % 2][A][L + 1] + val) % mod;
                    v[(i + 1) % 2][A][0] = (v[(i + 1) % 2][A][0] + val) % mod;
                    if (i == n - 1) ans = (ans + val) % mod;
                }
            }
        }
        return ans;
    }
};
```