// OJ: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
// Author: github.com/lzl124631x
// Time: O(3^N). It should be smaller than O(3^N) since there are cases skipped earlier, but should be greater than O(NK).
// Space: O(NK)
// Ref: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/discuss/585557/C%2B%2B-Straightforward-DFS.-Skip-appending-same-char.
class Solution {
    vector<string> ans;
    void dfs(string &cur, int n, int k) {
        if (ans.size() == k) return;
        if (cur.size() == n) {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < 3; ++i) {
            if (cur.size() && cur.back() == 'a' + i) continue;
            cur.push_back('a' + i);
            dfs(cur, n, k);
            cur.pop_back();
        }
    }
public:
    string getHappyString(int n, int k) {
        string cur;
        dfs(cur, n, k);
        return ans.size() == k ? ans.back() : "";
    }
};