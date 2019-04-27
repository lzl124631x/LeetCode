// OJ: https://leetcode.com/problems/gray-code/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(2^N)
class Solution {
private:
    inline int toggle(int n, int i) {
        return n ^ (1 << i);
    }
    int next(int n, unordered_set<int> s) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            ans = toggle(n, i);
            if (s.find(ans) == s.end()) break;
        }
        return ans;
    }
public:
    vector<int> grayCode(int n) {
        unordered_set<int> s{0};
        vector<int> ans(pow(2, n), 0);
        for (int i = 1; i < ans.size(); ++i) {
            s.insert(ans[i] = next(ans[i - 1], s));
        }
        return ans;
    }
};