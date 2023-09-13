// OJ: https://leetcode.com/problems/distinct-subsequences-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/distinct-subsequences-ii/discuss/192017/C%2B%2BJavaPython-4-lines-O(N)-Time-O(1)-Space
class Solution {
public:
    int distinctSubseqII(string S) {
        long endsWith[26] = {}, mod = 1e9 + 7;
        for (char c : S)
            endsWith[c - 'a'] = accumulate(begin(endsWith), end(endsWith), 1L) % mod;
        return accumulate(begin(endsWith), end(endsWith), 0L) % mod;
    }
};