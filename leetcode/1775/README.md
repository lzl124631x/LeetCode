# [1775. Equal Sum Arrays With Minimum Number of Operations (Medium)](https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/)

<p>You are given two arrays of integers <code>nums1</code> and <code><font face="monospace">nums2</font></code>, possibly of different lengths. The values in the arrays are between <code>1</code> and <code>6</code>, inclusive.</p>

<p>In one operation, you can change any integer's value in <strong>any </strong>of the arrays to <strong>any</strong> value between <code>1</code> and <code>6</code>, inclusive.</p>

<p>Return <em>the minimum number of operations required to make the sum of values in </em><code>nums1</code><em> equal to the sum of values in </em><code>nums2</code><em>.</em> Return <code>-1</code>​​​​​ if it is not possible to make the sum of the two arrays equal.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
<strong>Output:</strong> 3
<strong>Explanation:</strong> You can make the sums of nums1 and nums2 equal with 3 operations. All indices are 0-indexed.
- Change nums2[0] to 6. nums1 = [1,2,3,4,5,6], nums2 = [<u><strong>6</strong></u>,1,2,2,2,2].
- Change nums1[5] to 1. nums1 = [1,2,3,4,5,<strong><u>1</u></strong>], nums2 = [6,1,2,2,2,2].
- Change nums1[2] to 2. nums1 = [1,2,<strong><u>2</u></strong>,4,5,1], nums2 = [6,1,2,2,2,2].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,1,1,1,1,1,1], nums2 = [6]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There is no way to decrease the sum of nums1 or to increase the sum of nums2 to make them equal.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums1 = [6,6], nums2 = [1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> You can make the sums of nums1 and nums2 equal with 3 operations. All indices are 0-indexed. 
- Change nums1[0] to 2. nums1 = [<strong><u>2</u></strong>,6], nums2 = [1].
- Change nums1[1] to 2. nums1 = [2,<strong><u>2</u></strong>], nums2 = [1].
- Change nums2[0] to 4. nums1 = [2,2], nums2 = [<strong><u>4</u></strong>].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 6</code></li>
</ul>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Number of Dice Rolls With Target Sum (Medium)](https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/)

## Solution 1. Brute force

```cpp
// OJ: https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(1)
class Solution {
    int getOp(int cnt[7], int diff) {
        int ans = 0;
        if (diff > 0) {
            for (int i = 1; i < 6; ++i) {
                int d = 6 - i;
                int q = min((diff + d - 1) / d, cnt[i]);
                diff -= q * d;
                ans += q;
                if (diff <= 0) break;
            }
        } else {
            diff = -diff;
            for (int i = 6; i > 1; --i) {
                int d = i - 1;
                int q = min((diff + d - 1) / d, cnt[i]);
                diff -= q * d;
                ans += q;
                if (diff <= 0) break;
            }
        }
        return ans;
    }
public:
    int minOperations(vector<int>& A, vector<int>& B) {
        int M = A.size(), N = B.size();
        if (M > 6 * N || N > 6 * M) return -1;
        int ans = INT_MAX, cnta[7] = {}, cntb[7] = {}, sa = accumulate(begin(A), end(A), 0), sb = accumulate(begin(B), end(B), 0);
        for (int a : A) cnta[a]++;
        for (int b : B) cntb[b]++;
        for (int i = max(M, N), mx = 6 * min(M, N); i <= mx; ++i) {
            int op = getOp(cnta, i - sa) + getOp(cntb, i - sb);
            ans = min(ans, op);
        }
        return ans;
    }
};
```

## Solution 2. Greedy

```cpp
// OJ: https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(1)
class Solution {
    int solve(int A[7], int B[7], int diff) {
        int ans = 0;
        for (int d = 5; d >= 1 && diff > 0; --d) {
            int q = min((diff + d - 1) / d, A[d + 1]);
            diff -= q * d;
            ans += q;
            q = min((diff + d - 1) / d, B[6 - d]);
            diff -= q * d;
            ans += q;
        }
        return ans;
    }
public:
    int minOperations(vector<int>& A, vector<int>& B) {
        int M = A.size(), N = B.size();
        if (M > 6 * N || N > 6 * M) return -1;
        int ans = INT_MAX, cnta[7] = {}, cntb[7] = {}, sa = accumulate(begin(A), end(A), 0), sb = accumulate(begin(B), end(B), 0);
        if (sa == sb) return 0;
        for (int a : A) cnta[a]++;
        for (int b : B) cntb[b]++;
        return sa > sb ? solve(cnta, cntb, sa - sb) : solve(cntb, cnta, sb - sa);
    }
};
```