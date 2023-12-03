# [2952. Minimum Number of Coins to be Added (Medium)](https://leetcode.com/problems/minimum-number-of-coins-to-be-added)

<p>You are given a <strong>0-indexed</strong> integer array <code>coins</code>, representing the values of the coins available, and an integer <code>target</code>.</p>

<p>An integer <code>x</code> is <strong>obtainable</strong> if there exists a subsequence of <code>coins</code> that sums to <code>x</code>.</p>

<p>Return <em>the<strong> minimum</strong> number of coins <strong>of any value</strong> that need to be added to the array so that every integer in the range</em> <code>[1, target]</code><em> is <strong>obtainable</strong></em>.</p>

<p>A <strong>subsequence</strong> of an array is a new <strong>non-empty</strong> array that is formed from the original array by deleting some (<strong>possibly none</strong>) of the elements without disturbing the relative positions of the remaining elements.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> coins = [1,4,10], target = 19
<strong>Output:</strong> 2
<strong>Explanation:</strong> We need to add coins 2 and 8. The resulting array will be [1,2,4,8,10].
It can be shown that all integers from 1 to 19 are obtainable from the resulting array, and that 2 is the minimum number of coins that need to be added to the array. 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> coins = [1,4,10,5,7,19], target = 19
<strong>Output:</strong> 1
<strong>Explanation:</strong> We only need to add the coin 2. The resulting array will be [1,2,4,5,7,10,19].
It can be shown that all integers from 1 to 19 are obtainable from the resulting array, and that 1 is the minimum number of coins that need to be added to the array. 
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> coins = [1,1,1], target = 20
<strong>Output:</strong> 3
<strong>Explanation:</strong> We need to add coins 4, 8, and 16. The resulting array will be [1,1,1,4,8,16].
It can be shown that all integers from 1 to 20 are obtainable from the resulting array, and that 3 is the minimum number of coins that need to be added to the array.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= target &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= coins.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= coins[i] &lt;= target</code></li>
</ul>


**Similar Questions**:
* [Coin Change (Medium)](https://leetcode.com/problems/coin-change)

**Hints**:
* Sort the coins array and maintain the smallest sum that is unobtainable by induction.
* If we don’t use any coins, the smallest integer that we cannot obtain by sum is <code>1</code>. Suppose currently, for a fixed set of the first several coins the smallest integer that we cannot obtain is <code>x + 1</code>, namely we can form all integers in the range <code>[1, x]</code> but not <code>x + 1</code>.
* If the next unused coin’s value is NOT <code>x + 1</code> (note the array is sorted), we have to add <code>x + 1</code> to the array. After this addition, we can form all values from <code>x + 1</code> to <code>2 * x + 1</code> by adding <code>x + 1</code> in <code>[1, x]</code>'s formations. So now we can form all the numbers of <code>[1, 2 * x + 1]</code>. After this iteration the new value of <code>x</code> becomes <code>2 * x + 1</code>.

## Solution 1.

**Intuition**: We sort `A` and add smaller numbers first.

Assume we added the first few numbers that can form all the numbers in range `[1, sum]` (`sum` is the sum of these numbers). The next number we need to form is `sum + 1`.

Now discuss what we do with a new number `A[i]`:

* If `A[i] <= sum + 1`, then we can extend the range from `[1, sum]` to `[1, sum+A[i]]`.
* If `A[i] > sum + 1`, then we have to patch a number, which is `sum + 1`. Then the new range becomes `[1, 2*sum+1]`.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-coins-to-be-added
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int minimumAddedCoins(vector<int>& A, int target) {
        sort(begin(A), end(A));
        long i = 0, sum = 0, N = A.size(), ans = 0;
        while (i < N || sum < target) {
            if (i < N && A[i] <= sum + 1) sum += A[i++];
            else {
                ++ans; // patch `sum+1`
                sum += sum + 1;
            }
        }
        return ans;
    }
};
```