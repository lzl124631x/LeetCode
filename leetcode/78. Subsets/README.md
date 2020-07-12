# [78. Subsets (Medium)](https://leetcode.com/problems/subsets/)

<p>Given a set of <strong>distinct</strong> integers, <em>nums</em>, return all possible subsets (the power set).</p>

<p><strong>Note:</strong> The solution set must not contain duplicate subsets.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong>
[
  [3],
&nbsp; [1],
&nbsp; [2],
&nbsp; [1,2,3],
&nbsp; [1,3],
&nbsp; [2,3],
&nbsp; [1,2],
&nbsp; []
]</pre>


## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/subsets/
// Author: github.com/lzl124631x
// Time: O(N * 2^N)
// Space: O(N)
class Solution {
    vector<vector<int>> ans;
    void dfs(vector<int> &A, int i, vector<int> &s) {
        if (i == A.size()) {
            ans.push_back(s);
            return;
        }
        s.push_back(A[i]); // Pick A[i]
        dfs(A, i + 1, s);
        s.pop_back(); // Skip A[i]
        dfs(A, i + 1, s);
    }
public:
    vector<vector<int>> subsets(vector<int>& A) {
        vector<int> s;
        dfs(A, 0, s);
        return ans;
    }
};
```

## Solution 2. Backtrack

```cpp
// OJ: https://leetcode.com/problems/subsets
// Author: github.com/lzl124631x
// Time: O(N * 2^N)
// Space: O(N)
class Solution {
    vector<vector<int>> ans;
    void dfs(vector<int> &A, int start, int len, vector<int> &s) {
        if (s.size() == len) {
            ans.push_back(s);
            return;
        }
        for (int i = start; i <= A.size() - len + s.size(); ++i) {
            s.push_back(A[i]);
            dfs(A, i + 1, len, s);
            s.pop_back(); // backtrack
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& A) {
        vector<int> s;
        for (int len = 0; len <= A.size(); ++len) dfs(A, 0, len, s);
        return ans;
    }
};
```

## Solution 3. Bit Mask

```cpp
// OJ: https://leetcode.com/problems/subsets
// Author: github.com/lzl124631x
// Time: O(N * 2^N)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/2764/my-solution-using-bit-manipulation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& A) {
        int N = 1 << A.size();
        vector<vector<int>> ans(N);
        for (int i = 0; i < A.size(); ++i) { // For each numbers in A
            for (int j = 0; j < N; ++j) { // check if it is in the jth subset in the output
                if (j >> i & 1) ans[j].push_back(A[i]);
            }
        }
        return ans;
    }
};
```

## Solution 4. DP

Let `dp[i]` be the subsets ending with `A[i]`.

```
dp[i] = [ [k, A[i]] | k is in dp[i-1] ]
```

```cpp
// OJ: https://leetcode.com/problems/subsets
// Author: github.com/lzl124631x
// Time: O(N * 2^N)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& A) {
        vector<vector<int>> ans(1);
        for (int i = 0; i < A.size(); ++i) {
            int len = ans.size();
            for (int j = 0; j < len; ++j) {
                ans.push_back(ans[j]);
                ans.back().push_back(A[i]);
            }
        }
        return ans;
    }
};
```