# [2907. Maximum Profitable Triplets With Increasing Prices I (Medium)](https://leetcode.com/problems/maximum-profitable-triplets-with-increasing-prices-i)

<p>Given the <strong>0-indexed</strong> arrays <code>prices</code> and <code>profits</code> of length <code>n</code>. There are <code>n</code> items in an store where the <code>i<sup>th</sup></code> item has a price of <code>prices[i]</code> and a profit of <code>profits[i]</code>.</p>

<p>We have to pick three items with the following condition:</p>

<ul>
	<li><code>prices[i] &lt; prices[j] &lt; prices[k]</code> where <code>i &lt; j &lt; k</code>.</li>
</ul>

<p>If we pick items with indices <code>i</code>, <code>j</code> and <code>k</code> satisfying the above condition, the profit would be <code>profits[i] + profits[j] + profits[k]</code>.</p>

<p>Return<em> the <strong>maximum profit</strong> we can get, and </em><code>-1</code><em> if it&#39;s not possible to pick three items with the given condition.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> prices = [10,2,3,4], profits = [100,2,7,10]
<strong>Output:</strong> 19
<strong>Explanation:</strong> We can&#39;t pick the item with index i=0 since there are no indices j and k such that the condition holds.
So the only triplet we can pick, are the items with indices 1, 2 and 3 and it&#39;s a valid pick since prices[1] &lt; prices[2] &lt; prices[3].
The answer would be sum of their profits which is 2 + 7 + 10 = 19.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> prices = [1,2,3,4,5], profits = [1,5,3,4,6]
<strong>Output:</strong> 15
<strong>Explanation:</strong> We can select any triplet of items since for each triplet of indices i, j and k such that i &lt; j &lt; k, the condition holds.
Therefore the maximum profit we can get would be the 3 most profitable items which are indices 1, 3 and 4.
The answer would be sum of their profits which is 5 + 4 + 6 = 15.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> prices = [4,3,2,1], profits = [33,20,19,87]
<strong>Output:</strong> -1
<strong>Explanation:</strong> We can&#39;t select any triplet of indices such that the condition holds, so we return -1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= prices.length == profits.length &lt;= 2000</code></li>
	<li><code>1 &lt;= prices[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= profits[i] &lt;= 10<sup>6</sup></code></li>
</ul>


**Companies**:
[IBM](https://leetcode.com/company/ibm)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming)

**Hints**:
* Let's fix the middle chosen item.
* For a fixed item with an index <code>j</code>, iterate over items with an index <code>k > j</code> such that <code>prices[k] > prices[j]</code>.
* Find the maximum <code>profit[k]</code> with the above condition. Let's call this maximum value <code>max_right</code>.
* Do the same for items with an index <code>i < j</code> such that <code>prices[i] < prices[j]</code> and find the maximum <code>profit[i]</code> among them. Let's call this maximum value <code>max_left</code>.
* Now the profit when an item with the index <code>j</code> is the middle one would be <code>profit[j] + max_right + max_left</code>.
* Finally, do the above procedure for all <code>j</code>'s and find the maximum profit among them. That would be the final answer.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-profitable-triplets-with-increasing-prices-i
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& A, vector<int>& B) {
        int N = A.size(), ans = -1;
        for (int i = 1; i < N - 1; ++i) {
            int left = 0, right = 0;
            for (int j = 0; j < N; ++j) {
                if (j < i) {
                    if (A[j] < A[i]) left = max(left, B[j]);
                } else if (j > i) {
                    if (A[j] > A[i]) right = max(right, B[j]);
                }
            }
            if (left && right) ans = max(ans, left + right + B[i]);
        }
        return ans;
    }
};
```

## Solution 2. Monotonic Map

```cpp
// OJ: https://leetcode.com/problems/maximum-profitable-triplets-with-increasing-prices-i
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
// Ref: https://leetcode.com/problems/maximum-profitable-triplets-with-increasing-prices-i/solutions/4183514/just-binary-search-map-lower-bound-upper-bound/
class Solution {
    void insert(map<int, int> &m, int price, int profit) {
        auto it = m.upper_bound(price);
        if (it != m.begin() && prev(it)->second >= profit) return;
        for (it = m.lower_bound(price); it != m.end() && it->second <= profit; m.erase(it++));
        m[price] = profit;
    }
public:
    int maxProfit(vector<int>& A, vector<int>& B) {
        int N = A.size(), ans = -1;
        map<int, int> one, two;
        for (int i = 0; i < N; ++i) {
            auto it = two.lower_bound(A[i]);
            if (it != two.begin()) ans = max(ans, prev(it)->second + B[i]);
            it = one.lower_bound(A[i]);
            if (it != one.begin()) insert(two, A[i], prev(it)->second + B[i]);
            insert(one, A[i], B[i]);
        }
        return ans;
    }
};
```