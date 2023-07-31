# [2593. Find Score of an Array After Marking All Elements (Medium)](https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements)

<p>You are given an array <code>nums</code> consisting of positive integers.</p>
<p>Starting with <code>score = 0</code>, apply the following algorithm:</p>
<ul>
	<li>Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.</li>
	<li>Add the value of the chosen integer to <code>score</code>.</li>
	<li>Mark <strong>the chosen element and its two adjacent elements if they exist</strong>.</li>
	<li>Repeat until all the array elements are marked.</li>
</ul>
<p>Return <em>the score you get after applying the above algorithm</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [2,1,3,4,5,2]
<strong>Output:</strong> 7
<strong>Explanation:</strong> We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [<u>2</u>,<u>1</u>,<u>3</u>,4,5,2].
- 2 is the smallest unmarked element, so we mark it and its left adjacent element: [<u>2</u>,<u>1</u>,<u>3</u>,4,<u>5</u>,<u>2</u>].
- 4 is the only remaining unmarked element, so we mark it: [<u>2</u>,<u>1</u>,<u>3</u>,<u>4</u>,<u>5</u>,<u>2</u>].
Our score is 1 + 2 + 4 = 7.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [2,3,5,1,3,2]
<strong>Output:</strong> 5
<strong>Explanation:</strong> We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,3,<u>5</u>,<u>1</u>,<u>3</u>,2].
- 2 is the smallest unmarked element, since there are two of them, we choose the left-most one, so we mark the one at index 0 and its right adjacent element: [<u>2</u>,<u>3</u>,<u>5</u>,<u>1</u>,<u>3</u>,2].
- 2 is the only remaining unmarked element, so we mark it: [<u>2</u>,<u>3</u>,<u>5</u>,<u>1</u>,<u>3</u>,<u>2</u>].
Our score is 1 + 2 + 2 = 5.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sorting](https://leetcode.com/tag/sorting/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Simulation](https://leetcode.com/tag/simulation/)

**Similar Questions**:
* [Sort Integers by The Power Value (Medium)](https://leetcode.com/problems/sort-integers-by-the-power-value/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    long long findScore(vector<int>& A) {
        long long N = A.size(), ans = 0;
        vector<int> id(N);
        iota(begin(id), end(id), 0);
        sort(begin(id), end(id), [&](int a, int b) { return A[a] != A[b] ? A[a] < A[b] : a < b; });
        for (int i = 0; i < N; ++i) {
            int j = id[i];
            if (A[j] == 0) continue;
            ans += A[j];
            if (j - 1 >= 0) A[j - 1] = 0;
            if (j + 1 < N) A[j + 1] = 0;
        }
        return ans;
    }
};
```