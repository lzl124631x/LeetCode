# [1505. Minimum Possible Integer After at Most K Adjacent Swaps On Digits (Hard)](https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/)

<p>Given a string <code>num</code> representing <strong>the digits</strong> of&nbsp;a very large integer and an integer <code>k</code>.</p>

<p>You are allowed to swap any two adjacent digits of the integer <strong>at most</strong> <code>k</code> times.</p>

<p>Return <em>the minimum integer</em> you can obtain also as a string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/06/17/q4_1.jpg" style="width: 500px; height: 40px;">
<pre><strong>Input:</strong> num = "4321", k = 4
<strong>Output:</strong> "1342"
<strong>Explanation:</strong> The steps to obtain the minimum integer from 4321 with 4 adjacent swaps are shown.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> num = "100", k = 1
<strong>Output:</strong> "010"
<strong>Explanation:</strong> It's ok for the output to have leading zeros, but the input is guaranteed not to have any leading zeros.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> num = "36789", k = 1000
<strong>Output:</strong> "36789"
<strong>Explanation:</strong> We can keep the number without any swaps.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> num = "22", k = 22
<strong>Output:</strong> "22"
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> num = "9438957234785635408", k = 23
<strong>Output:</strong> "0345989723478563548"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num.length &lt;= 30000</code></li>
	<li><code>num</code> contains <strong>digits</strong> only and doesn't have <strong>leading zeros</strong>.</li>
	<li><code>1 &lt;= k &lt;= 10^9</code></li>
</ul>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
// Ref: https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/discuss/720548/O(n-logn)-or-Java-or-Heavily-Commented-or-Segment-Tree-or-Detailed-Explanation
class SegmentTree {
    vector<int> A;
    int N;
    void addUntil(int num, int L, int R, int node) {
        if (num < L || num > R) return;
        if (L == R) {
            A[node]++;
            return;
        }
        int M = (L + R) / 2;
        addUntil(num, L, M, 2 * node + 1);
        addUntil(num, M + 1, R, 2 * node + 2);
        A[node] = A[2 * node + 1] + A[2 * node + 2];
    }
    int getUntil(int qL, int qR, int L, int R, int node) {
        if (qR < L || qL > R) return 0;
        if (qL <= L && qR >= R) return A[node];
        int M = (L + R) / 2;
        return getUntil(qL, qR, L, M, 2 * node + 1) + getUntil(qL, qR, M + 1, R, 2 * node + 2);
    }
public:
    SegmentTree(int n) : A(4 * n), N(n) {}
    void add (int num) { addUntil(num, 0, N, 0); }
    int countLessThan(int num) { return getUntil(0, num, 0, N, 0); }
};
class Solution {
public:
    string minInteger(string A, int k) {
        queue<int> q[10];
        int N = A.size();
        for (int i = 0; i < N; ++i) q[A[i] - '0'].push(i);
        string ans;
        SegmentTree tree(N);
        for (int i = 0; i < N; ++i) {
            for (int d = 0; d <= 9; ++d) {
                if (q[d].empty()) continue;
                int j = q[d].front(), shift = tree.countLessThan(j);
                if (j - shift > k) continue;
                k -= j - shift;
                tree.add(j);
                q[d].pop();
                ans += '0' + d;
                break;
            }
        }
        return ans;
    }
};
```