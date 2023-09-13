# [1674. Minimum Moves to Make Array Complementary (Medium)](https://leetcode.com/problems/minimum-moves-to-make-array-complementary/)

<p>You are given an integer array <code>nums</code> of <strong>even</strong> length <code>n</code> and an integer <code>limit</code>. In one move, you can replace any integer from <code>nums</code> with another integer between <code>1</code> and <code>limit</code>, inclusive.</p>

<p>The array <code>nums</code> is <strong>complementary</strong> if for all indices <code>i</code> (<strong>0-indexed</strong>), <code>nums[i] + nums[n - 1 - i]</code> equals the same number. For example, the array <code>[1,2,3,4]</code> is complementary because for all indices <code>i</code>, <code>nums[i] + nums[n - 1 - i] = 5</code>.</p>

<p>Return the <em><strong>minimum</strong> number of moves required to make </em><code>nums</code><em> <strong>complementary</strong></em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,4,3], limit = 4
<strong>Output:</strong> 1
<strong>Explanation:</strong> In 1 move, you can change nums to [1,2,<u>2</u>,3] (underlined elements are changed).
nums[0] + nums[3] = 1 + 3 = 4.
nums[1] + nums[2] = 2 + 2 = 4.
nums[2] + nums[1] = 2 + 2 = 4.
nums[3] + nums[0] = 3 + 1 = 4.
Therefore, nums[i] + nums[n-1-i] = 4 for every i, so nums is complementary.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,2,1], limit = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> In 2 moves, you can change nums to [<u>2</u>,2,2,<u>2</u>]. You cannot change any number to 3 since 3 &gt; limit.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,1,2], limit = 2
<strong>Output:</strong> 0
<strong>Explanation:</strong> nums is already complementary.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>2 &lt;= n&nbsp;&lt;=&nbsp;10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i]&nbsp;&lt;= limit &lt;=&nbsp;10<sup>5</sup></code></li>
	<li><code>n</code> is even.</li>
</ul>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. Difference Array

Assume we want to make all the pairs to sum to `T`, and `(A, B)` is a pair of numbers. We have the following cases:

1. `2 <= T <= min(A, B)`. We need `2` operations because we need to make both smaller.
2. `min(A, B) < T < A + B`. We need `1` operation because we only need to make the greater one smaller.
3. `T == A + B`. We need `0` operation.
4. `A + B < T <= max(A, B) + limit`. We need `1` operation because we only need to make the smaller one greater.
5. `max(A, B) + limit < T <= 2 * limit`. We need `2` operations because we need to make both greater.

We can calculate the boundary for each pair `(A, B)` and note down the corresponding operation needed in `cnt` array where `cnt[i]` means that we need `cnt[i]` operations when `T == i`. 

We need to use the above 5 cases to add values into `cnt`.

For each pair `(A, B)`, we do the following:

1. `cnt[i] += 2` if `2 <= i <= min(A, B)`
2. `cnt[i] += 1` if `min(A, B) < i < A + B`
3. `cnt[i] += 0` if `i == A + B`
4. `cnt[i] += 1` if `A + B < i <= max(A, B) + limit`
5. `cnt[i] += 2` if `max(A, B) + limit < T <= 2 * limit`

But for each pair we need to visit `2 * limit - 2` elements in `cnt`, and there are `N / 2` pairs, so the time complexity is `O(NL)` which will get TLE.

To resolve this, we can make it a **difference array**, i.e. only save the difference of operations when we move from `i - 1` to `i`.

Assume the difference array is `delta`, where `delta[i] = cnt[i] - cnt[i - 1]`, i.e. the difference of operations needed when changing `T` from `i - 1` to `i`.

For example, `delta[3] = 1` means that if we change `T` from `2` to `3`, we need one more operation.

So in this way, we don't need to change all `2 * limit - 2` elements. Instead, just change 5 break points:

1. `delta[2] += 2`.
2. `delta[min(A, B) + 1] -= 1`.
3. `delta[A + B] -= 1`.
4. `delta[A + B + 1] += 1`.
5. `delta[max(A, B) + limit + 1] += 1`.

And in the end we just need to go over the `2 * limit - 2` elements to get the operations needed for each `T`, and return the minimum among them.

### Time complexity

Calculating the `delta` array takes `O(N)` time. Reconstructing the `cnt`s from `delta` takes `O(L)` time. So overall it's `O(N + L)` time.

```cpp
// OJ: https://leetcode.com/problems/minimum-moves-to-make-array-complementary/
// Author: github.com/lzl124631x
// Time: O(N + L)
// Space: O(L)
// Ref: https://leetcode.com/problems/minimum-moves-to-make-array-complementary/discuss/952773/PythonJava-simple-O(max(n-k))-method
class Solution {
public:
    int minMoves(vector<int>& A, int L) {
        vector<int> delta(2 * L + 2); // difference array
        int N = A.size(), ans = N, cur = 0;
        for (int i = 0; i < N / 2; ++i) {
            int a = A[i], b = A[N - i - 1];
            delta[2] += 2;
            delta[min(a, b) + 1]--;
            delta[a + b]--;
            delta[a + b + 1]++;
            delta[max(a, b) + L + 1]++;
        }
        for (int i = 2; i <= 2 * L; ++i) {
            cur += delta[i];
            ans = min(ans, cur);
        }
        return ans;
    }
};
```