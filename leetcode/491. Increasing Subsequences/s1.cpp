class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        ans.insert(vector<int>());
        for (int i = 0; i < nums.size(); ) {
            int n = nums[i++], cnt = 1, len = ans.size();
            while (i < nums.size() && nums[i] == n) ++i, ++cnt;
            set<vector<int>> newAns = ans;
            for (auto it = ans.begin(); it != ans.end(); ++it) {
                vector<int> v = *it;
                if (!v.empty() && n < v.back()) continue;
                for (int j = 0; j < cnt; ++j) {
                    v.push_back(n);
                    newAns.insert(v);
                }
            }
            ans = newAns;
        }
        for (auto it = ans.begin(); it != ans.end(); ) {
            if (it->size() <= 1) it = ans.erase(it);
            else ++it;
        }
        vector<vector<int>> v(ans.begin(), ans.end());
        return v;
    }
};