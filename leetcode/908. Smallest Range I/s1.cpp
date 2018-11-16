// OJ: https://leetcode.com/problems/smallest-range-i/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int minVal = INT_MAX, maxVal = INT_MIN;
        for (int n : A) {
            minVal = min(minVal, n);
            maxVal = max(maxVal, n);
        }
        return max(maxVal - minVal - 2 * K, 0);
    }
};