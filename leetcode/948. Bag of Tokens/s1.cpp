// OJ: https://leetcode.com/problems/bag-of-tokens/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size() - 1, S = 0;
        while (i <= j) {
            while (i <= j && tokens[i] <= P) {
                P -= tokens[i++];
                S++;
            }
            if (i < j && S) {
                S--;
                P += tokens[j--];
            } else break;
        }
        return S;
    }
};