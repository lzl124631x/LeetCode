// OJ: https://leetcode.com/problems/gas-station
// Auther: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Note: The circuit can be completed when the sum of (gas[i] - cost[i])
// is non-negative, which is denoted using `total`.
// Use `tank` to denote the current available gas in tank, `prev` to denote
// the last dead point.
// When tank is negative, this point is a dead point, which means moving from
// prev + 1 to current point is impossible. Thus reset prev to i, and tank to 0.
// Finally, if total is non-negative, prev + 1 should be the start point.
class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int tank = 0, total = 0, prev = -1;
    for (int i = 0; i < gas.size(); ++i) {
      total += gas[i] - cost[i];
      if ((tank += gas[i] - cost[i]) < 0) {
        tank = 0;
        prev = i;
      }
    }
    return total < 0 ? -1 : prev + 1;
  }
};