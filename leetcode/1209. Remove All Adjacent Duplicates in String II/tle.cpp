// OJ: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(1)
class Solution {
public:
    string removeDuplicates(string s, int k) {
        string ans;
        for (char c : s) {
            ans += c;
            int i = 2;
            for (; i <= k && (int)ans.size() - i >= 0; ++i) {
                if (ans[(int)ans.size() - i] != ans.back()) break;
            }
            if (i == k + 1) {
                for (int i = 0; i < k; ++i) ans.pop_back();
            }
        }
        return ans;
    }
};