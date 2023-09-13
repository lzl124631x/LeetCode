# [446. Arithmetic Slices II - Subsequence (Hard)](https://leetcode.com/problems/arithmetic-slices-ii-subsequence/)

<p>A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.</p>

<p>For example, these are arithmetic sequences:</p>

<pre>1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9</pre>

<p>The following sequence is not arithmetic.</p>

<pre>1, 1, 2, 5, 7</pre>
&nbsp;

<p>A zero-indexed array A consisting of N numbers is given. A <b>subsequence</b> slice of that array is any sequence of integers (P<sub>0</sub>, P<sub>1</sub>, ..., P<sub>k</sub>) such that 0 ≤ P<sub>0</sub> &lt; P<sub>1</sub> &lt; ... &lt; P<sub>k</sub> &lt; N.</p>

<p>A <b>subsequence</b> slice (P<sub>0</sub>, P<sub>1</sub>, ..., P<sub>k</sub>) of array A is called arithmetic if the sequence A[P<sub>0</sub>], A[P<sub>1</sub>], ..., A[P<sub>k-1</sub>], A[P<sub>k</sub>] is arithmetic. In particular, this means that k ≥ 2.</p>

<p>The function should return the number of arithmetic subsequence slices in the array A.</p>

<p>The input contains N integers. Every integer is in the range of -2<sup>31</sup> and 2<sup>31</sup>-1 and 0 ≤ N ≤ 1000. The output is guaranteed to be less than 2<sup>31</sup>-1.</p>
&nbsp;

<p><b>Example:</b></p>

<pre><b>Input:</b> [2, 4, 6, 8, 10]

<b>Output:</b> 7

<b>Explanation:</b>
All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]
</pre>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Arithmetic Slices (Medium)](https://leetcode.com/problems/arithmetic-slices/)

## Solution 1. DP

Let `dp[i][d]` be the number of weak arithmetic subsequences ending at `A[i]` and with common difference `d`. Here `weak` means the subsequence can be of size `2`.

For each `A[i]`, we loop through all `j < i`:
1. `A[j], A[i]` forms a new sequence.
1. We can append `A[i]` to all the weak arithmetic subsequences ending at `A[j]` with common difference `d`.

```
dp[i][d] = sum(dp[j][d] + 1 | 0 <= j < i && A[i] - A[j] == d)
```

While summing the answer, we can ignore the `1`s corresponding to weak arithmetic subsequences.

```cpp
// OJ: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
// Ref: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/solution/
class Solution {
    typedef long long LL;
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int N = A.size(), ans = 0;
        vector<unordered_map<LL, int>> dp(N);
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                LL d = (LL)A[i] - A[j];
                int sum = dp[j].count(d) ? dp[j][d] : 0;
                dp[i][d] += sum + 1;
                ans += sum;
            }
        }
        return ans;
    }
};
```

## Solution 2. DP

One optimization based on Solution 1 is that we can skip updating `dp[i][d]` if there won't be a next element appendable to this subsequence. This would save lots of runtime and space consumption.

```cpp
// OJ: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
    typedef long long LL;
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.empty()) return 0;
        int ans = 0, N = A.size();
        vector<unordered_map<LL, int>> dp(N);
        unordered_set<int> s(A.begin(), A.end());
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                LL d = (LL)A[i] - A[j];
                int count = dp[j].count(d) ? dp[j][d] : 0;
                ans += count;
                if (s.count(A[i] + d)) dp[i][d] += 1 + count;
            }
        }
        return ans;
    }
};
```

## Solution 3. DP

```cpp
// OJ: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        int N = A.size(), ans = 0;
        vector<vector<int>> dp(N, vector<int>(N));
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < N; ++i) pos[A[i]].push_back(i);
        for (int i = 2; i < N; ++i) {
            for (int j = 1; j < i; ++j) {
                long num = 2l * A[j] - A[i];
                if (num < INT_MIN || num > INT_MAX || !pos.count(num)) continue;
                for (int k : pos[num]) {
                    if (k >= j) break;
                    dp[i][j] += dp[j][k] + 1;
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};
```