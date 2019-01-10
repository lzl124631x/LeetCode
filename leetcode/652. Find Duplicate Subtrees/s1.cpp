// OJ: https://leetcode.com/problems/find-duplicate-subtrees/
// Author: github.com/lzl124631x
// Time: O(N^2) since string concatenation takes O(N) time on average
// Space: O(N^2) since string take O(N) space on average
// Ref: https://leetcode.com/problems/find-duplicate-subtrees/solution/
class Solution {
private:
    unordered_map<string, int> treeToCnt;
    vector<TreeNode*> ans;
    string collect(TreeNode *node) {
        if (!node) return "#";
        string s = to_string(node->val) + "," + collect(node->left) + "," + collect(node->right);
        if (treeToCnt[s] == 1) ans.push_back(node);
        treeToCnt[s]++;
        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        collect(root);
        return ans;
    }
};