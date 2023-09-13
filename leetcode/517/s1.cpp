// OJ: https://leetcode.com/problems/super-washing-machines/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/super-washing-machines/solution/
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int N = machines.size(), sum = accumulate(machines.begin(), machines.end(), 0);
        if (sum % N) return -1;
        int avg = sum / N, curSum = 0, maxSum = 0, ans = 0;
        for (int &n : machines) n -= avg;
        for (int n : machines) {
            curSum += n;
            maxSum = max(maxSum, abs(curSum));
            ans = max(ans, max(maxSum, n));
        }
        return ans;
    }
};