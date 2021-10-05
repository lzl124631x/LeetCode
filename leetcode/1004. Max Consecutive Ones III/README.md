# [1004. Max Consecutive Ones III (Medium)](https://leetcode.com/problems/max-consecutive-ones-iii/)

<p>Given a binary array <code>nums</code> and an integer <code>k</code>, return <em>the maximum number of consecutive </em><code>1</code><em>'s in the array if you can flip at most</em> <code>k</code> <code>0</code>'s.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
<strong>Output:</strong> 6
<strong>Explanation:</strong> [1,1,1,0,0,<u><strong>1</strong>,1,1,1,1,<strong>1</strong></u>]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
<strong>Output:</strong> 10
<strong>Explanation:</strong> [0,0,<u>1,1,<strong>1</strong>,<strong>1</strong>,1,1,1,<strong>1</strong>,1,1</u>,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> is either <code>0</code> or <code>1</code>.</li>
	<li><code>0 &lt;= k &lt;= nums.length</code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [DE Shaw](https://leetcode.com/company/de-shaw), [Apple](https://leetcode.com/company/apple), [Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Sliding Window](https://leetcode.com/tag/sliding-window/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Longest Substring with At Most K Distinct Characters (Medium)](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/)
* [Longest Repeating Character Replacement (Medium)](https://leetcode.com/problems/longest-repeating-character-replacement/)
* [Max Consecutive Ones (Easy)](https://leetcode.com/problems/max-consecutive-ones/)
* [Max Consecutive Ones II (Medium)](https://leetcode.com/problems/max-consecutive-ones-ii/)

## Solution 1. Sliding Window

Check out "[C++ Maximum Sliding Window Cheatsheet Template!](https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175088/C%2B%2B-Maximum-Sliding-Window-Cheatsheet-Template!)"

Shrinkable sliding window:
```cpp
// OJ: https://leetcode.com/problems/max-consecutive-ones-iii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int longestOnes(vector<int>& A, int k) {
        int i = 0, j = 0, cnt = 0, N = A.size(), ans = 0;
        while (j < N) {
            cnt += A[j++] == 0;
            while (cnt > k) cnt -= A[i++] == 0;
            ans = max(ans, j - i);
        }
        return ans;
    }
};
```

Or non-shrinkable sliding window:

```cpp
// OJ: https://leetcode.com/problems/max-consecutive-ones-iii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int longestOnes(vector<int>& A, int k) {
        int i = 0, j = 0, cnt = 0, N = A.size();
        while (j < N) {
            cnt += A[j++] == 0;
            if (cnt > k) cnt -= A[i++] == 0;
        }
        return j - i;
    }
};
```

## Discuss

https://leetcode.com/problems/max-consecutive-ones-iii/discuss/1504260/C%2B%2B-Sliding-Window-(%2B-Cheat-Sheet)