// OJ: https://leetcode.com/problems/gas-station
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0, total = 0, ans = 0, N = gas.size();
        for (int i = 0; i < N; ++i) {
            total += gas[i] - cost[i];
            if ((tank += gas[i] - cost[i]) < 0) {
                tank = 0;
                ans = i + 1;
            }
        }
        return total < 0 ? -1 : ans;
    }
};