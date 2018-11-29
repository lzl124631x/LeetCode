// OJ: https://leetcode.com/problems/distinct-subsequences-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/distinct-subsequences-ii/discuss/192095/C%2B%2B-O(n)-or-O-(n)-Geeks4Geeks-improved-to-O(n)-or-O(1)
class Solution {
public:
    int distinctSubseqII(string S) {
        int mod = pow(10, 9) + 7, picks[26] = {0}, sum = 1;
        for (char c : S) {
            int oldSum = sum;
            sum = (sum * 2 % mod - picks[c - 'a'] + mod) % mod;
            picks[c - 'a'] = oldSum;
        }
        return sum - 1;
    }
};