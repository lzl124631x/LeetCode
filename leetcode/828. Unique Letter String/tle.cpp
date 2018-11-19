// OJ: https://leetcode.com/problems/unique-letter-string/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int uniqueLetterString(string S) {
        long long ans = 0;
        int N = S.size(), mod = pow(10, 9) + 7;
        for (int i = 0; i < N; ++i) {
            unordered_map<char, int> m;
            int cnt = 0;
            for (int j = i; j < N; ++j) {
                if (m[S[j]] == 0) cnt++;
                else if (m[S[j]] == 1) cnt--;
                m[S[j]]++;
                ans = (ans + cnt) % mod;
            }
        }
        return ans;
    }
};