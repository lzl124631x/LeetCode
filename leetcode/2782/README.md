# [2782. Number of Unique Categories (Medium)](https://leetcode.com/problems/number-of-unique-categories)

<p>You are given an integer <code>n</code> and an object <code>categoryHandler</code> of class <code>CategoryHandler</code>.</p>

<p>There are <code>n&nbsp;</code>elements, numbered from <code>0</code> to <code>n - 1</code>. Each element has a category, and your task is to find the number of unique categories.</p>

<p>The class <code>CategoryHandler</code> contains the following function, which may help you:</p>

<ul>
	<li><code>boolean haveSameCategory(integer a, integer b)</code>: Returns <code>true</code> if <code>a</code> and <code>b</code> are in the same category and <code>false</code> otherwise. Also, if either <code>a</code> or <code>b</code> is not a valid number (i.e. it&#39;s greater than or equal to <code>n</code>or less than <code>0</code>), it returns <code>false</code>.</li>
</ul>

<p>Return <em>the number of unique categories.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 6, categoryHandler = [1,1,2,2,3,3]
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are 6 elements in this example. The first two elements belong to category 1, the second two belong to category 2, and the last two elements belong to category 3. So there are 3 unique categories.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 5, categoryHandler = [1,2,3,4,5]
<strong>Output:</strong> 5
<strong>Explanation:</strong> There are 5 elements in this example. Each element belongs to a unique category. So there are 5 unique categories.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 3, categoryHandler = [1,1,1]
<strong>Output:</strong> 1
<strong>Explanation:</strong> There are 3 elements in this example. All of them belong to one category. So there is only 1 unique category.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Union Find](https://leetcode.com/tag/union-find), [Interactive](https://leetcode.com/tag/interactive), [Counting](https://leetcode.com/tag/counting)

**Hints**:
* It can be proven that all pairs should be asked from the helper function.
* Iterate from the first element. For each element `i`, ask the helper function `i` with all `j < i`.
* If there is some `j < i` that `i` and `j` belong to the same group, go to next `i`. Otherwise, add one to the current number of groups.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-of-unique-categories
// Author: github.com/lzl124631x
// Time: O(N^2 * logN)
// Space: O(N)
class UnionFind {
    vector<int> id;
    int cnt;
public:
    UnionFind(int N) : id(N), cnt(N) {
        iota(begin(id), end(id), 0);
    }
    int find(int x) { return id[x] == x ? x : (id[x] = find(id[x])); }
    void connect(int a, int b) {
        int p = find(a), q = find(b);
        if (p == q) return;
        id[p] = q;
        cnt--;
    }
    int getCount() { return cnt; }
};
class Solution {
public:
    int numberOfCategories(int n, CategoryHandler* categoryHandler) {
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (categoryHandler->haveSameCategory(i, j)) uf.connect(i, j);
            }
        }
        return uf.getCount();
    }
};
```