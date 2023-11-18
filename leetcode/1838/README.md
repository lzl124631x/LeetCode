# [1838. Frequency of the Most Frequent Element (Medium)](https://leetcode.com/problems/frequency-of-the-most-frequent-element)

<p>The <strong>frequency</strong> of an element is the number of times it occurs in an array.</p>

<p>You are given an integer array <code>nums</code> and an integer <code>k</code>. In one operation, you can choose an index of <code>nums</code> and increment the element at that index by <code>1</code>.</p>

<p>Return <em>the <strong>maximum possible frequency</strong> of an element after performing <strong>at most</strong> </em><code>k</code><em> operations</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,4], k = 5
<strong>Output:</strong> 3<strong>
Explanation:</strong> Increment the first element three times and the second element two times to make nums = [4,4,4].
4 has a frequency of 3.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,4,8,13], k = 5
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are multiple optimal solutions:
- Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
- Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2.
- Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,9,6], k = 2
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Deutsche Bank](https://leetcode.com/company/deutsche-bank), [Uber](https://leetcode.com/company/uber), [CRED](https://leetcode.com/company/cred), [Microsoft](https://leetcode.com/company/microsoft), [PhonePe](https://leetcode.com/company/phonepe), [Apple](https://leetcode.com/company/apple), [Google](https://leetcode.com/company/google), [Pony.ai](https://leetcode.com/company/ponyai)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Binary Search](https://leetcode.com/tag/binary-search), [Greedy](https://leetcode.com/tag/greedy), [Sliding Window](https://leetcode.com/tag/sliding-window), [Sorting](https://leetcode.com/tag/sorting), [Prefix Sum](https://leetcode.com/tag/prefix-sum)

**Similar Questions**:
* [Find All Lonely Numbers in the Array (Medium)](https://leetcode.com/problems/find-all-lonely-numbers-in-the-array)
* [Longest Nice Subarray (Medium)](https://leetcode.com/problems/longest-nice-subarray)

**Hints**:
* Note that you can try all values in a brute force manner and find the maximum frequency of that value.
* To find the maximum frequency of a value consider the biggest elements smaller than or equal to this value

## Solution 1. Sliding window (Shrinkable)

Check out "[C++ Maximum Sliding Window Cheatsheet Template!](https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175088/C%2B%2B-Maximum-Sliding-Window-Cheatsheet-Template!)"

Since we only care about the frequency, we can sort the array first to simplify the problem.

Let two pointers `i, j` form a window `[i, j]`. The window is valid if `(j - i + 1) * A[j] - sum <= k` where `sum` is the sum of the numbers in window `[i, j]`.

We increment `j` and update `sum`, then shrink the window by incrementing `i` until the window become valid again.

Then the window `[i, j]` with length `j - i + 1` is the maximum window we've seen so far.

```cpp
// OJ: https://leetcode.com/problems/frequency-of-the-most-frequent-element/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maxFrequency(vector<int>& A, int k) {
        sort(begin(A), end(A));
        long i = 0, N = A.size(), ans = 1, sum = 0;
        for (int j = 0; j < N; ++j) {
            sum += A[j];
            while ((j - i + 1) * A[j] - sum > k) sum -= A[i++];
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
```

## Solution 2. Sliding window (Non-shrinkable)

```cpp
// OJ: https://leetcode.com/problems/frequency-of-the-most-frequent-element/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maxFrequency(vector<int>& A, int k) {
        sort(begin(A), end(A));
        long i = 0, j = 0, N = A.size(), sum = 0;
        for (; j < N; ++j) {
            sum += A[j];
            if ((j - i + 1) * A[j] - sum > k) sum -= A[i++];
        }
        return j - i;
    }
};
```

## Discuss

https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175088/C%2B%2B-Maximum-Sliding-Window-Cheatsheet-Template!