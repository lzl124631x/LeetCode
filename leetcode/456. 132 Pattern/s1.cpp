// OJ: https://leetcode.com/problems/132-pattern/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    bool find132pattern(vector<int>& A) {
        multiset<int, greater<int>> s(begin(A), end(A));
        int mn = INT_MAX;
        for (int n : A) {
            mn = min(mn, n);
            s.erase(s.find(n));
            auto it = s.upper_bound(n);
            if (it != s.end() && mn < *it) return true;
        }
        return false;
    }
};