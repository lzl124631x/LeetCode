# [875. Koko Eating Bananas (Medium)](https://leetcode.com/problems/koko-eating-bananas/)

Koko loves to eat bananas.  There are `N` piles of bananas, the `i`\-th pile has `piles[i]` bananas.  The guards have gone and will come back in `H` hours.

Koko can decide her bananas-per-hour eating speed of `K`.  Each hour, she chooses some pile of bananas, and eats K bananas from that pile.  If the pile has less than `K` bananas, she eats all of them instead, and won't eat any more bananas during this hour.

Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.

Return the minimum integer `K` such that she can eat all the bananas within `H` hours.

**Example 1:**

**Input:** piles = \[3,6,7,11\], H = 8  
**Output:** 4

**Example 2:**

**Input:** piles = \[30,11,23,4,20\], H = 5  
**Output:** 30

**Example 3:**

**Input:** piles = \[30,11,23,4,20\], H = 6  
**Output:** 23

**Note:**

*   `1 <= piles.length <= 10^4`
*   `piles.length <= H <= 10^9`
*   `1 <= piles[i] <= 10^9`

## Solution 1. Binary Search

Search a eating speed `K` between `[1, P_max]` where `P_max` is the max pile size. The `K` should be the first (smallest) one requiring `h` (`h <= H`) hour to consume all the bananas.

```cpp
// OJ: https://leetcode.com/problems/koko-eating-bananas/
// Author: github.com/lzl124631x
// Time: O(P*log(P_max)) where P is count of piles, P_max is max pile size.
// Space: O(K)
class Solution {
private:
    int countH(vector<int> &piles, int K) {
        int cnt = 0;
        for (int p : piles) cnt += (p + K - 1) / K;
        return cnt;
    }
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int L = 1, R = *max_element(piles.begin(), piles.end());
        while (L <= R) {
            int M = L + (R - L) / 2;
            int h = countH(piles, M);
            if (h > H) L = M + 1;
            else R = M - 1;
        }
        return L;
    }
};
```