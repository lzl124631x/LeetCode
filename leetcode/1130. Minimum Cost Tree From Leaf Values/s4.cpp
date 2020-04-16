// OJ: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/discuss/339959/One-Pass-O(N)-Time-and-Space
class Solution {
public:
    int mctFromLeafValues(vector<int>& A) {
        int ans = 0;
        vector<int> s{INT_MAX};
        for (int n : A) {
            while (s.back() <= n) {
                int mid = s.back();
                s.pop_back();
                ans += mid * min(s.back(), n);
            }
            s.push_back(n);
        }
        for (int i = 2; i < s.size(); ++i) ans += s[i] * s[i - 1];
        return ans;
    }
};