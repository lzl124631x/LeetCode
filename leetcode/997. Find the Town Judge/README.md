# [997. Find the Town Judge (Easy)](https://leetcode.com/problems/find-the-town-judge/)

<p>In a town, there are <code>N</code> people labelled from&nbsp;<code>1</code> to <code>N</code>.&nbsp; There is a rumor that one of these people is secretly the town judge.</p>

<p>If the&nbsp;town judge exists, then:</p>

<ol>
	<li>The town judge trusts nobody.</li>
	<li>Everybody (except for the town judge) trusts the town judge.</li>
	<li>There is exactly one person that satisfies properties 1 and 2.</li>
</ol>

<p>You are given <code>trust</code>, an array of pairs <code>trust[i] = [a, b]</code> representing that the person labelled <code>a</code> trusts the person labelled <code>b</code>.</p>

<p>If the town judge exists and can be identified, return the label of the town judge.&nbsp; Otherwise, return <code>-1</code>.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>N = <span id="example-input-1-1">2</span>, trust = <span id="example-input-1-2">[[1,2]]</span>
<strong>Output: </strong><span id="example-output-1">2</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>N = <span id="example-input-2-1">3</span>, trust = <span id="example-input-2-2">[[1,3],[2,3]]</span>
<strong>Output: </strong><span id="example-output-2">3</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>N = <span id="example-input-3-1">3</span>, trust = <span id="example-input-3-2">[[1,3],[2,3],[3,1]]</span>
<strong>Output: </strong><span id="example-output-3">-1</span>
</pre>

<div>
<p><strong>Example 4:</strong></p>

<pre><strong>Input: </strong>N = <span id="example-input-4-1">3</span>, trust = <span id="example-input-4-2">[[1,2],[2,3]]</span>
<strong>Output: </strong><span id="example-output-4">-1</span>
</pre>

<div>
<p><strong>Example 5:</strong></p>

<pre><strong>Input: </strong>N = <span id="example-input-5-1">4</span>, trust = <span id="example-input-5-2">[[1,3],[1,4],[2,3],[2,4],[4,3]]</span>
<strong>Output: </strong><span id="example-output-5">3</span></pre>

<p>&nbsp;</p>
</div>
</div>
</div>
</div>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= N &lt;= 1000</code></li>
	<li><code>trust.length &lt;= 10000</code></li>
	<li><code>trust[i]</code> are all different</li>
	<li><code>trust[i][0] != trust[i][1]</code></li>
	<li><code>1 &lt;= trust[i][0], trust[i][1] &lt;= N</code></li>
</ol>


**Related Topics**:  
[Graph](https://leetcode.com/tag/graph/)

**Similar Questions**:
* [Find the Celebrity (Medium)](https://leetcode.com/problems/find-the-celebrity/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-the-town-judge/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> indegree(N + 1), outdegree(N + 1);
        for (auto &t : trust) {
            outdegree[t[0]]++;
            indegree[t[1]]++;
        }
        int judge = -1;
        for (int i = 1; i <= N; ++i) {
            if (indegree[i] != N - 1 || outdegree[i] != 0) continue;
            if (judge != -1) return false;
            judge = i;
        }
        return judge;
    }
};
```