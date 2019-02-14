// OJ: https://leetcode.com/problems/meeting-rooms-ii/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts, ends;
        for (auto &i : intervals) {
            starts.push_back(i.start);
            ends.push_back(i.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int ans = 0, cnt = 0;
        for (int i = 0, j = 0, N = intervals.size(); i < N;) {
            if (starts[i] < ends[j]) {
                ++cnt;
                ++i;
                ans = max(ans, cnt);
            } else if (starts[i] > ends[j]) {
                --cnt;
                ++j;
            } else {
                ++i;
                ++j;
            }
        }
        return ans;
    }
};