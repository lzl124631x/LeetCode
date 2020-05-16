// OJ: https://leetcode.com/problems/simplified-fractions/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                if (gcd(i, j) != 1) continue;
                ans.push_back(to_string(j) + "/" + to_string(i));
            }
        }
        return ans;
    }
};