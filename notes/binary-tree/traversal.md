# Binary Tree Traversal

## Preorder

[144. Binary Tree Preorder Traversal (Medium)](https://leetcode.com/problems/binary-tree-preorder-traversal/)

See more my solutions [here](../../leetcode/144.%20Binary%20Tree%20Preorder%20Traversal)

```cpp
// OJ: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> v;
        stack<TreeNode*> s;
        s.push(root);
        while (s.size()) {
            root = s.top();
            s.pop();
            v.push_back(root->val);
            if (root->right) s.push(root->right);
            if (root->left) s.push(root->left);
        }
        return v;
    }
};
```

## Inorder

[94. Binary Tree Inorder Traversal (Medium)](https://leetcode.com/problems/binary-tree-inorder-traversal/)

See more my solutions [here](../../leetcode/94.%20Binary%20Tree%20Inorder%20Traversal)

```cpp
// OJ: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            v.push_back(root->val);
            root = root->right;
        }
        return v;
    }
};
```

## Postorder

[145. Binary Tree Postorder Traversal (Hard)](https://leetcode.com/problems/binary-tree-postorder-traversal/)

See more my solutions [here](../../leetcode/145.%20Binary%20Tree%20Postorder%20Traversal)

```cpp
// OJ: https://leetcode.com/problems/binary-tree-postorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        TreeNode *prev = NULL;
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            if (!root->right || root->right == prev) {
                s.pop();
                v.push_back(root->val);
                prev = root;
                root = NULL;
            } else {
                root = root->right;
            }
        }
        return v;
    }
};
```

## Level-order

[102. Binary Tree Level Order Traversal (Medium)](https://leetcode.com/problems/binary-tree-level-order-traversal/)

See more my solutions [here](../../leetcode/102.%20Binary%20Tree%20Level%20Order%20Traversal)

```cpp
// OJ: https://leetcode.com/problems/binary-tree-level-order-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 1;
        while (q.size()) {
            int nextCnt = 0;
            vector<int> level;
            while (cnt--) {
                root = q.front();
                q.pop();
                level.push_back(root->val);
                if (root->left) {
                    ++nextCnt;
                    q.push(root->left);
                }
                if (root->right) {
                    ++nextCnt;
                    q.push(root->right);
                }
            }
            ans.push_back(level);
            cnt = nextCnt;
        }
        return ans;
    }
};
```

## Other variations

* [107. Binary Tree Level Order Traversal II (Easy)](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)
* [103. Binary Tree Zigzag Level Order Traversal (Medium)](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)