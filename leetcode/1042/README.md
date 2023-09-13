# [1042. Flower Planting With No Adjacent (Easy)](https://leetcode.com/problems/flower-planting-with-no-adjacent/)

<p>You have <code>N</code> gardens, labelled <code>1</code> to <code>N</code>.&nbsp; In each garden, you want to plant one of 4 types of flowers.</p>

<p><code>paths[i] = [x, y]</code> describes the existence of a bidirectional path from garden <code>x</code> to garden <code>y</code>.</p>

<p>Also, there is no garden that has more than 3 paths coming into or leaving it.</p>

<p>Your task is to choose a flower type for each garden such that,&nbsp;for any two gardens connected by a path, they have different types of flowers.</p>

<p>Return <strong>any</strong> such a choice as an array <code>answer</code>, where&nbsp;<code>answer[i]</code> is the type of flower&nbsp;planted in the <code>(i+1)</code>-th garden.&nbsp; The flower types are denoted&nbsp;<font face="monospace">1</font>, <font face="monospace">2</font>, <font face="monospace">3</font>, or <font face="monospace">4</font>.&nbsp; It is guaranteed an answer exists.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>N = <span id="example-input-1-1">3</span>, paths = <span id="example-input-1-2">[[1,2],[2,3],[3,1]]</span>
<strong>Output: </strong><span id="example-output-1">[1,2,3]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>N = <span id="example-input-2-1">4</span>, paths = <span id="example-input-2-2">[[1,2],[3,4]]</span>
<strong>Output: </strong><span id="example-output-2">[1,2,1,2]</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>N = <span id="example-input-3-1">4</span>, paths = <span id="example-input-3-2">[[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]</span>
<strong>Output: </strong><span id="example-output-3">[1,2,3,4]</span>
</pre>

<p>&nbsp;</p>

<p><strong><span>Note:</span></strong></p>

<ul>
	<li><code><span>1 &lt;= N &lt;= 10000</span></code></li>
	<li><code><span>0 &lt;= paths.size &lt;= 20000</span></code></li>
	<li>No garden has 4 or more paths coming into or leaving it.</li>
	<li>It is guaranteed an answer exists.</li>
</ul>
</div>
</div>
</div>


**Related Topics**:  
[Graph](https://leetcode.com/tag/graph/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/flower-planting-with-no-adjacent/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>> G(N);
        for (auto & e : paths) {
            G[e[0] - 1].push_back(e[1] - 1);
            G[e[1] - 1].push_back(e[0] - 1);
        }
        vector<int> ans(N);
        for (int i = 0; i < N; ++i) {
            int color[5] = {};
            for (int j : G[i]) color[ans[j]] = 1;
            for (int j = 4; j > 0; --j) {
                if (color[j]) continue;
                ans[i] = j;
                break;
            }
        }
        return ans;
    }
};
```