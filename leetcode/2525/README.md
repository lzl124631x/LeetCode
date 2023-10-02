# [2525. Categorize Box According to Criteria (Easy)](https://leetcode.com/problems/categorize-box-according-to-criteria)

<p>Given four integers <code>length</code>, <code>width</code>, <code>height</code>, and <code>mass</code>, representing the dimensions and mass of a box, respectively, return <em>a string representing the <strong>category</strong> of the box</em>.</p>
<ul>
	<li>The box is <code>"Bulky"</code> if:

	<ul>
		<li><strong>Any</strong> of the dimensions of the box is greater or equal to <code>10<sup>4</sup></code>.</li>
		<li>Or, the <strong>volume</strong> of the box is greater or equal to <code>10<sup>9</sup></code>.</li>
	</ul>
	</li>
	<li>If the mass of the box is greater or equal to <code>100</code>, it is <code>"Heavy".</code></li>
	<li>If the box is both <code>"Bulky"</code> and <code>"Heavy"</code>, then its category is <code>"Both"</code>.</li>
	<li>If the box is neither <code>"Bulky"</code> nor <code>"Heavy"</code>, then its category is <code>"Neither"</code>.</li>
	<li>If the box is <code>"Bulky"</code> but not <code>"Heavy"</code>, then its category is <code>"Bulky"</code>.</li>
	<li>If the box is <code>"Heavy"</code> but not <code>"Bulky"</code>, then its category is <code>"Heavy"</code>.</li>
</ul>
<p><strong>Note</strong> that the volume of the box is the product of its length, width and height.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> length = 1000, width = 35, height = 700, mass = 300
<strong>Output:</strong> "Heavy"
<strong>Explanation:</strong> 
None of the dimensions of the box is greater or equal to 10<sup>4</sup>. 
Its volume = 24500000 &lt;= 10<sup>9</sup>. So it cannot be categorized as "Bulky".
However mass &gt;= 100, so the box is "Heavy".
Since the box is not "Bulky" but "Heavy", we return "Heavy".</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> length = 200, width = 50, height = 800, mass = 50
<strong>Output:</strong> "Neither"
<strong>Explanation:</strong> 
None of the dimensions of the box is greater or equal to 10<sup>4</sup>.
Its volume = 8 * 10<sup>6</sup> &lt;= 10<sup>9</sup>. So it cannot be categorized as "Bulky".
Its mass is also less than 100, so it cannot be categorized as "Heavy" either. 
Since its neither of the two above categories, we return "Neither".</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= length, width, height &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= mass &lt;= 10<sup>3</sup></code></li>
</ul>

**Companies**:
[Zendesk](https://leetcode.com/company/zendesk)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Fizz Buzz (Easy)](https://leetcode.com/problems/fizz-buzz/)
* [Find Winner on a Tic Tac Toe Game (Easy)](https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/)
* [Best Poker Hand (Easy)](https://leetcode.com/problems/best-poker-hand/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/categorize-box-according-to-criteria
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool bulky = length >= 1e4 || width >= 1e4 || height >= 1e4 || ((long long)length * width * height >= 1e9), heavy = mass >= 100;
        return bulky && heavy ? "Both" : (!bulky && !heavy ? "Neither" : (bulky ? "Bulky" : "Heavy"));
    }
};
```