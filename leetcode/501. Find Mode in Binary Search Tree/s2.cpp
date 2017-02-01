// https://discuss.leetcode.com/topic/77335/proper-o-1-space
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
    void handleVal(int val) {
        if (val != currVal) {
            currVal = val;
            currCount = 0;
        }
        ++currCount;
        if (currCount > maxCount) {
            maxCount = currCount;
            modeCount = 1;
        } else if (currCount == maxCount) {
            if (collect) {
                modes.push_back(currVal);
            }
            ++modeCount;
        }
    }
    
    void traverse(TreeNode *root) {
        if (!root) return;
        traverse(root->left);
        handleVal(root->val);
        traverse(root->right);
    }
    vector<int> modes;
    int modeCount = 0;
    int currCount = 0;
    int currVal = 0;
    int maxCount = 0;
    bool collect = false;
public:
    vector<int> findMode(TreeNode* root) {
        traverse(root);
        modeCount = 0;
        currCount = 0;
        collect = true;
        traverse(root);
        return modes;
    }
};