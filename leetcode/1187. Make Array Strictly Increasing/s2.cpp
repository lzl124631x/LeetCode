// OJ: https://leetcode.com/problems/make-array-strictly-increasing/
// Author: github.com/lzl124631x
// Time: O(MN * logN)
// Space: O(MN)
// Ref: https://leetcode.com/problems/make-array-strictly-increasing/discuss/377403/Python-DP-solution-with-explanation.
class Solution {
public:
    int makeArrayIncreasing(vector<int>& A, vector<int>& B) {
        int M = A.size(), N = B.size();
        sort(B.begin(), B.end());
        unordered_map<int, int> dp;
        dp[-1] = 0;
        for (int a : A) {
            unordered_map<int, int> tmp;
            for (auto &p : dp) {
                if (a > p.first) {
                    int cnt = tmp.count(a) ? tmp[a] : INT_MAX;
                    tmp[a] = min(cnt, p.second);
                }
                int b = upper_bound(B.begin(), B.end(), p.first) - B.begin();
                if (b < N) {
                    int cnt = tmp.count(B[b]) ? tmp[B[b]] : INT_MAX;
                    tmp[B[b]] = min(cnt, p.second + 1);
                }
            }
            dp = tmp;
        }
        if (dp.empty()) return -1;
        int ans = INT_MAX;
        for (auto &p : dp) ans = min(ans, p.second);
        return ans;
    }
};