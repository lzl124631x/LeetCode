# [1125. Smallest Sufficient Team (Hard)](https://leetcode.com/problems/smallest-sufficient-team/)

<p>In a project, you have a list of required skills <code>req_skills</code>,&nbsp;and a list of <code>people</code>.&nbsp; The i-th person <code>people[i]</code>&nbsp;contains a list of skills that person has.</p>

<p>Consider a <em>sufficient team</em>: a set of people such that for every required skill in <code>req_skills</code>, there is at least one person in the team who has that skill.&nbsp; We can represent these teams by the index of each person: for example, <code>team = [0, 1, 3]</code> represents the people with skills <code>people[0]</code>, <code>people[1]</code>, and <code>people[3]</code>.</p>

<p>Return <strong>any</strong>&nbsp;sufficient team of the smallest possible size, represented by the index of each person.</p>

<p>You may return the answer in any order.&nbsp; It is guaranteed an answer exists.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
<strong>Output:</strong> [0,2]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
<strong>Output:</strong> [1,2]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= req_skills.length &lt;= 16</code></li>
	<li><code>1 &lt;= people.length &lt;= 60</code></li>
	<li><code>1 &lt;= people[i].length, req_skills[i].length, people[i][j].length&nbsp;&lt;= 16</code></li>
	<li>Elements of <code>req_skills</code> and <code>people[i]</code> are (respectively) distinct.</li>
	<li><code>req_skills[i][j], people[i][j][k]</code> are&nbsp;lowercase English letters.</li>
	<li>Every skill in <code>people[i]</code>&nbsp;is a skill in <code>req_skills</code>.</li>
	<li>It is guaranteed a sufficient team exists.</li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1. DP

This looks like a knapsack problem. Let's try to use DP.

To represent which skills each people have, we can use bitmask. For example, `0110` means that this people have 1 and 2 skills but doesn't have 0 and 4 skills.

Let's first turn the skills from strings to number IDs using `unordered_map<string, int> m`.

Then `vector<int> p` stores the bitmasks of the skills of each people.

Let `dp[state][j + 1]` be the min number of people required for skills represented by `state` if we only use people `0` to `j`.

For `dp[state][j + 1]`, we have two choices:
1. Skip people `j`, then `dp[state][j + 1] = dp[state][j]`
2. Pick people `j`, then `dp[state][j + 1] = dp[prevState][j] + 1`, where `prevState` is `state` subtracting all the skills people `j` has.

```
dp[state][j] = min(
                    dp[state][j],            // If we skip people `j`
                    dp[prevState][j] + 1     // If we pick people `j`
                  )
dp[0][j] = 0
```

`dp[(1 << M) - 1][N]` is the size of the answer.

To reconstruct the answer, we can start from `state = (1 << M) - 1, j = N - 1`.

* If `dp[state][j + 1] == dp[state][j]`, it means that we should skip people `j`.
* Otherwise, we should pick people `j`. So we push `j` into the answer, and subtract the skills people `j` has from the `state`.

We loop until `state == 0`.

```cpp
// OJ: https://leetcode.com/problems/smallest-sufficient-team/
// Author: github.com/lzl124631x
// Time: O(2^M * N) where M is the size of `req_skills`, N is the number of people
// Space: O(2^M * N)
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> m;
        int M = 0, N = people.size();
        for (auto &s : req_skills) m[s] = M++;
        vector<int> p(N);
        for (int i = 0; i < N; ++i) {
            for (auto &s : people[i]) {
                p[i] |= 1 << m[s];
            }
        }
        vector<vector<int>> dp(1 << M, vector<int>(N + 1, N));
        for (int i = 0; i <= N; ++i) dp[0][i] = 0;
        for (int state = 0; state < 1 << M; ++state) {
            for (int j = 0; j < N; ++j) {
                int prev = state & ~p[j];
                dp[state][j + 1] = min(dp[state][j], dp[prev][j] + 1);
            }
        }
        vector<int> ans;
        int state = (1 << M) - 1, j = N - 1;
        for (; state; --j) {
            if (dp[state][j + 1] == dp[state][j]) continue; 
            ans.push_back(j);
            state &= ~p[j];
        }
        return ans;
    }
};
```

## Solution 2. DP

Let `dp[state]` be the min number of people we required for skills represented by `state`.

To get the optimal value of `dp[state]`, we try each people `j`.

```
dp[state] = min( dp[prevState(j)] + 1 | prevState(j) = state & ~p[j] && 0<= j < N )
dp[0] = 0
```

`dp[(1 << M) - 1]` is the size of the answer.

To reconstruct the answer, we use `pick[state]` to store the people we should pick given `state`, and `prevState[state]` to store the state before we pick people `pick[state]`.

```cpp
// OJ: https://leetcode.com/problems/smallest-sufficient-team/
// Author: github.com/lzl124631x
// Time: O(2^M * N) where M is the size of `req_skills`, N is the number of people
// Space: O(2^M + N)
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> m;
        int M = 0, N = people.size();
        for (auto &s : req_skills) m[s] = M++;
        vector<int> p(N);
        for (int i = 0; i < N; ++i) {
            for (auto &s : people[i]) {
                p[i] |= 1 << m[s];
            }
        }
        vector<int> dp(1 << M, N), pick(1 << M, -1), prevState(1 << M);
        dp[0] = 0;
        for (int state = 0; state < 1 << M; ++state) {
            for (int j = 0; j < N; ++j) {
                int prev = state & ~p[j];
                if (dp[prev] + 1 < dp[state]) {
                    dp[state] = dp[prev] + 1;
                    pick[state] = j;
                    prevState[state] = prev;
                }
            }
        }
        vector<int> ans;
        int state = (1 << M) - 1;
        while (pick[state] != -1) {
            ans.push_back(pick[state]);
            state = prevState[state];
        }
        return ans;
    }
};
```

```cpp
// OJ: https://leetcode.com/problems/smallest-sufficient-team/
// Author: github.com/lzl124631x
// Time: O(2^M * N) where M is the size of `req_skills`, N is the number of people
// Space: O(2^M + N)
// Ref: https://leetcode.com/problems/smallest-sufficient-team/discuss/342120/C%2B%2B-DP-32ms-DP-solution.-Easy-to-implement
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> m;
        int M = req_skills.size(), N = people.size();
        for (int i = 0; i < M; ++i) m[req_skills[i]] = i;
        vector<int> p(N), dp(1 << M, INT_MAX), pick(1 << M, -1), prevState(1 << M);
        dp[0] = 0;
        for (int i = 0; i < N; ++i) {
            for (auto &s : people[i]) {
                p[i] |= (1 << m[s]);
            }
        }
        for (int state = 0; state < 1 << M; ++state) {
            for (int j = 0; j < N; ++j) {
                if (dp[state] == INT_MAX) continue;
                int next = state | p[j];
                if (dp[next] > dp[state] + 1) {
                    pick[next] = j;
                    prevState[next] = state;
                    dp[next] = dp[state] + 1;
                }
            }
        }
        int state = (1 << M) - 1;
        vector<int> ans;
        while (pick[state] != -1) {
            ans.push_back(pick[state]);
            state = prevState[state];
        }
        return ans;
    }
};
```