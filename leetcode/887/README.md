# [887. Super Egg Drop (Hard)](https://leetcode.com/problems/super-egg-drop/)

You are given `K` eggs, and you have access to a building with `N` floors from `1` to `N`. 

Each egg is identical in function, and if an egg breaks, you cannot drop it again.

You know that there exists a floor `F` with `0 <= F <= N` such that any egg dropped at a floor higher than `F` will break, and any egg dropped at or below floor `F` will not break.

Each _move_, you may take an egg (if you have an unbroken one) and drop it from any floor `X` (with `1 <= X <= N`). 

Your goal is to know **with certainty** what the value of `F` is.

What is the minimum number of moves that you need to know with certainty what `F` is, regardless of the initial value of `F`?

**Example 1:**

**Input:** K = 1, N = 2  
**Output:** 2  
**Explanation:**   
Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
If it didn't break, then we know with certainty F = 2.
Hence, we needed 2 moves in the worst case to know what F is with certainty.

**Example 2:**

**Input:** K = 2, N = 6  
**Output:** 3

**Example 3:**

**Input:** K = 3, N = 14  
**Output:** 4

**Note:**

1.  `1 <= K <= 100`
2.  `1 <= N <= 10000`

## TLE Solution
Assume we choose to throw the egg at floor `i`:
* If the egg breaks, we continue throwing between floors `[1, i - 1]`, with one less egg available
* If the egg doesn't break, we continue throwing between floors `[i + 1, N]`, with the same number of eggs.
In this way, for whichever floors region `[m, n] (1 <= m <= n <= N)`, we can regard floor `m - 1` is safe while floor `n + 1` is not safe. So the 2nd case above is analogous to throwing between floors `[1, N - i]`.

Denote `f(K, N)` as the result. The 1st case corresponds to `f(K - 1, i - 1)`, and the 2nd case `f(K, N - i)`. We have to pick the max of them to ensure certainty. Denote `g(K, N, i)` as this max.

Thus, `f(K, N) = 1 + min{ g(K, N, i) | 1 <= i <= N }`. This is the equation of DP.

In the worse case we need to visit all the combinations of `k` and `n` `(k in [1, K], n in [1, N])`, thus time complexity is `O(KN)`.

```cpp
// OJ: https://leetcode.com/problems/super-egg-drop/
// Author: github.com/lzl124631x
// Time: O(KN)
// Space: O(KN)
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        return std::hash<T1>{}(p.first * 10000 + p.second);
    }
};
class Solution {
private:
    unordered_map<pair<int, int>, int, pair_hash> m;
public:
    int superEggDrop(int K, int N) {
        if (!K || !N) return 0;
        if (K == 1) return N;
        auto p = make_pair(K, N);
        if (m.find(p) != m.end()) return m[p];
        int val = INT_MAX;
        int prev = INT_MAX;
        for (int i = (N + 1) / 2; i >= 1; --i) {
            int v = max(superEggDrop(K - 1, i - 1), superEggDrop(K, N - i));
            if (v > prev) break;
            prev = val;
            val = min(val, v);
            
        }
        return m[p] = 1 + val;
    }
};
```

## Solution 1.
Denote `f(K, S)` as the max number of floors that is solvable given `K` eggs and `S` steps.

After I throw an egg:
* If the egg is broken, I should continue throw the eggs within lower floors. The max number of lower floors I can handle is `f(K - 1, S - 1)`.
* If the egg is not broken, I should continue throw the eggs within upper floors. The max number of upper floors I can handle is `f(K, S - 1)`.

So the max total number of floors I can handle is 1 plus the result of the above two cases, i.e. `f(K, S) = 1 + f(K - 1, S - 1) + f(K, S - 1)`.
```cpp
// OJ: https://leetcode.com/problems/super-egg-drop/
// Author: github.com/lzl124631x
// Time: O(SK) where S is the result.
// Space: O(K)
// Ref: https://leetcode.com/problems/super-egg-drop/discuss/159508/easy-to-understand
class Solution {
public:
    int superEggDrop(int K, int N) {
        int step = 0;
        vector<int> dp(K + 1);
        for (; dp[K] < N; ++step) {
            for (int k = K; k > 0; --k) {
                dp[k] += 1 + dp[k - 1];
            }
        }
        return step;
    }
};
```
