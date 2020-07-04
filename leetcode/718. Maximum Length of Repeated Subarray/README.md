# [718. Maximum Length of Repeated Subarray (Medium)](https://leetcode.com/problems/maximum-length-of-repeated-subarray/)

<p>Given two integer arrays <code>A</code> and <code>B</code>, return the maximum length of an subarray that appears in both arrays.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b>
A: [1,2,3,2,1]
B: [3,2,1,4,7]
<b>Output:</b> 3
<b>Explanation:</b> 
The repeated subarray with maximum length is [3, 2, 1].
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>1 &lt;= len(A), len(B) &lt;= 1000</li>
<li>0 &lt;= A[i], B[i] &lt; 100</li>
</ol>
<p></p>

**Companies**:  
[Intuit](https://leetcode.com/company/intuit)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Binary Search](https://leetcode.com/tag/binary-search/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Minimum Size Subarray Sum (Medium)](https://leetcode.com/problems/minimum-size-subarray-sum/)

## Solution 1. DP

Let `dp[i + 1][j + 1]` be the lenght of the maximum subarray that appears in both the tail of `A` and `B`.

```
dp[i + 1][j + 1] = 1 + dp[i][j]     // A[i] == B[j]
                 = 0                // A[i] != B[j]
```

Since `dp[i + 1][j + 1]` only depends on `dp[i][j]`, we can use 1D array to store the `dp` array.

```cpp
// OJ: https://leetcode.com/problems/maximum-length-of-repeated-subarray/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(min(M, N))
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if (A.size() < B.size()) swap(A, B);
        int M = A.size(), N = B.size(), ans = 0;
        vector<int> dp(N + 1, 0);
        for (int i = 0; i < M; ++i) {
            for (int j = N - 1; j >= 0; --j) {
                dp[j + 1] = A[i] == B[j] ? 1 + dp[j] : 0;
                ans = max(ans, dp[j + 1]);
            }
        }
        return ans;
    }
};
```

## Solution 2. Binary Answer + Rolling Hash

Use binary answer to search the maximum length.

For a given length `len`, generate the rolling hash on `A` and `B` and see if there is any hash showing up for both array.

```cpp
// OJ: https://leetcode.com/problems/maximum-length-of-repeated-subarray/
// Author: github.com/lzl124631x
// Time: O(log(min(M, N)) * (M + N))
// Space: O(M + N)
class Solution {
    vector<int> rolling(vector<int> &A, int len) {
        vector<int> ans(A.size() - len + 1);
        long h = A[0], p = 1, mod = 1e9+7, d = 14;
        for (int i = 1; i < len; ++i) {
            h = (h * d + A[i]) % mod;
            p = (p * d) % mod;
        }
        ans[0] = h;
        for (int i = 0; i < A.size() - len; ++i) {
            h = ((h - A[i] * p) * d + A[i + len]) % mod;
            if (h < 0) h += mod;
            ans[i + 1] = h;
        }
        return ans;
    }
    bool valid(int len, vector<int> &A, vector<int>& B) {
        if (!len) return true;
        unordered_map<int, vector<int>> m;
        int index = 0;
        for (int h : rolling(A, len)) m[h].push_back(index++);
        int j = 0;
        for (int h : rolling(B, len)) {
            for (int i : m[h]) {
                bool same = true;
                for (int k = 0; k < len && same; ++k) same = A[i + k] == B[j + k];
                if (same) return true;
            }
            ++j;
        }
        return false;
    }
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int L = 0, R = min(A.size(), B.size());
        while (L <= R) {
            int M = (L + R) / 2;
            if (valid(M, A, B)) L = M + 1;
            else R = M - 1;
        }
        return R;
    }
};
```