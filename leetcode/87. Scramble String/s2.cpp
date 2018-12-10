// OJ: https://leetcode.com/problems/scramble-string
// Author: github.com/lzl124631x
// Time: O(N^4)
// Space: O(N^4)
class Solution {
private:
    unordered_map<int, bool> m;
    string A, B;
    int getHash (int sa, int ea, int sb, int eb) {
        return sa + ea * 100 + sb * 10000 + eb * 1000000;
    }
    bool isScramble(int sa, int ea, int sb, int eb) {
        int M = ea - sa, N = eb - sb;
        if (M != N) return false;
        int key = getHash(sa, ea, sb, eb);
        if (m.find(key) != m.end()) return m[key];
        bool ans = false;
        if (!A.compare(sa, ea - sa, B, sb, eb - sb)) ans = true;
        else {
           for (int len = 1; len < M; ++len) {
                if ((isScramble(sa, sa + len, sb, sb + len) && isScramble(sa + len, ea, sb + len, eb))
                   || (isScramble(sa, sa + len, eb - len, eb) && isScramble(sa + len, ea, sb, eb - len))) {
                    ans = true;
                    break;
                }
            } 
        }
        return m[key] = ans;
    }
public:
    bool isScramble(string s1, string s2) {
        A = s1;
        B = s2;
        return isScramble(0, s1.size(), 0, s2.size());
    }
};