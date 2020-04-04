// OJ: https://leetcode.com/problems/count-largest-group/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> m;
        for (int i = 1; i <= n; ++i) {
            int sum = 0, x = i;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            m[sum]++;
        }
        int maxSize = 0;
        for (auto &p : m) {
            maxSize = max(maxSize, p.second);
        }
        int ans = 0;
        for (auto &p : m) {
            if (p.second == maxSize) ++ans;
        }
        return ans;
    }
};