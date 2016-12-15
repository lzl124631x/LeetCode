class Solution {
private:
    vector<vector<int>> res;
    void rec(vector<int> &c, int t, int pos, vector<int> &tmp) {
        if (t == 0) {
            res.push_back(tmp);
            return;
        }
        if (pos >= c.size()) return;
        int x = c[pos];
        int n = 1;
        while (t - n * x >= 0) {
            tmp.push_back(x);
            ++n;
        }
        --n;
        while (n >= 0) {
            rec(c, t - n * x, pos + 1, tmp);
            if (n > 0) tmp.pop_back();
            --n;
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        rec(candidates, target, 0, tmp);
        return res;
    }
};