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

## Solution 1. Bitmask DP on Subsets

```cpp
// OJ: https://leetcode.com/problems/matchsticks-to-square/
// Author: github.com/lzl124631x
// Time: O(N * 2^N)
// Space: O(2^N)
class Solution {
public:
    bool makesquare(vector<int>& A) {
        int sum = accumulate(begin(A), end(A), 0), N = A.size();
        if (sum % 4 || *max_element(begin(A), end(A)) > sum / 4) return false;
        sum /= 4;
        sort(begin(A), end(A), greater<>());
        vector<int> dp(1 << N, -1);
        dp[(1 << N) - 1] = 1;
        function<bool(int, int)> dfs = [&](int mask, int target) {
            if (dp[mask] != -1) return dp[mask];
            dp[mask] = 0;
            if (target == 0) target = sum;
            for (int i = 0; i < N && !dp[mask]; ++i) {
                if ((mask >> i & 1) || A[i] > target) continue;
                dp[mask] = dfs(mask | (1 << i), target - A[i]);
            }
            return dp[mask];
        };
        return dfs(0, sum);
    }
};
```

## Solution 2. Backtrack to Fill Buckets

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
public:
    bool makesquare(vector<int>& A) {
        vector<int> v(4);
        int sum = accumulate(begin(A), end(A), 0);
        if (sum % 4 || *max_element(begin(A), end(A)) > sum / 4) return false;
        sum /= 4;
        sort(begin(A), end(A), greater<>()); // Try rocks before sands
        function<bool(int)> dfs = [&](int i) {
            if (i == A.size()) return true;
            unordered_set<int> seen;
            for (int j = 0; j < 4; ++j) {
                if (A[i] + v[j] > sum || seen.count(v[j])) continue;
                seen.insert(v[j]);
                v[j] += A[i];
                if (dfs(i + 1)) return true;
                v[j] -= A[i];
            }
            return false;
        };
        return dfs(0);
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/matchsticks-to-square/
// Author: github.com/lzl124631x
// Time: O(4^N)
// Space: O(N * SUM(A))
class Solution {
public:
    bool makesquare(vector<int>& A) {
        vector<int> v(4);
        int sum = accumulate(begin(A), end(A), 0);
        if (sum % 4 || *max_element(begin(A), end(A)) > sum / 4) return false;
        sum /= 4;
        sort(begin(A), end(A), greater<>()); // Try rocks before sands
        function<bool(int)> dfs = [&](int i) {
            if (i == A.size()) return true;
            for (int j = 0; j < 4; ++j) {
                if (A[i] + v[j] > sum) continue;
                v[j] += A[i];
                if (dfs(i + 1)) return true;
                v[j] -= A[i];
                if (v[j] == 0) continue; // Simply don't visit empty bucket again. This takes less space but longer time.
            }
            return false;
        };
        return dfs(0);
    }
};
```