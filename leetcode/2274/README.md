# [2274. Maximum Consecutive Floors Without Special Floors (Medium)](https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors)

<p>Alice manages a company and has rented some floors of a building as office space. Alice has decided some of these floors should be <strong>special floors</strong>, used for relaxation only.</p>

<p>You are given two integers <code>bottom</code> and <code>top</code>, which denote that Alice has rented all the floors from <code>bottom</code> to <code>top</code> (<strong>inclusive</strong>). You are also given the integer array <code>special</code>, where <code>special[i]</code> denotes a special floor that Alice has designated for relaxation.</p>

<p>Return <em>the <strong>maximum</strong> number of consecutive floors without a special floor</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> bottom = 2, top = 9, special = [4,6]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The following are the ranges (inclusive) of consecutive floors without a special floor:
- (2, 3) with a total amount of 2 floors.
- (5, 5) with a total amount of 1 floor.
- (7, 9) with a total amount of 3 floors.
Therefore, we return the maximum number which is 3 floors.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> bottom = 6, top = 8, special = [7,6,8]
<strong>Output:</strong> 0
<strong>Explanation:</strong> Every floor rented is a special floor, so we return 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= special.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= bottom &lt;= special[i] &lt;= top &lt;= 10<sup>9</sup></code></li>
	<li>All the values of <code>special</code> are <strong>unique</strong>.</li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Sorting](https://leetcode.com/tag/sorting)

**Similar Questions**:
* [Longest Consecutive Sequence (Medium)](https://leetcode.com/problems/longest-consecutive-sequence)
* [Maximum Gap (Hard)](https://leetcode.com/problems/maximum-gap)

**Hints**:
* Say we have a pair of special floors (x, y) with no other special floors in between. There are x - y - 1 consecutive floors in between them without a special floor.
* Say there are n special floors. After sorting special, we have answer = max(answer, special[i] – special[i – 1] – 1) for all 0 < i ≤ n.
* However, there are two special cases left to consider: the floors before special[0] and after special[n-1].
* To consider these cases, we have answer = max(answer, special[0] – bottom, top – special[n-1]).

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& A) {
        sort(begin(A), end(A));
        int prev = bottom, ans = 0;
        for (int n : A) {
            ans = max(ans, n - prev);
            prev = n + 1;
        }
        return max(ans, top - prev + 1);
    }
};
```