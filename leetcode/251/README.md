# [251. Flatten 2D Vector (Medium)](https://leetcode.com/problems/flatten-2d-vector/)

<p>Design an iterator to flatten a 2D vector. It should support the <code>next</code> and <code>hasNext</code> operations.</p>

<p>Implement the <code>Vector2D</code> class:</p>

<ul>
	<li><code>Vector2D(int[][] vec)</code> initializes the object with the 2D vector <code>vec</code>.</li>
	<li><code>next()</code> returns the next element from the 2D vector and moves the pointer one step forward. You may assume that all the calls to <code>next</code> are valid.</li>
	<li><code>hasNext()</code> returns <code>true</code> if there are still some elements in the vector, and <code>false</code> otherwise.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["Vector2D", "next", "next", "next", "hasNext", "hasNext", "next", "hasNext"]
[[[[1, 2], [3], [4]]], [], [], [], [], [], [], []]
<strong>Output</strong>
[null, 1, 2, 3, true, true, 4, false]

<strong>Explanation</strong>
Vector2D vector2D = new Vector2D([[1, 2], [3], [4]]);
vector2D.next();    // return 1
vector2D.next();    // return 2
vector2D.next();    // return 3
vector2D.hasNext(); // return True
vector2D.hasNext(); // return True
vector2D.next();    // return 4
vector2D.hasNext(); // return False
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= vec.length &lt;= 200</code></li>
	<li><code>0 &lt;= vec[i].length &lt;= 500</code></li>
	<li><code>-500 &lt;= vec[i][j] &lt;= 500</code></li>
	<li>At most <code>10<sup>5</sup></code> calls will be made to <code>next</code> and <code>hasNext</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> As an added challenge, try to code it using only <a href="http://www.cplusplus.com/reference/iterator/iterator/" target="_blank">iterators in C++</a> or <a href="http://docs.oracle.com/javase/7/docs/api/java/util/Iterator.html" target="_blank">iterators in Java</a>.</p>


**Companies**:  
[Airbnb](https://leetcode.com/company/airbnb)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Design](https://leetcode.com/tag/design/), [Iterator](https://leetcode.com/tag/iterator/)

**Similar Questions**:
* [Binary Search Tree Iterator (Medium)](https://leetcode.com/problems/binary-search-tree-iterator/)
* [Zigzag Iterator (Medium)](https://leetcode.com/problems/zigzag-iterator/)
* [Peeking Iterator (Medium)](https://leetcode.com/problems/peeking-iterator/)
* [Flatten Nested List Iterator (Medium)](https://leetcode.com/problems/flatten-nested-list-iterator/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/flatten-2d-vector/
// Author: github.com/lzl124631x
// Time:
//      Vector2D: O(N)
//      next: O(1) amortized
//      hasNext: O(1)
// Space: O(1)
class Vector2D {
    vector<vector<int>> v;
    int i = 0, j = 0;
    void move() {
        while (i < v.size() && j == v[i].size()) {
            ++i;
            j = 0;
        }
    }
public:
    Vector2D(vector<vector<int>>& v) : v(v) {
        move();
    }
    int next() {
        int ans = v[i][j++];
        move();
        return ans;
    }
    bool hasNext() {
        return i < v.size();
    }
};
```