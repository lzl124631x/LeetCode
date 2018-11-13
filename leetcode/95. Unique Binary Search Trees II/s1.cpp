// OJ: https://leetcode.com/problems/unique-binary-search-trees-ii/
// Author: github.com/lzl124631x
// Time: O(N*C(N)) where C(N) is Catalan Number which equals
//   the count of unique BST. For each tree we visit each node once.
// Space: O(C(N)) because the intermediate `lefts` and `rights` vectors.
//   The actual nodes and the returned vector are not counted as consumptions.
class Solution {
private:
    vector<TreeNode*> generateTrees(int first, int last) {
        if (first > last) return { NULL };
        vector<TreeNode*> v;
        for (int i = first; i <= last; ++i) {
            auto lefts = generateTrees(first, i - 1);
            auto rights = generateTrees(i + 1, last);
            for (auto left : lefts) {
                for (auto right : rights) {
                    v.push_back(new TreeNode(i));
                    v.back()->left = left;
                    v.back()->right = right;
                }
            }
        }
        return v;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0) return {};
        return generateTrees(1, n);
    }
};