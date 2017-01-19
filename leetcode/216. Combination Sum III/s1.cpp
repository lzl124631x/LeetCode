class Solution {
private:
    vector<vector<int>> res;
    void rec(int k, int n, vector<int> &v, int d) {
        if (!k && !n) {
            res.push_back(v);
            return;
        }
        for (int i = d; i <= 9 && n >= i; ++i) {
            v.push_back(i);
            rec(k - 1, n - i, v, i + 1);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        rec(k, n, v, 1);
        return res;
    }
};