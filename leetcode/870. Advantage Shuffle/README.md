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


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/advantage-shuffle/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int N = A.size(), i = 0;
        vector<int> ia(N), ib(N), ans(N, -1);
        iota(begin(ia), end(ia), 0);
        iota(begin(ib), end(ib), 0);
        sort(begin(ia), end(ia), [&](int a, int b) { return A[a] > A[b]; });
        sort(begin(ib), end(ib), [&](int a, int b) { return B[a] > B[b]; });
        for (int j = 0; i < N && j < N; ++i) {
            while (j < N && B[ib[j]] >= A[ia[i]]) ++j;
            if (j < N) {
                ans[ib[j++]] = A[ia[i]];
            } else break;
        }
        for (int j = 0; i < N && j < N; ++i) {
            while (j < N && ans[j] != -1) ++j;
            if (j < N) {
                ans[j++] = A[ia[i]];
            }
        }
        return ans;
    }
};
```