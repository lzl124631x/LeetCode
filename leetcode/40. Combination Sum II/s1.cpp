class Solution {
private:
    vector<vector<int>> res;
    void rec(vector<int> &c, int t, int pos, vector<int> &v) {
        if (!t) {
            res.push_back(v);
            return;
        }
        for (int i = pos; i < c.size() && t >= c[i]; ++i) {
            if (i == pos || c[i] != c[i - 1]) {
                v.push_back(c[i]);
                rec(c, t - c[i], i + 1, v);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        rec(candidates, target, 0, v);
        return res;
    }
};