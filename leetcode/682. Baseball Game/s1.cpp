// OJ: https://leetcode.com/problems/baseball-game/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> v;
        for (auto op : ops) {
            if (isdigit(op[0]) || op[0] == '-') v.push_back(stoi(op));
            else {
                switch(op[0]) {
                    case 'C': v.pop_back(); break;
                    case 'D': v.push_back(v.back() * 2); break;
                    case '+': v.push_back(v.back() + v[v.size() - 2]); break;
                }
            }
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};