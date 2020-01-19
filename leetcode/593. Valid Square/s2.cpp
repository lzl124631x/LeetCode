// OJ: https://leetcode.com/problems/valid-square/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
// Ref: https://leetcode.com/problems/valid-square/discuss/103442/C%2B%2B-3-lines-(unordered_set)
class Solution {
private:
    long long d(vector<int>& a, vector<int>& b) {
        return pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<long long> s({ d(p1, p2), d(p1, p3), d(p1, p4), d(p2, p3), d(p2, p4), d(p3, p4) });
        return !s.count(0) && s.size() == 2;
    }
};