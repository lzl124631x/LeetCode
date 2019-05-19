// OJ: https://leetcode.com/problems/best-sightseeing-pair/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int maxVal = A[0], ans = INT_MIN;
        for (int i = 1; i < A.size(); ++i) {
            ans = max(ans, maxVal + A[i] - i);
            maxVal = max(maxVal, A[i] + i);
        }
        return ans;
    }
};