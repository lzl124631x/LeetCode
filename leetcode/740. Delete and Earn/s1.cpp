// OJ: https://leetcode.com/problems/delete-and-earn/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> m;
        for (int n : nums) m[n]++;
        int prev = 0, prev2 = 0, num = INT_MIN;
        for (auto &p : m) {
            int cur = p.first == num + 1 ? max(prev, prev2 + p.first * p.second) : (prev + p.first * p.second);
            prev2 = prev;
            prev = cur;
            num = p.first;
        }
        return prev;
    }
};