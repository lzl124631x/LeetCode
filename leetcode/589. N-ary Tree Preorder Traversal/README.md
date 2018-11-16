# [589. N-ary Tree Preorder Traversal (Easy)](https://leetcode.com/problems/n-ary-tree-preorder-traversal/)

<p>Given an n-ary tree, return the <i>preorder</i> traversal of its nodes' values.</p>

<p>For example, given a <code>3-ary</code> tree:</p>

<p>&nbsp;</p>

<p><img src="https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png" style="width: 100%; max-width: 300px;"></p>

<p>&nbsp;</p>

<p>Return its preorder traversal as: <code>[1,3,5,6,2,4]</code>.</p>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<p>Recursive solution is trivial, could you do it iteratively?</p>


## Solution 1. Recursive

```cpp
// OJ: https://leetcode.com/problems/n-ary-tree-preorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
private:
    vector<int> ans;
    void rec(Node *root) {
        if (!root) return;
        ans.push_back(root->val);
        for (auto ch : root->children) rec(ch);
    }
public:
    vector<int> preorder(Node* root) {
        rec(root);
        return ans;
    }
};
```

## Solution 2. Iterative

```cpp
// OJ: https://leetcode.com/problems/n-ary-tree-preorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root) return {};
        vector<int> ans;
        stack<Node*> s;
        s.push(root);
        while (s.size()) {
            root = s.top();
            s.pop();
            ans.push_back(root->val);
            for (int i = root->children.size() - 1; i >= 0; --i) {
                if (root->children[i]) s.push(root->children[i]);
            }
        }
        return ans;
    }
};
```