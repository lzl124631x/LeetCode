# [1561. Maximum Number of Coins You Can Get (Medium)](https://leetcode.com/problems/maximum-number-of-coins-you-can-get)

<p>There are <code>3n</code> piles of coins of varying size, you and your friends will take piles of coins as follows:</p>

<ul>
	<li>In each step, you will choose <strong>any </strong><code>3</code> piles of coins (not necessarily consecutive).</li>
	<li>Of your choice, Alice will pick the pile with the maximum number of coins.</li>
	<li>You will pick the next pile with the maximum number of coins.</li>
	<li>Your friend Bob will pick the last pile.</li>
	<li>Repeat until there are no more piles of coins.</li>
</ul>

<p>Given an array of integers <code>piles</code> where <code>piles[i]</code> is the number of coins in the <code>i<sup>th</sup></code> pile.</p>

<p>Return the maximum number of coins that you can have.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> piles = [2,4,1,2,7,8]
<strong>Output:</strong> 9
<strong>Explanation: </strong>Choose the triplet (2, 7, 8), Alice Pick the pile with 8 coins, you the pile with <strong>7</strong> coins and Bob the last one.
Choose the triplet (1, 2, 4), Alice Pick the pile with 4 coins, you the pile with <strong>2</strong> coins and Bob the last one.
The maximum number of coins which you can have are: 7 + 2 = 9.
On the other hand if we choose this arrangement (1, <strong>2</strong>, 8), (2, <strong>4</strong>, 7) you only get 2 + 4 = 6 coins which is not optimal.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> piles = [2,4,5]
<strong>Output:</strong> 4
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> piles = [9,8,7,6,5,1,2,3,4]
<strong>Output:</strong> 18
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= piles.length &lt;= 10<sup>5</sup></code></li>
	<li><code>piles.length % 3 == 0</code></li>
	<li><code>1 &lt;= piles[i] &lt;= 10<sup>4</sup></code></li>
</ul>


**Companies**:
[Cleartrip](https://leetcode.com/company/cleartrip), [Flipkart](https://leetcode.com/company/flipkart), [Dunzo](https://leetcode.com/company/dunzo)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Math](https://leetcode.com/tag/math), [Greedy](https://leetcode.com/tag/greedy), [Sorting](https://leetcode.com/tag/sorting), [Game Theory](https://leetcode.com/tag/game-theory)

**Hints**:
* Which pile of coins will you never be able to pick up?
* Bob is forced to take the last pile of coins, no matter what it is. Which pile should you give to him?

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maxCoins(vector<int>& A) {
        sort(begin(A), end(A));
        int ans = 0;
        for (int i = 0, j = A.size() - 1; i < j; ++i, j -= 2) ans += A[j - 1];
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maxCoins(vector<int>& A) {
        sort(begin(A), end(A));
        int N = A.size(), ans = 0;
        for (int i = N / 3; i < N; i += 2) ans += A[i];
        return ans;
    }
};
```