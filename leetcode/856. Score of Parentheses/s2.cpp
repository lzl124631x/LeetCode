// OJ: https://leetcode.com/problems/score-of-parentheses/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
private:
    int score(string &S, int begin, int end) {
        if (begin + 2 == end) return 1;
        int i = begin, left = 0;
        do {
            left += S[i++] == '(' ? 1 : -1;
        } while (left);
        if (i == end) return 2 * score(S, begin + 1, end - 1);
        return score(S, begin, i) + score(S, i, end);
    }
public:
    int scoreOfParentheses(string S) {
        return score(S, 0, S.size());
    }
};