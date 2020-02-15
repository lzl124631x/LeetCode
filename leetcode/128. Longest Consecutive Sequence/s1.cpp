// OJ: https://leetcode.com/problems/longest-consecutive-sequence/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<pair<int, int>> s;
        for (int n : nums) {
            auto it = s.upper_bound(make_pair(n, n));
            if (it != s.end() && it->first == n) continue; 
            int start = n, end = n;
            if (it != s.begin()) {
                auto j = prev(it);
                if (j->second >= n) continue;
                if (j->second + 1 == n) {
                    start = j->first;
                    s.erase(j);
                }
            }
            if (it != s.end() && it->first == n + 1) {
                end = it->second;
                s.erase(it);
            }
            s.emplace(start, end);
        }
        int ans = 0;
        for (auto &p : s) ans = max(ans, p.second - p.first + 1);
        return ans;
    }
};