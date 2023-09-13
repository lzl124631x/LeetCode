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

## Solution 1. Brute Force

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

## Solution 2. Binary Search

For the first `i + 1` numbers in `A`, the count of missing numbers in these `i + 1` numbers is `miss(i) = A[i] - i - 1`.

Example:

```
A=[1,4,5,8]
i=2
miss(2) = A[2] - 2 - 1 = 2 // There are two missing numbers in [1,4,5].
```

We can binary search the greatest index `i` which satisfies `miss(i) < k`. Assume it's `x`, then `x + k + 1` is the answer. It's because adding `x + 1`(the count of existing numbers) to `k` (the index of the target missing number) will get the answer (the value of the target missing number).

Example, 

```
A=[1,4,5,8]
k=4
For i = 2, miss(2) = 2 < k
For i = 3, miss(3) = 4 >= k
So x = 2
The answer is x + k + 1 = 7 
```

The range of the index to search is `[0, N - 1]`. When `miss(M) < k`, `L = M + 1`; otherwise, `R = M - 1`.

Then in the end, `R` will be the `x`, i.e. the greatest index that `miss(R) < k`. So the answer is `R + k + 1`, or `L + k`.

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