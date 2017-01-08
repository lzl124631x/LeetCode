const int MAX_N = 100000;
class Solution {
public:
    int magicalString(int n) {
        vector<int> S(MAX_N, 0);
        int cnt = 0, val = 1;
        for (int i = 0, j = 0; j < n; ++i) {
            if (S[i] == 0) S[i] = val;
            if (val == 1) cnt += min(n - j, S[i]);
            if (S[i] == 2) {
                S[j++] = val;
            }
            S[j++] = val;
            val = 3 - val;
        }
        return cnt;
    }
};