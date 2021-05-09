# [1854. Maximum Population Year (Easy)](https://leetcode.com/problems/maximum-population-year/)

<p>You are given a 2D integer array <code>logs</code> where each <code>logs[i] = [birth<sub>i</sub>, death<sub>i</sub>]</code> indicates the birth and death years of the <code>i<sup>th</sup></code> person.</p>

<p>The <strong>population</strong> of some year <code>x</code> is the number of people alive during that year. The <code>i<sup>th</sup></code> person is counted in year <code>x</code>'s population if <code>x</code> is in the <strong>inclusive</strong> range <code>[birth<sub>i</sub>, death<sub>i</sub> - 1]</code>. Note that the person is <strong>not</strong> counted in the year that they die.</p>

<p>Return <em>the <strong>earliest</strong> year with the <strong>maximum population</strong></em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> logs = [[1993,1999],[2000,2010]]
<strong>Output:</strong> 1993
<strong>Explanation:</strong> The maximum population is 1, and 1993 is the earliest year with this population.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> logs = [[1950,1961],[1960,1971],[1970,1981]]
<strong>Output:</strong> 1960
<strong>Explanation:</strong> 
The maximum population is 2, and it had happened in years 1960 and 1970.
The earlier year between them is 1960.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= logs.length &lt;= 100</code></li>
	<li><code>1950 &lt;= birth<sub>i</sub> &lt; death<sub>i</sub> &lt;= 2050</code></li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/maximum-population-year/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& A) {
        sort(begin(A), end(A));
        int ans = 0, mx = 0, N = A.size();
        for (int i = 0; i < N; ++i) {
            int yr = A[i][0], cnt = 0;
            for (int j = 0; j < N; ++j) {
                cnt += A[j][0] <= yr && A[j][1] > yr;
            }
            if (cnt > mx) {
                mx = cnt;
                ans = yr;
            }
        }
        return ans;
    }
};
```

## Solution 2. Line Sweep

```cpp
// OJ: https://leetcode.com/problems/maximum-population-year/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(Y) where Y is the range of the year
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& A) {
        int diff[101] = {}, mx = 0, ans = 0, cur = 0;
        for (auto &v : A) {
            diff[v[0] - 1950]++;
            diff[v[1] - 1950]--;
        }
        for (int i = 0; i < 101; ++i) {
            cur += diff[i];
            if (cur > mx) {
                mx = cur;
                ans = i;
            }
        }
        return ans + 1950;
    }
};
```