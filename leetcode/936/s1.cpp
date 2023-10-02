// OJ: https://leetcode.com/problems/stamping-the-sequence/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
private:
    int findStamp(string &stamp, string &target) {
        for (int i = 0; i <= target.size() - stamp.size(); ++i) {
            int j = 0, cnt = 0;
            for (; j < stamp.size(); ++j) {
                if (target[i + j] == '?') continue;
                if (target[i + j] != stamp[j]) break;
                ++cnt;
            }
            if (cnt && j == stamp.size()) return i;
        }
        return -1;
    }
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;
        int cnt = target.size();
        while (cnt) {
            int start = findStamp(stamp, target);
            if (start == -1) return {};
            ans.push_back(start);
            for (int i = 0; i < stamp.size(); ++i) {
                if (target[start + i] != '?') --cnt;
                target[start + i] = '?';
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};