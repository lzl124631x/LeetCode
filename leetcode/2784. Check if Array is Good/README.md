# [2784. Check if Array is Good (Easy)](https://leetcode.com/problems/check-if-array-is-good)

<p>You are given an integer array <code>nums</code>. We consider an array <strong>good </strong>if it is a permutation of an array <code>base[n]</code>.</p>
<p><code>base[n] = [1, 2, ..., n - 1, n, n] </code>(in other words, it is an array of length <code>n + 1</code> which contains <code>1</code> to <code>n - 1 </code>exactly once, plus two occurrences of <code>n</code>). For example, <code>base[1] = [1, 1]</code> and<code> base[3] = [1, 2, 3, 3]</code>.</p>
<p>Return <code>true</code> <em>if the given array is good, otherwise return</em><em> </em><code>false</code>.</p>
<p><strong>Note: </strong>A permutation of integers represents an arrangement of these numbers.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [2, 1, 3]
<strong>Output:</strong> false
<strong>Explanation:</strong> Since the maximum element of the array is 3, the only candidate n for which this array could be a permutation of base[n], is n = 3. However, base[3] has four elements but array nums has three. Therefore, it can not be a permutation of base[3] = [1, 2, 3, 3]. So the answer is false.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1, 3, 3, 2]
<strong>Output:</strong> true
<strong>Explanation:</strong> Since the maximum element of the array is 3, the only candidate n for which this array could be a permutation of base[n], is n = 3. It can be seen that nums is a permutation of base[3] = [1, 2, 3, 3] (by swapping the second and fourth elements in nums, we reach base[3]). Therefore, the answer is true.</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [1, 1]
<strong>Output:</strong> true
<strong>Explanation:</strong> Since the maximum element of the array is 1, the only candidate n for which this array could be a permutation of base[n], is n = 1. It can be seen that nums is a permutation of base[1] = [1, 1]. Therefore, the answer is true.</pre>
<p><strong class="example">Example 4:</strong></p>
<pre><strong>Input:</strong> nums = [3, 4, 4, 1, 2, 1]
<strong>Output:</strong> false
<strong>Explanation:</strong> Since the maximum element of the array is 4, the only candidate n for which this array could be a permutation of base[n], is n = 4. However, base[4] has five elements but array nums has six. Therefore, it can not be a permutation of base[4] = [1, 2, 3, 4, 4]. So the answer is false.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= num[i] &lt;= 200</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Sorting](https://leetcode.com/tag/sorting/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/check-if-array-is-good
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isGood(vector<int>& A) {
        int N = A.size() - 1;
        for (int i = 0; i < N; ) {
            if (A[i] != i + 1) {
                if (A[i] < i + 1 || A[i] > N || (A[i] != N && A[A[i] - 1] == A[i])) return false;
                if (A[i] == N && A[A[i] - 1] == N) {
                    if (A[N] == N) return false;
                    swap(A[i], A[N]);
                }
                else swap(A[i], A[A[i] - 1]);
            } else ++i;
        }
        return A[N] == N;
    }
};
```

## Solution 2. Cycle Sort

```cpp
// OJ: https://leetcode.com/problems/check-if-array-is-good
// Author: github.com/lzl124631x
// Time: O()
// Space: O()
class Solution {
public:
    bool isGood(vector<int>& A) {
        int N = A.size();
        for (int i = 0; i < N;) {
            if (A[i] >= N) return false;
            int pos = A[i] - 1;
            if (A[pos] == A[i]) ++i;
            else swap(A[pos], A[i]);
        }
        for (int i = 0; i < N - 1; ++i) {
            if (A[i] != i + 1) return false;
        }
        return A[N - 1] == N - 1;
    }
};
```