## Solution 1.

Let `half` be the first half of the palindrome. The range of it is `begin = 10^((len-1)/2)` (inclusive) to `end = 10^((len+1)/2)` (exclusive).

For a given `rank = Q[i]`, `half = begin + Q[i] - 1`. We can use `getPalindrome` helper function to generate the palindrome.

```cpp
// OJ: https://leetcode.com/problems/find-palindrome-with-fixed-length/
// Author: github.com/lzl124631x
// Time: O(QlogL)
// Space: O(1) extra space
class Solution {
    long getPalindrome(long half, bool odd) {
        long pal = half;
        if (odd) half /= 10;
        for (; half; half /= 10) pal = pal * 10 + half % 10;
        return pal;
    }
public:
    vector<long long> kthPalindrome(vector<int>& Q, int len) {
        long begin = pow(10L, (len - 1) / 2), end = pow(10L, (len + 1) / 2);
        vector<long long> ans(Q.size(), -1);
        for (int i = 0; i < Q.size(); ++i) {
            long half = begin + Q[i] - 1;
            if (half < end) ans[i] = getPalindrome(half, len % 2);
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/find-palindrome-with-fixed-length/discuss/1887018/