// OJ: https://leetcode.com/problems/number-of-recent-calls/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class RecentCounter {
private:
    queue<int> times;
public:
    RecentCounter() {}
    
    int ping(int t) {
        times.push(t);
        t -= 3000;
        while (times.front() < t) times.pop();
        return times.size();
    }
};