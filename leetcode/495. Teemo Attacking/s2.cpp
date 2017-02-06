class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0, end = 0;
        for (int i = 0; i < timeSeries.size(); ++i) {
            ans += duration - (end > timeSeries[i] ? end - timeSeries[i] : 0);
            end = timeSeries[i] + duration;
        }
        return ans;
    }
};