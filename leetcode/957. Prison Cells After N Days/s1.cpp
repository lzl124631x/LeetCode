// OJ: https://leetcode.com/problems/prison-cells-after-n-days/
// Author: github.com/lzl124631x
// Time: O(2^N) where N is the length of cells.
// Space: O(2^N)
class Solution {
private:
    char getNext(char c) {
        char next = 0;
        for (int j = 1; j < 7; ++j) {
            next |= ((c >> (j - 1) & 1) == (c >> (j + 1) & 1) ? 1 : 0) << j;
        }
        return next;
    }
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        char c = 0;
        for (int i = 0; i < 8; ++i) {
            c |= cells[i] << i;
        }
        unordered_map<char, int> m;
        int dist = -1, from = -1;
        for (int i = 1; i <= N; ++i) {
            c = getNext(c);
            if (m.find(c) != m.end()) {
                dist = i - m[c];
                from = i;
                break;
            }
            m[c] = i;
        }
        if (dist != -1) {
            int d = (N - from) % dist;
            for (int i = 0; i < d; ++i) c = getNext(c);
        }
        vector<int> ans;
        for (int i = 0; i < 8; ++i) ans.push_back((c >> i) & 1);
        return ans;
    }
};