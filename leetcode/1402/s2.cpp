// OJ: https://leetcode.com/problems/reducing-dishes/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maxSatisfaction(vector<int>& A) {
        sort(begin(A), end(A), greater<int>());
        partial_sum(begin(A), end(A), begin(A));
        partial_sum(begin(A), end(A), begin(A));
        return max(0, *max_element(begin(A), end(A)));
    }
};