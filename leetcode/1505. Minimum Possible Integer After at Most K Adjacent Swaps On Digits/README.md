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

## Solution 1. Segment Tree

We should greedily find the smallest digit and shift it leftwards. For example

```
43215, k = 4
// we shift 1 leftwards 3 times
14325, k = 1
```

```
43215, k = 2
// now we can only move 2 leftwards twice since that's in reach of k
24315, k = 0
```

So, let `d` be the digit we shift leftwards. We have two observations:

1. Always greedily choose first smallest `d` that is in reach of `k`.
2. Only digits to the left of `d` get their position shifted rightwards. Those to the right of `d` are unchanged.

For observation 1, for each digit, we use `queue<int>` to store its indexes in ascending order, with which we can easily get the smallest index.

For observation 2, we need to find a way to efficiently update and retrieve the positions of digits after shifts. ???to calculate the correct number of shifts, we need to store how many elements before `d` already shifted. We use segment tree for this.

Assume we are currently at index `i` and we pop an index `j` from the `queue`, this index `j` might be outdated because some digits to the right are moved to the left of it.


```cpp
// OJ: https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
// Ref: https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/discuss/720548/O(n-logn)-or-Detailed-Explanation
class SegmentTree {
    vector<int> A; // nodes of the segment tree. Root is at index 0, which represents range `[0, N]` (but there is actually no node at `N`). Node `i`'s children are at `2 * i + 1` and `2 * i + 2`.
    int N;
    void addUntil(int num, int L, int R, int node) { // when position `num` is shifted leftwards, we increment the node corresponding to `num` and all its parents.
        if (num < L || num > R) return;
        if (L == R) {
            A[node]++; // this node represents `num`. We increment the node value to indicate that this digit at position `num` has been shifted leftwards.
            return;
        }
        int M = (L + R) / 2;
        addUntil(num, L, M, 2 * node + 1); // update left child which represents range `[L, M]`
        addUntil(num, M + 1, R, 2 * node + 2); // update right child which represents range `[M + 1, R]`
        A[node] = A[2 * node + 1] + A[2 * node + 2]; // parent is the sum of its children
    }
    int getUntil(int qL, int qR, int L, int R, int node) { // <qL, qR> is the query range. <L, R> is the range of the current `node`.
        if (qR < L || qL > R) return 0; // no intersection
        if (qL <= L && qR >= R) return A[node]; // the query range covers the entire range of the current node
        int M = (L + R) / 2;
        return getUntil(qL, qR, L, M, 2 * node + 1) + getUntil(qL, qR, M + 1, R, 2 * node + 2);
    }
public:
    SegmentTree(int n) : A(4 * n), N(n) {}
    void add (int num) { addUntil(num, 0, N, 0); }
    int countLessThan(int num) { return getUntil(0, num - 1, 0, N, 0); } // how many numbers in range `[0, num)` has been shifted leftwards?
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
            for (int d = 0; d <= 9; ++d) { // try from the smallest digit to the largest
                if (q[d].empty()) continue;
                int j = q[d].front(), shift = tree.countLessThan(j); // This `j` might be outdated and should be greater because some digits might get shifted from the right to the left of it. We try to find how many numbers already got shifted that were to the left of `j`.
                if (j - shift > k) continue; // `j - shift` is the number of steps to make digit move from `j` to `i`.
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