struct TreeNode* invertTree(struct TreeNode* root) {
    if (root) {
        struct TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
    }
    return root;
}