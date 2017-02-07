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
    unordered_map<int, int> m;
    int maxCnt = 0;
    int getSum(TreeNode *root) {
        if (!root) return 0;
        int sum = root->val + getSum(root->left) + getSum(root->right);
        m[sum]++;
        maxCnt = max(maxCnt, m[sum]);
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        getSum(root);
        vector<int> ans;
        for (auto p : m) {
            if (p.second == maxCnt) ans.push_back(p.first);
        }
        return ans;
    }
};