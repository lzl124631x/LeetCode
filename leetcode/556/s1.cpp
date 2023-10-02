// OJ: https://leetcode.com/problems/next-greater-element-iii/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int nextGreaterElement(int n) {
        auto s = to_string(n);
        for (int i = s.size() - 2; i >= 0; --i) {
            if (s[i] >= s[i + 1]) continue;
            int j = lower_bound(s.begin() + i + 1, s.end(), s[i], greater<int>()) - s.begin() - 1;
            swap(s[i], s[j]);
            sort(s.begin() + i + 1, s.end());
            long n = stol(s);
            return n > INT_MAX ? -1 : n;
        }
        return -1;
    }
};