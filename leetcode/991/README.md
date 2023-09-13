# [991. Broken Calculator (Medium)](https://leetcode.com/problems/broken-calculator/)

<p>There is a broken calculator that has the integer <code>startValue</code> on its display initially. In one operation, you can:</p>

<ul>
	<li>multiply the number on display by <code>2</code>, or</li>
	<li>subtract <code>1</code> from the number on display.</li>
</ul>

<p>Given two integers <code>startValue</code> and <code>target</code>, return <em>the minimum number of operations needed to display </em><code>target</code><em> on the calculator</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> startValue = 2, target = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong> Use double operation and then decrement operation {2 -&gt; 4 -&gt; 3}.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> startValue = 5, target = 8
<strong>Output:</strong> 2
<strong>Explanation:</strong> Use decrement and then double {5 -&gt; 4 -&gt; 8}.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> startValue = 3, target = 10
<strong>Output:</strong> 3
<strong>Explanation:</strong> Use double, decrement and double {3 -&gt; 6 -&gt; 5 -&gt; 10}.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= x, y &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:  
[Bloomberg](https://leetcode.com/company/bloomberg), [Arcesium](https://leetcode.com/company/arcesium), [Nutanix](https://leetcode.com/company/nutanix)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [2 Keys Keyboard (Medium)](https://leetcode.com/problems/2-keys-keyboard/)

## Solution 1. Greedy

Since we are looking for the shortest path, BFS is the first option. But this will create too many states.

We can get the following intuition if we think in the reverse order, get `X` from `Y` by dividing by `2` or adding `1`.

**Intuition**:

* If `Y < X`, we can only keep adding `1`s, so it takes `X - Y` steps.
* If `Y > X`, we have the two options but we can greedily pick one. It's deterministic.
  * If `Y` is even, dividing by `2` first is always better than adding `1` first.  
  For example, to reach `target / 2 + 1`, one division and one addition is better than 2 additions and one division.  
  After trying more examples, we can see that doing division first then addition is always better than doing addition first than division.
  * If `Y` is odd, we can only add `1`.

```cpp
// OJ: https://leetcode.com/problems/broken-calculator/
// Author: github.com/lzl124631x
// Time: O(logY)
// Space: O(1)
class Solution {
public:
    int brokenCalc(int X, int Y) {
        int ans = 0;
        while (Y > X) {
            ++ans;
            if (Y % 2) ++Y;
            else Y /= 2;
        }
        return ans + X - Y;
    }
};
```