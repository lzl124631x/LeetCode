// OJ: https://leetcode.com/problems/reordered-power-of-2/
// Author: github.com/lzl124631x
// Time: O(lg(N)! * log(N)),
//     where lg(N) is number of digits in N base-10,
//     and log(N) is number of digits in N base-2.
//     O(lg(N)!) is because of permutation, log(N) is because of testing `isPow2`.
// Space: O(lg(N))
class Solution {
private:
    bool isPow2(long long N) {
        while (N != 1) {
            if (N % 2) return false;
            N /= 2;
        }
        return true;
    }
    string num;
    bool dfs(int start) {
        if (start == num.size()) return isPow2(stoll(num));
        for (int i = start; i < num.size(); ++i) {
            if (num[i] == '0' && start == 0) continue;
            swap(num[start], num[i]);
            if (dfs(start + 1)) return true;
            swap(num[start], num[i]);
            while (i + 1 < num.size() && num[i] == num[i + 1]) ++i;
        }
        return false;
    }
public:
    bool reorderedPowerOf2(int N) {
        while (N) {
            num.push_back('0' + (N % 10));
            N /= 10;
        }
        sort(num.begin(), num.end(), greater<char>());
        return dfs(0);
    }
};