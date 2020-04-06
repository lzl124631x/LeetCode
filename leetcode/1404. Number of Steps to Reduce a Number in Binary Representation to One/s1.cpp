// OJ: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        while (s != "1") {
            if (s.back() == '1') {
                int i = s.size() - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    --i;
                }
                if (i == -1) s.insert(s.begin(), '1');
                else s[i] = '1';
            } else s.pop_back();
            ++ans;
        }
        return ans;
    }
};