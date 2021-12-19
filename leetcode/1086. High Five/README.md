# [1086. High Five (Easy)](https://leetcode.com/problems/high-five/)

<p>Given a list of the scores of different students, <code>items</code>, where <code>items[i] = [ID<sub>i</sub>, score<sub>i</sub>]</code> represents one score from a student with <code>ID<sub>i</sub></code>, calculate each student's <strong>top five average</strong>.</p>

<p>Return <em>the answer as an array of pairs </em><code>result</code><em>, where </em><code>result[j] = [ID<sub>j</sub>, topFiveAverage<sub>j</sub>]</code><em> represents the student with </em><code>ID<sub>j</sub></code><em> and their <strong>top five average</strong>. Sort </em><code>result</code><em> by </em><code>ID<sub>j</sub></code><em> in <strong>increasing order</strong>.</em></p>

<p>A student's <strong>top five average</strong> is calculated by taking the sum of their top five scores and dividing it by <code>5</code> using <strong>integer division</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> items = [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
<strong>Output:</strong> [[1,87],[2,88]]
<strong>Explanation: </strong>
The student with ID = 1 got scores 91, 92, 60, 65, 87, and 100. Their top five average is (100 + 92 + 91 + 87 + 65) / 5 = 87.
The student with ID = 2 got scores 93, 97, 77, 100, and 76. Their top five average is (100 + 97 + 93 + 77 + 76) / 5 = 88.6, but with integer division their average converts to 88.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> items = [[1,100],[7,100],[1,100],[7,100],[1,100],[7,100],[1,100],[7,100],[1,100],[7,100]]
<strong>Output:</strong> [[1,100],[7,100]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= items.length &lt;= 1000</code></li>
	<li><code>items[i].length == 2</code></li>
	<li><code>1 &lt;= ID<sub>i</sub> &lt;= 1000</code></li>
	<li><code>0 &lt;= score<sub>i</sub> &lt;= 100</code></li>
	<li>For each <code>ID<sub>i</sub></code>, there will be <strong>at least</strong> five scores.</li>
</ul>


**Companies**:  
[Goldman Sachs](https://leetcode.com/company/goldman-sachs)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Sorting](https://leetcode.com/tag/sorting/)

## Solution 1. Sorting

```cpp
// OJ: https://leetcode.com/problems/high-five/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& A) {
        map<int, vector<int>> m;
        for (auto &v : A) m[v[0]].push_back(v[1]);
        vector<vector<int>> ans;
        for (auto &[id, scores] : m) {
            sort(begin(scores), end(scores), greater());
            ans.push_back({ id, accumulate(begin(scores), begin(scores) + 5, 0) / 5 });
        }
        return ans;
    }
};
```

## Solution 2. Heap

```cpp
// OJ: https://leetcode.com/problems/high-five/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& A) {
        map<int, priority_queue<int, vector<int>, greater<>>> m;
        for (auto &v : A) {
            m[v[0]].push(v[1]);
            if (m[v[0]].size() > 5) m[v[0]].pop();
        }
        vector<vector<int>> ans;
        for (auto &[id, scores] : m) {
            int score = 0;
            while (scores.size()) {
                score += scores.top();
                scores.pop();
            }
            ans.push_back({ id, score / 5 });
        }
        return ans;
    }
};
```