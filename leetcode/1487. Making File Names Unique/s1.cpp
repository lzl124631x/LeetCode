// OJ: https://leetcode.com/problems/making-file-names-unique/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        int N = names.size();
        vector<string> ans(N);
        unordered_map<string, int> m;
        for (int i = 0; i < N; ++i) {
            auto &name = names[i];
            if (m.count(name) == 0) {
                ans[i] = name;
                m[name] = 1;
            } else {
                int index = m[name];
                while (true) {
                    auto n = name + "(" + to_string(index++) + ")";
                    if (m.count(n) == 0) {
                        ans[i] = n;
                        m[name] = index;
                        m[n] = 1;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};