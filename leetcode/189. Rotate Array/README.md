# [189. Rotate Array (Medium)](https://leetcode.com/problems/rotate-array/)

<p>Given an array, rotate the array to the right by <code>k</code> steps, where <code>k</code> is non-negative.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4,5,6,7], k = 3
<strong>Output:</strong> [5,6,7,1,2,3,4]
<strong>Explanation:</strong>
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [-1,-100,3,99], k = 2
<strong>Output:</strong> [3,99,-1,-100]
<strong>Explanation:</strong> 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>

<ul>
	<li>Try to come up with as many solutions as you can. There are at least <strong>three</strong> different ways to solve this problem.</li>
	<li>Could you do it in-place with <code>O(1)</code> extra space?</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google), [Adobe](https://leetcode.com/company/adobe), [Apple](https://leetcode.com/company/apple), [Yahoo](https://leetcode.com/company/yahoo), [tcs](https://leetcode.com/company/tcs)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [Rotate List (Medium)](https://leetcode.com/problems/rotate-list/)
* [Reverse Words in a String II (Medium)](https://leetcode.com/problems/reverse-words-in-a-string-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/rotate-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(K)
class Solution {
public:
    void rotate(vector<int>& A, int k) {
        int N = A.size();
        k %= N;
        if (k == 0) return;
        vector<int> tmp(k);
        for (int i = 0; i < k; ++i) tmp[i] = A[N + i - k];
        for (int i = N - k - 1; i >= 0; --i) A[i + k] = A[i];
        for (int i = 0; i < k; ++i) A[i] = tmp[i];
    }
};
```

## Solution 2. In-place Rotation

```cpp
// OJ: https://leetcode.com/problems/rotate-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void rotate(vector<int>& A, int k) {
        int cnt = 0, N = A.size();
        k %= N;
        if (k == 0) return;
        for (int i = 0; cnt < N; ++i) {
            int j = i, tmp = A[j];
            do {
                int t = (j + k) % N, next = A[t];
                A[t] = tmp;
                tmp = next;
                j = t;
                ++cnt;
            } while (j != i);
        }
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/rotate-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void rotate(vector<int>& A, int k) {
        k = (2 * A.size() - k) % A.size();
        if (k == 0) return;
        reverse(begin(A), begin(A) + k);
        reverse(begin(A) + k, end(A));
        reverse(begin(A), end(A));
    }
};
```