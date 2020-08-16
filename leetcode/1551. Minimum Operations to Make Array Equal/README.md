# [1551. Minimum Operations to Make Array Equal (Medium)](https://leetcode.com/problems/minimum-operations-to-make-array-equal/)

<p>You have an array <code>arr</code> of length <code>n</code> where <code>arr[i] = (2 * i) + 1</code> for all valid values of <code>i</code> (i.e. <code>0 &lt;= i &lt; n</code>).</p>

<p>In one operation, you can select two indices <code>x</code>&nbsp;and <code>y</code> where <code>0 &lt;= x, y &lt; n</code> and subtract <code>1</code> from <code>arr[x]</code> and add <code>1</code> to <code>arr[y]</code>&nbsp;(i.e. perform <code>arr[x] -=1&nbsp;</code>and <code>arr[y] += 1</code>).&nbsp;The goal is to make all the elements of the array <strong>equal</strong>. It is <strong>guaranteed</strong> that all the elements of the array can be made equal using some operations.</p>

<p>Given an integer <code>n</code>, the length of the array. Return <em>the minimum number of operations</em> needed to make&nbsp;all the elements of arr equal.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong> arr = [1, 3, 5]
First operation choose x = 2 and y = 0, this leads arr to be [2, 3, 4]
In the second operation choose x = 2 and y = 0 again, thus arr = [3, 3, 3].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 6
<strong>Output:</strong> 9
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^4</code></li>
</ul>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-operations-to-make-array-equal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            int a = 2 * i + 1, b = 2 * j + 1;
            ans += (b - a) / 2;
        }
        return ans;
    }
};
```

We can simplify the code by removing constants.

```cpp
// OJ: https://leetcode.com/problems/minimum-operations-to-make-array-equal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        for (int i = 0, j = n - 1; i < j; ++i, --j) ans += j - i;
        return ans;
    }
};
```

## Solution 2.

Consider `[1,3,5,7,9]`. The difference between `1` and `9` is `8`, between `3`, `7` is `4`. The answer is the sum of these differences divided by 2.

The largest difference is `2 * (n - 1) + 1` minus `2 * 0 + 1` which equals `2 * (n - 1)`. The differences form a algorithmetic sequence whose constant difference is `4`. So given the maximum value of the sequence is `mx = 2 * (n - 1)`, there are `len = (mx + 3) / 4` items in the sequence.

So the sum is `(mx + (mx - (len - 1) * 4)) * len / 2`, and the answer is `(2 * mx - (len - 1) * 4) * len / 4`.

```cpp
// OJ: https://leetcode.com/problems/minimum-operations-to-make-array-equal/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int minOperations(int n) {
        int mx = 2 * (n - 1), len = (mx + 3) / 4;
        return (2 * mx - (len - 1) * 4) * len  / 4;
    }
};
```

## Solution 3.

`n` is the mean. The answer is `sum( n - 2 * i - 1 | 0 <= i < n / 2 )`.

`sum ( n - 1 | 0 <= i < n / 2 ) = (n - 1) * floor(n / 2)`. 

`sum ( 2 * i | 0 <= i < n / 2 ) = (0 + 2 * (floor(n / 2) - 1)) * floor(n / 2) / 2 = (floor(n / 2) - 1) * floor(n / 2)`

Let `floor(n / 2) = k`, then the total is `(n - 1) * k - (k - 1) * k = (n - k) * k`.

So we can do

```cpp
return (n - n / 2) * (n / 2);
```

Since `n - floor(n / 2)` is `ceil(n / 2)`, so the answer is also `ceil(n / 2) * floor(n / 2)`. We can also do

```cpp
return (n + 1) / 2 * (n / 2);
```

If `n` is even, then `ceil(n/2) * floor(n/2) = n^2 /2`.

If `n` is odd, then `ceil(n/2) * floor(n/2) = (n + 1) / 2 * (n - 1) / 2 = (n^2-1) / 4 = floor(n^2 / 4)`.

So in sum, we can do

```cpp
return n * n / 4;
```

```cpp
// OJ: https://leetcode.com/problems/minimum-operations-to-make-array-equal/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
// Ref: https://leetcode.com/problems/minimum-operations-to-make-array-equal/discuss/794229/C%2B%2B-1-liner-O(1)-solution-(return-n*n4)-beats-100-with-detailed-explanation
class Solution {
public:
    int minOperations(int n) {
        return n * n / 4;
    }
};
```