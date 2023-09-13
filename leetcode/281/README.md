# [281. Zigzag Iterator (Medium)](https://leetcode.com/problems/zigzag-iterator/)

<p>Given two 1d vectors, implement an iterator to return their elements alternately.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong>
v1 = [1,2]
v2 = [3,4,5,6] 

<strong>Output:</strong> <code>[1,3,2,4,5,6]

<strong>Explanation:</strong></code>&nbsp;By calling <i>next</i> repeatedly until <i>hasNext</i> returns <code>false</code>, 
&nbsp;            the order of elements returned by <i>next</i> should be: <code>[1,3,2,4,5,6]</code>.</pre>

<p><b>Follow up</b>: What if you are given <code>k</code> 1d vectors? How well can your code be extended to such cases?</p>

<p><strong>Clarification </strong><b>for the follow up question</b><strong>:</strong><br>
The "Zigzag" order is not clearly defined and is ambiguous for <code>k &gt; 2</code> cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example:</p>

<pre><strong>Input:</strong>
[1,2,3]
[4,5,6,7]
[8,9]

<strong>Output: </strong><code>[1,4,8,2,5,9,3,6,7]</code>.
</pre>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Design](https://leetcode.com/tag/design/)

**Similar Questions**:
* [Binary Search Tree Iterator (Medium)](https://leetcode.com/problems/binary-search-tree-iterator/)
* [Flatten 2D Vector (Medium)](https://leetcode.com/problems/flatten-2d-vector/)
* [Peeking Iterator (Medium)](https://leetcode.com/problems/peeking-iterator/)
* [Flatten Nested List Iterator (Medium)](https://leetcode.com/problems/flatten-nested-list-iterator/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/zigzag-iterator/
// Author: github.com/lzl124631x
// Time:
//   ZigzagIterator: O(K)
//   next: O(1)
//   hasNext: O(1)
// Space: O(K) where K is the number of input vectors
class ZigzagIterator {
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.begin() != v1.end()) q.push(make_pair(v1.begin(), v1.end()));
        if (v2.begin() != v2.end()) q.push(make_pair(v2.begin(), v2.end()));
    }
    int next() {
        auto p = q.front();
        q.pop();
        int val = *p.first;
        p.first++;
        if (p.first != p.second) q.push(p);
        return val;
    }
    bool hasNext() {
        return q.size();
    }
};
```