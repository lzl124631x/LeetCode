// OJ: https://leetcode.com/problems/construct-k-palindrome-strings/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool canConstruct(string s, int k) {
        int N = s.size();
        if (k > N) return false;
        if (k == N) return true;
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;
        int sum = 0;
        for (int i = 0; i < 26; ++i) if (cnt[i] % 2) ++sum;
        return sum <= k;
    }
};