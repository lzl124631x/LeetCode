// OJ: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    int maxVowels(string s, int k) {
        int cnt = 0, ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i >= k) cnt -= isVowel(s[i - k]);
            cnt += isVowel(s[i]);
            ans = max(ans, cnt);
        }
        return ans;
    }
};