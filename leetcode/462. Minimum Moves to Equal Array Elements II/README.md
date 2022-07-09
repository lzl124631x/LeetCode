# [462. Minimum Moves to Equal Array Elements II (Medium)](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/)

<p>Given an integer array <code>nums</code> of size <code>n</code>, return <em>the minimum number of moves required to make all array elements equal</em>.</p>

<p>In one move, you can increment or decrement an element of the array by <code>1</code>.</p>

<p>Test cases are designed so that the answer will fit in a <strong>32-bit</strong> integer.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 2
<strong>Explanation:</strong>
Only two moves are needed (remember each move increments or decrements one element):
[<u>1</u>,2,3]  =&gt;  [2,2,<u>3</u>]  =&gt;  [2,2,2]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,10,2,9]
<strong>Output:</strong> 16
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Best Meeting Point (Hard)](https://leetcode.com/problems/best-meeting-point/)
* [Minimum Moves to Equal Array Elements (Medium)](https://leetcode.com/problems/minimum-moves-to-equal-array-elements/)
* [Minimum Operations to Make a Uni-Value Grid (Medium)](https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/)
* [Removing Minimum Number of Magic Beans (Medium)](https://leetcode.com/problems/removing-minimum-number-of-magic-beans/)

## Solution 1.

Sort the array. 

For `A[i]`, the numbers to its right need `right - (N - i - 1) * A[i]` steps where `right = A[i+1] + A[i+2] + .. + A[N-1]`; the numbers to its left need `i * A[i] - left` steps. So in total we need `right - (N - i - 1) * A[i] + i * A[i] - left` moves.

We can keep track of `left` and `right` on the fly, and get the minimum `moves`.

```cpp
// OJ: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int minMoves2(vector<int>& A) {
        long left = 0, right = 0, N = A.size(), ans = LONG_MAX;
        sort(begin(A), end(A));
        for (int n : A) right += n;
        for (long i = 0; i < N; ++i) {
            right -= A[i];
            long moves = right - (N - i - 1) * A[i] + i * A[i] - left;
            ans = min(ans, moves);
            left += A[i];
        }
        return ans;
    }
};
```

## Solution 2. Median

Any Median minimizes the sum of absolute deviations. [See more](https://liuzhenglaichn.gitbook.io/algorithm/math/median-minimizes-sum-of-absolute-deviations)

```cpp
// OJ: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
// https://discuss.leetcode.com/topic/68736/java-just-like-meeting-point-problem
class Solution {
public:
    int minMoves2(vector<int>& A) {
        sort(begin(A), end(A));
        int i = 0, j = A.size() - 1, ans = 0;
        while (i < j) ans += A[j--] - A[i++];
        return ans;
    }
};
```

## Solution 3. Median

If the array has odd number of elements, there is only a single median which minimizes the sum of absolute deviations.

If the array has even number of elements, any numbers between (including) the two median numbers minimizes the sum of absolute deviations.

```cpp
// OJ: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// Author: github.com/lzl124631x
// Time: O(N) on average, O(N^2) in the worst case
// Space: O(1)
class Solution {
public:
    int minMoves2(vector<int>& A) {
        int N = A.size();
        nth_element(begin(A), begin(A) + N / 2, end(A));
        int median = A[N / 2], ans = 0;
        for (int n : A) ans += abs(n - median);
        return ans;
    }
};
```