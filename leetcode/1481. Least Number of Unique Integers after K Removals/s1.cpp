// OJ: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
// Author: github.com/lzl124631x
// Time: O(N + UlogU) where U is the number of unique counts
// Space: O(N)
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& A, int k) {
        unordered_map<int, int> cnt;
        for (int n : A) cnt[n]++;
        map<int, int> m;
        for (auto &p : cnt) m[p.second]++;
        int ans = cnt.size();
        for (auto &p : m) {
            int n = min(p.second, k / p.first);
            if (n == 0) break;
            ans -= n;
            k -= p.first * n;
        }
        return ans;
    }
};