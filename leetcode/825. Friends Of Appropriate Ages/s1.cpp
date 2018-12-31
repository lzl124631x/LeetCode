// OJ: https://leetcode.com/problems/friends-of-appropriate-ages/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
    bool request(int A, int B) {
        return !(B <= .5 * A + 7 || B > A);
    }
public:
    int numFriendRequests(vector<int>& ages) {
        int ans = 0;
        vector<int> cnts(120, 0);
        for (int age : ages) cnts[age - 1]++;
        for (int i = 0; i < 120; ++i) {
            if (!cnts[i]) continue;
            for (int j = 0; j < 120; ++j) {
                if (!cnts[j] || !request(i + 1, j + 1)) continue;
                ans += cnts[i] * cnts[j];
                if (i == j) ans -= cnts[i];
            }
        }
        return ans;
    }
};