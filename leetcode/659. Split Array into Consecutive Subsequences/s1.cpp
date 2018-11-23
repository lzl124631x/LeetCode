// OJ: https://leetcode.com/problems/split-array-into-consecutive-subsequences/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> m;
        for (int n : nums) m[n]++;
        while (m.size()) {
            auto i = m.begin();
            int cnt = 0, len = 0, prev = i->first - 1;
            while (i != m.end() && i->first == prev + 1 && i->second >= cnt) {
                cnt = i->second;
                prev = i->first;
                if (!--i->second) i = m.erase(i);
                else ++i;
                ++len;
            }
            if (len < 3) return false;
        }
        return true;
    }
};