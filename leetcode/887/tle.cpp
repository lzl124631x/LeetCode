// OJ: https://leetcode.com/problems/super-egg-drop/
// Author: github.com/lzl124631x
// Time: O(KN)
// Space: O(KN)
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        return std::hash<T1>{}(p.first * 10000 + p.second);
    }
};
class Solution {
private:
    unordered_map<pair<int, int>, int, pair_hash> m;
public:
    int superEggDrop(int K, int N) {
        if (!K || !N) return 0;
        if (K == 1) return N;
        auto p = make_pair(K, N);
        if (m.find(p) != m.end()) return m[p];
        int val = INT_MAX;
        int prev = INT_MAX;
        for (int i = (N + 1) / 2; i >= 1; --i) {
            int v = max(superEggDrop(K - 1, i - 1), superEggDrop(K, N - i));
            if (v > prev) break;
            prev = val;
            val = min(val, v);
            
        }
        return m[p] = 1 + val;
    }
};