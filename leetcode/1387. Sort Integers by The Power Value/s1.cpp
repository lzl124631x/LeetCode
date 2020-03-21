// OJ: https://leetcode.com/problems/sort-integers-by-the-power-value/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
    int power(int x) {
        int ans = 0;
        while (x != 1) {
            if (x % 2) x = x * 3 + 1;
            else x /= 2;
            ++ans;
        }
        return ans;
    }
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> v;
        for (int i = lo; i <= hi; ++i) v.emplace_back(power(i), i);
        sort(v.begin(), v.end());
        return v[k - 1].second;
    }
};