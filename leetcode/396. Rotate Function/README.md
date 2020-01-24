# [396. Rotate Function (Medium)](https://leetcode.com/problems/rotate-function/)

<p>
Given an array of integers <code>A</code> and let <i>n</i> to be its length.
</p>

<p>
Assume <code>B<sub>k</sub></code> to be an array obtained by rotating the array <code>A</code> <i>k</i> positions clock-wise, we define a "rotation function" <code>F</code> on <code>A</code> as follow:
</p>

<p>
<code>F(k) = 0 * B<sub>k</sub>[0] + 1 * B<sub>k</sub>[1] + ... + (n-1) * B<sub>k</sub>[n-1]</code>.</p>

<p>Calculate the maximum value of <code>F(0), F(1), ..., F(n-1)</code>. 
</p>

<p><b>Note:</b><br>
<i>n</i> is guaranteed to be less than 10<sup>5</sup>.
</p>

<p><b>Example:</b>
</p><pre>A = [4, 3, 2, 6]

F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
</pre>
<p></p>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```
F(0) = (0 * A[0]) + (1 * A[1]) + ... + ((N - 1) * A[N - 1])

F(1) = (1 * A[0]) + (2 * A[1]) + ... + (0 * A[N - 1])
     = F(0) + Sum(A) - N * A[N - 1]

F(2) = F(1) + Sum(A) - N * A[N - 2]

...

F(k) = F(k - 1) + Sum(A) - N * A[N - k]
```

So we can compute each `F(k)` in `O(1)` time and get the max in `O(N)` time.

```cpp
// OJ: https://leetcode.com/problems/rotate-function/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.empty()) return 0;
        long long f = 0, ans = INT_MIN, N = A.size(), sum = accumulate(A.begin(), A.end(), (long long)0);
        for (int i = 0; i < N; ++i) f += i * A[i];
        for (int i = N - 1; i >= 0; --i) ans = max(ans, f += (sum - N * A[i]));
        return ans;
    }
};
```