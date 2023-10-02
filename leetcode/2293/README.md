# [2293. Min Max Game (Easy)](https://leetcode.com/problems/min-max-game)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> whose length is a power of <code>2</code>.</p>
<p>Apply the following algorithm on <code>nums</code>:</p>
<ol>
	<li>Let <code>n</code> be the length of <code>nums</code>. If <code>n == 1</code>, <strong>end</strong> the process. Otherwise, <strong>create</strong> a new <strong>0-indexed</strong> integer array <code>newNums</code> of length <code>n / 2</code>.</li>
	<li>For every <strong>even</strong> index <code>i</code> where <code>0 &lt;= i &lt; n / 2</code>, <strong>assign</strong> the value of <code>newNums[i]</code> as <code>min(nums[2 * i], nums[2 * i + 1])</code>.</li>
	<li>For every <strong>odd</strong> index <code>i</code> where <code>0 &lt;= i &lt; n / 2</code>, <strong>assign</strong> the value of <code>newNums[i]</code> as <code>max(nums[2 * i], nums[2 * i + 1])</code>.</li>
	<li><strong>Replace</strong> the array <code>nums</code> with <code>newNums</code>.</li>
	<li><strong>Repeat</strong> the entire process starting from step 1.</li>
</ol>
<p>Return <em>the last number that remains in </em><code>nums</code><em> after applying the algorithm.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/04/13/example1drawio-1.png" style="width: 500px; height: 240px;">
<pre><strong>Input:</strong> nums = [1,3,5,2,4,8,2,2]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The following arrays are the results of applying the algorithm repeatedly.
First: nums = [1,5,4,2]
Second: nums = [1,4]
Third: nums = [1]
1 is the last remaining number, so we return 1.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [3]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 3 is already the last remaining number, so we return 3.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 1024</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>nums.length</code> is a power of <code>2</code>.</li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Simulation](https://leetcode.com/tag/simulation/)

**Similar Questions**:
* [Elimination Game (Medium)](https://leetcode.com/problems/elimination-game/)
* [Find Triangular Sum of an Array (Medium)](https://leetcode.com/problems/find-triangular-sum-of-an-array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/min-max-game
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int minMaxGame(vector<int>& A) {
        while (A.size() > 1) {
            vector<int> next(A.size() / 2);
            for (int i = 0; i < next.size(); ++i) {
                if (i % 2 == 0) next[i] = min(A[2 * i], A[2 * i + 1]);
                else next[i] = max(A[2 * i], A[2 * i + 1]);
            }
            swap(next, A);
        }
        return A[0];
    }
};
```

Or compute in place

```cpp
// OJ: https://leetcode.com/problems/min-max-game
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int minMaxGame(vector<int>& A) {
        int N = A.size();
        while (N > 1) {
            N /= 2;
            for (int i = 0; i < N; ++i) {
                if (i % 2 == 0) A[i] = min(A[2 * i], A[2 * i + 1]);
                else A[i] = max(A[2 * i], A[2 * i + 1]);
            }
        }
        return A[0];
    }
};
```