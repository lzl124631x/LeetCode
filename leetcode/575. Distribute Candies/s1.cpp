// OJ: https://leetcode.com/problems/distribute-candies/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> m(candies.begin(), candies.end());
        return min(m.size(), candies.size() / 2);
    }
};