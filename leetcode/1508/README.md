# [1508. Range Sum of Sorted Subarray Sums (Medium)](https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/)

<p>Given the array <code>nums</code> consisting of <code>n</code> positive integers. You computed the sum of all non-empty continous subarrays from&nbsp;the array and then sort them in non-decreasing order, creating a new array of <code>n * (n + 1) / 2</code>&nbsp;numbers.</p>

<p><em>Return the sum of the numbers from index </em><code>left</code><em> to index </em><code>right</code> (<strong>indexed from 1</strong>)<em>, inclusive, in the&nbsp;new array.&nbsp;</em>Since the answer can be a huge number return it modulo 10^9 + 7.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4], n = 4, left = 1, right = 5
<strong>Output:</strong> 13 
<strong>Explanation:</strong> All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. After sorting them in non-decreasing order we have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13. 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4], n = 4, left = 3, right = 4
<strong>Output:</strong> 6
<strong>Explanation:</strong> The given array is the same as example 1. We have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 3 to ri = 4 is 3 + 3 = 6.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4], n = 4, left = 1, right = 10
<strong>Output:</strong> 50
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10^3</code></li>
	<li><code>nums.length == n</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>1 &lt;= left &lt;= right&nbsp;&lt;= n * (n + 1) / 2</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sort](https://leetcode.com/tag/sort/)

## Solution 1. Prefix Sum

Compute the prefix sum array using `pre`. Use `pre` to get the array of all subarray sums -- `sum`. Sort `sum` array then add from `sum[left - 1]` to `sum[right - 1]`.

```cpp
// OJ: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/
// Author: github.com/lzl124631x
// Time: O(N^2 * log(N^2))
// Space: O(N^2)
class Solution {
public:
    int rangeSum(vector<int>& A, int N, int left, int right) {
        vector<int> sum;
        long ans = 0, mod = 1e9+7;
        for (int i = 0; i < N; ++i) {
            int pre = 0;
            for (int j = i; j < N; ++j) {
                pre += A[j];
                sum.push_back(pre);
            }
        }
        sort(begin(sum), end(sum));
        for (int i = left; i <= right; ++i) ans = (ans + sum[i - 1]) % mod;
        return ans;
    }
};
```

## Solution 2. Heap

```cpp
// OJ: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/
// Author: github.com/lzl124631x
// Time: O(right * logN)
// Space: O(N)
// Ref: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/discuss/730511/C++-priority_queue-solution
class Solution {
public:
    int rangeSum(vector<int>& A, int N, int left, int right) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // partial sum, next index
        for (int i = 0; i < N; ++i) q.emplace(A[i], i + 1);
        long ans = 0, mod = 1e9+7;
        for (int i = 1; i <= right; ++i) {
            auto p = q.top();
            q.pop();
            if (i >= left) ans = (ans + p.first) % mod;
            if (p.second < N) {
                p.first += A[p.second++];
                q.push(p);
            }
        }
        return ans;
    }
};
```

## Solution 3. Binary Search + Sliding Window

```cpp
// OJ: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/
// Author: github.com/lzl124631x
// Time: O(Nlog(sum(A)))
// Space: O(N)
// Ref: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/discuss/733047/Python-Binary-Search-Time-O(NlogSum(A))
class Solution {
    vector<int> B, C; // B is partial_sum array of A. C is partial_sum array of B.
    int N;
    int countSumUnder(int score) { // Use sliding window to cound the partial sums that are smaller or equal to `score`.
        int ans = 0, i = 0;
        for (int j = 0; j < N + 1; ++j) {
            while (B[j] - B[i] > score) ++i;
            ans += j - i;
        }
        return ans;
    }
    int sumKSums(int k) { // Use sliding window to get the sum of the k smallest items in all the subarray sums.
        int score = kthScore(k), ans = 0, i = 0;
        for (int j = 0; j < N + 1; ++j) {
            while (B[j] - B[i] > score) ++i;
            ans += B[j] * (j - i + 1) - (C[j] - (i ? C[i - 1] : 0));
        }
        return ans - (countSumUnder(score) - k) * score;
    }
    int kthScore(int k) { // use binary search to find the kth smallest sum in all subarray sums.
        int L = 0, R = B[N];
        while (L < R) {
            int M = (L + R) / 2;
            if (countSumUnder(M) < k) ++L;
            else R = M;
        }
        return L;
    }
public:
    int rangeSum(vector<int>& A, int n, int left, int right) {
        N = n;
        B.assign(N + 1, 0);
        C.assign(N + 1, 0);
        for (int i = 0; i < N; ++i) {
            B[i + 1] = B[i] + A[i];
            C[i + 1] = C[i] + B[i + 1];
        }
        return sumKSums(right) - sumKSums(left - 1);
    }
};
```