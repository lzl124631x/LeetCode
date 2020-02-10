# [1348. Tweet Counts Per Frequency (Medium)](https://leetcode.com/problems/tweet-counts-per-frequency/)

<p>Implement the class <code>TweetCounts</code> that supports two methods:</p>

<p>1.<code> recordTweet(string tweetName, int time)</code></p>

<ul>
	<li>Stores the <code>tweetName</code> at the recorded <code>time</code> (in <strong>seconds</strong>).</li>
</ul>

<p>2.<code> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime)</code></p>

<ul>
	<li>Returns the total number of occurrences for the given <code>tweetName</code> per <strong>minute</strong>, <strong>hour</strong>, or <strong>day</strong> (depending on <code>freq</code>) starting from the <code>startTime</code> (in <strong>seconds</strong>) and ending at the <code>endTime</code> (in <strong>seconds</strong>).</li>
	<li><code>freq</code> is always <strong>minute</strong><em>, </em><strong>hour</strong><em>&nbsp;or <strong>day</strong></em>, representing the time interval to get the total number of occurrences for the given&nbsp;<code>tweetName</code>.</li>
	<li>The first time interval always starts from the <code>startTime</code>, so the time intervals are <code>[startTime, startTime + delta*1&gt;, &nbsp;[startTime + delta*1, startTime + delta*2&gt;, [startTime + delta*2, startTime + delta*3&gt;, ... , [startTime + delta*i, <strong>min</strong>(startTime + delta*(i+1), endTime + 1)&gt;</code> for some non-negative number <code>i</code> and <code>delta</code> (which depends on <code>freq</code>).&nbsp;&nbsp;</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example:</strong></p>

<pre><strong>Input</strong>
["TweetCounts","recordTweet","recordTweet","recordTweet","getTweetCountsPerFrequency","getTweetCountsPerFrequency","recordTweet","getTweetCountsPerFrequency"]
[[],["tweet3",0],["tweet3",60],["tweet3",10],["minute","tweet3",0,59],["minute","tweet3",0,60],["tweet3",120],["hour","tweet3",0,210]]

<strong>Output</strong>
[null,null,null,null,[2],[2,1],null,[4]]

<strong>Explanation</strong>
TweetCounts tweetCounts = new TweetCounts();
tweetCounts.recordTweet("tweet3", 0);
tweetCounts.recordTweet("tweet3", 60);
tweetCounts.recordTweet("tweet3", 10);                             // All tweets correspond to "tweet3" with recorded times at 0, 10 and 60.
tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 59); // return [2]. The frequency is per minute (60 seconds), so there is one interval of time: 1) [0, 60&gt; - &gt; 2 tweets.
tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 60); // return [2, 1]. The frequency is per minute (60 seconds), so there are two intervals of time: 1) [0, 60&gt; - &gt; 2 tweets, and 2) [60,61&gt; - &gt; 1 tweet.
tweetCounts.recordTweet("tweet3", 120);                            // All tweets correspond to "tweet3" with recorded times at 0, 10, 60 and 120.
tweetCounts.getTweetCountsPerFrequency("hour", "tweet3", 0, 210);  // return [4]. The frequency is per hour (3600 seconds), so there is one interval of time: 1) [0, 211&gt; - &gt; 4 tweets.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>There will be at most <code>10000</code>&nbsp;operations considering both <code>recordTweet</code> and <code>getTweetCountsPerFrequency</code>.</li>
	<li><code>0 &lt;= time, startTime, endTime &lt;=&nbsp;10^9</code></li>
	<li><code>0 &lt;= endTime - startTime &lt;= 10^4</code></li>
</ul>


**Related Topics**:  
[Design](https://leetcode.com/tag/design/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/tweet-counts-per-frequency/
// Author: github.com/lzl124631x
// Time:
//      recordTweet: O(logN)
//      getTweetCountsPerFrequency: O(N)
// Space: O(N)
class TweetCounts {
    unordered_map<string, multiset<int>> m;
public:
    TweetCounts() {}
    
    void recordTweet(string tweetName, int time) {
        m[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int d = freq[0] == 'm' ? 60 : (freq[0] == 'h' ? 3600 : (3600 * 24));
        vector<int> ans((endTime - startTime) / d + 1);
        if (!m.count(tweetName)) return ans;
        auto &ps = m[tweetName];
        for (auto t = ps.lower_bound(startTime); t != ps.end() && *t <= endTime; ++t) {
           ++ans[(*t - startTime) / d];
        }
        return ans;
    }
};
```