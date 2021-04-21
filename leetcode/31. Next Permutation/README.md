# [31. Next Permutation (Medium)](https://leetcode.com/problems/next-permutation/)

<p>Implement <strong>next permutation</strong>, which rearranges numbers into the lexicographically next greater permutation of numbers.</p>

<p>If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).</p>

<p>The replacement must be <strong><a href="http://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in-place</a></strong> and use only constant&nbsp;extra memory.</p>

<p>Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.</p>

<p><code>1,2,3</code> → <code>1,3,2</code><br>
<code>3,2,1</code> → <code>1,2,3</code><br>
<code>1,1,5</code> → <code>1,5,1</code></p>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Permutations (Medium)](https://leetcode.com/problems/permutations/)
* [Permutations II (Medium)](https://leetcode.com/problems/permutations-ii/)
* [Permutation Sequence (Medium)](https://leetcode.com/problems/permutation-sequence/)
* [Palindrome Permutation II (Medium)](https://leetcode.com/problems/palindrome-permutation-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/next-permutation
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int N = A.size(), i = N - 2;
        for (; i >= 0 && A[i] >= A[i + 1]; --i);
        if (i < 0) {
            reverse(begin(A), end(A));
            return;
        }
        reverse(begin(A) + i + 1, end(A));
        int j = upper_bound(begin(A) + i + 1, end(A), A[i]) - begin(A);
        swap(A[i], A[j]);
    }
};
```