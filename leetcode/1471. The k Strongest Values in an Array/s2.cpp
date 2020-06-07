// OJ: https://leetcode.com/problems/the-k-strongest-values-in-an-array/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
// Ref: https://leetcode.com/problems/the-k-strongest-values-in-an-array/discuss/674384/C%2B%2BJavaPython-Two-Pointers-%2B-3-Bonuses
class Solution {
public:
    vector<int> getStrongest(vector<int>& A, int k) {
        sort(A.begin(), A.end());
        int m = A[(A.size() - 1) / 2], i = 0, j = A.size() - 1;
        vector<int> ans;
        while (ans.size() < k) {
            if (A[j] - m >= m - A[i]) ans.push_back(A[j--]);
            else ans.push_back(A[i++]);
        }
        return ans;
    }
};