# [1033. Moving Stones Until Consecutive (Easy)](https://leetcode.com/problems/moving-stones-until-consecutive/)

<p>Three stones are on a number line at positions <code>a</code>, <code>b</code>, and <code>c</code>.</p>

<p>Each turn, you pick up a stone at an endpoint (ie., either the lowest or highest position stone), and move it to an unoccupied position between those&nbsp;endpoints.&nbsp; Formally, let's say the stones are currently at positions <code>x, y, z</code> with <code>x &lt; y &lt; z</code>.&nbsp; You pick up the stone at either position <code>x</code> or position <code>z</code>, and move that stone to an integer position <code>k</code>, with <code>x &lt; k &lt; z</code> and <code>k != y</code>.</p>

<p>The game ends when you cannot make any more moves, ie. the stones are in consecutive positions.</p>

<p>When the game ends, what is the minimum and maximum number of moves that you could have made?&nbsp; Return the answer as an length 2 array: <code>answer = [minimum_moves, maximum_moves]</code></p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>a = <span id="example-input-1-1">1</span>, b = <span id="example-input-1-2">2</span>, c = <span id="example-input-1-3">5</span>
<strong>Output: </strong><span id="example-output-1">[1,2]</span>
<strong>Explanation: </strong>Move the stone from 5 to 3, or move the stone from 5 to 4 to 3.
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>a = <span id="example-input-2-1">4</span>, b = <span id="example-input-2-2">3</span>, c = <span id="example-input-2-3">2</span>
<strong>Output: </strong><span id="example-output-2">[0,0]</span>
<strong>Explanation: </strong>We cannot make any moves.
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>a = <span id="example-input-3-1">3</span>, b = <span id="example-input-3-2">5</span>, c = <span id="example-input-3-3">1</span>
<strong>Output: </strong><span id="example-output-3">[1,2]</span>
<strong>Explanation: </strong>Move the stone from 1 to 4; or move the stone from 1 to 2 to 4.
</pre>

<p>&nbsp;</p>
</div>
</div>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= a &lt;= 100</code></li>
	<li><code>1 &lt;= b &lt;= 100</code></li>
	<li><code>1 &lt;= c &lt;= 100</code></li>
	<li><code>a != b, b != c, c != a</code></li>
</ol>

<div>
<p>&nbsp;</p>

<div>
<div>&nbsp;</div>
</div>
</div>


**Related Topics**:  
[Brainteaser](https://leetcode.com/tag/brainteaser/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/moving-stones-until-consecutive/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int mx = max({ a, b, c }), mn = min({ a, b, c }), mid = a + b + c - mx - mn;
        return { mid - mn == 2 || mx - mid == 2 ? 1 : (mid - mn > 1) + (mx - mid > 1), mx - mn - 2 };
    }
};
```