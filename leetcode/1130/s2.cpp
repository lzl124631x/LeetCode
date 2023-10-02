// OJ: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
// Ref: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/discuss/339959/One-Pass-O(N)-Time-and-Space
class Solution {
public:
    int mctFromLeafValues(vector<int>& A) {
        int ans = 0;
        while (A.size() > 1) {
            auto it = min_element(A.begin(), A.end());
            int left = it == A.begin() ? INT_MAX : *(it - 1);
            int right = it == A.end() - 1 ? INT_MAX : *(it + 1);
            ans += *it * min(left, right);
            A.erase(it);
        }
        return ans;
    }
};