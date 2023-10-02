# [1130. Minimum Cost Tree From Leaf Values (Medium)](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/)

<p>Given an array <code>arr</code> of positive integers, consider all binary trees such that:</p>

<ul>
	<li>Each node has either 0 or 2 children;</li>
	<li>The values of <code>arr</code> correspond to the values of each&nbsp;<strong>leaf</strong> in an in-order traversal of the tree.&nbsp; <em>(Recall that a node is a leaf if and only if it has 0 children.)</em></li>
	<li>The value&nbsp;of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree respectively.</li>
</ul>

<p>Among all possible binary trees considered,&nbsp;return the smallest possible sum of the values of each non-leaf node.&nbsp; It is guaranteed this sum fits into a 32-bit integer.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [6,2,4]
<strong>Output:</strong> 32
<strong>Explanation:</strong>
There are two possible trees.  The first has non-leaf node sum 36, and the second has non-leaf node sum 32.

    24            24
   /  \          /  \
  12   4        6    8
 /  \               / \
6    2             2   4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= arr.length &lt;= 40</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 15</code></li>
	<li>It is guaranteed that the answer fits into a 32-bit signed integer (ie.&nbsp;it is less than <code>2^31</code>).</li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Stack](https://leetcode.com/tag/stack/), [Tree](https://leetcode.com/tag/tree/)

## Solution 1. DP

Let `dp[i][j]` be the answer to the subproblem on subarray `A[i..j]`.

```
dp[i][j] = min( dp[i][k] + dp[k+1][j] + mx(i, k) * mx(k+1, j) | i <= k < j )
dp[i][i] = 0
```
where `mx[i][j] = max(A[i], ..., A[j])`.

```cpp
// OJ: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
    int mctFromLeafValues(vector<int>& A) {
        int N = A.size();
        vector<vector<int>> mx(N, vector<int>(N)), dp(N, vector<int>(N, INT_MAX));
        for (int i = 0; i < N; ++i) {
            mx[i][i] = A[i];
            for (int j = i + 1; j < N; ++j) mx[i][j] = max(mx[i][j - 1], A[j]);
        }  
        for (int i = 0; i < N; ++i) dp[i][i] = 0;
        for (int i = N - 2; i >= 0; --i) {
            for (int j = i + 1; j < N; ++j) {
                for (int k = i; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + mx[i][k] * mx[k + 1][j]);
                }
            }
        }
        return dp[0][N - 1];
    }
};
```

## Solution 2. Greedy

```cpp
// OJ: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
// Ref: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/discuss/339959/One-Pass-O(N)-Time-and-Space
class Solution {
public:
    int mctFromLeafValues(vector<int>& A) {
        int ans = 0;
        while (A.size() > 1) {
            auto it = min_element(A.begin(), A.end());
            int left = it == A.begin() ? INT_MAX : *(it - 1);
            int right = it == A.end() - 1 ? INT_MAX : *(it + 1);
            ans += *it * min(left, right);
            A.erase(it);
        }
        return ans;
    }
};
```

## Solution 3. Greedy

We should greedily pick the smallest pair to form a subtree. Then we can remove the smaller element of the pair from the array since it won't be used again.

```cpp
// OJ: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int mctFromLeafValues(vector<int>& A) {
        int ans = 0, N = A.size();
        for (int N = A.size(); N > 1; --N) {
            int best = 1;
            for (int i = 2; i < N; ++i) {
                if (A[i] * A[i - 1] < A[best] * A[best - 1]) best = i;
            }
            ans += A[best] * A[best - 1];
            if (A[best] > A[best - 1]) --best;
            A.erase(A.begin() + best);
        }
        return ans;
    }
};
```

## Solution 4. Greedy + Monotonic Stack

```cpp
// OJ: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/discuss/339959/One-Pass-O(N)-Time-and-Space
class Solution {
public:
    int mctFromLeafValues(vector<int>& A) {
        int ans = 0;
        vector<int> s{INT_MAX};
        for (int n : A) {
            while (s.back() <= n) {
                int mid = s.back();
                s.pop_back();
                ans += mid * min(s.back(), n);
            }
            s.push_back(n);
        }
        for (int i = 2; i < s.size(); ++i) ans += s[i] * s[i - 1];
        return ans;
    }
};
```