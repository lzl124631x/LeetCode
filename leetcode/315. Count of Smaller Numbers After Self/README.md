# [315. Count of Smaller Numbers After Self (Hard)](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)

<p>You are given an integer array <i>nums</i> and you have to return a new <i>counts</i> array. The <i>counts</i> array has the property where <code>counts[i]</code> is the number of smaller elements to the right of <code>nums[i]</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [5,2,6,1]
<strong>Output:</strong> [2,1,1,0]
<strong>Explanation:</strong>
To the right of 5 there are <b>2</b> smaller elements (2 and 1).
To the right of 2 there is only <b>1</b> smaller element (1).
To the right of 6 there is <b>1</b> smaller element (1).
To the right of 1 there is <b>0</b> smaller element.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= nums.length &lt;= 10^5</code></li>
	<li><code>-10^4&nbsp;&lt;= nums[i] &lt;= 10^4</code></li>
</ul>


**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/), [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Sort](https://leetcode.com/tag/sort/), [Binary Indexed Tree](https://leetcode.com/tag/binary-indexed-tree/), [Segment Tree](https://leetcode.com/tag/segment-tree/)

**Similar Questions**:
* [Count of Range Sum (Hard)](https://leetcode.com/problems/count-of-range-sum/)
* [Queue Reconstruction by Height (Medium)](https://leetcode.com/problems/queue-reconstruction-by-height/)
* [Reverse Pairs (Hard)](https://leetcode.com/problems/reverse-pairs/)
* [How Many Numbers Are Smaller Than the Current Number (Easy)](https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/)

## Solution 1. Divide and Conquer (Merge Sort)

The idea is similar to Merge Sort.

```cpp
// OJ: https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
    vector<int> id, tmp, ans;
    void solve(vector<int> &A, int begin, int end) {
        if (begin + 1 >= end) return;
        int mid = (begin + end) / 2, i = begin, j = mid, k = begin;
        solve(A, begin, mid);
        solve(A, mid, end);
        for (; i < mid; ++i) {
            while (j < end && A[id[j]] < A[id[i]]) {
                tmp[k++] = id[j++];
            }
            ans[id[i]] += j - mid;
            tmp[k++] = id[i];
        }
        for (; j < end; ++j) tmp[k++] = id[j];
        for (int i = begin; i < end; ++i) id[i] = tmp[i];
    }
public:
    vector<int> countSmaller(vector<int>& A) {
        int N = A.size();
        id.assign(N, 0);
        tmp.assign(N, 0);
        ans.assign(N, 0);
        iota(begin(id), end(id), 0);
        solve(A, 0, N);
        return ans;
    }
};
```
