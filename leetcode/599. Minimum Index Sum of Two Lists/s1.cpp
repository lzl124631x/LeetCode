// OJ: https://leetcode.com/problems/minimum-index-sum-of-two-lists/
// Author: github.com/lzl124631x
// Time: O(L1 + L2)
// Space: O(L1)
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m;
        for (int i = 0; i < list1.size(); ++i) m[list1[i]] = i;
        int minSum = INT_MAX;
        vector<string> ans;
        for (int i = 0; i < list2.size() && i <= minSum; ++i) {
            if (m.find(list2[i]) == m.end() || i + m[list2[i]] > minSum) continue;
            if (i + m[list2[i]] < minSum) {
                ans.clear();
                minSum = i + m[list2[i]];
            }
            ans.push_back(list2[i]);
        }
        return ans;
    }
};