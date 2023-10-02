# [257. Binary Tree Paths (Easy)](https://leetcode.com/problems/binary-tree-paths/)

<p>Given a binary tree, return all root-to-leaf paths.</p>

<p><strong>Note:</strong>&nbsp;A leaf is a node with no children.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong>

   1
 /   \
2     3
 \
  5

<strong>Output:</strong> ["1-&gt;2-&gt;5", "1-&gt;3"]

<strong>Explanation:</strong> All root-to-leaf paths are: 1-&gt;2-&gt;5, 1-&gt;3
</pre>

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

## Solution 1. Preorder Traversal

Since each level we need to copy the `path`, it multiplies `O(H)` to both the time and space complexity.

```cpp
// OJ: https://leetcode.com/problems/binary-tree-paths/
// Author: github.com/lzl124631x
// Time: O(NH)
// Space: O(H^2)
class Solution {
private:
    vector<string> v;
    void preorder(TreeNode *root, string path) {
        path += to_string(root->val);
        if (!root->left && !root->right) {
            v.push_back(path);
            return;
        }
        path += "->";
        if (root->left) preorder(root->left, path);
        if (root->right) preorder(root->right, path);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        preorder(root, "");
        return v;
    }
};
```

## Solution 2. Preorder Traversal

Use `vector<TreeNode*>` to store the path visited and construct the string on leaf node.

```cpp
// OJ: https://leetcode.com/problems/binary-tree-paths/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
private:
    vector<TreeNode*> v;
    vector<string> ans;
    string getString() {
        string s = to_string(v[0]->val);
        for (int i = 1; i < v.size(); ++i) {
            s += "->" + to_string(v[i]->val);
        }
        return s;
    }
    void preorder(TreeNode *root) {
        v.push_back(root);
        if (!root->left && !root->right) ans.push_back(getString());
        if (root->left) preorder(root->left);
        if (root->right) preorder(root->right);
        v.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        preorder(root);
        return ans;
    }
};
```