// https://discuss.leetcode.com/topic/65158/c-0ms-o-n-35-lines-solution-with-detailed-explanation
class Solution {
public:
    int strongPasswordChecker(string s) {
        int N = s.size(), delMax = max(N - 20, 0), addMax = max(6 - N, 0);
        int lower = 1, upper = 1, digit = 1, add = 0, del = 0, rep = 0;
        for (int L = 0, R = 0; R < N; ++R) {
            if (islower(s[R])) lower = 0;
            if (isupper(s[R])) upper = 0;
            if (isdigit(s[R])) digit = 0;
            if (R - L == 2) {
                if (s[L] == s[L + 1] && s[L] == s[R]) {
                    if (add < addMax) { add++; L = R; }
                    else { rep++; L = R + 1; }
                } else ++L;
            }
        }
        if (N <= 20) return max(addMax + rep, upper + lower + digit);
        rep = 0;
        vector<unordered_map<int, int>> lenCnts(3);
        for (int L = 0, R = 0, len; R <= N; ++R) {
            if (R == N || s[L] != s[R]) {
                if((len = R - L) > 2) lenCnts[len % 3][len]++;
                L = R;
            }
        }
        for (int i = 1; i <= 3; ++i) {
            for (auto it = lenCnts[i - 1].begin(); it != lenCnts[i - 1].end(); ++it) {
                if (i <= 2) {
                    int d = min(it->second, (delMax - del) / i);
                    del += d * i;
                    it->second -= d;
                    if (it->first - i > 2) lenCnts[2][it->first - i] += d;
                }
                rep += it->second * (it->first / 3);
            }
        }
        return delMax + max(rep - (delMax - del) / 3, lower + upper + digit);
    }
};