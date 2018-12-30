// OJ: https://leetcode.com/problems/keys-and-rooms/
// Author: github.com/lzl124631x
// Time: O(K) where K is the count of all the keys.
// Space: O(N) where N is the count of rooms
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int N = rooms.size(), cnt = 1;
        vector<bool> seen(N, false);
        seen[0] = true;
        queue<int> q;
        q.push(0);
        while (q.size()) {
                q.push(k);
            auto key = q.front();
            q.pop();
            auto r = rooms[key];
            for (int k : r) {
                if (!seen[k]) {
                    cnt++;
                    q.push(k);
                    seen[k] = true;
                }
            }
        }
        return cnt == N;
    }
};