# [2226. Maximum Candies Allocated to K Children (Medium)](https://leetcode.com/problems/maximum-candies-allocated-to-k-children/)

<p>You are given a <strong>0-indexed</strong> integer array <code>candies</code>. Each element in the array denotes a pile of candies of size <code>candies[i]</code>. You can divide each pile into any number of <strong>sub piles</strong>, but you <strong>cannot</strong> merge two piles together.</p>

<p>You are also given an integer <code>k</code>. You should allocate piles of candies to <code>k</code> children such that each child gets the <strong>same</strong> number of candies. Each child can take <strong>at most one</strong> pile of candies and some piles of candies may go unused.</p>

<p>Return <em>the <strong>maximum number of candies</strong> each child can get.</em></p>
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> candies = [5,8,6], k = 3
<strong>Output:</strong> 5
<strong>Explanation:</strong> We can divide candies[1] into 2 piles of size 5 and 3, and candies[2] into 2 piles of size 5 and 1. We now have five piles of candies of sizes 5, 5, 3, 5, and 1. We can allocate the 3 piles of size 5 to 3 children. It can be proven that each child cannot receive more than 5 candies.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> candies = [2,5], k = 11
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are 11 children but only 7 candies in total, so it is impossible to ensure each child receives at least one candy. Thus, each child gets no candy and the answer is 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= candies.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= candies[i] &lt;= 10<sup>7</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>12</sup></code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Koko Eating Bananas (Medium)](https://leetcode.com/problems/koko-eating-bananas/)
* [Minimum Limit of Balls in a Bag (Medium)](https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/)
* [Minimum Speed to Arrive on Time (Medium)](https://leetcode.com/problems/minimum-speed-to-arrive-on-time/)
* [Maximum Number of Removable Characters (Medium)](https://leetcode.com/problems/maximum-number-of-removable-characters/)
* [Minimized Maximum of Products Distributed to Any Store (Medium)](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/)
* [Minimum Time to Complete Trips (Medium)](https://leetcode.com/problems/minimum-time-to-complete-trips/)

## Solution 1. Binary Answer

Binary search in range `L = 1, R = max(A)`.

For a given `M = (L + R) / 2`, we test if we can give `M` candies to each child, which can be done by traversing the array once, taking `O(N)` time. 

If possible/valid, we make `L = M + 1`; otherwise, we make `R = M - 1`.

In the end, since we are looking for the greatest valid number, we return `R`.

```cpp
// OJ: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
// Author: github.com/lzl124631x
// Time: O(Nlog(sum(A)))
// Space: O(1)
class Solution {
public:
    int maximumCandies(vector<int>& A, long long k) {
        long L = 1, R = *max_element(begin(A), end(A)), N = A.size();
        auto valid = [&](long m) {
            long cnt = 0;
            for (int n : A) {
                cnt += n / m;
                if (cnt >= k) return true;
            }
            return false;
        };
        while (L <= R) {
            long M = L + (R - L) / 2;
            if (valid(M)) L = M + 1;
            else R = M - 1;
        }
        return R;
    }
};
```

## Discuss

https://leetcode.com/problems/maximum-candies-allocated-to-k-children/discuss/1908820