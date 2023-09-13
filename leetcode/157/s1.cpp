// OJ: https://leetcode.com/problems/read-n-characters-given-read4/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Forward declaration of the read4 API.
int read4(char *buf);
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int cnt = 0;
        while (cnt < n) {
            int x = read4(buf + cnt);
            if (!x) break;
            cnt += x;
        }
        cnt = min(cnt, n);
        buf[cnt] = '\0';
        return cnt;
    }
};