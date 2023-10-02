// OJ: https://leetcode.com/problems/last-substring-in-lexicographical-order/
// Author: github.com/lzl124631x
// Time: O(VL) where V is the length of `v` and L is the max possible `len`.
//       It is strictly smaller than O(N^2)
// Space: O(N)
class Solution {
public:
    string lastSubstring(string s) {
        int start = 0, N = s.size();
        for (int i = 0; i < N; ++i) {
            if (s[i] > s[start]) start = i;
        }
        vector<int> v;
        for (int i = start; i < N; ++i) {
            if (s[i] == s[start] && (i == 0 || s[i - 1] != s[start])) v.push_back(i);
        }
        for (int len = 1; len <= N && v.size() > 1; ++len) {
            vector<int> next;
            char c = 'a';
            for (int n : v) {
                if (n + len >= N || s[n + len] < c) continue;
                if (s[n + len] > c) {
                    next.clear();
                    c = s[n + len];
                }
                next.push_back(n);
            }
            v = next;
        }
        return s.substr(v[0]);
    }
};