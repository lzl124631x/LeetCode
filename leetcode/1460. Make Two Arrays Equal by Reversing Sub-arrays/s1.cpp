// OJ: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool canBeEqual(vector<int>& B, vector<int>& A) {
        unordered_map<int, int> cnt;
        for (int n : A) cnt[n]++;
        for (int n : B) {
            if (--cnt[n] < 0) return false;
        }
        return true;
    }
};