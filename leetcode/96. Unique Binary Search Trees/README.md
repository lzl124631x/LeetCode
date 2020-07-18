# [96. Unique Binary Search Trees (Medium)](https://leetcode.com/problems/unique-binary-search-trees/)

<p>Given <em>n</em>, how many structurally unique <strong>BST's</strong> (binary search trees) that store values 1 ...&nbsp;<em>n</em>?</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> 3
<strong>Output:</strong> 5
<strong>Explanation:
</strong>Given <em>n</em> = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
</pre>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Tree](https://leetcode.com/tag/tree/)

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
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) dp[i] += dp[j - 1] * dp[i - j];
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
    vector<int> memo;
    int dp(int n) {
        if (memo[n]) return memo[n];
        int ans = 0;
        for (int i = 0; i < n; ++i) ans += dp(i) * dp(n - i - 1);
        return memo[n] = ans;
    }
public:
    int numTrees(int n) {
        memo.assign(n + 1, 0);
        memo[0] = 1;
        return dp(n);
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