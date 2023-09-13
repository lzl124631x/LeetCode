# [1588. Sum of All Odd Length Subarrays (Easy)](https://leetcode.com/problems/sum-of-all-odd-length-subarrays/)

<p>Given an array of positive integers&nbsp;<code>arr</code>, calculate the sum of all possible odd-length subarrays.</p>

<p>A subarray is a contiguous&nbsp;subsequence of the array.</p>

<p>Return&nbsp;<em>the sum of all odd-length subarrays of&nbsp;</em><code>arr</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [1,4,2,5,3]
<strong>Output:</strong> 58
<strong>Explanation: </strong>The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1,2]
<strong>Output:</strong> 3
<b>Explanation: </b>There are only 2 subarrays of odd length, [1] and [2]. Their sum is 3.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [10,11,12]
<strong>Output:</strong> 66
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 100</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 1000</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(1)
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& A) {
        int ans = 0;
        for (int len = 1; len <= A.size(); len += 2) {
            for (int i = 0; i <= A.size() - len; ++i) {
                for (int j = 0; j < len; ++j) ans += A[i + j];
            }
        }
        return ans;
    }
};
```

## Solution 2. Prefix Sum

```cpp
// OJ: https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& A) {
        vector<int> sum(A.size() + 1);
        partial_sum(begin(A), end(A), begin(sum) + 1);
        int ans = 0;
        for (int len = 1; len <= A.size(); len += 2) {
            for (int i = 0; i <= A.size() - len; ++i) ans += sum[i + len] - sum[i];
        }
        return ans;
    }
};
```

Or 

```cpp
// OJ: https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& A) {
        int ans = 0;
        for (int i = 0; i < A.size(); ++i) {
            int sum = 0;
            for (int j = i; j < A.size(); j += 2) {
                sum += (j > i ? A[j - 1] : 0) + A[j];
                ans += sum;
            }
        }
        return ans;
    }
};
```

## Solution 3. Count contribution of `A[i]`

How many subarrays that contain `A[i]`?

For the left bound, we can pick from `0, 1, 2, ..., i`-th elements, i.e. `i + 1` choices.

For the right bound, we can pick from `i, i + 1, ..., N - 1`-th elements, i.e. `N - i` choices.

So there are in total `k = (i + 1) * (N - i)` subarrays containing `A[i]`.

How many of them are of odd length?

Take `[1, 2, 3]` for example,

Subarrays containing `1`: `[1], [1,2], [1,2,3]`. 2 odd and 1 even.

Subarrays containing `2`: `[2], [1,2], [2,3], [1,2,3]`. 2 odd and 2 even.

Subarrays containing `3`: `[3], [2,3], [1,2,3]`. 2 odd and 1 even.

So the pattern is that the odd count is `ceil(k / 2) = (k + 1) / 2`.

Thus `A[i]` will be counted `((i + 1) * (N - i) + 1) / 2` times.


```cpp
// OJ: https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/sum-of-all-odd-length-subarrays/discuss/854184/JavaC%2B%2BPython-O(N)-Time-O(1)-Space
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& A) {
        int ans = 0, N = A.size();
        for (int i = 0; i < N; ++i) ans += ((i + 1) * (N - i) + 1) / 2 * A[i];
        return ans;
    }
};
```