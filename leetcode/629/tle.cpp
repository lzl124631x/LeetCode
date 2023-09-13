// OJ: https://leetcode.com/problems/k-inverse-pairs-array
// Author: github.com/lzl124631x
// Time: O(N^4)
// Space: O(1)
class Solution {
private:
    int cnt = 0;
    int mod = pow(10, 9) + 7;
    void permuteRec(vector<int> &v, int start, function<void()> cb) {
        if (start == v.size()) {
            cb();
            return;
        }
        for (int i = start; i < v.size(); ++i) {
            swap(v[i], v[start]);
            permuteRec(v, start + 1, cb);
            swap(v[i], v[start]);
        }
    }
    
    void permute(vector<int> &v, function<void()> cb) {
        permuteRec(v, 0, cb);
    }
    
    int countInversePairs(vector<int> &v) {
        int cnt = 0;
        for (int i = 0; i < v.size(); ++i) {
            for (int j = i + 1; j < v.size(); ++j) {
                if (v[i] > v[j]) ++cnt;
            }
        }
        return cnt;
    }
public:
    int kInversePairs(int n, int k) {
        vector<int> v(n, 1);
        partial_sum(v.begin(), v.end(), v.begin());
        permute(v, [&]() {
            if (k == countInversePairs(v)) cnt = (cnt + 1) % mod;
        });
        return cnt;
    }
};