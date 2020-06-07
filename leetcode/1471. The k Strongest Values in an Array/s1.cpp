// OJ: https://leetcode.com/problems/the-k-strongest-values-in-an-array/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    vector<int> getStrongest(vector<int>& A, int k) {
        sort(A.begin(), A.end());
        int m = A[(A.size() - 1) / 2];
        sort(A.begin(), A.end(), [&](int &a, int &b) {
            return abs(a - m) == abs(b - m) ? a > b : (abs(a - m) > abs(b - m));
        });
        vector<int> ans(A.begin(), A.begin() + k);
        return ans;
    }
};