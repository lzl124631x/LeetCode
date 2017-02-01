// https://discuss.leetcode.com/topic/5999/bucket-sort-java-solution-with-explanation-o-n-time-and-space
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int N = nums.size();
        int minVal = INT_MAX, maxVal = INT_MIN;
        for (int n : nums) {
            minVal = min(minVal, n);
            maxVal = max(maxVal, n);
        }
        int gap = ceil((double)(maxVal - minVal) / (N - 1));
        vector<int> mins(N - 1, INT_MAX), maxs(N - 1, INT_MIN);
        for (int n : nums) {
            if (n == minVal || n == maxVal) continue;
            int i = (n - minVal) / gap;
            mins[i] = min(mins[i], n);
            maxs[i] = max(maxs[i], n);
        }
        int ans = INT_MIN, prev = minVal;
        for (int i = 0; i < N - 1; ++i) {
            if (mins[i] == INT_MAX && maxs[i] == INT_MIN) continue;
            ans = max(ans, mins[i] - prev);
            prev = maxs[i];
        }
        return ans = max(ans, maxVal - prev);
    }
};