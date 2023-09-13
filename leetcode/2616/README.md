# [2616. Minimize the Maximum Difference of Pairs (Medium)](https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> and an integer <code>p</code>. Find <code>p</code> pairs of indices of <code>nums</code> such that the <strong>maximum</strong> difference amongst all the pairs is <strong>minimized</strong>. Also, ensure no index appears more than once amongst the <code>p</code> pairs.</p>
<p>Note that for a pair of elements at the index <code>i</code> and <code>j</code>, the difference of this pair is <code>|nums[i] - nums[j]|</code>, where <code>|x|</code> represents the <strong>absolute</strong> <strong>value</strong> of <code>x</code>.</p>
<p>Return <em>the <strong>minimum</strong> <strong>maximum</strong> difference among all </em><code>p</code> <em>pairs.</em> We define the maximum of an empty set to be zero.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [10,1,2,7,1,3], p = 2
<strong>Output:</strong> 1
<strong>Explanation:</strong> The first pair is formed from the indices 1 and 4, and the second pair is formed from the indices 2 and 5. 
The maximum difference is max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [4,2,1,2], p = 1
<strong>Output:</strong> 0
<strong>Explanation:</strong> Let the indices 1 and 3 form a pair. The difference of that pair is |2 - 2| = 0, which is the minimum we can attain.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= p &lt;= (nums.length)/2</code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Minimum Absolute Difference (Easy)](https://leetcode.com/problems/minimum-absolute-difference/)
* [Minimum Difference Between Largest and Smallest Value in Three Moves (Medium)](https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/)

## Solution 1. Binary Search

```cpp
// OJ: https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int minimizeMax(vector<int>& A, int P) {
        sort(begin(A), end(A));
        int N = A.size(), L = 0, R = A.back() - A[0];
        auto valid = [&](int t) {
            int cnt = 0;
            for (int i = 1; i < N && cnt < P;) {
                if (A[i] - A[i - 1] <= t) ++cnt, i += 2;
                else ++i;
            }
            return cnt == P;
        };
        while (L <= R) {
            int M = (L + R) / 2;
            if (valid(M)) R = M - 1;
            else L = M + 1;
        }
        return L;
    }
};
```