# [1604. Alert Using Same Key-Card Three or More Times in a One Hour Period (Medium)](https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/)

<p>Leetcode company workers use key-cards to unlock office doors. Each time a worker uses their key-card, the security system saves the worker's name and the time when it was used. The system emits an <strong>alert</strong> if any worker uses the key-card <strong>three or more times</strong> in a one-hour period.</p>

<p>You are given a list of strings <code>keyName</code> and <code>keyTime</code> where <code>[keyName[i], keyTime[i]]</code> corresponds to a person's name and the time when their key-card was used <strong>in a</strong> <strong>single day</strong>.</p>

<p>Access times are given in the <strong>24-hour time format "HH:MM"</strong>, such as <code>"23:51"</code> and <code>"09:49"</code>.</p>

<p>Return a <em>list of unique worker names who received an alert for frequent keycard use</em>. Sort the names in <strong>ascending order alphabetically</strong>.</p>

<p>Notice that <code>"10:00"</code> - <code>"11:00"</code> is considered to be within a one-hour period, while <code>"23:51"</code> - <code>"00:10"</code> is not considered to be within a one-hour period.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> keyName = ["daniel","daniel","daniel","luis","luis","luis","luis"], keyTime = ["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]
<strong>Output:</strong> ["daniel"]
<strong>Explanation:</strong> "daniel" used the keycard 3 times in a one-hour period ("10:00","10:40", "11:00").
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> keyName = ["alice","alice","alice","bob","bob","bob","bob"], keyTime = ["12:01","12:00","18:00","21:00","21:20","21:30","23:00"]
<strong>Output:</strong> ["bob"]
<strong>Explanation:</strong> "bob" used the keycard 3 times in a one-hour period ("21:00","21:20", "21:30").
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> keyName = ["john","john","john"], keyTime = ["23:58","23:59","00:01"]
<strong>Output:</strong> []
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> keyName = ["leslie","leslie","leslie","clare","clare","clare","clare"], keyTime = ["13:00","13:20","14:00","18:00","18:51","19:30","19:49"]
<strong>Output:</strong> ["clare","leslie"]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= keyName.length, keyTime.length &lt;= 10<sup>5</sup></code></li>
	<li><code>keyName.length == keyTime.length</code></li>
	<li><code>keyTime</code> are in the format <strong>"HH:MM"</strong>.</li>
	<li><code>[keyName[i], keyTime[i]]</code> is <strong>unique</strong>.</li>
	<li><code>1 &lt;= keyName[i].length &lt;= 10</code></li>
	<li><code>keyName[i] contains only lowercase English letters.</code></li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Ordered Map](https://leetcode.com/tag/ordered-map/)

## Solution 1. Hash Map

Use `unordered_map<string, vector<int>>` to group the times by name.

For the times of each person, sort the times. If there is any `times[i] - times[i - 2] <= 60`, then the person should get alerted.

```cpp
// OJ: https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> m;
        for (int i = 0; i < keyName.size(); ++i) {
            auto &key = keyName[i], &time = keyTime[i];
            int t = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
            m[key].push_back(t);
        }
        vector<string> ans;
        for (auto &[key, times] : m) {
            sort(begin(times), end(times));
            for (int i = 2; i < times.size(); ++i) {
                if (times[i] - times[i - 2] > 60) continue;
                ans.push_back(key);
                break;
            }
        }
        sort(begin(ans), end(ans));
        return ans;
    }
};
```