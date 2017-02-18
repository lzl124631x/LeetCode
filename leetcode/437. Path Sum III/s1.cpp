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
    int cnt = 0;
    void pathSum(TreeNode* root, int target, int sum) {
        if (!root) return;
        sum += root->val;
        if (sum == target) cnt++;
        pathSum(root->left, target, sum);
        pathSum(root->right, target, sum);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        pathSum(root, sum, 0);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return cnt;
    }
};