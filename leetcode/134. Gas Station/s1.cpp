// OJ: https://leetcode.com/problems/gas-station
// Auther: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Note: Imagine an array D, where D[i] = gas[i] - cost[i].
// Array D forms a polygonal line. The circuit can be completed
// as long as the integral of D is non-negative, and the point
// after the lowest point should be the start point.
class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int tank = 0, ans = -1, minVal = INT_MAX;
    for (int i = 0; i < gas.size(); ++i) {
      tank += gas[i] - cost[i];
      if (tank < minVal) {
        ans = i;
        minVal = tank;
      }
    }
    return tank < 0 ? -1 : (ans + 1) % gas.size();
  }
};