# [364. Nested List Weight Sum II (Medium)](https://leetcode.com/problems/nested-list-weight-sum-ii/)

<p>You are given a nested list of integers <code>nestedList</code>. Each element is either an integer or a list whose elements may also be integers or other lists.</p>

<p>The <strong>depth</strong> of an integer is the number of lists that it is inside of. For example, the nested list <code>[1,[2,2],[[3],2],1]</code> has each integer's value set to its <strong>depth</strong>. Let <code>maxDepth</code> be the <strong>maximum depth</strong> of any integer.</p>

<p>The <strong>weight</strong> of an integer is <code>maxDepth - (the depth of the integer) + 1</code>.</p>

<p>Return <em>the sum of each integer in </em><code>nestedList</code><em> multiplied by its <strong>weight</strong></em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/27/nestedlistweightsumiiex1.png" style="width: 426px; height: 181px;">
<pre><strong>Input:</strong> nestedList = [[1,1],2,[1,1]]
<strong>Output:</strong> 8
<strong>Explanation:</strong> Four 1's with a weight of 1, one 2 with a weight of 2.
1*1 + 1*1 + 2*2 + 1*1 + 1*1 = 8
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/27/nestedlistweightsumiiex2.png" style="width: 349px; height: 192px;">
<pre><strong>Input:</strong> nestedList = [1,[4,[6]]]
<strong>Output:</strong> 17
<strong>Explanation:</strong> One 1 at depth 3, one 4 at depth 2, and one 6 at depth 1.
1*3 + 4*2 + 6*1 = 17
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nestedList.length &lt;= 50</code></li>
	<li>The values of the integers in the nested list is in the range <code>[-100, 100]</code>.</li>
	<li>The maximum <strong>depth</strong> of any integer is less than or equal to <code>50</code>.</li>
</ul>


**Companies**:  
[LinkedIn](https://leetcode.com/company/linkedin)

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Nested List Weight Sum (Medium)](https://leetcode.com/problems/nested-list-weight-sum/)
* [Array Nesting (Medium)](https://leetcode.com/problems/array-nesting/)

## Solution 1. Double Pass DFS

```cpp
// OJ: https://leetcode.com/problems/nested-list-weight-sum-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    int getDepth(vector<NestedInteger>& nestedList) {
        int ans = 0;
        for (auto &item : nestedList) ans = max(ans, item.isInteger() ? 0 : getDepth(item.getList()));
        return 1 + ans;
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

## Solution 2. Single Pass BFS

Each integer get added **one extra time** for the mere existence of each **one** level under it.

```cpp
// OJ: https://leetcode.com/problems/nested-list-weight-sum-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
public:
    int depthSumInverse(vector<NestedInteger>& list) {
        queue<NestedInteger> q;
        for (auto &item : list) q.push(item);
        int ans = 0, unweighted = 0;
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto ni = q.front();
                q.pop();
                if (ni.isInteger()) {
                    unweighted += ni.getInteger();
                } else { 
                    for (auto &item : ni.getList()) q.push(item);
                }
            }
            ans += unweighted;
        }
        return ans;
    }
};
```