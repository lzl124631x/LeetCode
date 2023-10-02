# [1300. Sum of Mutated Array Closest to Target (Medium)](https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/)

<p>Given an integer array&nbsp;<code>arr</code> and a target value <code>target</code>, return&nbsp;the integer&nbsp;<code>value</code>&nbsp;such that when we change all the integers&nbsp;larger than <code>value</code>&nbsp;in the given array to be equal to&nbsp;<code>value</code>,&nbsp;the sum of the array gets&nbsp;as close as possible (in absolute difference) to&nbsp;<code>target</code>.</p>

<p>In case of a tie, return the minimum such integer.</p>

<p>Notice that the answer is not neccesarilly a number from <code>arr</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [4,9,3], target = 10
<strong>Output:</strong> 3
<strong>Explanation:</strong> When using 3 arr converts to [3, 3, 3] which sums 9 and that's the optimal answer.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [2,3,5], target = 10
<strong>Output:</strong> 5
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [60864,25176,27249,21296,20204], target = 56803
<strong>Output:</strong> 11361
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10^4</code></li>
	<li><code>1 &lt;= arr[i], target &lt;= 10^5</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

## Solution 1. Binary Answer

```cpp
// OJ: https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int findBestValue(vector<int>& A, int target) {
        sort(begin(A), end(A));
        vector<int> sum = A;
        partial_sum(begin(sum), end(sum), begin(sum));
        int N = A.size(), L = 0, R = A.back(), minDiff = INT_MAX, ans = R;
        while (L <= R) {
            int M = (L + R) / 2;
            int i = lower_bound(begin(A), end(A), M) - begin(A);
            int total = (i - 1 >= 0 ? sum[i - 1] : 0) + (N - i) * M;
            int diff = abs(total - target);
            if (diff <= minDiff) {
                if (diff < minDiff) ans = M;
                else ans = min(ans, M);
                minDiff = diff;
            }
            if (total >= target) R = M - 1;
            else L = M + 1;
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
// Ref: https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/discuss/463306/JavaC%2B%2BPython-Just-Sort-O(nlogn) 
class Solution {
public:
    int findBestValue(vector<int>& A, int target) {
        sort(begin(A), end(A));
        int N = A.size(), i = 0;
        while (i < N && target > A[i] * (N - i)) target -= A[i++];
        return i == N ? A[N - 1] : round((target - 0.0001) / (N - i));
    }
};
```

## Solution 3. 

https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/discuss/463268/JavaC%2B%2B-4ms-binary-search-short-readable-code-%2B-sorting-solution