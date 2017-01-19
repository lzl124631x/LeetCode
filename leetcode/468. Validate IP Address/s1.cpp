class Solution {
private:
    bool validIPv4(string &IP) {
        int begin = 0, end = 0, cnt = 0;
        while (end < IP.size()) {
            int leadingZeroCount = 0, num = 0;
            while (end < IP.size() && isdigit(IP[end])) {
                num = num * 10 + IP[end] - '0';
                if (IP[end] == '0' && num == 0) leadingZeroCount++;
                if ((leadingZeroCount > 0 && num != 0)
                || (leadingZeroCount > 1)
                || (end - begin + 1 > 3)
                || num > 255) return false;
                ++end;
            }
            if (end == begin) return false;
            ++cnt;
            if (cnt <= 3) {
                if (end >= IP.size() || IP[end] != '.') return false;
                begin = ++end;
            } else {
                if (end != IP.size()) return false;
            }
        }
        return cnt == 4;
    }
    
    bool validIPv6(string &IP) {
        int cnt = 0, begin = 0, end = 0;
        while (end < IP.size()) {
            while (end < IP.size() && isalnum(IP[end])) {
                if ((IP[end] > 'f' && IP[end] <= 'z')
                || (IP[end] > 'F' && IP[end] <= 'Z')
                || end - begin + 1 > 4) return false;
                ++end;
            }
            if (begin == end) return false;
            ++cnt;
            if (cnt <= 7) {
                if (end >= IP.size() || IP[end] != ':') return false;
                begin = ++end;
            } else {
                if (end != IP.size()) return false;
            }
        }
        return cnt == 8;
    }
public:
    string validIPAddress(string IP) {
        if (validIPv4(IP)) return "IPv4";
        if (validIPv6(IP)) return "IPv6";
        return "Neither";
    }
};