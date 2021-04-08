# [1815. Maximum Number of Groups Getting Fresh Donuts (Hard)](https://leetcode.com/problems/maximum-number-of-groups-getting-fresh-donuts/)

<p>There is a donuts shop that bakes donuts in batches of <code>batchSize</code>. They have a rule where they must serve <strong>all</strong> of the donuts of a batch before serving any donuts of the next batch. You are given an integer <code>batchSize</code> and an integer array <code>groups</code>, where <code>groups[i]</code> denotes that there is a group of <code>groups[i]</code> customers that will visit the shop. Each customer will get exactly one donut.</p>

<p>When a group visits the shop, all customers of the group must be served before serving any of the following groups. A group will be happy if they all get fresh donuts. That is, the first customer of the group does not receive a donut that was left over from the previous group.</p>

<p>You can freely rearrange the ordering of the groups. Return <em>the <strong>maximum</strong> possible number of happy groups after rearranging the groups.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> batchSize = 3, groups = [1,2,3,4,5,6]
<strong>Output:</strong> 4
<strong>Explanation:</strong> You can arrange the groups as [6,2,4,5,1,3]. Then the 1<sup>st</sup>, 2<sup>nd</sup>, 4<sup>th</sup>, and 6<sup>th</sup> groups will be happy.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> batchSize = 4, groups = [1,3,2,5,2,2,1,6]
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= batchSize &lt;= 9</code></li>
	<li><code>1 &lt;= groups.length &lt;= 30</code></li>
	<li><code>1 &lt;= groups[i] &lt;= 10<sup>9</sup></code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. Greedy + DP

Let `A` be `groups`, `B` be `batchSize`.

Split `A` into different subsets such that:
* at most one of them can have a sum that is not a multiple of `B`.
* all others must have a sum that is a multiple of `B`.

We can greedily use the groups that has remainder `0`.

And then greedily match 2 groups that has a sum of remainder `0`.

For groups of 3 or more, we need to use DP.

Let `dp[cnt]` be the maximum number of happy groups given a remainder array `cnt`.

For a given `cnt`, we can try using a group with remainder `cnt[i]`, `1 <= i < B`.

Assume after using the group, the `cnt` becomes `cnt2`. `cnt2` is the same as `cnt` expect `cnt2[i] = cnt[i] - 1` for the selected `i`.

So

```
dp[cnt] = max( (left == 0) + dp(cnt2, (left - i + B) % B ) | 1 <= i < B )
```

where `left` is the number of donuts left in the current batch. `left` can be derived from the `cnt` so we don't use it as a state for DP.

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-groups-getting-fresh-donuts/
// Author: github.com/lzl124631x
// Time: O(N^B)
// Space: O(B)
// Ref: https://leetcode.com/problems/maximum-number-of-groups-getting-fresh-donuts/discuss/1140644/C%2B%2B-0-ms%3A-Greedy-%2B-DP
class Solution {
    map<vector<int>, int> dp;
    int dfs(vector<int> &cnt, int left) {
        auto it = dp.find(cnt);
        if (it != end(dp)) return it->second;
        int ans = 0, B = cnt.size();
        for (int i = 1; i < B; ++i) {
            if (--cnt[i] >= 0) ans = max(ans, (left == 0) + dfs(cnt, (B + left - i) % B));
            ++cnt[i];
        }
        return dp[cnt] = ans;
    }
public:
    int maxHappyGroups(int B, vector<int>& A) {
        vector<int> cnt(B);
        int ans = 0;
        for (auto &n : A) {
            n %= B;
            if (n == 0) ++ans;
            else if (cnt[B - n]) {
                --cnt[B - n];
                ++ans;
            } else ++cnt[n];
        }
        return ans + dfs(cnt, 0);
    }
};
```