class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty() || duration <= 0) return 0;
        int ans = 0, N = timeSeries.size();
        for (int i = 0; i < N;) {
            int start = timeSeries[i], end = timeSeries[i] + duration, j = i + 1;
            while (j < N && timeSeries[j] < end) ++j;
            if (j != i + 1) {
                ans += timeSeries[j - 1] - start;
                i = j - 1;
            } else {
                ans += end - start;
                ++i;
            }
        }
        return ans;
    }
};