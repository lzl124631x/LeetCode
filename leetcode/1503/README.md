# [1503. Last Moment Before All Ants Fall Out of a Plank (Medium)](https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/)

<p>We have a wooden&nbsp;plank of the length <code>n</code> <strong>units</strong>. Some ants are walking on the&nbsp;plank, each ant moves with speed <strong>1 unit per second</strong>. Some of the ants move to the <strong>left</strong>, the other move to the <strong>right</strong>.</p>

<p>When two ants moving in two <strong>different</strong> directions meet at some point, they change their directions and continue moving again. Assume changing directions doesn't take any additional time.</p>

<p>When an ant reaches <strong>one end</strong> of the plank at a time <code>t</code>, it falls out of the plank imediately.</p>

<p>Given an integer <code>n</code> and two integer arrays <code>left</code> and <code>right</code>, the positions of the ants moving to the left and the right.&nbsp;Return <em>the&nbsp;moment</em> when the last ant(s) fall out of the plank.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/06/17/ants.jpg" style="width: 450px; height: 610px;">
<pre><strong>Input:</strong> n = 4, left = [4,3], right = [0,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> In the image above:
-The ant at index 0 is named A and going to the right.
-The ant at index 1 is named B and going to the right.
-The ant at index 3 is named C and going to the left.
-The ant at index 4 is named D and going to the left.
Note that the last moment when an ant was on the plank is t = 4 second, after that it falls imediately out of the plank. (i.e. We can say that at t = 4.0000000001, there is no ants on the plank).
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/06/17/ants2.jpg" style="width: 639px; height: 101px;">
<pre><strong>Input:</strong> n = 7, left = [], right = [0,1,2,3,4,5,6,7]
<strong>Output:</strong> 7
<strong>Explanation:</strong> All ants are going to the right, the ant at index 0 needs 7 seconds to fall.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/06/17/ants3.jpg" style="width: 639px; height: 100px;">
<pre><strong>Input:</strong> n = 7, left = [0,1,2,3,4,5,6,7], right = []
<strong>Output:</strong> 7
<strong>Explanation:</strong> All ants are going to the left, the ant at index 7 needs 7 seconds to fall.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> n = 9, left = [5], right = [4]
<strong>Output:</strong> 5
<strong>Explanation:</strong> At t = 1 second, both ants will be at the same intial position but with different direction.
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> n = 6, left = [6], right = [0]
<strong>Output:</strong> 6
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^4</code></li>
	<li><code>0 &lt;= left.length &lt;= n + 1</code></li>
	<li><code>0 &lt;= left[i] &lt;= n</code></li>
	<li><code>0 &lt;= right.length &lt;= n + 1</code></li>
	<li><code>0 &lt;= right[i] &lt;= n</code></li>
	<li><code>1 &lt;= left.length + right.length &lt;= n + 1</code></li>
	<li>All values of <code>left</code> and <code>right</code> are unique, and each value can appear <strong>only in one</strong> of the two arrays.</li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Brainteaser](https://leetcode.com/tag/brainteaser/)

## Solution 1.

If two ants meet each other, changing their directions is the effectively the same as keeping them moving in their original directions.

```cpp
// OJ: https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for (int x : left) ans = max(ans, x);
        for (int x : right) ans = max(ans, n - x);
        return ans;
    }
};
```