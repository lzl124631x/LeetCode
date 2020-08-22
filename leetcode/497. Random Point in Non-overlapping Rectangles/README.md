# [497. Random Point in Non-overlapping Rectangles (Medium)](https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/)

<p>Given a list of <strong>non-overlapping</strong>&nbsp;axis-aligned rectangles <code>rects</code>, write a function <code>pick</code> which randomly and uniformily picks an <strong>integer point</strong> in the space&nbsp;covered by the rectangles.</p>

<p>Note:</p>

<ol>
	<li>An <strong>integer point</strong>&nbsp;is a point that has integer coordinates.&nbsp;</li>
	<li>A point&nbsp;on the perimeter&nbsp;of a rectangle is&nbsp;<strong>included</strong> in the space covered by the rectangles.&nbsp;</li>
	<li><code>i</code>th rectangle = <code>rects[i]</code> =&nbsp;<code>[x1,y1,x2,y2]</code>, where <code>[x1, y1]</code>&nbsp;are the integer coordinates of the bottom-left corner, and <code>[x2, y2]</code>&nbsp;are the integer coordinates of the top-right corner.</li>
	<li>length and width of each rectangle does not exceed <code>2000</code>.</li>
	<li><code>1 &lt;= rects.length&nbsp;&lt;= 100</code></li>
	<li><code>pick</code> return a point as an array of integer coordinates&nbsp;<code>[p_x, p_y]</code></li>
	<li><code>pick</code> is called at most <code>10000</code>&nbsp;times.</li>
</ol>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: 
</strong><span id="example-input-1-1">["Solution","pick","pick","pick"]
</span><span id="example-input-1-2">[[[[1,1,5,5]]],[],[],[]]</span>
<strong>Output: 
</strong><span id="example-output-1">[null,[4,1],[4,1],[3,3]]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: 
</strong><span id="example-input-2-1">["Solution","pick","pick","pick","pick","pick"]
</span><span id="example-input-2-2">[[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]</span>
<strong>Output: 
</strong><span id="example-output-2">[null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]]</span></pre>
</div>

<div>
<p><strong>Explanation of Input Syntax:</strong></p>

<p>The input is two lists:&nbsp;the subroutines called&nbsp;and their&nbsp;arguments.&nbsp;<code>Solution</code>'s&nbsp;constructor has one argument, the array of rectangles <code>rects</code>. <code>pick</code>&nbsp;has no arguments.&nbsp;Arguments&nbsp;are&nbsp;always wrapped with a list, even if there aren't any.</p>
</div>
</div>

<div>
<div>&nbsp;</div>
</div>


**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/), [Random](https://leetcode.com/tag/random/)

**Similar Questions**:
* [Random Pick with Weight (Medium)](https://leetcode.com/problems/random-pick-with-weight/)
* [Generate Random Point in a Circle (Medium)](https://leetcode.com/problems/generate-random-point-in-a-circle/)

## Solution 1. Binary Search

```cpp
// OJ: https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/
// Author: github.com/lzl124631x
// Time:
//      Solution: O(N)
//      pick: O(logN)
// Space: O(N)
class Solution {
    vector<vector<int>> A;
    vector<int> size;
    int total = 0;
public:
    Solution(vector<vector<int>>& rects) : A(rects) {
        for (auto &r : A) size.push_back(total += (r[3] - r[1] + 1) * (r[2] - r[0] + 1));
    }
    vector<int> pick() {
        int r = rand() % total;
        int i = upper_bound(begin(size), end(size), r) - begin(size);
        r -= i > 0 ? size[i - 1] : 0;
        int w = A[i][3] - A[i][1] + 1;
        return { A[i][0] + r / w, A[i][1] + r % w };
    }
};
```