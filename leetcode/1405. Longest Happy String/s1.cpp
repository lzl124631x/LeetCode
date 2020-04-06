// OJ: https://leetcode.com/problems/longest-happy-string/
// Author: github.com/lzl124631x
// Time: O(A+B+C)
// Space: O(1)
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int cnt[3] = {a,b,c};
        string ans;
        while (true) {
            int maxIndex = -1;
            for (int i = 0; i < 3; ++i) {
                if (ans.size() && ans.back() - 'a' == i) continue;
                if (maxIndex == -1 || cnt[i] > cnt[maxIndex]) maxIndex = i;
            }
            if (cnt[maxIndex] == 0 || (ans.size() && maxIndex == ans.back() - 'a')) break;
            int c = min(cnt[maxIndex], 2);
            if (ans.size() && cnt[ans.back() - 'a'] > cnt[maxIndex]) c = min(cnt[maxIndex], 1);
            cnt[maxIndex] -= c;
            while (c--) ans.push_back('a' + maxIndex);
        }
        return ans;
    }
};