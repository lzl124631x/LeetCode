// Brute force O(n^2)
class Solution {
public:
    int characterReplacement(string s, int K) {
        int ans = 0;
        for (int i = 0; i < s.size();) {
            int j = i, k = K;
            for (; j < s.size(); ++j) {
                if (s[j] != s[i]) --k;
                if (k < 0) break;
            }
            ans = max(ans, j - i + (k > 0 ? min(i, k) : 0));
            do { ++i; } while (i < s.size() && s[i] == s[i - 1]);
        }
        return ans;
    }
};