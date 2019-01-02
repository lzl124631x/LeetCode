// OJ: https://leetcode.com/problems/super-palindromes/
// Author: github.com/lzl124631x
// Time: O(W^(1/4)*logW)
// Space: O(logW)
// Ref: https://leetcode.com/problems/super-palindromes/solution/
typedef unsigned long long ULL;
class Solution {
private:
    bool isPalindrome(ULL n) {
        ULL r = 0, num = n;
        while (n) {
            r = r * 10 + n % 10;
            n /= 10;
        }
        return r == num;
    }
public:
    int superpalindromesInRange(string L, string R) {
        ULL i = 1, ans = 0, nl = stoull(L), nr = stoull(R), MAGIC = 100000;
        for (int k = 1; k < MAGIC; ++k) {
            string s = to_string(k);
            for (int i = s.size() - 2; i >= 0; --i) s += s[i];
            ULL n = stoull(s);
            n *= n;
            if (n > nr) break;
            if (n >= nl && isPalindrome(n)) ++ans;
        }
        for (int k = 1; k < MAGIC; ++k) {
            string s = to_string(k);
            for (int i = s.size() - 1; i >= 0; --i) s += s[i];
            ULL n = stoull(s);
            n *= n;
            if (n > nr) break;
            if (n >= nl && isPalindrome(n)) ++ans;
        }
        return ans;
    }
};