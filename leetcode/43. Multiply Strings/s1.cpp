class Solution {
public:
    string multiply(string num1, string num2) {
        int M = num1.size(), N = num2.size();
        string ans(M + N, '0');
        for (int i = 0; i < M; ++i) {
            int carry = 0, j = 0;
            while (j < N || carry) {
                if (j < N) carry += (num1[M - i - 1] - '0') * (num2[N - j - 1] - '0');
                carry += ans[i + j] - '0';
                ans[i + j] = carry % 10 + '0';
                carry /= 10;
                ++j;
            }
        }
        while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};