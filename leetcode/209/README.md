# [209. Minimum Size Subarray Sum (Medium)](https://leetcode.com/problems/minimum-size-subarray-sum)

<p>Given an array of positive integers <code>nums</code> and a positive integer <code>target</code>, return <em>the <strong>minimal length</strong> of a </em><span data-keyword="subarray-nonempty" class=" cursor-pointer relative text-dark-blue-s text-sm"><div class="popover-wrapper inline-block" data-headlessui-state=""><div><div id="headlessui-popover-button-:r85:" aria-expanded="false" data-headlessui-state=""><em>subarray</em></div></div></div></span><em> whose sum is greater than or equal to</em> <code>target</code>. If there is no such subarray, return <code>0</code> instead.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> target = 7, nums = [2,3,1,2,4,3]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The subarray [4,3] has the minimal length under the problem constraint.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> target = 4, nums = [1,4,4]
<strong>Output:</strong> 1
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> target = 11, nums = [1,1,1,1,1,1,1,1]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= target &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> If you have figured out the <code>O(n)</code> solution, try coding another solution of which the time complexity is <code>O(n log(n))</code>.

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Sliding Window](https://leetcode.com/tag/sliding-window/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Minimum Window Substring (Hard)](https://leetcode.com/problems/minimum-window-substring/)
* [Maximum Size Subarray Sum Equals k (Hard)](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/)
* [Maximum Length of Repeated Subarray (Hard)](https://leetcode.com/problems/maximum-length-of-repeated-subarray/)
* [Minimum Operations to Reduce X to Zero (Hard)](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/)
* [K Radius Subarray Averages (Hard)](https://leetcode.com/problems/k-radius-subarray-averages/)
* [Maximum Product After K Increments (Hard)](https://leetcode.com/problems/maximum-product-after-k-increments/)

## Solution 1. Sliding Window

```cpp
// OJ: https://leetcode.com/problems/minimum-size-subarray-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0, i = 0, j = 0, N = nums.size(), ans = INT_MAX;
        while (j < N) {
            while (j < N && sum < s) sum += nums[j++];
            if (sum < s) break;
            while (i < j && sum >= s) sum -= nums[i++];
            ans = min(ans, j - i + 1);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
```

## Solution 2. Sliding Window

```cpp
// OJ: https://leetcode.com/problems/minimum-size-subarray-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& A) {
        int sum = 0, N = A.size(), i = 0, j = 0, ans = INT_MAX;
        while (j < N) {
            sum += A[j++];
            while (sum >= target) {
                ans = min(ans, j - i);
                sum -= A[i++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
```

## Solution 3. Binary Search

`valid(len)` returns true if whether there exists a subarray of length `len` that has sum greater than or equal to `target`.

We binary search the length range `[1, N]` because this predicate `valid(len)` is monotonic. That is, there must exist an index `K` that for any `len >= K`, `valid(len)` is true; and for any `len < K`, `valid(len)` is false.

```cpp
// OJ: https://leetcode.com/problems/minimum-size-subarray-sum
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& A) {
        int N = A.size(), L = 1, R = N;
        auto valid = [&](int len) {
            int sum = 0;
            for (int i = 0; i < N; ++i) {
                sum += A[i];
                if (i - len >= 0) sum -= A[i - len];
                if (sum >= target) return true;
            }
            return false;
        };
        while (L <= R) {
            int M = (L + R) / 2;
            if (valid(M)) R = M - 1;
            else L = M + 1;
        }
        return L > N ? 0 : L;
    }
};
```