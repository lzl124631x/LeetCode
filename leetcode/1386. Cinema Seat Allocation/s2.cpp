// OJ: https://leetcode.com/problems/cinema-seat-allocation/
// Author: github.com/lzl124631x
// Time: O(S)
// Space: O(S)
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& A) {
        int ans = 2 * n;
        unordered_map<int, char> m;
        for (auto &s : A) {
            if (s[1] == 1 || s[1] == 10) continue;
            m[s[0]] |= 1 << (s[1] - 2);
        }
        for (auto &p : m) {
            bool a = !(p.second & 0b11110000);
            bool b = !(p.second & 0b00111100);
            bool c = !(p.second & 0b00001111);
            if (a && c) continue;
            if (a || b || c) --ans;
            else ans -= 2;
        }
        return ans;
    }
};