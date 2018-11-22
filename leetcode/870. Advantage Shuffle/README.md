# [870. Advantage Shuffle (Medium)](https://leetcode.com/problems/advantage-shuffle/)

<p>Given two arrays <code>A</code> and <code>B</code> of equal size, the <em>advantage of <code>A</code> with respect to <code>B</code></em> is the number of indices <code>i</code>&nbsp;for which <code>A[i] &gt; B[i]</code>.</p>

<p>Return <strong>any</strong> permutation of <code>A</code> that maximizes its advantage with respect to <code>B</code>.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-1-1">[2,7,11,15]</span>, B = <span id="example-input-1-2">[1,10,4,11]</span>
<strong>Output: </strong><span id="example-output-1">[2,11,7,15]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-2-1">[12,24,8,32]</span>, B = <span id="example-input-2-2">[13,25,32,11]</span>
<strong>Output: </strong><span id="example-output-2">[24,32,8,12]</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= A.length = B.length &lt;= 10000</code></li>
	<li><code>0 &lt;= A[i] &lt;= 10^9</code></li>
	<li><code>0 &lt;= B[i] &lt;= 10^9</code></li>
</ol>
</div>
</div>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/advantage-shuffle/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        vector<int> copy(B.begin(), B.end());
        sort(B.begin(), B.end());
        unordered_map<int, queue<int>> m;
        queue<int> leftover;
        int i = 0;
        for (int a : A) {
            if (a > B[i]) m[B[i++]].push(a);
            else leftover.push(a);
        }
        vector<int> ans;
        for (int b : copy) {
            if (m[b].size()) {
                ans.push_back(m[b].front());
                m[b].pop();
            } else {
                ans.push_back(leftover.front());
                leftover.pop();
            }
        }
        return ans;
    }
};
```