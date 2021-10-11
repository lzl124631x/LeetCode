# [930. Binary Subarrays With Sum (Medium)](https://leetcode.com/problems/binary-subarrays-with-sum/)

<p>Given a binary array <code>nums</code> and an integer <code>goal</code>, return <em>the number of non-empty <strong>subarrays</strong> with a sum</em> <code>goal</code>.</p>

<p>A <strong>subarray</strong> is a contiguous part of the array.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,0,1,0,1], goal = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> The 4 subarrays are bolded and underlined below:
[<u><strong>1,0,1</strong></u>,0,1]
[<u><strong>1,0,1,0</strong></u>,1]
[1,<u><strong>0,1,0,1</strong></u>]
[1,0,<u><strong>1,0,1</strong></u>]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0,0,0,0,0], goal = 0
<strong>Output:</strong> 15
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>nums[i]</code> is either <code>0</code> or <code>1</code>.</li>
	<li><code>0 &lt;= goal &lt;= nums.length</code></li>
</ul>

**Companies**:  
[C3 IoT](https://leetcode.com/company/c3-iot), [Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Sliding Window](https://leetcode.com/tag/sliding-window/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

## Solution 1. Prefix State Map

```cpp
// OJ: https://leetcode.com/problems/binary-subarrays-with-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int goal) {
        unordered_map<int, int> m{{0,-1}}; // count of 1s -> index
        int ans = 0;
        for (int i = 0, N = A.size(), sum = 0; i < N; ++i) {
            sum += A[i];
            if (m.count(sum) == 0) m[sum] = i;
            if (goal == 0) ans += i - m[sum];
            else if (sum - goal >= 0) ans += m[sum - goal + 1] - m[sum - goal];
        }
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/binary-subarrays-with-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        unordered_map<int, int> m{{0, 1}}; // sum -> number of occurrences of this sum
        int sum = 0, ans = 0;
        for (int n : A) {
            sum += n;
            ans += m.count(sum - S) ? m[sum - S] : 0;
            m[sum]++;
        }
        return ans;
    }
};
```

## Solution 2. At Most to Equal + Find Maximum Sliding Window

Check out "[C++ Maximum Sliding Window Cheatsheet Template!](https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175088/C%2B%2B-Maximum-Sliding-Window-Cheatsheet-Template!)".

```cpp
// OJ: https://leetcode.com/problems/binary-subarrays-with-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    int atMost(vector<int> A, int goal) {
        int N = A.size(), i = 0, j = 0, cnt = 0, ans = 0;
        while (j < N) {
            cnt += A[j++];
            while (i < j && cnt > goal) cnt -= A[i++];
            ans += j - i;
        }
        return ans;
    }
public:
    int numSubarraysWithSum(vector<int>& A, int goal) {
        return atMost(A, goal) - atMost(A, goal - 1);
    }
};
```

Similar problem:
* [992. Subarrays with K Different Integers (Hard)](https://leetcode.com/problems/subarrays-with-k-different-integers/)
* [1248. Count Number of Nice Subarrays (Medium)](https://leetcode.com/problems/count-number-of-nice-subarrays/)