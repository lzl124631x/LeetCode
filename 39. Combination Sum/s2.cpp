// Much cleaner solution:
// https://discuss.leetcode.com/topic/14654/accepted-16ms-c-solution-use-backtracking-easy-understand
class Solution {
private:
    vector<vector<int>> res;
    void rec(vector<int> &c, int t, int start, vector<int> &v) {
        if (t == 0) {
            res.push_back(v);
            return;
        }
        for (int i = start; i < c.size() && t >= c[i]; ++i) {
            v.push_back(c[i]);
            rec(c, t - c[i], i, v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        rec(candidates, target, 0, v);
        return res;
    }
};