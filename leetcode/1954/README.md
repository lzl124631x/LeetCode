# [1954. Minimum Garden Perimeter to Collect Enough Apples (Medium)](https://leetcode.com/problems/minimum-garden-perimeter-to-collect-enough-apples/)

<p>In a garden represented as an infinite 2D grid, there is an apple tree planted at <strong>every</strong> integer coordinate. The apple tree planted at an integer coordinate <code>(i, j)</code> has <code>|i| + |j|</code> apples growing on it.</p>

<p>You will buy an axis-aligned <strong>square plot</strong> of land that is centered at <code>(0, 0)</code>.</p>

<p>Given an integer <code>neededApples</code>, return <em>the <strong>minimum perimeter</strong> of a plot such that <strong>at least</strong></em><strong> </strong><code>neededApples</code> <em>apples are <strong>inside or on</strong> the perimeter of that plot</em>.</p>

<p>The value of <code>|x|</code> is defined as:</p>

<ul>
	<li><code>x</code> if <code>x &gt;= 0</code></li>
	<li><code>-x</code> if <code>x &lt; 0</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/08/30/1527_example_1_2.png" style="width: 442px; height: 449px;">
<pre><strong>Input:</strong> neededApples = 1
<strong>Output:</strong> 8
<strong>Explanation:</strong> A square plot of side length 1 does not contain any apples.
However, a square plot of side length 2 has 12 apples inside (as depicted in the image above).
The perimeter is 2 * 4 = 8.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> neededApples = 13
<strong>Output:</strong> 16
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> neededApples = 1000000000
<strong>Output:</strong> 5040
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= neededApples &lt;= 10<sup>15</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Binary Search](https://leetcode.com/tag/binary-search/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-garden-perimeter-to-collect-enough-apples/
// Author: github.com/lzl124631x
// Time: O(root(T, 3))
// Space: O(1)
class Solution {
public:
    long long minimumPerimeter(long long target) {
        long long sum = 0, f = 0, i = 1;
        for (; true; ++i) {
            f += i * (i + 1) * 3 / 2;
            sum = f * 8 - 6 * i * (i + 1);
            if (sum >= target) return 8 * i;
        }
    }
};
```

## Solution 2. Math

```cpp
// OJ: https://leetcode.com/problems/minimum-garden-perimeter-to-collect-enough-apples/
// Author: github.com/lzl124631x
// Time: O(root(T, 3))
// Space: O(1)
class Solution {
public:
    long long minimumPerimeter(long long target) {
        for (long long i = 1; true; ++i) {
            if (i * (i + 1) * (2 * i + 1) * 2 >= target) return 8 * i;
        }
    }
};
```