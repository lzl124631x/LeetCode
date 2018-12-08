// OJ: https://leetcode.com/problems/boats-to-save-people/
// Author: github.com/lzl124631x
// Time: O(NlogD) where N is to total number of people
//                and D is the distinct count of weights.
// Space: O(D)
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        map<int, int, greater<int>> m;
        for (int w : people) m[w]++;
        int ans = 0;
        while (m.size()) {
            int w = limit, cnt = 0;
            while (w > 0 && cnt < 2) {
                auto it = m.lower_bound(w);
                if (it == m.end()) break;
                w -= it->first;
                it->second--;
                if (!it->second) m.erase(it->first);
                ++cnt;
            }
            ++ans;
        }
        return ans;
    }
};