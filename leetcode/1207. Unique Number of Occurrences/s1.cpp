// OJ: https://leetcode.com/problems/unique-number-of-occurrences/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool uniqueOccurrences(vector<int>& A) {
        unordered_map<int, int> m;
        for (int n : A) m[n]++;
        unordered_set<int> s;
        for (auto &p : m) {
            if (s.count(p.second)) return false;
            s.insert(p.second);
        }
        return true;
    }
};