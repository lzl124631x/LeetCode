// OJ: https://leetcode.com/problems/array-of-doubled-pairs/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        multiset<int> s(A.begin(), A.end());
        while (s.size()) {
            int val = *s.begin();
            if (val < 0 && val % 2) return false;
            int next = val >= 0 ? val * 2 : val / 2;
            s.erase(s.begin());
            auto it = s.find(next);
            if (it == s.end()) return false;
            s.erase(it);
        }
        return true;
    }
};