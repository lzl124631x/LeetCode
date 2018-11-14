// OJ: https://leetcode.com/problems/knight-dialer/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
    vector<vector<int>> nexts {
        { 4, 6 }, { 6, 8 }, { 7, 9 }, { 4, 8 }, { 3, 9, 0 },
        {}, { 1, 7, 0 }, { 2, 6 }, { 1, 3 }, { 2, 4 }
    };
public:
    int knightDialer(int N) {
        long long memo[2][10] = {}, mod = 1e9 + 7;
        for (int i = 0; i < 10; ++i) memo[0][i] = 1;
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < 10; ++j) {
                memo[i % 2][j] = 0;
                for (int next : nexts[j]) memo[i % 2][j] = (memo[i % 2][j] + memo[(i - 1) % 2][next]) % mod;
            }
        }
        long long sum = 0;
        for (int i = 0; i < 10; ++i) sum = (sum + memo[(N - 1) % 2][i]) % mod;
        return sum;
    }
};