// OJ: https://leetcode.com/problems/random-pick-with-weight/
// Author: github.com/lzl124631x
// Time: O(log(W))
// Space: O(W)
class Solution {
private:
    vector<int> sums;
public:
    Solution(vector<int> w): sums(w) {
        partial_sum(sums.begin(), sums.end(), sums.begin());
    }
    
    int pickIndex() {
        return upper_bound(sums.begin(), sums.end(), rand() % sums.back()) - sums.begin();
    }
};