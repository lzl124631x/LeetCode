// OJ: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    int cnt[3] = {0};
    bool valid() {
        for (int n : cnt) 
            if (!n) return false;
        return true;
    }
public:
    int numberOfSubstrings(string s) {
        int L = 0, R = 0, N = s.size(), ans = 0;
        while (R < N) { 
            if (!valid()) cnt[s[R++] - 'a']++;
            while (valid()) {
                ans += N - R + 1;
                cnt[s[L++] - 'a']--;
            }
        }
        return ans;
    }
};