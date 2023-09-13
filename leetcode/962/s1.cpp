// OJ: https://leetcode.com/problems/maximum-width-ramp/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int N = A.size(), ans = 0;
        vector<int> v, index;
        for (int i = N - 1; i >= 0; --i) {
            if (v.empty() || v.back() < A[i]) {
                v.push_back(A[i]);
                index.push_back(i);
            }
        }
        for (int i = 0; i < N; ++i) {
            int ind = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
            ans = max(ans, index[ind] - i);
        }
        return ans;
    }
};