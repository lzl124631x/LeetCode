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
    bool isBalanced(TreeNode* root, int &h) {
        h = 0;
        if (!root) return true;
        int L, R;
        bool b = isBalanced(root->left, L) && isBalanced(root->right, R) && abs(L - R) <= 1;
        h = 1 + max(L, R);
        return b;
    }
public:
    bool isBalanced(TreeNode* root) {
        int h;
        return isBalanced(root, h);
    }
};