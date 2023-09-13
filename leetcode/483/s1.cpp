// OJ: https://leetcode.com/problems/smallest-good-base/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
typedef unsigned long long ULL;
class Solution {
private:
    ULL getValue(ULL base, int cnt) {
        ULL ans = 1, p = 1;
        while (--cnt) ans += (p *= base);
        return ans;
    }
public:
    string smallestGoodBase(string n) {
        ULL num = stoull(n), ans = num - 1, cnt = 3, k, val;
        while (true) {
            k = pow(num, 1 / (double)(cnt - 1));
            if (k < 2) break;
            do {
                val = getValue(k, cnt);
                if (val == num) ans = k;
                --k;
            } while (val > num);
            ++cnt;
        }      
        return to_string(ans);
    }
};