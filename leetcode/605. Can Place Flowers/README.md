# [605. Can Place Flowers (Easy)](https://leetcode.com/problems/can-place-flowers/)

<p>You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in <strong>adjacent</strong> plots.</p>

<p>Given an integer array&nbsp;<code>flowerbed</code>&nbsp;containing <code>0</code>'s and <code>1</code>'s, where <code>0</code> means empty and <code>1</code> means not empty,&nbsp;and an integer <code>n</code>, return <em>if</em> <code>n</code> new flowers can be planted in the <code>flowerbed</code>&nbsp;without violating the no-adjacent-flowers rule.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> flowerbed = [1,0,0,0,1], n = 1
<strong>Output:</strong> true
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> flowerbed = [1,0,0,0,1], n = 2
<strong>Output:</strong> false
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= flowerbed.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>flowerbed[i]</code> is <code>0</code> or <code>1</code>.</li>
	<li>There are no two adjacent flowers in <code>flowerbed</code>.</li>
	<li><code>0 &lt;= n &lt;= flowerbed.length</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Teemo Attacking (Medium)](https://leetcode.com/problems/teemo-attacking/)
* [Asteroid Collision (Medium)](https://leetcode.com/problems/asteroid-collision/)

## Solution 1.

A placeable plot should be empty, as well as its direct neighbors, if any. So, go through the flowerbed, whenever you find a placeable plot, place the flower into it, decrement `n`. Finally, return `n == 0`.

```cpp
// OJ: https://leetcode.com/problems/can-place-flowers
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool canPlaceFlowers(vector<int>& A, int n) {
        for (int i = 0; i < A.size() && n > 0; ++i) {
            if (A[i] == 1) continue;
            if ((i == 0 || A[i - 1] == 0) && (i == A.size() - 1 || A[i + 1] == 0)) {
                A[i] = 1;
                --n;
            }
        }
        return n == 0;
    }
};
```
