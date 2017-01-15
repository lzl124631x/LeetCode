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
    bool isValidBST(TreeNode *root, TreeNode *LB, TreeNode *UB) {
        if (!root) return true;
        if ((LB && root->val <= LB->val) || (UB && root->val >= UB->val)) return false;
        return isValidBST(root->left, LB, root) && isValidBST(root->right, root, UB);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }
};