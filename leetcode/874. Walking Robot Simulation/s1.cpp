// OJ: https://leetcode.com/problems/walking-robot-simulation/
// Author: github.com/lzl124631x
// Time: O(C)
// Space: O(O)
class Solution {
private:
    long long hash(int x, int y) {
        return (long long)(x + 30000) * 100000 + y + 30000;
    }
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> obs;
        for (auto &ob : obstacles) obs.insert(hash(ob[0], ob[1]));
        int ans = 0, x = 0, y = 0, dir = 0; // 0=N, 1=W, 2=S, 3=E
        int dirs[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        for (int cmd : commands) {
            if (cmd == -2) {
                dir = (dir + 1) % 4;
            } else if (cmd == -1) {
                dir = (dir + 3) % 4;
            } else {
                auto &d = dirs[dir];
                while (cmd--) {
                    if (obs.find(hash(x + d[0], y + d[1])) != obs.end()) break;
                    x += d[0];
                    y += d[1];
                    ans = max(ans, x * x + y * y);
                }
            }
        }
        return ans;
    }
};