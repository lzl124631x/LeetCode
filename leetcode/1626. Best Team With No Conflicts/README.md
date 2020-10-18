# [1626. Best Team With No Conflicts (Medium)](https://leetcode.com/problems/best-team-with-no-conflicts/)

<p>You are the manager of a basketball team. For the upcoming tournament, you want to choose the team with the highest overall score. The score of the team is the <strong>sum</strong> of scores of all the players in the team.</p>

<p>However, the basketball team is not allowed to have <strong>conflicts</strong>. A <strong>conflict</strong> exists if a younger player has a <strong>strictly higher</strong> score than an older player. A conflict does <strong>not</strong> occur between players of the same age.</p>

<p>Given two lists, <code>scores</code> and <code>ages</code>, where each <code>scores[i]</code> and <code>ages[i]</code> represents the score and age of the <code>i<sup>th</sup></code> player, respectively, return <em>the highest overall score of all possible basketball teams</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> scores = [1,3,5,10,15], ages = [1,2,3,4,5]
<strong>Output:</strong> 34
<strong>Explanation:</strong>&nbsp;You can choose all the players.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> scores = [4,5,6,5], ages = [2,1,2,1]
<strong>Output:</strong> 16
<strong>Explanation:</strong>&nbsp;It is best to choose the last 3 players. Notice that you are allowed to choose multiple people of the same age.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> scores = [1,2,3,5], ages = [8,9,10,1]
<strong>Output:</strong> 6
<strong>Explanation:</strong>&nbsp;It is best to choose the first 3 players. 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= scores.length, ages.length &lt;= 1000</code></li>
	<li><code>scores.length == ages.length</code></li>
	<li><code>1 &lt;= scores[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= ages[i] &lt;= 1000</code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/best-team-with-no-conflicts/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
// Ref: https://leetcode.com/problems/best-team-with-no-conflicts/discuss/899475/Fairly-easy-DP
class Solution {
public:
    int bestTeamScore(vector<int>& S, vector<int>& A) {
        int N = S.size(), ans = 0;
        vector<pair<int, int>> v;
        for (int i = 0; i < N; ++i) v.emplace_back(A[i], S[i]);
        sort(begin(v), end(v), greater<>());
        vector<int> dp(N);
        for (int i = 0; i < N; ++i) {
            int score = v[i].second;
            dp[i] = score;
            for (int j = 0; j < i; ++j) {
                if (v[j].second >= score) dp[i] = max(dp[i], dp[j] + score);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```
