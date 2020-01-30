# AVL Tree
An AVL Tree (named after Soviet inventors **A**delson-**V**elsky and **L**andis) is a self-balancing binary search tree (BST). It was the first such data structure to be invented.

In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Lookup, insertion, and deletion all take `O(logN)` time in both the average and worst cases, where `n` is the number of nodes in the tree prior to the operation. Insertions and deletions may require the tree to be rebalanced by one or more tree rotations.

## Implementation

```cpp
class AvlTreeNode {
private:
    int diff = 0;
public:
    int value;
    AvlTreeNode *left = NULL, *right = NULL;
    AvlTreeNode(int val): value(val) {};
}

class AvlTree {
private:
    AvlTreeNode *root;
    AvlTreeNode *find(AclTreeNode *node, int target) {
        if (!node) return NULL;
        if (node->val == target) return node;
        if (node->val > target) return find(node->left, target);
        return find(node->right, target);
    }
public:
    void insert(int val) {
        if (!root) {
            root = new AvlTree(val);
        }
    }

    AvlTreeNode* find(int val) {
        return find(root, val);
    }

    void remove(int val) {

    }
}
```

## Reference
* [Wiki](https://en.wikipedia.org/wiki/AVL_tree)
* [AVL Tree | Set 1 (Insertion)](https://www.geeksforgeeks.org/avl-tree-set-1-insertion/)