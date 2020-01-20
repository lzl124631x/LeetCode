# Binary Search Tree

**Binary Search Tree** is a node-based binary tree data structure which has the following properties:

* The left subtree of a node contains only nodes with keys lesser than the node’s key.
* The right subtree of a node contains only nodes with keys greater than the node’s key.
* The left and right subtree each must also be a binary search tree.

## Implementation

```cpp
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val): val(val), left(NULL), right(NULL) {};
};

class BinarySearchTree {
private:
    TreeNode *find(TreeNode *node, int target) {
        if (!node || node->val == target) return node;
        if (node->val > target) return find(node->left, target);
        return find(node->right, target);
    }
    TreeNode *insert(TreeNode *node, int val) {
        if (!node) return new TreeNode(val);
        if (node->val < val) node->right = insert(node->right, val);
        else if (node->val > val) node->left = insert(node->left, val);
        return node;
    }
public:
    TreeNode *root = NULL;
    void insert(int val) {
        root = insert(root, val);
    }

    TreeNode* find(int target) {
        return find(root, target);
    }

    bool remove(int target) {
        TreeNode **parent = &root, *node = root;
        while (node) {
            if (node->val == target) break;
            if (node->val < target) {
                node = node->right;
                parent = &(*parent)->right;
            } else {
                node = node->left;
                parent = &(*parent)->left;
            }
        }
        if (!node) return false;
        if (node->right) {
            *parent = node->right;
            auto left = node->left;
            delete node;
            node = *parent;
            while (node->left) node = node->left;
            node->left = left;
        } else if (node->left) {
            *parent = node->left;
            delete node;
        } else *parent = NULL;
        return true;
    }
};
```

## Reference

* [Binary Search Tree | GeeksforGeeks](https://www.geeksforgeeks.org/binary-search-tree-data-structure/)