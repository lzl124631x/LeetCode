# [2064. Minimized Maximum of Products Distributed to Any Store (Medium)](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/)

<p>You are given an integer <code>n</code> indicating there are <code>n</code> specialty retail stores. There are <code>m</code> product types of varying amounts, which are given as a <strong>0-indexed</strong> integer array <code>quantities</code>, where <code>quantities[i]</code> represents the number of products of the <code>i<sup>th</sup></code> product type.</p>

<p>You need to distribute <strong>all products</strong> to the retail stores following these rules:</p>

<ul>
	<li>A store can only be given <strong>at most one product type</strong> but can be given <strong>any</strong> amount of it.</li>
	<li>After distribution, each store will be given some number of products (possibly <code>0</code>). Let <code>x</code> represent the maximum number of products given to any store. You want <code>x</code> to be as small as possible, i.e., you want to <strong>minimize</strong> the <strong>maximum</strong> number of products that are given to any store.</li>
</ul>

<p>Return <em>the minimum possible</em> <code>x</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 6, quantities = [11,6]
<strong>Output:</strong> 3
<strong>Explanation:</strong> One optimal way is:
- The 11 products of type 0 are distributed to the first four stores in these amounts: 2, 3, 3, 3
- The 6 products of type 1 are distributed to the other two stores in these amounts: 3, 3
The maximum number of products given to any store is max(2, 3, 3, 3, 3, 3) = 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 7, quantities = [15,10,10]
<strong>Output:</strong> 5
<strong>Explanation:</strong> One optimal way is:
- The 15 products of type 0 are distributed to the first three stores in these amounts: 5, 5, 5
- The 10 products of type 1 are distributed to the next two stores in these amounts: 5, 5
- The 10 products of type 2 are distributed to the last two stores in these amounts: 5, 5
The maximum number of products given to any store is max(5, 5, 5, 5, 5, 5, 5) = 5.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 1, quantities = [100000]
<strong>Output:</strong> 100000
<strong>Explanation:</strong> The only optimal way is:
- The 100000 products of type 0 are distributed to the only store.
The maximum number of products given to any store is max(100000) = 100000.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == quantities.length</code></li>
	<li><code>1 &lt;= m &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= quantities[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Similar Questions**:
* [Koko Eating Bananas (Medium)](https://leetcode.com/problems/koko-eating-bananas/)
* [Capacity To Ship Packages Within D Days (Medium)](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)
* [Find the Smallest Divisor Given a Threshold (Medium)](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/)
* [Magnetic Force Between Two Balls (Medium)](https://leetcode.com/problems/magnetic-force-between-two-balls/)
* [Minimum Limit of Balls in a Bag (Medium)](https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/)

## Solution 1. Binary Search

**Intuition**: 
1. Given `k` (the maximum number of products given to any store), we can compute the number of stores we are able to assign in `O(Q)` time where `Q` is the length of `quantities`.
2. `k` is in range `[1, MAX(quantities)]` and this answer range has perfect monotonicity: There must exist a `K` that for every `k >= K`, we can do the assignment with `k`; for every `k < K`, we can't do the assignment because the number of stores are not enough.

So, we can use binary search to find this `K` in `O(Qlog(MAX(quantities)))` time.

```cpp
// OJ: https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/
// Author: github.com/lzl124631x
// Time: O(QlogM) where `Q` is the length of `quantities` and `M` is the max element in `quantities`.
// Space: O(1)
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& Q) {
        long long L = 1, R = accumulate(begin(Q), end(Q), 0LL);
        auto valid = [&](int M) {
            int ans = 0;
            for (int n : Q) ans += (n + M - 1) / M; // ceil(n / M)
            return ans <= n;
        };
        while (L <= R) {
            long long M = (L + R) / 2;
            if (valid(M)) R = M - 1;
            else L = M + 1;
        }
        return L;
    }
};
```

Or use `L < R` template

```cpp
// OJ: https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/
// Author: github.com/lzl124631x
// Time: O(QlogM) where `Q` is the length of `quantities` and `M` is the max element in `quantities`.
// Space: O(1
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& Q) {
        long long L = 1, R = *max_element(begin(Q), end(Q));
        auto valid = [&](int M) {
            int ans = 0;
            for (int n : Q) {
                ans += (n + M - 1) / M;
            }
            return ans <= n;
        };
        while (L < R) {
            long long M = (L + R) / 2;
            if (valid(M)) R = M;
            else L = M + 1;
        }
        return L;
    }
};
```

## Discuss

https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/discuss/1563749/C%2B%2B-Binary-Search