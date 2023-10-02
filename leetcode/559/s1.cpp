// OJ: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        int maxd = 0;
        for (auto ch : root->children) {
            maxd = max(maxd, maxDepth(ch));
        }
        return 1 + maxd;
    }
};