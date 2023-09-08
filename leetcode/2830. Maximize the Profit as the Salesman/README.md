# [2830. Maximize the Profit as the Salesman (Medium)](https://leetcode.com/problems/maximize-the-profit-as-the-salesman)

<p>You are given an integer <code>n</code> representing the number of houses on a number line, numbered from <code>0</code> to <code>n - 1</code>.</p>
<p>Additionally, you are given a 2D integer array <code>offers</code> where <code>offers[i] = [start<sub>i</sub>, end<sub>i</sub>, gold<sub>i</sub>]</code>, indicating that <code>i<sup>th</sup></code> buyer wants to buy all the houses from <code>start<sub>i</sub></code> to <code>end<sub>i</sub></code> for <code>gold<sub>i</sub></code> amount of gold.</p>
<p>As a salesman, your goal is to <strong>maximize</strong> your earnings by strategically selecting and selling houses to buyers.</p>
<p>Return <em>the maximum amount of gold you can earn</em>.</p>
<p><strong>Note</strong> that different buyers can't buy the same house, and some houses may remain unsold.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> n = 5, offers = [[0,0,1],[0,2,2],[1,3,2]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are 5 houses numbered from 0 to 4 and there are 3 purchase offers.
We sell houses in the range [0,0] to 1<sup>st</sup> buyer for 1 gold and houses in the range [1,3] to 3<sup>rd</sup> buyer for 2 golds.
It can be proven that 3 is the maximum amount of gold we can achieve.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> n = 5, offers = [[0,0,1],[0,2,10],[1,3,2]]
<strong>Output:</strong> 10
<strong>Explanation:</strong> There are 5 houses numbered from 0 to 4 and there are 3 purchase offers.
We sell houses in the range [0,2] to 2<sup>nd</sup> buyer for 10 golds.
It can be proven that 10 is the maximum amount of gold we can achieve.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= offers.length &lt;= 10<sup>5</sup></code></li>
	<li><code>offers[i].length == 3</code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>1 &lt;= gold<sub>i</sub> &lt;= 10<sup>3</sup></code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Sorting](https://leetcode.com/tag/sorting/)

## Solution 1.

Let `dp[i+1]` be the maximum earnings if we sell `0~i`th houses.

`dp[0] = 0`

Sort `A` in ascending order of `end[i]`.

Traverse `A`, and update `dp[end[i] + 1] = rollingMax = max(rollingMax, dp[start[i]] + gold[i])`

```cpp
// OJ: https://leetcode.com/problems/maximize-the-profit-as-the-salesman
// Author: github.com/lzl124631x
// Time: O(OlogO + N)
// Space: O(N)
class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& A) {
        vector<int> dp(n + 1);
        sort(begin(A), end(A), [&](auto &a, auto &b) { return a[1] < b[1]; });
        int ans = 0, end = 0;
        for (auto &o : A) {
            for (int i = end + 1; i < o[1]; ++i) dp[i + 1] = ans; // fill the gaps of DP values
            dp[o[1] + 1] = ans = max(ans, dp[o[0]] + o[2]);
            end = o[1];
        }
        return ans;
    }
};
```

We can also use a `map` to store the DP values, and use binary search to find the maximum house index that has shown up in an offer and is smaller than the current `start[i]`.

```cpp
// OJ: https://leetcode.com/problems/maximize-the-profit-as-the-salesman
// Author: github.com/lzl124631x
// Time: O(OlogO + NlogO)
// Space: O(O)
class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& A) {
        map<int, int, greater<>> dp{{-1,0}};
        sort(begin(A), end(A), [&](auto &a, auto &b) { return a[1] < b[1]; });
        int ans = 0;
        for (auto &o : A) {
            dp[o[1]] = ans = max(ans, dp.upper_bound(o[0])->second + o[2]);
        }
        return ans;
    }
};
```