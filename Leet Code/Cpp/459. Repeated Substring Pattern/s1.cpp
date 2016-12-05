class Solution {
private:
    bool cmp (string &str, int start, int len) {
        for (int i = 0; i < len; ++i) {
            if (str[i] != str[start + i]) return false;
        }
        return true;
    }
public:
    bool repeatedSubstringPattern(string str) {
        int n = str.size();
        for (int len = n / 2; len >= 1; --len) {
            if (n % len) continue;
            bool allEqual = true;
            for (int i = len; i <= n - len; i += len) {
                if (!cmp(str, i, len)) {
                    allEqual = false;
                    break;
                }
            }
            if (allEqual) return true;
        }
        return false;
    }
};