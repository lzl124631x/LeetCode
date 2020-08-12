# [668. Kth Smallest Number in Multiplication Table (Hard)](https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/)

<p>
Nearly every one have used the <a href="https://en.wikipedia.org/wiki/Multiplication_table">Multiplication Table</a>. But could you find out the <code>k-th</code> smallest number quickly from the multiplication table?
</p>

<p>
Given the height <code>m</code> and the length <code>n</code> of a <code>m * n</code> Multiplication Table, and a positive integer <code>k</code>, you need to return the <code>k-th</code> smallest number in this table.
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> m = 3, n = 3, k = 5
<b>Output:</b> 
<b>Explanation:</b> 
The Multiplication Table:
1	2	3
2	4	6
3	6	9

The 5-th smallest number is 3 (1, 2, 2, 3, 3).
</pre>
<p></p>


<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> m = 2, n = 3, k = 6
<b>Output:</b> 
<b>Explanation:</b> 
The Multiplication Table:
1	2	3
2	4	6

The 6-th smallest number is 6 (1, 2, 2, 3, 4, 6).
</pre>
<p></p>


<p><b>Note:</b><br>
</p><ol>
<li>The <code>m</code> and <code>n</code> will be in the range [1, 30000].</li>
<li>The <code>k</code> will be in the range [1, m * n]</li>
</ol>
<p></p>

**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Kth Smallest Element in a Sorted Matrix (Medium)](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)
* [Find K-th Smallest Pair Distance (Hard)](https://leetcode.com/problems/find-k-th-smallest-pair-distance/)
* [K-th Smallest Prime Fraction (Hard)](https://leetcode.com/problems/k-th-smallest-prime-fraction/)

## TLE version: Next Heap

```cpp
// OJ: https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/
// Author: github.com/lzl124631x
// Time: O(k * MlogM) = O(M^2 * NlogM)
// Space: O(M)
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        auto cmp = [](pair<int, int> &a, pair<int, int> &b) { return a.first * a.second > b.first * b.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for (int i = 1; i <= m; ++i) q.emplace(i, 1);
        int ans = 0;
        while (k--) {
            auto p = q.top();
            q.pop();
            ans = p.first * p.second;
            if (p.second < n) q.emplace(p.first, p.second + 1);
        }
        return ans;
    }
};
```

## Solution 1. Binary Answer

The range of the answer is `[1, m * n]`. We can use binary answer to find it.

Let `L = 1, R = m * n, M = (L + R) / 2`.

Define `cnt(M)` as the count of numbers less than or equal to `M`.

For the answer `ans`, the corresponding `cnt(ans)` could be exactly `k` (when there is only one `ans` in the table) or greater than `k` (when there are multiple `ans` in the table).

The goal is to find the first element `M` whose `cnt(M)` is greater than or equal to `k`.

So let the left part of the array be those elements whose `cnt < k`, and the right part be `cnt >= k`.

In the end, `L` will point to the first element whose `cnt >= k` and it is the answer.

```cpp
// OJ: https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/
// Author: github.com/lzl124631x
// Time: O(Mlog(MN))
// Space: O(1)
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        long long L = 1, R = m * n;
        while (L <= R) {
            long long M = (L + R) / 2, cnt = 0;
            for (int i = 1; i <= m; ++i) cnt += min(M / i, (long long) n);
            if (cnt < k) L = M + 1;
            else R = M - 1;
        }
        return L;
    }
};
```