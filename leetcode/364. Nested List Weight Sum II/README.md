# [364. Nested List Weight Sum II (Medium)](https://leetcode.com/problems/nested-list-weight-sum-ii/)

<p>Given a nested list of integers, return the sum of all integers in the list weighted by their depth.</p>

<p>Each element is either an integer, or a list -- whose elements may also be integers or other lists.</p>

<p>Different from the <a href="https://leetcode.com/problems/nested-list-weight-sum/">previous question</a> where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.</p>

<p><strong>Example 1:</strong></p>

<div>
<pre><strong>Input: </strong><span id="example-input-1-1">[[1,1],2,[1,1]]</span>
<strong>Output: </strong><span id="example-output-1">8 
<strong>Explanation: </strong>F</span>our 1's at depth 1, one 2 at depth 2.
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[1,[4,[6]]]</span>
<strong>Output: </strong><span id="example-output-2">17 
<strong>Explanation:</strong> O</span>ne 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17.
</pre>
</div>
</div>


**Companies**:  
[LinkedIn](https://leetcode.com/company/linkedin)

**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/nested-list-weight-sum-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    int getDepth(vector<NestedInteger>& nestedList) {
        int ans = 0;
        for (auto &item : nestedList) ans = max(ans, item.isInteger() ? 1 : 1 + getDepth(item.getList()));
        return ans;
    }
    int getSum(vector<NestedInteger>& nestedList, int weight) {
        int sum = 0;
        for (auto &item : nestedList) sum += item.isInteger() ? (item.getInteger() * weight) : getSum(item.getList(), weight - 1);
        return sum;
    }
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int depth = getDepth(nestedList);
        return getSum(nestedList, depth);
    }
};
```