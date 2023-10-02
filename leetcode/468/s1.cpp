// OJ: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3362/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    bool isValidIPv6(string &IP) {
        int i = 0, N = IP.size(), segment = 0;
        while (i < N) {
            int cnt = 0;
            while (i < N && (isdigit(IP[i]) || (IP[i] >= 'a' && IP[i] <= 'f') || (IP[i] >= 'A' && IP[i] <= 'F'))) {
                ++i;
                if (++cnt > 4) return false;
            }
            if (cnt == 0) return false;
            ++segment;
            if (segment < 8) {
                if (i >= N || IP[i] != ':') return false;
                ++i;
            } else if (segment > 8) return false;
        }
        return segment == 8;
    }
    bool isValidIPv4(string &IP) {
        int i = 0, N = IP.size(), segment = 0;
        while (i < N) {
            int num = 0, digit = 0;
            bool leadingZero = i < N && IP[i] == '0';
            while (i < N && isdigit(IP[i])) {
                num = num * 10 + (IP[i++] - '0');
                ++digit;
                if (digit > 3 || num > 255) return false;
            }
            if (digit == 0) return false;
            ++segment;
            if (leadingZero && (num != 0 || digit != 1)) return false;
            if (segment < 4) {
                if (i >= N || IP[i] != '.') return false;
                ++i;
            } else if (segment > 4) return false;
        }
        return segment == 4;
    }
public:
    string validIPAddress(string IP) {
        if (isValidIPv4(IP)) return "IPv4";
        if (isValidIPv6(IP)) return "IPv6";
        return "Neither";
    }
};