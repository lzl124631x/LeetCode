# [943. Find the Shortest Superstring (Hard)](https://leetcode.com/problems/find-the-shortest-superstring/)

<p>Given an array A of strings, find any&nbsp;smallest string that contains each string in <code>A</code> as a&nbsp;substring.</p>

<p>We may assume that no string in <code>A</code> is substring of another string in <code>A</code>.</p>

<div>&nbsp;</div>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">["alex","loves","leetcode"]</span>
<strong>Output: </strong><span id="example-output-1">"alexlovesleetcode"</span>
<strong>Explanation: </strong>All permutations of "alex","loves","leetcode" would also be accepted.
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">["catg","ctaagt","gcta","ttca","atgcatc"]</span>
<strong>Output: </strong><span id="example-output-2">"gctaagttcatgcatc"</span></pre>

<p>&nbsp;</p>
</div>
</div>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 12</code></li>
	<li><code>1 &lt;= A[i].length &lt;= 20</code></li>
</ol>

<div>
<div>&nbsp;</div>
</div>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. Subset DP

The idea is similar to Traveling Salesperson Problem (TSP) -- instead of enumerating all the permutations, enumerate all the subsets and memoize the result.

Note that this solution doesn't use the assumption that no string in `A` is a substring of another string in `A`.

```cpp
// OJ: https://leetcode.com/problems/find-the-shortest-superstring/
// Author: github.com/lzl124631x
// Time: O(2^N * N * W)
// Space: O(2^N * N * W)
class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        string dp[1 << 12] = {};
        int N = A.size();
        for (int mask = 0; mask < (1 << N); ++mask) { // try to extend from the current subset to the next subset
            for (int i = 0; i < N; ++i) { // try extending using A[i]
                if (mask >> i & 1) continue; // If A[i] already used, we can't extend with it
                int next = (mask | (1 << i)), len = min(A[i].size(), dp[mask].size()); // `next` represents the next subset. Try to get the overlap length between `dp[mask]` and `A[i]`
                while (len >= 1 && dp[mask].substr(dp[mask].size() - len) != A[i].substr(0, len)) --len;
                auto s = dp[mask] + A[i].substr(len);
                if (dp[next].empty() || s.size() < dp[next].size()) { // Try updating the optimal solution of the next subset -- `dp[next]`.
                    dp[next] = s;
                }
            }
        }
        return dp[(1 << N) - 1];
    }
};
```

## Solution 2. Subset DP

Considering the assumption that no string in `A` is a substring of another string in `A`. We don't need to consider the case that a single string overlaps more than one previously used strings, so we can precompute the overlaps between two strings.

```cpp
// OJ: https://leetcode.com/problems/find-the-shortest-superstring/
// Author: github.com/lzl124631x
// Time: O(2^N * N * W)
// Space: O(2^N * N * W)
class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        string dp[1 << 12] = {};
        int overlap[12][12] = {}, last[1 << 12] = {}, N = A.size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) continue;
                int len = min(A[i].size(), A[j].size()) - 1;
                while (len >= 1 && A[i].substr(A[i].size() - len) != A[j].substr(0, len)) --len;
                overlap[i][j] = len;
            }
        }
        for (int mask = 0; mask < (1 << N); ++mask) {
            for (int i = 0; i < N; ++i) {
                if (mask >> i & 1) continue;
                int next = (mask | (1 << i)), len = mask ? overlap[last[mask]][i] : 0;
                auto s = dp[mask] + A[i].substr(len);
                if (dp[next].empty() || s.size() < dp[next].size()) {
                    dp[next] = s;
                    last[next] = i;
                }
            }
        }
        return dp[(1 << N) - 1];
    }
};
```

## Solution 3. Subset DP

Instead of storing all the string DP values, for a subset `mask`, we only store the index of the last string (as `last[mask]`) and the length (as `len[mask]`) of the optimal solution. We can use `last[mask]` to rebuild the optimal solution.

```cpp
// OJ: https://leetcode.com/problems/find-the-shortest-superstring/
// Author: github.com/lzl124631x
// Time: O(N^2 * (2^N + W))
// Space: O(N * (2^N + W))
// Ref: https://leetcode.com/problems/find-the-shortest-superstring/solution/
class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int overlap[12][12] = {}, last[1 << 12] = {}, len[1 << 12] = {}, N = A.size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) continue;
                int len = min(A[i].size(), A[j].size()) - 1;
                while (len >= 1 && A[i].substr(A[i].size() - len) != A[j].substr(0, len)) --len;
                overlap[i][j] = len;
            }
        }
        for (int mask = 0; mask < (1 << N); ++mask) {
            for (int i = 0; i < N; ++i) {
                if (mask >> i & 1) continue;
                int next = (mask | (1 << i)), update = len[mask] + A[i].size() - (mask ? overlap[last[mask]][i] : 0);
                if (len[next] == 0 || update < len[next]) {
                    last[next] = i;
                    len[next] = update;
                }
            }
        }
        string ans;
        for (int mask = (1 << N) - 1; mask > 0; ) {
            int j = last[mask], prev = (mask & ~(1 << j)), i = last[prev];
            ans = A[j].substr(prev ? overlap[i][j] : 0) + ans;
            mask = prev;
        }
        return ans;
    }
};
```