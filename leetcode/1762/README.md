# [1762. Buildings With an Ocean View (Medium)](https://leetcode.com/problems/buildings-with-an-ocean-view/)

<p>There are <code>n</code> buildings in a line. You are given an integer array <code>heights</code> of size <code>n</code> that represents the heights of the buildings in the line.</p>

<p>The ocean is to the right of the buildings. A building has an ocean view if the building can see the ocean without obstructions. Formally, a building has an ocean view if all the buildings to its right have a <strong>smaller</strong> height.</p>

<p>Return a list of indices <strong>(0-indexed)</strong> of buildings that have an ocean view, sorted in increasing order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> heights = [4,2,3,1]
<strong>Output:</strong> [0,2,3]
<strong>Explanation:</strong> Building 1 (0-indexed) does not have an ocean view because building 2 is taller.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> heights = [4,3,2,1]
<strong>Output:</strong> [0,1,2,3]
<strong>Explanation:</strong> All the buildings have an ocean view.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> heights = [1,3,2,4]
<strong>Output:</strong> [3]
<strong>Explanation:</strong> Only building 3 has an ocean view.</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> heights = [2,2,2,2]
<strong>Output:</strong> [3]
<strong>Explanation:</strong> Buildings cannot see the ocean if there are buildings of the <strong>same</strong> height to its right.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= heights.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= heights[i] &lt;= 10<sup>9</sup></code></li>
</ul>

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Stack](https://leetcode.com/tag/stack/), [Monotonic Stack](https://leetcode.com/tag/monotonic-stack/)

**Similar Questions**:
* [Number of Visible People in a Queue (Hard)](https://leetcode.com/problems/number-of-visible-people-in-a-queue/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/buildings-with-an-ocean-view/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> findBuildings(vector<int>& A) {
        vector<int> ans{(int)A.size() - 1};
        for (int i = A.size() - 2; i >= 0; --i) {
            if (A[i] > A[ans.back()]) ans.push_back(i);
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
```