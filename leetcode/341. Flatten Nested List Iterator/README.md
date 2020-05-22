# [341. Flatten Nested List Iterator (Medium)](https://leetcode.com/problems/flatten-nested-list-iterator/)

<p>Given a nested list of integers, implement an iterator to flatten it.</p>

<p>Each element is either an integer, or a list -- whose elements may also be integers or other lists.</p>

<p><strong>Example 1:</strong></p>

<div>
<pre><strong>Input: </strong><span id="example-input-1-1">[[1,1],2,[1,1]]</span>
<strong>Output: </strong><span id="example-output-1">[1,1,2,1,1]
</span><strong>Explanation: </strong>By calling <i>next</i> repeatedly until <i>hasNext</i> returns false, 
&nbsp;            the order of elements returned by <i>next</i> should be: <code>[1,1,2,1,1]</code>.</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[1,[4,[6]]]</span>
<strong>Output: </strong><span id="example-output-2">[1,4,6]
</span><strong>Explanation: </strong>By calling <i>next</i> repeatedly until <i>hasNext</i> returns false, 
&nbsp;            the order of elements returned by <i>next</i> should be: <code>[1,4,6]</code>.
</pre>
</div>
</div>


**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/), [Design](https://leetcode.com/tag/design/)

**Similar Questions**:
* [Flatten 2D Vector (Medium)](https://leetcode.com/problems/flatten-2d-vector/)
* [Zigzag Iterator (Medium)](https://leetcode.com/problems/zigzag-iterator/)
* [Mini Parser (Medium)](https://leetcode.com/problems/mini-parser/)
* [Array Nesting (Medium)](https://leetcode.com/problems/array-nesting/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/flatten-nested-list-iterator/
// Author: github.com/lzl124631x
// Time: O(1) amortized
// Space: O(D) where D is the max depth of the list
class NestedIterator {
    typedef vector<NestedInteger>::iterator iter;
    stack<pair<iter, iter>> s;
    void goToInteger() {
        while (s.size()) {
            if (s.top().first == s.top().second) {
                s.pop();
                if (s.size()) s.top().first++;
            } else if (s.top().first->isInteger()) break;
            else {
                auto &list = s.top().first->getList();
                s.emplace(list.begin(), list.end());
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &list) {
        s.emplace(list.begin(), list.end());
        goToInteger();
    }
    
    int next() {
        int val = s.top().first->getInteger();
        s.top().first++;
        goToInteger();
        return val;
    }
    
    bool hasNext() {
        return s.size();
    }
};
```