// OJ: https://leetcode.com/problems/flip-string-to-monotone-increasing/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/flip-string-to-monotone-increasing/discuss/189751/C%2B%2B-one-pass-DP-solution-0ms-O(n)-or-O(1)-one-line-with-explaination.
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int ones = 0, ans = 0;
        for (char c : S) {
            if (c == '1') ones++;
            else ans = min(ans + 1, ones);
        }
        return ans;
    }
};