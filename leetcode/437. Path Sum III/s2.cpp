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
    int pathSum(TreeNode* root, int target, int sum) {
        return root ? ((sum += root->val) == target) + pathSum(root->left, target, sum) + pathSum(root->right, target, sum) : 0;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        return root ? pathSum(root, sum, 0) + pathSum(root->left, sum) + pathSum(root->right, sum) : 0;
    }
};