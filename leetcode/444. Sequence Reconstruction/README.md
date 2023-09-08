# [444. Sequence Reconstruction (Medium)](https://leetcode.com/problems/sequence-reconstruction)

<p>You are given an integer array <code>nums</code> of length <code>n</code> where <code>nums</code> is a permutation of the integers in the range <code>[1, n]</code>. You are also given a 2D integer array <code>sequences</code> where <code>sequences[i]</code> is a subsequence of <code>nums</code>.</p>
<p>Check if <code>nums</code> is the shortest possible and the only <strong>supersequence</strong>. The shortest <strong>supersequence</strong> is a sequence <strong>with the shortest length</strong> and has all <code>sequences[i]</code> as subsequences. There could be multiple valid <strong>supersequences</strong> for the given array <code>sequences</code>.</p>
<ul>
	<li>For example, for <code>sequences = [[1,2],[1,3]]</code>, there are two shortest <strong>supersequences</strong>, <code>[1,2,3]</code> and <code>[1,3,2]</code>.</li>
	<li>While for <code>sequences = [[1,2],[1,3],[1,2,3]]</code>, the only shortest <strong>supersequence</strong> possible is <code>[1,2,3]</code>. <code>[1,2,3,4]</code> is a possible supersequence but not the shortest.</li>
</ul>
<p>Return <code>true</code><em> if </em><code>nums</code><em> is the only shortest <strong>supersequence</strong> for </em><code>sequences</code><em>, or </em><code>false</code><em> otherwise</em>.</p>
<p>A <strong>subsequence</strong> is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3], sequences = [[1,2],[1,3]]
<strong>Output:</strong> false
<strong>Explanation:</strong> There are two possible supersequences: [1,2,3] and [1,3,2].
The sequence [1,2] is a subsequence of both: [<strong><u>1</u></strong>,<strong><u>2</u></strong>,3] and [<strong><u>1</u></strong>,3,<strong><u>2</u></strong>].
The sequence [1,3] is a subsequence of both: [<strong><u>1</u></strong>,2,<strong><u>3</u></strong>] and [<strong><u>1</u></strong>,<strong><u>3</u></strong>,2].
Since nums is not the only shortest supersequence, we return false.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3], sequences = [[1,2]]
<strong>Output:</strong> false
<strong>Explanation:</strong> The shortest possible supersequence is [1,2].
The sequence [1,2] is a subsequence of it: [<strong><u>1</u></strong>,<strong><u>2</u></strong>].
Since nums is not the shortest supersequence, we return false.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3], sequences = [[1,2],[1,3],[2,3]]
<strong>Output:</strong> true
<strong>Explanation:</strong> The shortest possible supersequence is [1,2,3].
The sequence [1,2] is a subsequence of it: [<strong><u>1</u></strong>,<strong><u>2</u></strong>,3].
The sequence [1,3] is a subsequence of it: [<strong><u>1</u></strong>,2,<strong><u>3</u></strong>].
The sequence [2,3] is a subsequence of it: [1,<strong><u>2</u></strong>,<strong><u>3</u></strong>].
Since nums is the only shortest supersequence, we return true.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code> is a permutation of all the integers in the range <code>[1, n]</code>.</li>
	<li><code>1 &lt;= sequences.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= sequences[i].length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= sum(sequences[i].length) &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= sequences[i][j] &lt;= n</code></li>
	<li>All the arrays of <code>sequences</code> are <strong>unique</strong>.</li>
	<li><code>sequences[i]</code> is a subsequence of <code>nums</code>.</li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Graph](https://leetcode.com/tag/graph/), [Topological Sort](https://leetcode.com/tag/topological-sort/)

**Similar Questions**:
* [Course Schedule II (Medium)](https://leetcode.com/problems/course-schedule-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/sequence-reconstruction
// Author: github.com/lzl124631x
// Time: O(N + S)
// Space: O(N^2)
class Solution {
public:
    bool sequenceReconstruction(vector<int>& A, vector<vector<int>>& S) {
        int N = A.size(), i = 0;
        vector<unordered_set<int>> G(N + 1);
        vector<int> indegree(N + 1);
        for (auto &s : S) {
            for (int i = 1; i < s.size(); ++i) {
                if (G[s[i - 1]].count(s[i])) continue;
                G[s[i - 1]].insert(s[i]);
                indegree[s[i]]++;
            }
        }
        queue<int> q;
        for (int i = 1; i <= N; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        while (q.size()) {
            if (q.size() != 1) return false;
            int u = q.front();
            q.pop();
            if (u != A[i++]) return false;
            for (int v : G[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }
        return i == N;
    }
};
```