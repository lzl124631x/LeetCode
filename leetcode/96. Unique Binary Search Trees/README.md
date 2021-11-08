# [96. Unique Binary Search Trees (Medium)](https://leetcode.com/problems/unique-binary-search-trees/)

<p>Given an integer <code>n</code>, return <em>the number of structurally unique <strong>BST'</strong>s (binary search trees) which has exactly </em><code>n</code><em> nodes of unique values from</em> <code>1</code> <em>to</em> <code>n</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg" style="width: 600px; height: 148px;">
<pre><strong>Input:</strong> n = 3
<strong>Output:</strong> 5
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 19</code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Bloomberg](https://leetcode.com/company/bloomberg), [Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Tree](https://leetcode.com/tag/tree/), [Binary Search Tree](https://leetcode.com/tag/binary-search-tree/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Unique Binary Search Trees II (Medium)](https://leetcode.com/problems/unique-binary-search-trees-ii/)

## Solution 1. DP Bottom-up

Let `dp[i]` be the answer.

To get `dp[i]`, we can pick `j` as the root node (`1 <= j <= i`), then there are `j - 1` nodes in the left sub-tree and `i - j` nodes in the right sub-tree, and they have `dp[j - 1]` and `dp[i - j]` unique BSTs respectively. So `dp[i] = sum( dp[j - 1] * dp[i - j] | 1 <= j <= i)`

```cpp
// OJ: https://leetcode.com/problems/unique-binary-search-trees
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int numTrees(int n) {
        int dp[20] = {[0 ... 1] = 1};
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
```

## Solution 2. DP Top-down

Let `dp[i]` be the number of unique BST's given `i` nodes.

If there are `j` nodes in the left subtree, then there are `n - j - 1` nodes in the right subtree. Both subtrees are BST's as well. So `dp[i] = sum( dp[j] * dp[n - j - 1] | 0 <= j < n )`.

```cpp
// OJ: https://leetcode.com/problems/unique-binary-search-trees/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int numTrees(int n) {
        int dp[20] = {[0 ... 1] = 1};
        function<int(int)> dfs = [&](int n) {
            if (dp[n]) return dp[n];
            for (int i = 1; i <= n; ++i) dp[n] += dfs(i - 1) * dfs(n - i);
            return dp[n];
        };
        return dfs(n);
    }
};
```

## Solution 2. Catalan Number

$$
C_n = \dfrac{1}{n+1}{2n \choose n} = \dfrac{(2n)!}{(n+1)!n!}=\prod_{k=2}^{n}\dfrac{n+k}{k}\quad \text{for } n \ge 0
$$

```cpp
// OJ: https://leetcode.com/problems/unique-binary-search-trees
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/13321/a-very-simple-and-straight-ans-based-on-math-catalan-number-o-n-times-o-1-space
class Solution {
public:
    int numTrees(int n) {
        long long ans = 1, i;
        for (i = 1; i <= n; ++i) ans = ans * (i + n) / i;
        return ans / i;
    }
};
```