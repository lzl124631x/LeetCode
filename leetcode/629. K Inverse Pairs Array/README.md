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
        long long mod = 1e9 + 7;
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
        return k >= prev.size() ? 0 : prev[k];
    }
};
```