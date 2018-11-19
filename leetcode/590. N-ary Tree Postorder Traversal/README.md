# [590. N-ary Tree Postorder Traversal (Easy)](https://leetcode.com/problems/n-ary-tree-postorder-traversal/)

<p>Given an n-ary tree, return the <i>postorder</i> traversal of its nodes' values.</p>

<p>For example, given a <code>3-ary</code> tree:</p>

<p>&nbsp;</p>

<p><img src="https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png" style="width: 100%; max-width: 300px;"></p>

<p>&nbsp;</p>

<p>Return its postorder traversal as: <code>[5,6,3,2,4,1]</code>.</p>
&nbsp;

<p><b>Note:</b></p>

<p>Recursive solution is trivial, could you do it iteratively?</p>


## Solution 1. Recursive

```cpp
// OJ: https://leetcode.com/problems/n-ary-tree-postorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
private:
    vector<int> ans;
    void rec(Node *root) {
        if (!root) return;
        for (auto ch : root->children) rec(ch);
        ans.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        rec(root);
        return ans;
    }
};
```