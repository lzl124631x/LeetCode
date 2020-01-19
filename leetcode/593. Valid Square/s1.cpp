// OJ: https://leetcode.com/problems/valid-square/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
private:
    long long dist(vector<int>& a, vector<int>& b) {
        return pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<long long, int> m;
        vector<vector<int>> v = {p1, p2, p3, p4};
        for (int i = 0; i < 3; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                auto d = dist(v[i], v[j]);
                if (!d) return false;
                m[d]++;
            }
        }
        auto a = *m.begin(), b = *m.rbegin();
        return m.size() == 2 && a.second == 4 && 2 * a.first == b.first;
    }
};