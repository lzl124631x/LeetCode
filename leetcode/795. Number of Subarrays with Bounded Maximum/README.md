# [795. Number of Subarrays with Bounded Maximum (Medium)](https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/)

<p>We are given an array <code>A</code> of positive integers, and two positive integers <code>L</code> and <code>R</code> (<code>L &lt;= R</code>).</p>

<p>Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element in that subarray is at least <code>L</code> and at most <code>R</code>.</p>

<pre><strong>Example :</strong>
<strong>Input:</strong> 
A = [2, 1, 4, 3]
L = 2
R = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are three subarrays that meet the requirements: [2], [2, 1], [3].
</pre>

<p><strong>Note:</strong></p>

<ul>
	<li>L, R&nbsp; and <code>A[i]</code> will be an integer in the range <code>[0, 10^9]</code>.</li>
	<li>The length of <code>A</code> will be in the range of <code>[1, 50000]</code>.</li>
</ul>


**Companies**:  
[Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

Let's pretend each element is either `0` if it is less than `L`; `1` if it is between `L` and `R`; or `2` if it is greater than `R`.

Since the subarray cannot contain `2`, so we look for this pattern.

```
2 0 0 1 0 1 0 2
```

That is, a subarray surrounded by `2`. We look within this subsequence.

There can be multiple `1`s in the subarray. Now the question is: count subarrays that contain at least one `1`.

In this solution, I choosed to look at the `1`s one by one.

For the first `1`:
```
       v
2) 0 0 1 0 1 0 (2
```

There are `2` zeros to its left, and `3` zero/ones to its right. So the count of subarray containing this `1` is `(2 + 1) * (3 + 1) = 12`. 

Then for the next `1`:
```
       x   v
2) 0 0 1 0 1 0 (2
```
To prevent recount the subarrays containing the first `1`, we only look at the zeros to its left, and the count of which is `1`. And there are `1` zero/ones to its right. So the count of subarray containing this second `1` but not the first `1` is `(1 + 1) * (1 + 1) = 2`.

So the answer should be `12 + 2 = 14`.


```cpp
// OJ: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int N = A.size(), begin = 0, maxVal = INT_MIN, cnt = 0;
        while (begin < N) {
            int end = begin;
            while (end < N && A[end] <= R) {
                maxVal = max(maxVal, A[end++]);
            }
            if (maxVal >= L) {
                while (true) {
                    int i = begin;
                    while (i < end && A[i] < L) ++i;
                    if (i == end) break;
                    cnt += (i - begin + 1) * (end - i);
                    begin = i + 1;
                }
            }
            begin = end + 1;
        }
        return cnt;
    }
};
```