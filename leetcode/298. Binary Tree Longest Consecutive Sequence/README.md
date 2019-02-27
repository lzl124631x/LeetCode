# [298. Binary Tree Longest Consecutive Sequence (Medium)](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/)

<p>Given a binary tree, find the length of the longest consecutive sequence path.</p>

<p>The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong>

   1
    \
     3
    / \
   2   4
        \
         5

<strong>Output:</strong> <code>3</code>

<strong>Explanation: </strong>Longest consecutive sequence path is <code>3-4-5</code><span style="font-family: sans-serif, Arial, Verdana, &quot;Trebuchet MS&quot;;">, so return </span><code>3</code><span style="font-family: sans-serif, Arial, Verdana, &quot;Trebuchet MS&quot;;">.</span></pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:

</strong>   2
    \
     3
    / 
   2    
  / 
 1

<strong>Output: 2 

Explanation: </strong>Longest consecutive sequence path is <code>2-3</code><span style="font-family: sans-serif, Arial, Verdana, &quot;Trebuchet MS&quot;;">, not </span><code>3-2-1</code><span style="font-family: sans-serif, Arial, Verdana, &quot;Trebuchet MS&quot;;">, so return </span><code>2</code><span style="font-family: sans-serif, Arial, Verdana, &quot;Trebuchet MS&quot;;">.</span></pre>

**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

**Similar Questions**:
* [Longest Consecutive Sequence (Hard)](https://leetcode.com/problems/longest-consecutive-sequence/)
* [Binary Tree Longest Consecutive Sequence II (Medium)](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
private:
    int ans = 0;
    void preorder(TreeNode *node, TreeNode *parent, int length) {
        if (!node) return;
        length = parent && parent->val + 1 == node->val ? length + 1 : 1;
        ans = max(ans, length);
        preorder(node->left, node, length);
        preorder(node->right, node, length);
    }
public:
    int longestConsecutive(TreeNode* root) {
        preorder(root, NULL, 0);
        return ans;
    }
};
```