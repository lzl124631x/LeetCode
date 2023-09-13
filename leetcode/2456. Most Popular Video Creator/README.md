# [ ()](https://leetcode.com/problems/most-popular-video-creator)

<p>You are given two string arrays <code>creators</code> and <code>ids</code>, and an integer array <code>views</code>, all of length <code>n</code>. The <code>i<sup>th</sup></code> video on a platform was created by <code>creator[i]</code>, has an id of <code>ids[i]</code>, and has <code>views[i]</code> views.</p>
<p>The <strong>popularity</strong> of a creator is the <strong>sum</strong> of the number of views on <strong>all</strong> of the creator's videos. Find the creator with the <strong>highest</strong> popularity and the id of their <strong>most</strong> viewed video.</p>
<ul>
	<li>If multiple creators have the highest popularity, find all of them.</li>
	<li>If multiple videos have the highest view count for a creator, find the lexicographically <strong>smallest</strong> id.</li>
</ul>
<p>Return<em> a 2D array of strings </em><code>answer</code><em> where </em><code>answer[i] = [creator<sub>i</sub>, id<sub>i</sub>]</code><em> means that </em><code>creator<sub>i</sub></code> <em>has the <strong>highest</strong> popularity and </em><code>id<sub>i</sub></code><em> is the id of their most popular video.</em> The answer can be returned in any order.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> creators = ["alice","bob","alice","chris"], ids = ["one","two","three","four"], views = [5,10,5,4]
<strong>Output:</strong> [["alice","one"],["bob","two"]]
<strong>Explanation:</strong>
The popularity of alice is 5 + 5 = 10.
The popularity of bob is 10.
The popularity of chris is 4.
alice and bob are the most popular creators.
For bob, the video with the highest view count is "two".
For alice, the videos with the highest view count are "one" and "three". Since "one" is lexicographically smaller than "three", it is included in the answer.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> creators = ["alice","alice","alice"], ids = ["a","b","c"], views = [1,2,2]
<strong>Output:</strong> [["alice","b"]]
<strong>Explanation:</strong>
The videos with id "b" and "c" have the highest view count.
Since "b" is lexicographically smaller than "c", it is included in the answer.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>n == creators.length == ids.length == views.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= creators[i].length, ids[i].length &lt;= 5</code></li>
	<li><code>creators[i]</code> and <code>ids[i]</code> consist only of lowercase English letters.</li>
	<li><code>0 &lt;= views[i] &lt;= 10<sup>5</sup></code></li>
</ul>

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/most-popular-video-creator
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, long long> totalViews, highestViewVideoViewCountOfCreator;
        unordered_map<string, string> highestViewVideoOfCreator;
        long long highestView = 0;
        for (int i = 0; i < creators.size(); ++i) {
            auto c = creators[i], id = ids[i];
            int v = views[i];
            highestView = max(highestView, totalViews[c] += v);
            if (highestViewVideoViewCountOfCreator.count(c) == 0 || v > highestViewVideoViewCountOfCreator[c] || (v == highestViewVideoViewCountOfCreator[c] && id < highestViewVideoOfCreator[c])) {
                highestViewVideoOfCreator[c] = id;
                highestViewVideoViewCountOfCreator[c] = v;
            }
        }
        vector<vector<string>> ans;
        for (auto &[c, v] : totalViews) {
            if (v != highestView) continue;
            ans.push_back({c, highestViewVideoOfCreator[c]});
        }
        return ans;
    }
};
```