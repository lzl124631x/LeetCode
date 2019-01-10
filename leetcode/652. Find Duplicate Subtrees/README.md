# [652. Find Duplicate Subtrees (Medium)](https://leetcode.com/problems/find-duplicate-subtrees/)

<p>Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any <b>one</b> of them.</p>

<p>Two trees are duplicate if they have the same structure with same node values.</p>

<p><b>Example 1: </b></p>

<pre>        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
</pre>

<p>The following are two duplicate subtrees:</p>

<pre>      2
     /
    4
</pre>

<p>and</p>

<pre>    4
</pre>
Therefore, you need to return above trees' root in the form of a list.

**Companies**:  
[Uber](https://leetcode.com/company/uber), [Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

**Similar Questions**:
* [Serialize and Deserialize Binary Tree (Hard)](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)
* [Serialize and Deserialize BST (Medium)](https://leetcode.com/problems/serialize-and-deserialize-bst/)
* [Construct String from Binary Tree (Easy)](https://leetcode.com/problems/construct-string-from-binary-tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-duplicate-subtrees/
// Author: github.com/lzl124631x
// Time: O(N^2) since string concatenation takes O(N) time on average
// Space: O(N^2) since string take O(N) space on average
// Ref: https://leetcode.com/problems/find-duplicate-subtrees/solution/
class Solution {
private:
    unordered_map<string, int> treeToCnt;
    vector<TreeNode*> ans;
    string collect(TreeNode *node) {
        if (!node) return "#";
        string s = to_string(node->val) + "," + collect(node->left) + "," + collect(node->right);
        if (treeToCnt[s] == 1) ans.push_back(node);
        treeToCnt[s]++;
        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        collect(root);
        return ans;
    }
};
```