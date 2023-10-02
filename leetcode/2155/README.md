# [2155. All Divisions With the Highest Score of a Binary Array (Medium)](https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/)

<p>You are given a <strong>0-indexed</strong> binary array <code>nums</code> of length <code>n</code>. <code>nums</code> can be divided at index <code>i</code> (where <code>0 &lt;= i &lt;= n)</code> into two arrays (possibly empty) <code>nums<sub>left</sub></code> and <code>nums<sub>right</sub></code>:</p>

<ul>
	<li><code>nums<sub>left</sub></code> has all the elements of <code>nums</code> between index <code>0</code> and <code>i - 1</code> <strong>(inclusive)</strong>, while <code>nums<sub>right</sub></code> has all the elements of nums between index <code>i</code> and <code>n - 1</code> <strong>(inclusive)</strong>.</li>
	<li>If <code>i == 0</code>, <code>nums<sub>left</sub></code> is <strong>empty</strong>, while <code>nums<sub>right</sub></code> has all the elements of <code>nums</code>.</li>
	<li>If <code>i == n</code>, <code>nums<sub>left</sub></code> has all the elements of nums, while <code>nums<sub>right</sub></code> is <strong>empty</strong>.</li>
</ul>

<p>The <strong>division score</strong> of an index <code>i</code> is the <strong>sum</strong> of the number of <code>0</code>'s in <code>nums<sub>left</sub></code> and the number of <code>1</code>'s in <code>nums<sub>right</sub></code>.</p>

<p>Return <em><strong>all distinct indices</strong> that have the <strong>highest</strong> possible <strong>division score</strong></em>. You may return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [0,0,1,0]
<strong>Output:</strong> [2,4]
<strong>Explanation:</strong> Division at index
- 0: nums<sub>left</sub> is []. nums<sub>right</sub> is [0,0,<u><strong>1</strong></u>,0]. The score is 0 + 1 = 1.
- 1: nums<sub>left</sub> is [<u><strong>0</strong></u>]. nums<sub>right</sub> is [0,<u><strong>1</strong></u>,0]. The score is 1 + 1 = 2.
- 2: nums<sub>left</sub> is [<u><strong>0</strong></u>,<u><strong>0</strong></u>]. nums<sub>right</sub> is [<u><strong>1</strong></u>,0]. The score is 2 + 1 = 3.
- 3: nums<sub>left</sub> is [<u><strong>0</strong></u>,<u><strong>0</strong></u>,1]. nums<sub>right</sub> is [0]. The score is 2 + 0 = 2.
- 4: nums<sub>left</sub> is [<u><strong>0</strong></u>,<u><strong>0</strong></u>,1,<u><strong>0</strong></u>]. nums<sub>right</sub> is []. The score is 3 + 0 = 3.
Indices 2 and 4 both have the highest possible division score 3.
Note the answer [4,2] would also be accepted.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0,0,0]
<strong>Output:</strong> [3]
<strong>Explanation:</strong> Division at index
- 0: nums<sub>left</sub> is []. nums<sub>right</sub> is [0,0,0]. The score is 0 + 0 = 0.
- 1: nums<sub>left</sub> is [<u><strong>0</strong></u>]. nums<sub>right</sub> is [0,0]. The score is 1 + 0 = 1.
- 2: nums<sub>left</sub> is [<u><strong>0</strong></u>,<u><strong>0</strong></u>]. nums<sub>right</sub> is [0]. The score is 2 + 0 = 2.
- 3: nums<sub>left</sub> is [<u><strong>0</strong></u>,<u><strong>0</strong></u>,<u><strong>0</strong></u>]. nums<sub>right</sub> is []. The score is 3 + 0 = 3.
Only index 3 has the highest possible division score 3.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,1]
<strong>Output:</strong> [0]
<strong>Explanation:</strong> Division at index
- 0: nums<sub>left</sub> is []. nums<sub>right</sub> is [<u><strong>1</strong></u>,<u><strong>1</strong></u>]. The score is 0 + 2 = 2.
- 1: nums<sub>left</sub> is [1]. nums<sub>right</sub> is [<u><strong>1</strong></u>]. The score is 0 + 1 = 1.
- 2: nums<sub>left</sub> is [1,1]. nums<sub>right</sub> is []. The score is 0 + 0 = 0.
Only index 0 has the highest possible division score 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>


**Similar Questions**:
* [Ones and Zeroes (Medium)](https://leetcode.com/problems/ones-and-zeroes/)
* [Max Consecutive Ones II (Medium)](https://leetcode.com/problems/max-consecutive-ones-ii/)
* [Count Subarrays With More Ones Than Zeros (Medium)](https://leetcode.com/problems/count-subarrays-with-more-ones-than-zeros/)
* [Array Partition I (Easy)](https://leetcode.com/problems/array-partition-i/)
* [Divide Array in Sets of K Consecutive Numbers (Medium)](https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/)

## Solution 1. Count Left Ones and Right Zeros on the fly

Let `zero`/`one` be the number of zeros/ones in the left/right part. Initially `one = SUM(A)`.

For each `i`, `score = zero + one`. And we can update `zero` and `one` when we move `A[i]` from right part to left part.

```cpp
// OJ: https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& A) {
        int N = A.size(), one = accumulate(begin(A), end(A), 0), zero = 0, mx = 0;
        vector<int> ans;
        for (int i = 0; i <= N; ++i) {
            int score = one + zero;
            if (score > mx) {
                ans = {i};
                mx = score;
            } else if (score == mx) ans.push_back(i);
            if (i < N) {
                one -= A[i] == 1;
                zero += A[i] == 0;
            }
        }
        return ans;
    }
};
```

Note that here I marked extra space complexity as `O(N)` because the `ans` is used to store some temporary results whose length might be as long as `N-1` while the answer might be just of length 1. So, the extra space we used might be linear to the input but not strictly confined by the size of the real answer.

That said, we can make it `O(1)` space by calculating the maximum score in one loop first then gather the `ans` array in another loop. In this way, the size of the `ans` is absolutely the same as the size of the real answer and won't be linear to the input size. But, this requires two loops.

## Solution 2. Prefix Sum

Let `sum[i+1]` be `A[0] + ... + A[i]`.

For index `i`, there are `i - sum[i]` zeros in the left part and `sum[N] - sum[i]` ones in the right part.

So the score for `i` is `i - sum[i] + sum[N] - sum[i]`.

```cpp
// OJ: https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& A) {
        int N = A.size(), mx = 0;
        vector<int> sum(N + 1, 0), ans;
        for (int i = 0; i < N; ++i) sum[i + 1] = sum[i] + A[i];
        for (int i = 0; i <= N; ++i) {
            int score = i - sum[i] + sum[N] - sum[i];
            if (score > mx) {
                ans = {i};
                mx = score;
            } else if (score == mx) ans.push_back(i);
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/discuss/1730117