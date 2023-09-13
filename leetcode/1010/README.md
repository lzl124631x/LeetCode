# [1010. Pairs of Songs With Total Durations Divisible by 60 (Medium)](https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/)

<p>You are given a list of songs where the <code>i<sup>th</sup></code> song has a duration of <code>time[i]</code> seconds.</p>

<p>Return <em>the number of pairs of songs for which their total duration in seconds is divisible by</em> <code>60</code>. Formally, we want the number of indices <code>i</code>, <code>j</code> such that <code>i &lt; j</code> with <code>(time[i] + time[j]) % 60 == 0</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> time = [30,20,150,100,40]
<strong>Output:</strong> 3
<strong>Explanation:</strong> Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> time = [60,60,60]
<strong>Output:</strong> 3
<strong>Explanation:</strong> All three pairs have a total duration of 120, which is divisible by 60.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= time.length &lt;= 6 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= time[i] &lt;= 500</code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Citadel](https://leetcode.com/company/citadel), [ServiceNow](https://leetcode.com/company/servicenow), [Bloomberg](https://leetcode.com/company/bloomberg), [Cisco](https://leetcode.com/company/cisco), [VMware](https://leetcode.com/company/vmware), [Mathworks](https://leetcode.com/company/mathworks), [Salesforce](https://leetcode.com/company/salesforce), [Twilio](https://leetcode.com/company/twilio)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Counting](https://leetcode.com/tag/counting/)

## Solution 1. Prefix State Map

```cpp
// OJ: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& A) {
        int cnt[60] = {}, ans = 0;
        for (int n : A) {
            n %= 60;
            ans += cnt[(60 - n) % 60];
            cnt[n]++;
        }
        return ans;
    }
};
```