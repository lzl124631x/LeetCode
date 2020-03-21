// OJ: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int findTheDistanceValue(vector<int>& A, vector<int>& B, int d) {
        sort(begin(B), end(B));
        int ans = 0;
        for (int n : A) {
            if (upper_bound(begin(B), end(B), n + d) == lower_bound(begin(B), end(B), n - d)) ++ans;
        }
        return ans;
    }
};