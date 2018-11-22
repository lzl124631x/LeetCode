// OJ: https://leetcode.com/problems/exclusive-time-of-functions/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> s;
        int lastTime;
        for (string log : logs) {
            int id = stoi(log);
            int i = log.find_last_of(":");
            int time = stoi(log.substr(i + 1));
            if (log[i - 1] == 't') {
                if (s.size()) ans[s.top()] += time - lastTime;
                s.push(id);
                lastTime = time;
            } else {
                ans[s.top()] += time - lastTime + 1;
                s.pop();
                lastTime = time + 1;
            }
        }
        return ans;
    }
};