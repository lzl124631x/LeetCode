// OJ: https://leetcode.com/problems/open-the-lock/
// Author: github.com/lzl124631x
// Time: O(A^N) where A is the number of digits in our alphabet, N is the number of digits in the lock.
// Space: O(A^N)
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<int> seen;
        for (auto &d : deadends) seen.insert(stoi(d));
        int T = stoi(target), dist = 0;
        if (seen.find(0) != seen.end()) return -1;
        queue<int> q;
        q.push(0);
        seen.insert(0);
        while (q.size()) {
            int cnt = q.size();
            ++dist;
            while (cnt--) {
                int n = q.front();
                q.pop();
                for (int i = 1; i <= 1000; i *= 10) {
                    int d = n / i % 10;
                    int up = d == 9 ? n - 9 * i : n + i;
                    int down = d == 0 ? n + 9 * i : n - i;
                    if (up == T || down == T) return dist;
                    if (seen.find(up) == seen.end()) {
                        seen.insert(up);
                        q.push(up);
                    }
                    if (seen.find(down) == seen.end()) {
                        seen.insert(down);
                        q.push(down);
                    }
                }
            }
        }
        return -1;
    }
};