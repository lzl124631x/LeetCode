// OJ: https://leetcode.com/problems/string-compression/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, N = chars.size(), j = 0, r = 0;
        while (i < N) {
            j = i + 1;
            while (j < N && chars[j] == chars[i]) ++j;
            chars[r++] = chars[i];
            if (j - i > 1) {
                int cnt = j - i, pow = 1;
                while (cnt / (pow * 10)) pow *= 10;
                while (pow) {
                    chars[r++] = '0' + cnt / pow;
                    cnt %= pow;
                    pow /= 10;
                }
            }
            i = j;
        }
        return r;
    }
};