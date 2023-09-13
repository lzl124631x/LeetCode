# [2233. Maximum Product After K Increments (Medium)](https://leetcode.com/problems/maximum-product-after-k-increments/)

<p>You are given an array of non-negative integers <code>nums</code> and an integer <code>k</code>. In one operation, you may choose <strong>any</strong> element from <code>nums</code> and <strong>increment</strong> it by <code>1</code>.</p>

<p>Return<em> the <strong>maximum</strong> <strong>product</strong> of </em><code>nums</code><em> after <strong>at most</strong> </em><code>k</code><em> operations. </em>Since the answer may be very large, return it <b>modulo</b> <code>10<sup>9</sup> + 7</code>. Note that you should maximize the product before taking the modulo.&nbsp;</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [0,4], k = 5
<strong>Output:</strong> 20
<strong>Explanation:</strong> Increment the first number 5 times.
Now nums = [5, 4], with a product of 5 * 4 = 20.
It can be shown that 20 is maximum product possible, so we return 20.
Note that there may be other ways to increment nums to have the maximum product.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [6,3,3,2], k = 2
<strong>Output:</strong> 216
<strong>Explanation:</strong> Increment the second number 1 time and increment the fourth number 1 time.
Now nums = [6, 4, 3, 3], with a product of 6 * 4 * 3 * 3 = 216.
It can be shown that 216 is maximum product possible, so we return 216.
Note that there may be other ways to increment nums to have the maximum product.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length, k &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>


**Similar Questions**:
* [Minimum Size Subarray Sum (Medium)](https://leetcode.com/problems/minimum-size-subarray-sum/)
* [Minimum Increment to Make Array Unique (Medium)](https://leetcode.com/problems/minimum-increment-to-make-array-unique/)
* [Minimum Operations to Make the Array Increasing (Easy)](https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/)

## Solution 1. Heap

```cpp
// OJ: https://leetcode.com/problems/maximum-product-after-k-increments/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int maximumProduct(vector<int>& A, int k) {
        long mod = 1e9 + 7, ans = 1;
        priority_queue<int, vector<int>, greater<>> pq(begin(A), end(A));
        while (k--) {
            int u = pq.top(), d = 1;
            pq.pop();
            pq.push(u + 1);
        }
        while (pq.size()) {
            ans = ans * pq.top() % mod;
            pq.pop();
        }
        return ans;
    }
};
```

## Solution 2. Binary Search

```cpp
// OJ: https://leetcode.com/problems/maximum-product-after-k-increments/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maximumProduct(vector<int>& A, int k) {
        long mod = 1e9 + 7, ans = 1, L = 0, R = LONG_MAX, r = 0;
        sort(begin(A), end(A));
        while (L <= R) { // After the binary search, R is the maximum number such that if we turn all A[i] < R to R, we take no more than `k` increments
            long M = L + (R - L) / 2, used = 0;
            for (int n : A) {
                used += max(0L, M - n);
                if (used > k) break;
            }
            if (used <= k) {
                L = M + 1;
                r = k - used; // `r` is the remainder increments
            } else R = M - 1;
        }
        for (int n : A) {
            int diff = min((long)k, max(0L, R - n));
            if (r) diff++, r--;
            k -= diff;
            ans = ans * (n + diff) % mod;
        }
        return ans;
    }
};
```

## Solution 3. Greedy

```cpp
// OJ: https://leetcode.com/problems/maximum-product-after-k-increments/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
    void fillK(vector<int> &A, int k) {
        long N = A.size(), sum = 0, i = 0; 
        while (i < N && A[i] * i - sum <= k) sum += A[i++]; // If we bump `A[0]~A[i-1]` to be `A[i]`, we need `A[i] * i - (A[0]+...+A[i-1])` increments which should be no more than `k`
        int h = (sum + k) / i, r = (sum + k) % i;  // We split `sum + k` heights among `A[0]~A[i-1]` `i` elements.
        for (int j = 0; j < i; ++j) {
            A[j] = h; 
            if (j < r) A[j]++;
        }
    }
public:
    int maximumProduct(vector<int>& A, int k) {
        long mod = 1e9 + 7, ans = 1;
        sort(begin(A), end(A));
        fillK(A, k);
        for (int n : A) ans = ans * n % mod;
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/maximum-product-after-k-increments/discuss/1937658