// OJ: https://leetcode.com/problems/bulb-switcher-iii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numTimesAllBlue(vector<int>& A) {
        int N = A.size(), maxId = 0, cnt = 0, ans = 0;
        for (int n : A) {
            maxId = max(maxId, n);
            if (++cnt == maxId) ++ans;
        }
        return ans;
    }
};