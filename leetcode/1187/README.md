# [1187. Make Array Strictly Increasing (Hard)](https://leetcode.com/problems/make-array-strictly-increasing/)

<p>Given two integer arrays&nbsp;<code>arr1</code> and <code>arr2</code>, return the minimum number of operations (possibly zero) needed&nbsp;to make <code>arr1</code> strictly increasing.</p>

<p>In one operation, you can choose two indices&nbsp;<code>0 &lt;=&nbsp;i &lt; arr1.length</code>&nbsp;and&nbsp;<code>0 &lt;= j &lt; arr2.length</code>&nbsp;and do the assignment&nbsp;<code>arr1[i] = arr2[j]</code>.</p>

<p>If there is no way to make&nbsp;<code>arr1</code>&nbsp;strictly increasing,&nbsp;return&nbsp;<code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
<strong>Output:</strong> 1
<strong>Explanation:</strong> Replace <code>5</code> with <code>2</code>, then <code>arr1 = [1, 2, 3, 6, 7]</code>.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr1 = [1,5,3,6,7], arr2 = [4,3,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> Replace <code>5</code> with <code>3</code> and then replace <code>3</code> with <code>4</code>. <code>arr1 = [1, 3, 4, 6, 7]</code>.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
<strong>Output:</strong> -1
<strong>Explanation:</strong> You can't make <code>arr1</code> strictly increasing.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr1.length, arr2.length &lt;= 2000</code></li>
	<li><code>0 &lt;= arr1[i], arr2[i] &lt;= 10^9</code></li>
</ul>

<p>&nbsp;</p>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP Top-down

```cpp
// OJ: https://leetcode.com/problems/make-array-strictly-increasing/
// Author: github.com/lzl124631x
// Time: O(MN * logN)
// Space: O(MN)
// Ref: https://leetcode.com/problems/make-array-strictly-increasing/discuss/379095/C%2B%2B-DFS-%2B-Memo
class Solution {
    int dp[2001][2001] = {};
    int dfs(vector<int>& A, vector<int>& B, int i, int prev) {
        if (i >= A.size()) return 1;
        int j = upper_bound(B.begin(), B.end(), prev) - B.begin();
        if (dp[i][j]) return dp[i][j];
        int skip = prev < A[i] ? dfs(A, B, i + 1, A[i]) : B.size() + 1;
        int swap = j < B.size() ? 1 + dfs(A, B, i + 1, B[j]) : B.size() + 1;
        return dp[i][j] = min(skip, swap);
    }
public:
    int makeArrayIncreasing(vector<int>& A, vector<int>& B) {
        sort(B.begin(), B.end());
        auto ans = dfs(A, B, 0, INT_MIN);
        return ans > B.size() ? -1 : ans - 1;
    }
};
```

Or pass the previous `j` value into `dfs` so that `j` only traverse `B` in one pass.

```cpp
// OJ: https://leetcode.com/problems/make-array-strictly-increasing/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
// Ref: https://leetcode.com/problems/make-array-strictly-increasing/discuss/379095/C%2B%2B-DFS-%2B-Memo
class Solution {
    int dp[2001][2001] = {};
    int dfs(vector<int>& A, vector<int>& B, int i, int j, int prev) {
        if (i >= A.size()) return 1;
        j = upper_bound(B.begin() + j, B.end(), prev) - B.begin();
        if (dp[i][j]) return dp[i][j];
        int skip = prev < A[i] ? dfs(A, B, i + 1, j, A[i]) : B.size() + 1;
        int swap = j < B.size() ? 1 + dfs(A, B, i + 1, j, B[j]) : B.size() + 1;
        return dp[i][j] = min(skip, swap);
    }
public:
    int makeArrayIncreasing(vector<int>& A, vector<int>& B) {
        sort(B.begin(), B.end());
        auto ans = dfs(A, B, 0, 0, INT_MIN);
        return ans > B.size() ? -1 : ans - 1;
    }
};
```

## Solution 2. DP

```cpp
// OJ: https://leetcode.com/problems/make-array-strictly-increasing/
// Author: github.com/lzl124631x
// Time: O(MN * logN)
// Space: O(MN)
// Ref: https://leetcode.com/problems/make-array-strictly-increasing/discuss/377403/Python-DP-solution-with-explanation.
class Solution {
public:
    int makeArrayIncreasing(vector<int>& A, vector<int>& B) {
        int M = A.size(), N = B.size();
        sort(B.begin(), B.end());
        unordered_map<int, int> dp;
        dp[-1] = 0;
        for (int a : A) {
            unordered_map<int, int> tmp;
            for (auto &p : dp) {
                if (a > p.first) {
                    int cnt = tmp.count(a) ? tmp[a] : INT_MAX;
                    tmp[a] = min(cnt, p.second);
                }
                int b = upper_bound(B.begin(), B.end(), p.first) - B.begin();
                if (b < N) {
                    int cnt = tmp.count(B[b]) ? tmp[B[b]] : INT_MAX;
                    tmp[B[b]] = min(cnt, p.second + 1);
                }
            }
            dp = tmp;
        }
        if (dp.empty()) return -1;
        int ans = INT_MAX;
        for (auto &p : dp) ans = min(ans, p.second);
        return ans;
    }
};
```