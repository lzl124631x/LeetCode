# [199. Binary Tree Right Side View (Medium)](https://leetcode.com/problems/binary-tree-right-side-view/)

<p>Given a binary tree, imagine yourself standing on the <em>right</em> side of it, return the values of the nodes you can see ordered from top to bottom.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong>&nbsp;[1,2,3,null,5,null,4]
<strong>Output:</strong>&nbsp;[1, 3, 4]
<strong>Explanation:
</strong>
   1            &lt;---
 /   \
2     3         &lt;---
 \     \
  5     4       &lt;---
</pre>

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/), [Recursion](https://leetcode.com/tag/recursion/), [Queue](https://leetcode.com/tag/queue/)

**Similar Questions**:
* [Populating Next Right Pointers in Each Node (Medium)](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)
* [Boundary of Binary Tree (Medium)](https://leetcode.com/problems/boundary-of-binary-tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/binary-tree-right-side-view/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    vector<int> ans;
    void dfs(TreeNode *root, int lv) {
        if (!root) return;
        if (lv == ans.size()) ans.push_back(root->val);
        else ans[lv] = root->val;
        dfs(root->left, lv + 1);
        dfs(root->right, lv + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};
```