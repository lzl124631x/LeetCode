# [1874. Minimize Product Sum of Two Arrays (Medium)](https://leetcode.com/problems/minimize-product-sum-of-two-arrays/)

<p>The <b>product sum </b>of two equal-length arrays <code>a</code> and <code>b</code> is equal to the sum of <code>a[i] * b[i]</code> for all <code>0 &lt;= i &lt; a.length</code> (<strong>0-indexed</strong>).</p>

<ul>
	<li>For example, if <code>a = [1,2,3,4]</code> and <code>b = [5,2,3,1]</code>, the <strong>product sum</strong> would be <code>1*5 + 2*2 + 3*3 + 4*1 = 22</code>.</li>
</ul>

<p>Given two arrays <code>nums1</code> and <code>nums2</code> of length <code>n</code>, return <em>the <strong>minimum product sum</strong> if you are allowed to <strong>rearrange</strong> the <strong>order</strong> of the elements in </em><code>nums1</code>.&nbsp;</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums1 = [5,3,4,2], nums2 = [4,2,2,5]
<strong>Output:</strong> 40
<strong>Explanation:</strong>&nbsp;We can rearrange nums1 to become [3,5,4,2]. The product sum of [3,5,4,2] and [4,2,2,5] is 3*4 + 5*2 + 4*2 + 2*5 = 40.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums1 = [2,1,4,5,7], nums2 = [3,2,4,8,6]
<strong>Output:</strong> 65
<strong>Explanation: </strong>We can rearrange nums1 to become [5,7,4,1,2]. The product sum of [5,7,4,1,2] and [3,2,4,8,6] is 5*3 + 7*2 + 4*4 + 1*8 + 2*6 = 65.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums1.length == nums2.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 100</code></li>
</ul>

**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Choose Numbers From Two Arrays in Range (Hard)](https://leetcode.com/problems/choose-numbers-from-two-arrays-in-range/)

## Solution 1. Greedy

```cpp
// OJ: https://leetcode.com/problems/minimize-product-sum-of-two-arrays/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int minProductSum(vector<int>& A, vector<int>& B) {
        sort(begin(A), end(A));
        sort(begin(B), end(B), greater<>());
        int ans = 0;
        for (int i = 0; i < A.size(); ++i) ans += A[i] * B[i];
        return ans;
    }
};
```

## Solution 2. Counting Sort

```cpp
// OJ: https://leetcode.com/problems/minimize-product-sum-of-two-arrays/
// Author: github.com/lzl124631x
// Time: O(N + K) where `K` is the range of values in `A` and `B`.
// Space: O(K)
class Solution {
public:
    int minProductSum(vector<int>& A, vector<int>& B) {
        int ca[101] = {}, cb[101] = {}, ans = 0;
        for (int n : A) ca[n]++;
        for (int n : B) cb[n]++;
        for (int i = 1, j = 100, cnt = 0; cnt < A.size();) {
            while (i < 101 && ca[i] == 0) ++i;
            while (j > 0 && cb[j] == 0) --j;
            int d = min(ca[i], cb[j]);
            ans += i * j * d;
            ca[i] -= d;
            cb[j] -= d;
            cnt += d;
        }
        return ans;
    }
};
```