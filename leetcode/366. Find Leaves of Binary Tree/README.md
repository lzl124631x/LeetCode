# [366. Find Leaves of Binary Tree (Medium)](https://leetcode.com/problems/find-leaves-of-binary-tree/)

<p>Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.</p>

<p>&nbsp;</p>

<p><strong>Example:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[1,2,3,4,5]
&nbsp; 
&nbsp;         </span>1
         / \
        2   3
       / \     
      4   5    

<strong>Output: </strong><span id="example-output-1">[[4,5,3],[2],[1]]</span>
</pre>

<p>&nbsp;</p>

<p><strong>Explanation:</strong></p>

<p>1. Removing the leaves <code>[4,5,3]</code> would result in this tree:</p>

<pre>          1
         / 
        2          
</pre>

<p>&nbsp;</p>

<p>2. Now removing the leaf <code>[2]</code> would result in this tree:</p>

<pre>          1          
</pre>

<p>&nbsp;</p>

<p>3. Now removing the leaf <code>[1]</code> would result in the empty tree:</p>

<pre>          []         
</pre>

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-leaves-of-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
private:
    bool dfs(TreeNode *root, vector<int> &v) {
        if (!root) return true;
        if (!root->left && !root->right) {
            v.push_back(root->val);
            return true;
        }
        if (dfs(root->left, v)) root->left = NULL;
        if (dfs(root->right, v)) root->right = NULL;
        return false;
    }
    vector<int> removeLeaves(TreeNode *root) {
        vector<int> v;
        dfs(root, v);
        return v;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        while (root->left || root->right) {
            ans.push_back(removeLeaves(root));
        }
        ans.push_back({ root->val });
        return ans;
    }
};
```