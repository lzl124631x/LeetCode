// OJ: https://leetcode.com/problems/the-k-strongest-values-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/the-k-strongest-values-in-an-array/discuss/674384/C%2B%2BJavaPython-Two-Pointers-%2B-3-Bonuses
class Solution {
public:
    vector<int> getStrongest(vector<int>& A, int k) {
        nth_element(A.begin(), A.begin() + (A.size() - 1) / 2, A.end());
        int m = A[(A.size() - 1) / 2];
        nth_element(A.begin(), A.begin() + k, A.end(), [&](int a, int b) {
            return abs(a - m) == abs(b - m) ? a > b : abs(a - m) > abs(b - m); 
        });
        A.resize(k);
        return A;
    }
};