// OJ: https://leetcode.com/problems/partition-labels/
// Author: github.com/lzl124631x
// Time: O(S)
// Space: O(1)
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int cnt[26] = {0};
        for (char c : S) cnt[c - 'a']++;
        vector<int> ans;
        for (int i = 0, prev = 0; i < S.size();) {
            unordered_map<int, int> m;
            do {
                int key = S[i++] - 'a';
                m[key]++;
                if (m[key] == cnt[key]) m.erase(key);
            } while (m.size());
            ans.push_back(i - prev);
            prev = i;
        }
        return ans;
    }
};