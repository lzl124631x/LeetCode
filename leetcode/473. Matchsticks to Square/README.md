# [473. Matchsticks to Square (Medium)](https://leetcode.com/problems/matchsticks-to-square/)

<p>Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks. You should not break any stick, but you can link them up, and each matchstick must be used <b>exactly</b> one time.</p>

<p> Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> [1,1,2,2,2]
<b>Output:</b> true

<b>Explanation:</b> You can form a square with length 2, one side of the square came two sticks with length 1.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> [3,3,3,3,4]
<b>Output:</b> false

<b>Explanation:</b> You cannot find a way to form a square with all the matchsticks.
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>The length sum of the given matchsticks is in the range of <code>0</code> to <code>10^9</code>.
</li><li>The length of the given matchstick array will not exceed <code>15</code>.</li>
</ol>
<p></p>

**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/)

## Solution 1. DP on Subsets

```cpp
// OJ: https://leetcode.com/problems/matchsticks-to-square/
// Author: github.com/lzl124631x
// Time: O(N * 2^N)
// Space: O(2^N)
class Solution {
    vector<int> dp;
    bool dfs(vector<int> &A, int used, int todo, int target) {
        if (dp[used] != -1) return dp[used];
        dp[used] = 0;
        int mx = todo % target;
        if (mx == 0) mx = target;
        for (int i = 0; i < A.size() && !dp[used]; ++i) {
            dp[used] = ((used >> i) & 1) == 0 && A[i] <= mx && dfs(A, used | (1 << i), todo - A[i], target);
        }
        return dp[used];
    }
public:
    bool makesquare(vector<int>& A) {
        if (A.empty()) return false;
        int len = accumulate(begin(A), end(A), 0);
        if (len % 4 || *max_element(begin(A), end(A)) > len / 4) return false;
        dp.assign(1 << A.size(), -1);
        dp[(1 << A.size()) - 1] = 1;
        return dfs(A, 0, len, len / 4);
    }
};
```

## Solution 2. DFS to Fill Buckets

Let `target = sum(A) / 4`, which is the target length of each edge.

We use DFS to try to fill each `A[i]` into different edges.

Two optimizations here:

1. The `unordered_set<int> seen` is used to prevent handling the same edge value again. For example, assume `edge = [1, 1, 1, 1]`, and now we are trying to add a stick of length `2` to it. Adding `2` to either `1` will yield the same result. So we just need to add to a edge with length `1` once.
1. Sorting the sticks in descending order will make it converge faster because it's easy to fill in sands but hard to fill in peddles; filling peddles first will fail faster.

```cpp
// OJ: https://leetcode.com/problems/matchsticks-to-square/
// Author: github.com/lzl124631x
// Time: O(4^N)
// Space: O(N * SUM(A))
class Solution {
    int edge[4] = {}, target;
    bool dfs(vector<int> &A, int i) {
        if (i == A.size()) return true;
        unordered_set<int> seen;
        for (int j = 0; j < 4; ++j) {
            if (seen.count(edge[j]) || edge[j] + A[i] > target) continue;
            seen.insert(edge[j]);
            edge[j] += A[i];
            if (dfs(A, i + 1)) return true;
            edge[j] -= A[i];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& A) {
        if (A.size() < 4) return false;
        int sum = accumulate(begin(A), end(A), 0);
        if (sum % 4 || *max_element(begin(A), end(A)) > sum / 4) return false;
        target = sum / 4;
        sort(begin(A), end(A), greater<>());
        return dfs(A, 0);
    }
};
```