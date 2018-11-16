// OJ: https://leetcode.com/problems/jewels-and-stones/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> s(J.begin(), J.end());
        int cnt = 0;
        for (char c : S) {
            if (s.find(c) != s.end()) ++cnt;
        }
        return cnt;
    }
};