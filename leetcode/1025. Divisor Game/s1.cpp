// OJ: https://leetcode.com/problems/divisor-game/
// Author: github.com/lzl124631x
// Time: O(N * sqrt(N))
// Space: O(N)
class Solution {
private:
    unordered_map<int, bool> m;
public:
    bool divisorGame(int N) {
        if (N == 1) return false;
        if (m.find(N) != m.end()) return m[N];
        bool ans = false;
        for (int x = sqrt(N); x >= 1 && !ans; --x) {
            if (N % x) continue;
            if (!divisorGame(N - x)) ans = true;
        }
        return m[N] = ans;
    }
};