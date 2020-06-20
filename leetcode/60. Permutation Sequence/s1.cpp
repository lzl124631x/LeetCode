// OJ: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3366/
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(N)
class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        for (int i = 0; i < n; ++i) s += ('1' + i);
        while (--k) next_permutation(s.begin(), s.end());
        return s;
    }
};