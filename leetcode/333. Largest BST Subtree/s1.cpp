// OJ: https://leetcode.com/problems/largest-bst-subtree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
private:
    bool postorder(TreeNode *root, int &minVal, int &maxVal, int &largestBSTSize) {
        if (!root) {
            largestBSTSize = 0;
            return true;
        }
        int leftMin, leftMax, leftCnt, rightMin, rightMax, rightCnt;
        bool left = postorder(root->left, leftMin, leftMax, leftCnt);
        bool right = postorder(root->right, rightMin, rightMax, rightCnt);
        if (left && right && (!leftCnt || root->val > leftMax) && (!rightCnt || root->val < rightMin)) {
            minVal = leftCnt ? leftMin : root->val;
            maxVal = rightCnt ? rightMax : root->val;
            largestBSTSize = leftCnt + rightCnt + 1;
            return true;
        }
        largestBSTSize = max(1, max(leftCnt, rightCnt));
        return false;
    }
public:
    int largestBSTSubtree(TreeNode* root) {
        int minVal, maxVal, largestBSTSize;
        postorder(root, minVal, maxVal, largestBSTSize);
        return largestBSTSize;
    }
};