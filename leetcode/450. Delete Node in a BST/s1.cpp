/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void find (TreeNode *root, int key, TreeNode *&p, TreeNode *&node) {
        if (!root) {
            node = NULL;
            return;
        }
        p = node;
        node = root;
        if (root->val == key) return;
        else if (root->val > key) find(root->left, key, p, node);
        else find(root->right, key, p, node);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *p = NULL, *node = NULL;
        find(root, key, p, node);
        if (!node) return root; // not found
        if (!node->left && !node->right) { // delete leaf node
            if (!p) return NULL; // delete root node
            if (p->left == node) p->left = NULL;
            else p->right = NULL;
        } else if (node->left && node->right) {
            TreeNode *d = node->left;
            p = node;
            while (d->right) {
                p = d;
                d = d->right;
            }
            node->val = d->val;
            if (node != p) {
                p->right = d->left;
            } else {
                p->left = d->left;
            }
        } else {
            TreeNode *newNode = node->left ? node->left : node->right;
            if (!p) return newNode;
            if (p->left == node) {
                p->left = newNode;
            } else {
                p->right = newNode;
            }
        }
        return root;
    }
};