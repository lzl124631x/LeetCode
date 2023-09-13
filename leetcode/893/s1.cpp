// OJ: https://leetcode.com/problems/groups-of-special-equivalent-strings/
// Author: github.com/lzl124631x
// Time: O(NWlogW) where N is length of `A`, W is max word length
// Space: O(A) where A is the length of all the contents in array `A`
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> s;
        for (string str : A) {
            string a, b;
            for (int i = 0; i < str.size(); ++i) {
                if (i % 2) a += str[i];
                else b += str[i];
            }
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            s.insert(a + b);
        }
        return s.size();
    }
};