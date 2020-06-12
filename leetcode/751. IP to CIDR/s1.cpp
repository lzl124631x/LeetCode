// OJ: https://leetcode.com/problems/ip-to-cidr/
// Author: github.com/lzl124631x
// Time: O()
// Space: O()
class Solution {
private:
    unsigned ipToUnsigned(string &ip) {
        unsigned ans = 0, val = 0;
        for (int i = 0; i < ip.size(); ++i) {
            if (ip[i] == '.') {
                ans = (ans + val) << 8;
                val = 0;
            } else val = val * 10 + ip[i] - '0';
        }
        return ans + val;
    }
    string unsignedToIp(unsigned val) {
        unsigned mask = ~0 ^ ((unsigned)~0 >> 8);
        string ans;
        for (int i = 0; i < 4; ++i) {
            ans += to_string((val & mask) >> ((3 - i) * 8));
            mask >>= 8;
            if (i < 3) ans += ".";
        }
        return ans;
    }
public:
    vector<string> ipToCIDR(string ip, int n) {
        unsigned s = ipToUnsigned(ip);
        return { unsignedToIp(s) };
    }
};