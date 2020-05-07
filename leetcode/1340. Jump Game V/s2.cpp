// OJ: https://leetcode.com/problems/jump-game-v/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxJumps(vector<int>& A, int d) {
        int N = A.size();
        vector<int> dp(N + 1, 1), left, right;
        A.push_back(INT_MAX);
        for (int i = 0; i <= N; ++i) {
            while (left.size() && A[left.back()] < A[i]) {
                int pre = A[left.back()];
                while (left.size() && A[left.back()] == pre) {
                    int j = left.back();
                    left.pop_back();
                    if (i - j <= d) dp[i] = max(dp[i], dp[j] + 1);
                    right.push_back(j);
                }
                while (right.size()) {
                    int j = right.back();
                    right.pop_back();
                    if (left.size() && j - left.back() <= d) dp[left.back()] = max(dp[left.back()], dp[j] + 1);
                }
            }
            left.push_back(i);
        }
        return *max_element(dp.begin(), dp.end() - 1);
    }
};