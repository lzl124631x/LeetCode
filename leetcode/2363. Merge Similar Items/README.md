# [2363. Merge Similar Items (Easy)](https://leetcode.com/problems/merge-similar-items)

<p>You are given two 2D integer arrays, <code>items1</code> and <code>items2</code>, representing two sets of items. Each array <code>items</code> has the following properties:</p>
<ul>
	<li><code>items[i] = [value<sub>i</sub>, weight<sub>i</sub>]</code> where <code>value<sub>i</sub></code> represents the <strong>value</strong> and <code>weight<sub>i</sub></code> represents the <strong>weight </strong>of the <code>i<sup>th</sup></code> item.</li>
	<li>The value of each item in <code>items</code> is <strong>unique</strong>.</li>
</ul>
<p>Return <em>a 2D integer array</em> <code>ret</code> <em>where</em> <code>ret[i] = [value<sub>i</sub>, weight<sub>i</sub>]</code><em>,</em> <em>with</em> <code>weight<sub>i</sub></code> <em>being the <strong>sum of weights</strong> of all items with value</em> <code>value<sub>i</sub></code>.</p>
<p><strong>Note:</strong> <code>ret</code> should be returned in <strong>ascending</strong> order by value.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> items1 = [[1,1],[4,5],[3,8]], items2 = [[3,1],[1,5]]
<strong>Output:</strong> [[1,6],[3,9],[4,5]]
<strong>Explanation:</strong> 
The item with value = 1 occurs in items1 with weight = 1 and in items2 with weight = 5, total weight = 1 + 5 = 6.
The item with value = 3 occurs in items1 with weight = 8 and in items2 with weight = 1, total weight = 8 + 1 = 9.
The item with value = 4 occurs in items1 with weight = 5, total weight = 5.  
Therefore, we return [[1,6],[3,9],[4,5]].
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> items1 = [[1,1],[3,2],[2,3]], items2 = [[2,1],[3,2],[1,3]]
<strong>Output:</strong> [[1,4],[2,4],[3,4]]
<strong>Explanation:</strong> 
The item with value = 1 occurs in items1 with weight = 1 and in items2 with weight = 3, total weight = 1 + 3 = 4.
The item with value = 2 occurs in items1 with weight = 3 and in items2 with weight = 1, total weight = 3 + 1 = 4.
The item with value = 3 occurs in items1 with weight = 2 and in items2 with weight = 2, total weight = 2 + 2 = 4.
Therefore, we return [[1,4],[2,4],[3,4]].</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> items1 = [[1,3],[2,2]], items2 = [[7,1],[2,2],[1,4]]
<strong>Output:</strong> [[1,7],[2,4],[7,1]]
<strong>Explanation:
</strong>The item with value = 1 occurs in items1 with weight = 3 and in items2 with weight = 4, total weight = 3 + 4 = 7. 
The item with value = 2 occurs in items1 with weight = 2 and in items2 with weight = 2, total weight = 2 + 2 = 4. 
The item with value = 7 occurs in items2 with weight = 1, total weight = 1.
Therefore, we return [[1,7],[2,4],[7,1]].
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= items1.length, items2.length &lt;= 1000</code></li>
	<li><code>items1[i].length == items2[i].length == 2</code></li>
	<li><code>1 &lt;= value<sub>i</sub>, weight<sub>i</sub> &lt;= 1000</code></li>
	<li>Each <code>value<sub>i</sub></code> in <code>items1</code> is <strong>unique</strong>.</li>
	<li>Each <code>value<sub>i</sub></code> in <code>items2</code> is <strong>unique</strong>.</li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Sorting](https://leetcode.com/tag/sorting/), [Ordered Set](https://leetcode.com/tag/ordered-set/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/merge-similar-items
// Author: github.com/lzl124631x
// Time: O((M + N)log(M + N))
// Space: O(M + N)
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& A, vector<vector<int>>& B) {
        map<int, int> m;
        vector<vector<int>> ans;
        for (auto &a : A) m[a[0]] += a[1];
        for (auto &b : B) m[b[0]] += b[1];
        for (auto &[n, w] : m) ans.push_back({n, w});
        return ans;
    }
};
```