// OJ: https://leetcode.com/problems/flip-string-to-monotone-increasing/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int rightZeros = 0, leftOnes = 0;
        for (char c : S) if (c == '0') rightZeros++;
        int ans = rightZeros;
        for (char c : S) {
            if (c == '1') leftOnes++;
            else rightZeros--;
            ans = min(ans, rightZeros + leftOnes);
        }
        return ans;
    }
};