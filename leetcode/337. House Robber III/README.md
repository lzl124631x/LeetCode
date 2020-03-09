# [337. House Robber III (Medium)](https://leetcode.com/problems/house-robber-iii/)

<p>The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.</p>

<p>Determine the maximum amount of money the thief can rob tonight without alerting the police.</p>

<p><b>Example 1:</b></p>

<pre><strong>Input: </strong>[3,2,3,null,3,null,1]

     <font color="red">3</font>
    / \
   2   3
    \   \ 
     <font color="red">3   1
</font>
<strong>Output:</strong> 7 
<strong>Explanation:</strong>&nbsp;Maximum amount of money the thief can rob = <font color="red" style="font-family: sans-serif, Arial, Verdana, &quot;Trebuchet MS&quot;;">3</font><span style="font-family: sans-serif, Arial, Verdana, &quot;Trebuchet MS&quot;;"> + </span><font color="red" style="font-family: sans-serif, Arial, Verdana, &quot;Trebuchet MS&quot;;">3</font><span style="font-family: sans-serif, Arial, Verdana, &quot;Trebuchet MS&quot;;"> + </span><font color="red" style="font-family: sans-serif, Arial, Verdana, &quot;Trebuchet MS&quot;;">1</font><span style="font-family: sans-serif, Arial, Verdana, &quot;Trebuchet MS&quot;;"> = </span><b style="font-family: sans-serif, Arial, Verdana, &quot;Trebuchet MS&quot;;">7</b><span style="font-family: sans-serif, Arial, Verdana, &quot;Trebuchet MS&quot;;">.</span></pre>

<p><b>Example 2:</b></p>

<pre><strong>Input: </strong>[3,4,5,1,3,null,1]

&nbsp;    3
    / \
   <font color="red">4</font>   <font color="red">5</font>
  / \   \ 
 1   3   1

<strong>Output:</strong> 9
<strong>Explanation:</strong>&nbsp;Maximum amount of money the thief can rob = <font color="red">4</font> + <font color="red">5</font> = <b>9</b>.
</pre>

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

**Similar Questions**:
* [House Robber (Easy)](https://leetcode.com/problems/house-robber/)
* [House Robber II (Medium)](https://leetcode.com/problems/house-robber-ii/)

## Solution 1. DP

At each node, we have two options, rob or skip.

If we rob it, the best we can get is `node->val + skip(node->left) + skip(node->right)` where `skip(x)` means the best outcome we can get if we skip node  `x`.

If we skip it, the best we can get is `best(node->left) + best(node->right)`, where `best(x)` means the best outcome we can get at node `x` (`best(x) = max(rob(x), skip(x))`).

So we can do a postorder traversal and return a pair of `rob(x)` and `skip(x)` at each node `x`.

```cpp
// OJ: https://leetcode.com/problems/house-robber-iii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    pair<int, int> dfs(TreeNode *root) {
        if (!root) return {0, 0};
        auto a = dfs(root->left), b = dfs(root->right);
        return { root->val + a.second + b.second, max(a.first, a.second) + max(b.first, b.second) };
    }
public:
    int rob(TreeNode* root) {
        auto p = dfs(root);
        return max(p.first, p.second);
    }
};
```