class Solution {
private:
    int getNum(int &i, string &s) {
        int ans = 0;
        while (i < s.size() && isdigit(s[i])) {
            ans = ans * 10 + s[i++] - '0';
        }
        return ans;
    }
public:
    int calculate(string s) {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        int i = 0, cur = getNum(i, s), prev = cur;
        while (i < s.size()) {
            char c = s[i++];
            int n = getNum(i, s);
            if (c == '+') {
                cur += n;
                prev = n;
            } else if (c == '-') {
                cur -= n;
                prev = -n;
            } else if (c == '*') {
                cur = cur - prev + prev * n;
                prev = prev * n;
            } else {
                cur = cur - prev + prev / n;
                prev = prev / n;
            }
        }
        return cur;
    }
};