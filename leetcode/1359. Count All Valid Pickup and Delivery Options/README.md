# [1359. Count All Valid Pickup and Delivery Options (Hard)](https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options)

<p>Given <code>n</code> orders, each order consist in pickup and delivery services.&nbsp;</p>
<p>Count all valid pickup/delivery possible sequences such that delivery(i) is always after of&nbsp;pickup(i).&nbsp;</p>
<p>Since the answer&nbsp;may be too large,&nbsp;return it modulo&nbsp;10^9 + 7.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> 1
<strong>Explanation:</strong> Unique order (P1, D1), Delivery 1 always is after of Pickup 1.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> 6
<strong>Explanation:</strong> All possible orders: 
(P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and (P2,D2,P1,D1).
This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> n = 3
<strong>Output:</strong> 90
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= n &lt;= 500</code></li>
</ul>

**Companies**:
[DoorDash](https://leetcode.com/company/doordash), [Apple](https://leetcode.com/company/apple), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Combinatorics](https://leetcode.com/tag/combinatorics/)

## Solution 1.

Let `f(n)` be the answer.

It's trivial that `f(1) = 1`

For `n = 2`, the single arrangement of `f(1)` gives us `3` spots to put `P2`.

* If `P2` is put at the first spot, `D2` has `3` spots to be put.
* If `P2` is put at the 2nd spot, `D2` has `2` spots to be put.
* If `P2` is put at the 3rd spot, `D2` has `1` spot to be put.

So `f(2) = 3 + 2 + 1 = 6` or `f(2) = (1 + N) * N / 2 * f(1)` where `N = 3 = 2 * 2 - 1`.

By induction, we have `f(n) = f(n - 1) * (1 + N) * N / 2` where `N = 2n - 1`

```cpp
// OJ: https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countOrders(int n) {
        long ans = 1, mod = 1e9 + 7;
        for (int i = 2, cnt = 3; i <= n; ++i, cnt += 2) {
            ans = ans * cnt * (cnt + 1) / 2 % mod;
        }
        return ans;
    }
};
```