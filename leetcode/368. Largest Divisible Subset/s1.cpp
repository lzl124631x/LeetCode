// OJ: https://leetcode.com/problems/largest-divisible-subset/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& A) {
        if (A.empty()) return {};
        sort(A.begin(), A.end());
        int N = A.size(), maxLen = 1, best = 0;
        vector<int> cnt(N, 1);
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (A[i] % A[j] == 0) cnt[i] = max(cnt[i], cnt[j] + 1);
            }
            if (cnt[i] > maxLen) {
                maxLen = cnt[i];
                best = i;
            }
        }
        vector<int> ans{A[best]};
        while (cnt[best] != 1) {
            for (int i = best - 1; i >= 0; --i) {
                if (cnt[i] == cnt[best] - 1) {
                    best = i;
                    break;
                }
            }
            ans.push_back(A[best]);
        }
        return ans;
    }
};