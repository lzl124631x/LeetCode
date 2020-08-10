# [1539. Kth Missing Positive Number (Easy)](https://leetcode.com/problems/kth-missing-positive-number/)

<p>Given an array <code>arr</code>&nbsp;of positive integers&nbsp;sorted in a <strong>strictly increasing order</strong>, and an integer <code><font face="monospace">k</font></code>.</p>

<p><em>Find the </em><font face="monospace"><code>k<sup>th</sup></code></font><em>&nbsp;positive integer that is missing from this array.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [2,3,4,7,11], k = 5
<strong>Output:</strong> 9
<strong>Explanation: </strong>The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5<sup>th</sup>&nbsp;missing positive integer is 9.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1,2,3,4], k = 2
<strong>Output:</strong> 6
<strong>Explanation: </strong>The missing positive integers are [5,6,7,...]. The 2<sup>nd</sup> missing positive integer is 6.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 1000</code></li>
	<li><code>1 &lt;= k &lt;= 1000</code></li>
	<li><code>arr[i] &lt; arr[j]</code> for <code>1 &lt;= i &lt; j &lt;= arr.length</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/kth-missing-positive-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findKthPositive(vector<int>& A, int k) {
        for (int i = 1, j = 0; i <= 2000; ++i) {
            if (j < A.size() && A[j] == i) ++j;
            else if (--k == 0) return i;
        }
        return -1;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/kth-missing-positive-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findKthPositive(vector<int>& A, int k) {
        for (int i = 1, j = 0; i <= 1000; ++i) {
            if (j < A.size() && A[j] == i) ++j;
            else if (--k == 0) return i;
        }
        return 1000 + k;
    }
};
```

## Solution 2.

For the first `i` numbers in `A`, the count of missing numbers in these `i` numbers is `A[i-1] - i`.

Example:

```
A=[1,4,5,8]
i=3
A[i-1]-i = 5-3 = 2 // There are two missing numbers in [1,4,5]
```

We can binary search the maximum `i` which satisfies `A[i-1] - i < k`. Assume it's `L`, then `L + k` is the answer. It's because adding `L`(the count of existing numbers) to `k` (the index of the target missing number) will get the answer (the value of the target missing number).

Example, 

```
A=[1,4,5,8]
k=4
L=3
```

so `[1,4,5]` is the range we are looking for -- it has 2 missing numbers and 3 existing numbers. Since we are looking for the 4th missing number, the value should be `3 (count of existing number) + 4 (index of target) = 7 (value of target)`

A special case of `i` is when `i == 0`, then there is `0` missing number in this empty subarray. This is a valid case because for example `A=[2], k=1`, the maximum number of `i` which satisfies `count of missing number < k` is `0`.

So the range of the binary search should be `[0, N]`.

So initially let `L = 0, R = N`, and `M` be the middle value. To avoid infinite loop, let `M = (L + R + 1) / 2`.

When count of missing number is less then `k`, `M` might be too small or exactly the index we are looing for, we let `L = M`.

Otherwise, `M` is too large, let `R = M - 1`.

```cpp
// OJ: https://leetcode.com/problems/kth-missing-positive-number/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
// Ref: https://leetcode.com/problems/kth-missing-positive-number/discuss/779999/JavaC%2B%2BPython-O(logN)
class Solution {
public:
    int findKthPositive(vector<int>& A, int k) {
        int L = 0, R = A.size();
        while (L < R) {
            int M = (L + R + 1) / 2;
            if (M == 0 || A[M - 1] - M < k) L = M;
            else R = M - 1;
        }
        return L + K;
    }
};
```

Or another more concise version.

Now we want to find the smallest index `i` which satisfies `A[i] > k + i`. Assume `L` is such a number, then the answer is `L + k`.

Example:

```
A=[1,4,5,8]
k=3
The smallest index i which satisfies `A[i] > k + i` is 3, so the answer is 3 + k = 6.
```

```cpp
// OJ: https://leetcode.com/problems/kth-missing-positive-number/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
// Ref: https://leetcode.com/problems/kth-missing-positive-number/discuss/779999/JavaC%2B%2BPython-O(logN)
class Solution {
public:
    int findKthPositive(vector<int>& A, int k) {
        int L = 0, R = A.size();
        while (L < R) {
            int M = (L + R) / 2;
            if (A[M] <= k + M) L = M + 1;
            else R = M;
        }
        return L + k;
    }
};
```

Or 

```cpp
// OJ: https://leetcode.com/problems/kth-missing-positive-number/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int findKthPositive(vector<int>& A, int k) {
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] - M - 1 < k) L = M + 1;
            else R = M - 1;
        }
        return L + k;
    }
};
```