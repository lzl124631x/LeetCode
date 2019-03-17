# [1013. Pairs of Songs With Total Durations Divisible by 60 (Easy)](https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/)

<p>In a list of songs, the <code>i</code>-th&nbsp;song has a duration of&nbsp;<code>time[i]</code> seconds.&nbsp;</p>

<p>Return the number of pairs of songs for which their total&nbsp;duration in seconds is divisible by <code>60</code>.&nbsp; Formally, we want the number of&nbsp;indices <code>i &lt; j</code> with <code>(time[i] + time[j]) % 60 == 0</code>.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[30,20,150,100,40]</span>
<strong>Output: </strong><span id="example-output-1">3</span>
<strong>Explanation: </strong>Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[60,60,60]</span>
<strong>Output: </strong><span id="example-output-2">3</span>
<strong>Explanation: </strong>All three pairs have a total duration of 120, which is divisible by 60.
</pre>
</div>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= time.length &lt;= 60000</code></li>
	<li><code>1 &lt;= time[i] &lt;= 500</code></li>
</ol>


**Companies**:  
[Goldman Sachs](https://leetcode.com/company/goldman-sachs)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
// Author: github.com/lzl124631x
// Time: O(T)
// Space: O(1)
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cnt(501, 0);
        int ans = 0;
        for (int t : time) cnt[t]++;
        for (int i = 1; i <= 500; ++i) {
            if (!cnt[i]) continue;
            if (cnt[i] >= 2 && 2 * i % 60 == 0) ans += cnt[i] * (cnt[i] - 1) / 2;
            for (int j = i + 1; j <= 500; ++j) {
                if (!cnt[j] || (i + j) % 60) continue;
                ans += cnt[i] * cnt[j];
            }
        }
        return ans;
    }
};
```