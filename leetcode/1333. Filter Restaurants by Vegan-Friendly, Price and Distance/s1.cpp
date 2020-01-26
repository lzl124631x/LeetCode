// OJ: https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int, int>> v;
        for (auto r : restaurants) {
            if ((veganFriendly && !r[2]) || r[3] > maxPrice || r[4] > maxDistance) continue;
            v.emplace_back(r[1], r[0]);
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        vector<int> ans;
        for (auto r : v) ans.push_back(r.second);
        return ans;
    }
};