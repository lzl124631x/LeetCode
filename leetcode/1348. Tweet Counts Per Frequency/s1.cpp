// OJ: https://leetcode.com/problems/tweet-counts-per-frequency/
// Author: github.com/lzl124631x
// Time:
//      recordTweet: O(logN)
//      getTweetCountsPerFrequency: O(N)
// Space: O(N)
class TweetCounts {
    unordered_map<string, multiset<int>> m;
public:
    TweetCounts() {}
    
    void recordTweet(string tweetName, int time) {
        m[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int d = freq[0] == 'm' ? 60 : (freq[0] == 'h' ? 3600 : (3600 * 24));
        vector<int> ans((endTime - startTime) / d + 1);
        if (!m.count(tweetName)) return ans;
        auto &ps = m[tweetName];
        for (auto t = ps.lower_bound(startTime); t != ps.end() && *t <= endTime; ++t) {
           ++ans[(*t - startTime) / d];
        }
        return ans;
    }
};