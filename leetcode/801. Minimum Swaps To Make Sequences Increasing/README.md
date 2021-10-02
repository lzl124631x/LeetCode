# [801. Minimum Swaps To Make Sequences Increasing (Medium)](https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/)

<p>We have two integer sequences <code>A</code> and <code>B</code> of the same non-zero length.</p>

<p>We are allowed to swap elements <code>A[i]</code> and <code>B[i]</code>.&nbsp; Note that both elements are in the same index position in their respective sequences.</p>

<p>At the end of some number of swaps, <code>A</code> and <code>B</code> are both strictly increasing.&nbsp; (A sequence is <em>strictly increasing</em> if and only if <code>A[0] &lt; A[1] &lt; A[2] &lt; ... &lt; A[A.length - 1]</code>.)</p>

<p>Given A and B, return the minimum number of swaps to make both sequences strictly increasing.&nbsp; It is guaranteed that the given input always makes it possible.</p>

<pre><strong>Example:</strong>
<strong>Input:</strong> A = [1,3,5,4], B = [1,2,3,7]
<strong>Output:</strong> 1
<strong>Explanation: </strong>
Swap A[3] and B[3].  Then the sequences are:
A = [1, 3, 5, 7] and B = [1, 2, 3, 4]
which are both strictly increasing.
</pre>

<p><strong>Note:</strong></p>

<ul>
	<li><code>A, B</code> are arrays with the same length, and that length will be in the range <code>[1, 1000]</code>.</li>
	<li><code>A[i], B[i]</code> are integer values in the range <code>[0, 2000]</code>.</li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

Scan from left to right. At each element we have two options, swap or skip.

The best solution to the subproblem on the subarrays from `i` to `N-1` is fixed as long as we know `i` and whether we swapped at `i-1`.

So we can try to swap and skip for each `i` and memoize the best result.

```cpp
// OJ: https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    int inf = 1e9;
    inline bool valid(vector<int>& A, vector<int>& B, int i) {
        return i == 0 || (A[i] > A[i - 1] && B[i] > B[i - 1]);
    }
    unordered_map<int, int> memo;
    int dp(vector<int> &A, vector<int>& B, int i, bool swapped = false) {
        if (i == A.size()) return 0;
        int key = swapped * 2000 + i;
        if (memo.count(key)) return memo[key];
        int cnt = valid(A, B, i) ? solve(A, B, i + 1, false) : inf;
        swap(A[i], B[i]);
        cnt = min(cnt, valid(A, B, i) ? 1 + solve(A, B, i + 1, true) : inf);
        swap(A[i], B[i]);
        return memo[key] = cnt;
    }
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        return dp(A, B, 0);
    }
};
```

## Solution 2. DP

```cpp
// OJ: https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/solution/
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int swap = 1, skip = 0;
        for (int i = 1; i < A.size(); ++i) {
            int swap2 = INT_MAX, skip2 = INT_MAX;
            if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
                skip2 = min(skip2, skip);
                swap2 = min(swap2, swap + 1);
            }
            if (A[i - 1] < B[i] && B[i - 1] < A[i]) {
                skip2 = min(skip2, swap);
                swap2 = min(swap2, skip + 1);
            }
            swap = swap2;
            skip = skip2;
        }
        return min(swap, skip);
    }
};
```