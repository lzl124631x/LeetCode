// OJ: https://leetcode.com/problems/reverse-only-letters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i = 0, j = S.size() - 1;
        while (i < j) {
            while (i < j && !isalpha(S[i])) ++i;
            while (i < j && !isalpha(S[j])) --j;
            if (i < j) swap(S[i++], S[j--]);
        }
        return S;
    }
};