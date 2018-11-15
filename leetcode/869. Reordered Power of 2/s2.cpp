// OJ: https://leetcode.com/problems/reordered-power-of-2/
// Author: github.com/lzl124631x
// Time: O(lg(N))
//     where lg(N) is number of digits in N base-10.
//     There are just 32 possible powers of 2. The comparison is O(lg(N)).
// Space: O(lg(N))
class Solution {
private:
    vector<int> count(int N) {
        vector<int> cnt(10, 0);
        while (N) {
            cnt[N % 10]++;
            N /= 10;
        }
        return cnt;
    }
public:
    bool reorderedPowerOf2(int N) {
        auto cnt = count(N);
        for (int i = 0; i < 31; ++i) {
            auto c = count(1 << i);
            if (equal(cnt.begin(), cnt.end(), c.begin())) return true;
        }
        return false;
    }
};