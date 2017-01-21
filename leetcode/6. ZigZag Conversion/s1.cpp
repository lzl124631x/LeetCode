class Solution {
public:
    string convert(string s, int numRows) {
        if (s.empty()) return "";
        if (numRows == 1) return s;
        string ans;
        int N = (numRows - 1) * 2;
        for (int i = 0; i < numRows; ++i) {
            int d = N - 2 * i;
            if (d == 0) d = N;
            for (int j = i; j < s.size(); ) {
                ans += s[j];
                j += d;
                if (d != N) d = N - d;
            }
        }
        return ans;
    }
};