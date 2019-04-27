// OJ: https://leetcode.com/problems/gray-code/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(1)
class Solution {
private:
    inline int toggle(int val, int i) {
        return val ^ (1 << i);
    }
    void grayCode(int n, int &val, vector<int> &v){
        if (n < 0) return;
        grayCode(n - 1, val, v);
        val = toggle(val, n);
        v.push_back(val);
        grayCode(n - 1, val, v);
    }
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        int val = 0;
        v.push_back(val);
        grayCode(n - 1, val, v);
        return v;
    }
};