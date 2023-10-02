# [907. Sum of Subarray Minimums (Medium)](https://leetcode.com/problems/sum-of-subarray-minimums/)

<p>Given an array of integers arr, find the sum of <code>min(b)</code>, where <code>b</code> ranges over every (contiguous) subarray of <code>arr</code>. Since the answer may be large, return the answer <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [3,1,2,4]
<strong>Output:</strong> 17
<strong>Explanation:</strong> 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [11,81,94,43,3]
<strong>Output:</strong> 444
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= arr[i] &lt;= 3 * 10<sup>4</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Stack](https://leetcode.com/tag/stack/)

## Solution 1. Monotonic Stack

Think from simple case to complex case.

If there is only one number, say `A = [1]`, the answer is `A[0] = 1`.

If there are two numbers, can we reuse the previous results?

Assume based on `A = [1]`, we add a number `2`. This new number will create two new subarrays, `[1,2]` and `[2]`. The min value of `[2]` is trivial. For min value of `[1,2]`, we can reuse the result we got when `A = [1]`.

Now assume based on `A = [1]`, we add a number `0`. This new number will create two new subarrays, `[1,0]` and `[0]`. For `[1,0]`, the min value becomes `0`. And if we keep adding more numbers, this leading `1` will no longer be added because of this smaller `0`.

Here we can see that we need a monotonic stack of keep track of the small numbers in ascending order. For example, if `A = [100,1,100,2,100,3,100]`, the stack should be `[1,2,3,100]`. 

Consider array `A = [2,3,4,3,0]`

For `A[0] = 2`, we push `2` into stack and add `2` to answer.

For `A[1] = 3`, we push `3` into stack and add `2+3` to answer.

For `A[2] = 4`, we push `4` into stack and add `2+3+4` to answer.

For `A[3] = 3`, we pop `4` from stack

```cpp
// OJ: https://leetcode.com/problems/sum-of-subarray-minimums/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        stack<int> q; // index
        q.push(-1);
        long N = A.size(), ans = 0, sum = 0, mod = 1e9+7;
        for (int i = 0; i < N; ++i) {
            sum = (sum + A[i]) % mod;
            while (q.top() != -1 && A[q.top()] >= A[i]) {
                int j = q.top();
                q.pop();
                int c = j - q.top();
                sum = (sum + c * (A[i] - A[j]) % mod) % mod;
            }
            q.push(i);
            ans = (ans + sum) % mod;
        }
        return ans;
    }
};
```

## Solution 2. Previous LessEqual and Next LessThan

For a given `A[i]`, how many subarrays have this `A[i]` as the minimum value?

The first intuition is that we can find the previous and next LessThan value.

Example: 

```
 0  1  2  3  4  5  6  7
[1, 3, 4, 3, 2, 4, 3, 0]
```

For `A[4] = 2`:
* the previous LessThan value is `A[0] = 1` so the left bound of the subarrays must be `0 < lb <= 4` (i.e. 4 candidate values).
* the next LessThan value is `A[7] = 0`, so the right bound of the subarrays must be `4 <= rb < 7` (i.e. 3 candidate values).

Since the left/right bound has 4/3 candidate values, `A[4] = 2` appears as the minimum value of `4 * 3 = 12` subarrays.

Now **consider duplicates**.

For `A[3] = 3`. If we still use LessThan values, `A[1]` and `A[3]` will be counted twice in subarray `A[1..3] = [3, 4, 3]` because they share the same left/right bound.

To prevent counting duplicate values twice, we can limit left or right side to never go beyong the same values. For example, we find the previous LessEqual value instead.


```cpp
// OJ: https://leetcode.com/problems/sum-of-subarray-minimums/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        long N = A.size(), ans = 0, mod = 1e9 + 7;
        vector<int> prevLE(N, -1), nextLT(N, N);
        stack<int> s;
        for (int i = 0; i < N; ++i) {
            while (s.size() && A[s.top()] > A[i]) {
                nextLT[s.top()] = i;
                s.pop();
            }
            if (s.size()) prevLE[i] = s.top();
            s.push(i);
        }
        for (int i = 0; i < N; ++i) ans = (ans + (i - prevLE[i]) * (nextLT[i] - i) % mod * A[i] % mod) % mod;
        return ans;
    }
};
```

## TODO

https://leetcode.com/problems/sum-of-subarray-minimums/discuss/178876/stack-solution-with-very-detailed-explanation-step-by-step

https://leetcode.com/problems/sum-of-subarray-minimums/discuss/170750/C++JavaPython-Stack-Solution