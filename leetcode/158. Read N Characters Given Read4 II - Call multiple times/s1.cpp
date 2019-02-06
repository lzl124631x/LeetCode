// OJ: https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/
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
    char leftover[4] = { '\0' };
    int read(char *buf, int n) {
        strcpy(buf, leftover);
        int cnt = strlen(leftover);
        while (cnt < n) {
            int x = read4(buf + cnt);
            if (!x) break;
            cnt += x;
        }
        if (cnt > n) {
            memcpy(leftover, buf + n, cnt - n);
            leftover[cnt - n] = '\0';
        } else leftover[0] = '\0';
        cnt = min(cnt, n);
        return cnt;
    }
};