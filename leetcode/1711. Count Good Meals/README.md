# [1711. Count Good Meals (Medium)](https://leetcode.com/problems/count-good-meals/)

<p>A <strong>good meal</strong> is a meal that contains <strong>exactly two different food items</strong> with a sum of deliciousness equal to a power of two.</p>

<p>You can pick <strong>any</strong> two different foods to make a good meal.</p>

<p>Given an array of integers <code>deliciousness</code> where <code>deliciousness[i]</code> is the deliciousness of the <code>i<sup>​​​​​​th</sup>​​​​</code>​​​​ item of food, return <em>the number of different <strong>good meals</strong> you can make from this list modulo</em> <code>10<sup>9</sup> + 7</code>.</p>

<p>Note that items with different indices are considered different even if they have the same deliciousness value.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> deliciousness = [1,3,5,7,9]
<strong>Output:</strong> 4
<strong>Explanation: </strong>The good meals are (1,3), (1,7), (3,5) and, (7,9).
Their respective sums are 4, 8, 8, and 16, all of which are powers of 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> deliciousness = [1,1,1,3,3,3,7]
<strong>Output:</strong> 15
<strong>Explanation: </strong>The good meals are (1,1) with 3 ways, (1,3) with 9 ways, and (1,7) with 3 ways.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= deliciousness.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= deliciousness[i] &lt;= 2<sup>20</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)
* [Max Number of K-Sum Pairs (Medium)](https://leetcode.com/problems/max-number-of-k-sum-pairs/)

## Solution 1.

Use an `unordered_map<int, int> m` to store the frequency of each number in array `A` (i.e. `m[a]` is the frequency of `a`).

Since `A[i]` is in range `[0, 2^20]`, the sum of two numbers is in range `[0, 2^21]`. 

For each pair `a, cnt` in `m`, we try to find if `b = sum - a` is in `m` as well, where `sum` is power of `2`.

To avoid repetitive computation, we skip a `b` value if `b < a`.

If `a == b`, add `cnt * (cnt - 1) / 2` to answer.

Otherwise, add `cnt * m[b]` to answer.

```cpp
// OJ: https://leetcode.com/problems/count-good-meals/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int countPairs(vector<int>& A) {
        long mod = 1e9 + 7, ans = 0;
        unordered_map<int, int> m;
        for (int n : A) m[n]++;
        for (auto &[a, cnt] : m) {
            for (int i = 0; i <= 21; ++i) {
                long b = (1 << i) - a;
                if (b < a || m.count(b) == 0) continue;
                long c = m[b];
                if (a == b) ans = (ans + (c * (c - 1) / 2) % mod) % mod;
                else ans = (ans + cnt * c % mod) % mod; 
            }
        }
        return ans;
    }
};
```