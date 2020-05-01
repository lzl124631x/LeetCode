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

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/find-the-shortest-superstring/
// Author: github.com/lzl124631x
// Time: O(N^2 * (2^N + W))
// Space: O(N * (2^N + W))
// Ref: https://leetcode.com/problems/find-the-shortest-superstring/solution/
class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int N = A.size();
        vector<vector<int>> overlaps(N, vector<int>(N));
        for (int i = 0; i < N ; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) continue;
                int len = min(A[i].size(), A[j].size());
                for (int k = len; k >= 0; --k) {
                    if (A[i].substr(A[i].size() - k) != (A[j].substr(0, k))) continue;
                    overlaps[i][j] = k;
                    break;
                }
            }
        }
        vector<vector<int>> dp(1 << N, vector<int>(N));
        vector<vector<int>> parent(1 << N, vector<int>(N, -1));
        for (int mask = 0; mask < (1 << N); ++mask) {
            for (int bit = 0; bit < N; ++bit) {
                if (((mask >> bit) & 1) == 0) continue;
                int pmask = mask ^ (1 << bit);
                if (pmask == 0) continue;
                for (int i = 0; i < N; ++i) {
                    if (((pmask >> i) & 1) == 0) continue;
                    int val = dp[pmask][i] + overlaps[i][bit];
                    if (val > dp[mask][bit]) {
                        dp[mask][bit] = val;
                        parent[mask][bit] = i;
                    }
                }
            }
        }
        vector<int> perm(N);
        vector<bool> seen(N);
        int t = 0, mask = (1 << N) - 1, p = 0;
        for (int j = 0; j < N; ++j) {
            if (dp[(1 << N) - 1][j] > dp[(1 << N) - 1][p]) p = j;
        }
        while (p != -1) {
            perm[t++] = p;
            seen[p] = true;
            int p2 = parent[mask][p];
            mask ^= 1 << p;
            p = p2;
        }
        reverse(perm.begin(), perm.begin() + t);
        for (int i = 0; i < N; ++i) {
            if (!seen[i]) perm[t++] = i;
        }
        string ans = A[perm[0]];
        for (int i = 1; i < N; ++i) {
            int overlap = overlaps[perm[i - 1]][perm[i]];
            ans += A[perm[i]].substr(overlap);
        }
        return ans;
    }
};
```