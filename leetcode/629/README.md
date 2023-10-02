# [629. K Inverse Pairs Array (Hard)](https://leetcode.com/problems/k-inverse-pairs-array/)

<p>
Given two integers <code>n</code> and <code>k</code>, find how many different arrays consist of numbers from <code>1</code> to <code>n</code> such that there are exactly <code>k</code> inverse pairs. 
</p>
<p>
We define an inverse pair as following:
For <code>i<sub>th</sub></code> and <code>j<sub>th</sub></code> element in the array, if <code>i</code> &lt; <code>j</code> and <code>a[i]</code> &gt; <code>a[j]</code> then it's an inverse pair; Otherwise, it's not.
</p>

<p>
Since the answer may be very large, the answer should be modulo 10<sup>9</sup> + 7.
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> n = 3, k = 0
<b>Output:</b> 1
<b>Explanation:</b> 
Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pair.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> n = 3, k = 1
<b>Output:</b> 2
<b>Explanation:</b> 
The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>The integer <code>n</code> is in the range [1, 1000] and <code>k</code> is in the range [0, 1000].</li>
</ol>
<p></p>

**Companies**:  
[Works Applications](https://leetcode.com/company/works-applications)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1.

Let `dp[i][j]` be the number ways to form `k` reverse pairs with `i` numbers.

For `i` numbers, there are `i!` permutations.

The decreasing sequence has `(i-1) + (i-2) + ... + 0 = (i-1) * i / 2` reverse pairs.

```
dp[1][0] = 1       (1)

dp[2][0] = 1       (12)
dp[2][1] = 1       (21)

dp[3][0] = 1       (123)
dp[3][1] = 2       (132, 213)
dp[3][2] = 2       (312, 231)
dp[3][3] = 1       (321)

dp[4][0] = 1       (1234)
dp[4][1] = 3        (2134,1324,1243)
dp[4][2] = 
dp[4][3] = 
dp[4][4] =          (4321)
dp[4][5] = 
dp[4][6] = 

```

Denote `R(n, k)` as the result number, `P` as a permutation.


For `n = 1`, only 1 case for `k = 0`. So `R(1, 0) = 1`.

```
| 1 |               // If P[0] = 1
```

For `n = 2`:

```
| 1 |               // If P[0] = 1
    | 1 |           // If P[0] = 2
|
V
| 1 | 1 |
```

For `n = 3`:

```
| 1 | 1 |               // If P[0] = 1
    | 1 | 1 |           // If P[0] = 2
        | 1 | 1 |       // If P[0] = 3
|
V
| 1 | 2 | 2 | 1 |

```

For `n = 4`:
```
| 1 | 2 | 2 | 1 |              // If P[0] = 1
    | 1 | 2 | 2 | 1 |          // If P[0] = 2
        | 1 | 2 | 2 | 1 |      // If P[0] = 3
            | 1 | 2 | 2 | 1 |  // If P[0] = 4
|
V
| 1 | 3 | 5 | 6 | 5 | 3 | 1 |

```

```cpp
// OJ: https://leetcode.com/problems/k-inverse-pairs-array/
// Author: github.com/lzl124631x
// Time: O(N * K^2)
// Space: O(K)
class Solution {
public:
    int kInversePairs(int n, int k) {
        if (k > n * (n - 1) / 2) return 0;
        int mod = 1e9 + 7;
        vector<int> prev(1, 1);
        for (int i = 1; i <= n; ++i) {
            vector<int> cnt(min(k + 1, (int)prev.size() + i - 1));
            for (int j = 0; j < i; ++j) {
                for (int t = 0; t < prev.size(); ++t) {
                    if (j + t > k) break;
                    cnt[j + t] = (cnt[j + t] + prev[t]) % mod;
                }
            }
            prev = cnt;
        }
        return prev[k];
    }
};
```

## Solution 2. DP

Denote `F(N, K)` as the result.

Observations:
* Valid range of `K` is `[0, N * (N - 1) / 2]`. `F(N, K) = 0` if `K` &notin; `[0, N * (N - 1) / 2]`.
* `F(N, 0) = F(N, N * (N - 1) / 2) = 1`.

For `F(N, K)`, let's pick 1, 2, ..., N as the first number:
* When 1 is picked, we need to compute `F(N - 1, K)`.
* When 2 is picked, we need to compute `F(N - 1, K - 1)`.
* ...
* When N is picked, we need to compute `F(N - 1, K - (N - 1))`.

Eventually `F(N, K) = Sum(F(N - 1, K) + F(N - 1, K - 1) + ... + F(N - 1, K - (N - 1))`.

We can use this formula to compute `F(n, K)` for `N = 1, 2, 3, ..., N`.

```cpp
// OJ: https://leetcode.com/problems/k-inverse-pairs-array/
// Author: github.com/lzl124631x
// Time: O(NK * min(N, K))
// Space: O(K)
class Solution {
public:
    int kInversePairs(int N, int K) {
        if (K > N * (N - 1) / 2) return 0;
        vector<int> m(K + 1, 0);
        m[0] = 1;
        int mod = 1e9 + 7;
        for (int n = 2; n <= N; ++n) {
            for (int k = min(K, (n * (n - 1) / 2)); k > 0; --k) {
                for (int i = max(0, k - n + 1); i < k && m[i]; ++i) {
                    m[k] = (m[k] + m[i]) % mod;
                }
            }
        }
        return m[K];
    }
};
```

## Solution 3. DP + Cumulative Sum

In Solution 2, we alway compute the sum of a segment of the previous row. Considering this, we can use Cumulative Sum to make it faster.

Denote `G(N, K)` as `Sum{k=[0,K]}(F(N, k))`.

```
G(N, K) = G(N, K - 1) + F(N, K)
        = G(N, K - 1) + [F(N - 1, K - min(K, N - 1)) + ... + F(N - 1, K)]
        = G(N, K - 1) + [G(N - 1, K) - G(N - 1, K - min(K, N - 1) - 1)]
```

After all the `G(N, K)` are computed, we can get `F(N, K) = G(N, K) - G(N, K - 1)`.

```cpp
// OJ: https://leetcode.com/problems/k-inverse-pairs-array/
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(K)
class Solution {
public:
    int kInversePairs(int N, int K) {
        if (K > N * (N - 1) / 2) return 0;
        vector<vector<int>> dp(2, vector<int>(K + 1, 0));
        dp[0][0] = dp[1][0] = 1;
        int mod = 1e9 + 7;
        for (int n = 2; n <= N; ++n) {
            int bound = min(K, n * (n - 1) / 2);
            for (int k = 1; k <= bound; ++k) {
                dp[n % 2][k] = (dp[n % 2][k - 1] + (mod + dp[(n - 1) % 2][k] - dp[(n - 1) % 2][k - min(k, n - 1) - 1]) % mod) % mod;
            }
        }
        return dp[N % 2][K];
    }
};
```