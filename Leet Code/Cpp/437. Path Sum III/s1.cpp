class Solution {
private:
    int _cnt = 0;
    int _sum;
    int _curSum;
    void traverseRoot(TreeNode *root) {
        if (!root) return;
        count(root);
        traverseRoot(root->left);
        traverseRoot(root->right);
    }
    void count(TreeNode *node) {
        if (!node) return;
        _curSum += node->val;
        if (_curSum == _sum) {
            ++_cnt;
        }
        count(node->left);
        count(node->right);
        _curSum -= node->val;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        _sum = sum;
        _curSum = 0;
        traverseRoot(root);
        return _cnt;
    }
};