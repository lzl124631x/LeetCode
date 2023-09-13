# [805. Split Array With Same Average (Hard)](https://leetcode.com/problems/split-array-with-same-average/)

<p>In a given integer array A, we must move every element of A to either list B or list C. (B and C initially start empty.)</p>

<p>Return true if and only if after such a move, it is possible that the average value of B is equal to the average value of C, and B and C are both non-empty.</p>

<pre><strong>Example :</strong>
<strong>Input:</strong> 
[1,2,3,4,5,6,7,8]
<strong>Output:</strong> true
<strong>Explanation: </strong>We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have the average of 4.5.
</pre>

<p><strong>Note:</strong></p>

<ul>
	<li>The length of <code>A</code> will be in the range&nbsp;[1, 30].</li>
	<li><code>A[i]</code> will be in the range of <code>[0, 10000]</code>.</li>
</ul>

<p>&nbsp;</p>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1. Brute Force

Our goal is to find a non-empty subsequence `B` which satisfies `Sum(B) * N == Sum(A) * Len(B)`, where `N` is the length of `A`.

We can try to get all the sums of the subsequences of `A`. There are `2^N` subsequences of A.

We can't put all the sums of subsequences into a single set since the length of the subsequence matters.

So we store the sums of subsequences into `vector<unordered_set<int>> v(N + 1)`, where `v[i]` is a set of sums of subsequences of length `i` and `v[0] = {0}`.

We try using each `A[i]` to update `v`. For each value `n` in `v[j]`, we put `n + A[i]` into `v[j + 1]`.

If any `(n + A[i]) * N == Sum(A) * (j + 1)`, we can return `true`.

```cpp
// OJ: https://leetcode.com/problems/split-array-with-same-average/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(2^N)
class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int N = A.size(), sum = accumulate(A.begin(), A.end(), 0);
        vector<unordered_set<int>> v(N + 1);
        v[0] = {0};
        for (int i = 0; i < N; ++i) {
            for (int j = i; j >= 0; --j) {
                if (j == N - 1) continue;
                for (int n : v[j]) {
                    int m = n + A[i];
                    if (m * N == sum * (j + 1)) return true;
                    v[j + 1].insert(m);
                }
            }
        }
        return false;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/split-array-with-same-average/
// Author: github.com/lzl124631x
// Time: O(n^3 * M) where M the maximum possible number in `A`
// Space: O(n^2 * M)
// Ref: https://leetcode.com/problems/split-array-with-same-average/discuss/120667/C%2B%2B-Solution-with-explanation-early-termination-(Updated-for-new-test-case)
class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int N = A.size(), sum = accumulate(A.begin(), A.end(), 0), M = N / 2;
        bool possible = false;
        for (int i = 1; i <= N && !possible; ++i) possible = sum * i % N == 0;
        if (!possible) return false;
        vector<unordered_set<int>> v(M + 1);
        v[0] = {0};
        for (int i = 0; i < N; ++i) {
            for (int j = min(M, i + 1); j >= 1; --j) {
                for (int n : v[j - 1]) {
                    int m = n + A[i];
                    if (m * N == sum * j) return true;
                    v[j].insert(m);
                }
            }
        }
        return false;
    }
};
```