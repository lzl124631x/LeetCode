// OJ: https://leetcode.com/problems/split-array-into-consecutive-subsequences/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        queue<int> starts;
        int prevCnt = 0, prev, N = nums.size();
        for (int i = 0; i < N; ++i) {
            if (i > 0 && nums[i] != nums[i - 1] + 1) {
                while (prevCnt--) {
                    if (prev - starts.front() < 2) return false;
                    starts.pop();
                }
            }
            int cnt = 1;
            for (; i + 1 < N && nums[i + 1] == nums[i]; ++cnt, ++i);
            if (cnt > prevCnt) {
                for (int j = prevCnt; j < cnt; ++j) starts.push(nums[i]);
            } else if (cnt < prevCnt){
                int c = prevCnt - cnt;
                while (c--) {
                    if (prev - starts.front() < 2) return false;
                    starts.pop();
                }
            }
            prevCnt = cnt;
            prev = nums[i];
        }
        while (prevCnt--) {
            if (prev - starts.front() < 2) return false;
            starts.pop();
        }
        return true;
    }
};