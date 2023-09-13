# [718. Maximum Length of Repeated Subarray (Medium)](https://leetcode.com/problems/maximum-length-of-repeated-subarray/)

<p>Given two integer arrays <code>nums1</code> and <code>nums2</code>, return <em>the maximum length of a subarray that appears in <strong>both</strong> arrays</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The repeated subarray with maximum length is [3,2,1].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
<strong>Output:</strong> 5
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 100</code></li>
</ul>


**Companies**:  
[Karat](https://leetcode.com/company/karat), [Indeed](https://leetcode.com/company/indeed), [Apple](https://leetcode.com/company/apple), [Amazon](https://leetcode.com/company/amazon), [Intuit](https://leetcode.com/company/intuit), [Wayfair](https://leetcode.com/company/wayfair)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Sliding Window](https://leetcode.com/tag/sliding-window/), [Rolling Hash](https://leetcode.com/tag/rolling-hash/), [Hash Function](https://leetcode.com/tag/hash-function/)

**Similar Questions**:
* [Minimum Size Subarray Sum (Medium)](https://leetcode.com/problems/minimum-size-subarray-sum/)

## Solution 1. DP

Let `dp[i + 1][j + 1]` be the length of the maximum subarray that appears in both the tail of `A[0..i]` and `B[0..j]`.

```
dp[i + 1][j + 1] = 1 + dp[i][j]     // A[i] == B[j]
                 = 0                // A[i] != B[j]
```

```cpp
// OJ: https://leetcode.com/problems/maximum-length-of-repeated-subarray
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int M = A.size(), N = B.size(), ans = 0;
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[i + 1][j + 1] = A[i] == B[j] ? (1 + dp[i][j]) : 0;
                ans = max(ans, dp[i + 1][j + 1]);
            }
        }
        return ans;
    }
};
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

Without hash conflict check (unsafe):

```cpp
// OJ: https://leetcode.com/problems/maximum-length-of-repeated-subarray/
// Author: github.com/lzl124631x
// Time: O((A + B)log(min(A, B)))
// Space: O(max(A, B))
class Solution {
    bool valid(vector<int> &A, vector<int> &B, int len) {
        unsigned long long d = 16777619, h = 0, p = 1;
        unordered_set<unsigned long long> s;
        for (int i = 0; i < A.size(); ++i) {
            h = h * d + A[i];
            if (i < len) p *= d;
            else h -= A[i - len] * p;
            if (i >= len - 1) s.insert(h);
        }
        h = 0;
        for (int i = 0; i < B.size(); ++i) {
            h = h * d + B[i];
            if (i >= len) h -= B[i - len] * p;
            if (i >= len - 1 && s.count(h)) return true;
        }
        return false;
    }
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int L = 0, R = min(A.size(), B.size());
        while (L < R) {
            int M = (L + R + 1) / 2;
            if (valid(A, B, M)) L = M;
            else R = M - 1;
        }
        return L;
    }
};
```

With hash conflict check:

```cpp
// OJ: https://leetcode.com/problems/maximum-length-of-repeated-subarray/
// Author: github.com/lzl124631x
// Time: O((A + B)log(min(A, B)))
// Space: O(A + B)
class Solution {
    typedef unsigned long long ULL;
    vector<ULL> rolling(vector<int> &A, int len) {
        unsigned long long d = 16777619, h = 0, p = 1;
        vector<ULL> ans;
        for (int i = 0; i < A.size(); ++i) {
            h = h * d + A[i];
            if (i < len) p *= d;
            else h -= A[i - len] * p;
            if (i >= len - 1) ans.push_back(h);
        }
        return ans;
    }
    bool valid(vector<int> &A, vector<int> &B, int len) {
        unordered_map<ULL, vector<int>> m;
        auto ra = rolling(A, len), rb = rolling(B, len);
        for (int i = 0; i < ra.size(); ++i) m[ra[i]].push_back(i);
        for (int i = 0; i < rb.size(); ++i) {
            if (m.count(rb[i]) == 0) continue;
            for (int j : m[rb[i]]) {
                if (equal(begin(A) + j, begin(A) + j + len, begin(B) + i)) return true;
            }
        }
        return false;
    }
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int L = 0, R = min(A.size(), B.size());
        while (L < R) {
            int M = (L + R + 1) / 2;
            if (valid(A, B, M)) L = M;
            else R = M - 1;
        }
        return L;
    }
};
```

Precompute hashes:

```cpp
// OJ: https://leetcode.com/problems/maximum-length-of-repeated-subarray/
// Author: github.com/lzl124631x
// Time: O((A + B)log(min(A, B)))
// Space: O(A)
const int maxN = 1001;
class Solution {
    typedef unsigned long long ULL;
    ULL ha[maxN], hb[maxN], p[maxN], d = 16777619;
    ULL hash(ULL *h, int begin, int end) {
        return h[end] - h[begin] * p[end - begin];
    }
    bool valid(vector<int> &A, vector<int> &B, int len) {
        unordered_map<ULL, vector<int>> m;
        for (int i = 0; i + len <= A.size(); ++i) m[hash(ha, i, i + len)].push_back(i);
        for (int i = 0; i + len <= B.size(); ++i) {
            ULL h = hash(hb, i, i + len);
            if (m.count(h) == 0) continue;
            for (int j : m[h]) {
                if (equal(begin(A) + j, begin(A) + j + len, begin(B) + i)) return true;
            }
        }
        return false;
    }
public:
    int findLength(vector<int>& A, vector<int>& B) {
        p[0] = 1;
        for (int i = 0; i < A.size() || i < B.size(); ++i) {
            p[i + 1] = p[i] * d;
            if (i < A.size()) ha[i + 1] = ha[i] * d + A[i];
            if (i < B.size()) hb[i + 1] = hb[i] * d + B[i];
        }
        int L = 0, R = min(A.size(), B.size());
        while (L < R) {
            int M = (L + R + 1) / 2;
            if (valid(A, B, M)) L = M;
            else R = M - 1;
        }
        return L;
    }
};
```