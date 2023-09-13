# [363. Max Sum of Rectangle No Larger Than K (Hard)](https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/)

<p>Given an <code>m x n</code> matrix <code>matrix</code> and an integer <code>k</code>, return <em>the max sum of a rectangle in the matrix such that its sum is no larger than</em> <code>k</code>.</p>

<p>It is <strong>guaranteed</strong> that there will be a rectangle with a sum no larger than <code>k</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/18/sum-grid.jpg" style="width: 255px; height: 176px;">
<pre><strong>Input:</strong> matrix = [[1,0,1],[0,-2,3]], k = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> matrix = [[2,2,-1]], k = 3
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>-100 &lt;= matrix[i][j] &lt;= 100</code></li>
	<li><code>-10<sup>5</sup> &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> What if the number of rows is much larger than the number of columns?</p>


**Companies**:  
[Roblox](https://leetcode.com/company/roblox), [Google](https://leetcode.com/company/google), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Matrix](https://leetcode.com/tag/matrix/), [Ordered Set](https://leetcode.com/tag/ordered-set/)

## Note

The brute force solution is enumerating `O((MN)^2)` all rectangles and for each rectangle sum the matrix sum in `O(MN)` time. The overall time complexity is `O((MN)^3)` which is too slow.

A better brute force is using prefix sum to save the `O(MN)` time calculating the matrix sum given a rectangle. The overall time complexity is `O((MN)^2)`. Since `M` and `N` are at most `100`, the time complexity is around `O(10^8)` which will still get TLE.

Now consider a single row matrix, we can scan the matrix from left to right and keep storing the prefix sums we've seen in a set. For the current prefix sum `S`, we want to find a prefix sum `X` from set that `S - X <= K`, i.e. `X >= S - K`. To find such a `X`, we can leverage `lower_bound` of `set` which takes `O(logN)` time. So this algorithm overall takes `O(NlogN)` time.

For a `2 x N` matrix, how to find a 2-row submatrix with sum `<= K`? We can compress the matrix by summing each column individually.

```
2  1 -4
1  0  1
// after compression
3  1 -3 
```

Then for this compressed `(3 1 -3)` vector, we can use the algorithm above for a single row matrix.

For a `M x N` matrix, we can enumerate different starting rows. For each starting row, we extend the bottom edge of the matrix continuously until it reaches the end. During this extention, we can keep compressing the matrix and running the algorithm for the compressed vector.

The overall time complexity is `O(M^2 * NlogN)

## Solution 1. DP + Binary Search

```cpp
// OJ: https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
// Author: github.com/lzl124631x
// Time: O(M^2 * NlogN)
// Space: O(N)
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& A, int k) {
        int M = A.size(), N = A[0].size(), ans = INT_MIN;
        for (int i = 0; i < M; ++i) { // starting row
            vector<int> prefix(N, 0);
            for (int j = i; j < M; ++j) { // ending row
                int sum = 0;
                set<int> s{0};
                for (int t = 0; t < N; ++t) {
                    sum += A[j][t];
                    prefix[t] += sum;
                    int target = prefix[t + 1] - k;
                    auto it = s.lower_bound(target);
                    if (it != s.end()) {
                        ans = max(ans, prefix[t] - *it);
                    }
                    s.insert(prefix[t]);
                }
            }
        }
        return ans;
    }
};
```

Or extract the `maxSumSubarray` function.

```cpp
// OJ: https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
// Author: github.com/lzl124631x
// Time: O(M^2 * NlogN)
// Space: O(N)
class Solution {
    int maxSumSubarray(vector<int> &A, int k) {
        set<int> s{0};
        int ans = INT_MIN;
        for (int n : A) {
            int target = n - k;
            auto it = s.lower_bound(target);
            if (it != s.end()) ans = max(ans, n - *it);
            s.insert(n);
        }
        return ans;
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& A, int k) {
        int M = A.size(), N = A[0].size(), ans = INT_MIN;
        for (int i = 0; i < M; ++i) { // starting row
            vector<int> prefix(N, 0);
            for (int j = i; j < M; ++j) { // ending row
                int sum = 0;
                for (int t = 0; t < N; ++t) {
                    sum += A[j][t];
                    prefix[t] += sum;
                }
                ans = max(ans, maxSumSubarray(prefix, k));
            }
        }
        return ans;
    }
};
```

## Solution 2. Transpose Matrix to Reduce Time

Considering the follow-up, the original algorithm is using `O(M^2 * NlogN)` time and `M` is always the number of rows.

If the number of rows is way larger than number of columns, we should transpose the matrix.

```cpp
// OJ: https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
// Author: github.com/lzl124631x
// Time: O(min(M, N)^2 * max(M, N)log(max(M, N)))
// Space: O(max(M, N))
class Solution {
    int maxSumSubarray(vector<int> &A, int k) {
        set<int> s{0};
        int ans = INT_MIN;
        for (int n : A) {
            int target = n - k;
            auto it = s.lower_bound(target);
            if (it != s.end()) ans = max(ans, n - *it);
            s.insert(n);
        }
        return ans;
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& A, int k) {
        int M = A.size(), N = A[0].size(), ans = INT_MIN;
        bool swapped = M > N;
        if (swapped) swap(M, N);
        for (int i = 0; i < M; ++i) { // starting row
            vector<int> prefix(N, 0);
            for (int j = i; j < M; ++j) { // ending row
                int sum = 0;
                for (int t = 0; t < N; ++t) {
                    sum += swapped ? A[t][j] : A[j][t];
                    prefix[t] += sum;
                }
                ans = max(ans, maxSumSubarray(prefix, k));
            }
        }
        return ans;
    }
};
```

## Solution 3. With Kadane Optimization

The `maxSumSubarray` function takes `O(NlogN)` time. We can use Kadane algorithm to get the maximum subarray sum in `O(N)` time, and if the maximum subarray sum is no more than `k`, we can directly return it.

```cpp
// OJ: https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
// Author: github.com/lzl124631x
// Time: O(min(M, N)^2 * max(M, N)log(max(M, N)))
// Space: O(max(M, N))
class Solution {
    int kadane(vector<int> &A) {
        int ans = INT_MIN, mx = 0;
        for (int n : A) {
            mx = max(mx + n, n);
            ans = max(ans, mx);
        }
        return ans;
    }
    int maxSumSubarray(vector<int> &A, int k) {
        int maxKadane = kadane(A);
        if (maxKadane <= k) return maxKadane;
        set<int> s{0};
        int ans = INT_MIN, sum = 0;
        for (int n : A) {
            sum += n;
            int target = sum - k;
            auto it = s.lower_bound(target);
            if (it != s.end()) ans = max(ans, sum - *it);
            s.insert(sum);
        }
        return ans;
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& A, int k) {
        int M = A.size(), N = A[0].size(), ans = INT_MIN;
        bool swapped = M > N;
        if (swapped) swap(M, N);
        for (int i = 0; i < M; ++i) { // starting row
            vector<int> sum(N, 0);
            for (int j = i; j < M; ++j) { // ending row
                for (int t = 0; t < N; ++t) sum[t] += swapped ? A[t][j] : A[j][t];
                ans = max(ans, maxSumSubarray(sum, k));
            }
        }
        return ans;
    }
};
```

## Reference

* https://discuss.leetcode.com/topic/48875/accepted-c-codes-with-explanation-and-references
* https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/solution/