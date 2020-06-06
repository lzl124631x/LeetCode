// OJ: https://leetcode.com/problems/longest-consecutive-sequence/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/longest-consecutive-sequence/discuss/41088/Possibly-shortest-cpp-solution-only-6-lines.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = 0;
        for (int n : nums) {
            if (m[n]) continue;
            ans = max(ans, m[n] = m[n - m[n - 1]] = m[n + m[n + 1]] = m[n - 1] + m[n + 1] + 1);
        }
        return ans;
    }
};