// OJ: https://leetcode.com/problems/reduce-array-size-to-the-half/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int n : arr) m[n]++;
        vector<int> v;
        for (auto p : m) v.push_back(p.second);
        sort(v.begin(), v.end(), greater<int>());
        int ans = 0, cnt = 0;
        for (int n : v) {
            cnt += n;
            ++ans;
            if (cnt >= (arr.size() + 1) / 2) break;
        }
        return ans;
    }
};