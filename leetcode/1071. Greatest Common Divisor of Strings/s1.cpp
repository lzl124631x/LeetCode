// OJ: https://leetcode.com/problems/greatest-common-divisor-of-strings/
// Author: github.com/lzl124631x
// Time: O(S^2)
// Space: O(S)
class Solution {
private:
    bool divisible(string a, string b) {
        int i = 0, j = 0, M = a.size(), N = b.size();
        for (; i < M; ++i) {
            if (a[i] != b[j]) return false;
            if (++j == N) j = 0;
        }
        return true;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        string d = str1.size() < str2.size() ? str1 : str2;
        for (; d.size(); d.pop_back()) {
            if (str1.size() % d.size() || str2.size() % d.size()) continue;
            if (divisible(str1, d) && divisible(str2, d)) return d;
        }
        return d;
    }
};