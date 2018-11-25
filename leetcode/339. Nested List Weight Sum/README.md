# [339. Nested List Weight Sum (Easy)](https://leetcode.com/problems/nested-list-weight-sum/)

<p>Given a nested list of integers, return the sum of all integers in the list weighted by their depth.</p>

<p>Each element is either an integer, or a list -- whose elements may also be integers or other lists.</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[[1,1],2,[1,1]]</span>
<strong>Output: </strong><span id="example-output-1">10 </span>
<strong>Explanation: </strong>Four 1's at depth 2, one 2 at depth 1.</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[1,[4,[6]]]</span>
<strong>Output: </strong><span id="example-output-2">27 </span>
<strong>Explanation: </strong>One 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27.</pre>
</div>
</div>


**Companies**:  
[LinkedIn](https://leetcode.com/company/linkedin), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/)

**Similar Questions**:
* [Nested List Weight Sum II (Medium)](https://leetcode.com/problems/nested-list-weight-sum-ii/)
* [Array Nesting (Medium)](https://leetcode.com/problems/array-nesting/)
* [Employee Importance (Easy)](https://leetcode.com/problems/employee-importance/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/nested-list-weight-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(D) where D is the max depth of the list.
class Solution {
private:
    int depthSum(vector<NestedInteger>& nestedList, int depth) {
        int sum = 0;
        for (auto &i : nestedList) {
            if (i.isInteger()) sum += i.getInteger() * depth;
            else sum += depthSum(i.getList(), depth + 1);
        }
        return sum;
    }
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return depthSum(nestedList, 1);
    }
};
```