// OJ: https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/
// Author: github.com/lzl124631x
// Time: O(N(S+logN))
// Space: O(logN)
class Solution {
private:
    string toBinary(int N) {
        string ans;
        while (N) {
            ans += '0' + (N % 2);
            N /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
public:
    bool queryString(string S, int N) {
        for (int i = N; i >= 1 && i > N / 2; --i) {
            if (S.find(toBinary(i)) == string::npos) return false;
        }
        return true;
    }
};