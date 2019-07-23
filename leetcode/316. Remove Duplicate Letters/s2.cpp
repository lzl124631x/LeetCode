// OJ: https://leetcode.com/problems/remove-duplicate-letters/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.empty()) return s;
        vector<int> rightCnt(s.size(), 0);
        unordered_map<char, int> cnt;
        unordered_set<char> added;
        string ans;
        int N = s.size(), i = 0;
        for (int j = N - 1; j >= 0; --j) rightCnt[j] = cnt[s[j]]++;
        while (i < N) {
            int best = -1;
            for (; i < N; ++i) {
                if (added.find(s[i]) != added.end()) continue;
                if (best == -1 || s[i] < s[best]) best = i;
                if (!rightCnt[i]) break;
            }
            if (best == -1) best = i;
            if (best >= N) break;
            ans += s[best];
            added.insert(s[best]);
            i = best + 1;
        }
        return ans;
    }
};