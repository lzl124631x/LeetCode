// OJ: https://leetcode.com/problems/path-sum-iv/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int pathSum(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n : nums) {
            m[n / 10] = n % 10;
        }
        int sum = 0;
        for (int n : nums) {
            int d = n / 100, p = n / 10 % 10, v = m[d * 10 + p];
            int left = (d + 1) * 10 + p * 2 - 1, right = left + 1;
            if (m.find(left) != m.end()) m[left] += v;
            if (m.find(right) != m.end()) m[right] += v;
            if (m.find(left) == m.end() && m.find(right) == m.end()) sum += v;
        }
        return sum;
    }
};