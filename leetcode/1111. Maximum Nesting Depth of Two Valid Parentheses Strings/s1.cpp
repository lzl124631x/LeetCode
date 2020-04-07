// OJ: https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> maxDepthAfterSplit(string A) {
        int N = A.size(), lv = 0;
        vector<int> ans(N);
        for (int i = 0; i < N; ++i) {
            if (A[i] == '(') ans[i] = lv++ % 2;
            else ans[i] = --lv % 2;
        }
        return ans;
    }
};