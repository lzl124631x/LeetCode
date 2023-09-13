# [2106. Maximum Fruits Harvested After at Most K Steps (Hard)](https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/)

<p>Fruits are available at some positions on an infinite x-axis. You are given a 2D integer array <code>fruits</code> where <code>fruits[i] = [position<sub>i</sub>, amount<sub>i</sub>]</code> depicts <code>amount<sub>i</sub></code> fruits at the position <code>position<sub>i</sub></code>. <code>fruits</code> is already <strong>sorted</strong> by <code>position<sub>i</sub></code> in <strong>ascending order</strong>, and each <code>position<sub>i</sub></code> is <strong>unique</strong>.</p>

<p>You are also given an integer <code>startPos</code> and an integer <code>k</code>. Initially, you are at the position <code>startPos</code>. From any position, you can either walk to the <strong>left or right</strong>. It takes <strong>one step</strong> to move <strong>one unit</strong> on the x-axis, and you can walk <strong>at most</strong> <code>k</code> steps in total. For every position you reach, you harvest all the fruits at that position, and the fruits will disappear from that position.</p>

<p>Return <em>the <strong>maximum total number</strong> of fruits you can harvest</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/11/21/1.png" style="width: 472px; height: 115px;">
<pre><strong>Input:</strong> fruits = [[2,8],[6,3],[8,6]], startPos = 5, k = 4
<strong>Output:</strong> 9
<strong>Explanation:</strong> 
The optimal way is to:
- Move right to position 6 and harvest 3 fruits
- Move right to position 8 and harvest 6 fruits
You moved 3 steps and harvested 3 + 6 = 9 fruits in total.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/11/21/2.png" style="width: 512px; height: 129px;">
<pre><strong>Input:</strong> fruits = [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]], startPos = 5, k = 4
<strong>Output:</strong> 14
<strong>Explanation:</strong> 
You can move at most k = 4 steps, so you cannot reach position 0 nor 10.
The optimal way is to:
- Harvest the 7 fruits at the starting position 5
- Move left to position 4 and harvest 1 fruit
- Move right to position 6 and harvest 2 fruits
- Move right to position 7 and harvest 4 fruits
You moved 1 + 3 = 4 steps and harvested 7 + 1 + 2 + 4 = 14 fruits in total.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/11/21/3.png" style="width: 476px; height: 100px;">
<pre><strong>Input:</strong> fruits = [[0,3],[6,4],[8,5]], startPos = 3, k = 2
<strong>Output:</strong> 0
<strong>Explanation:</strong>
You can move at most k = 2 steps and cannot reach any position with fruits.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= fruits.length &lt;= 10<sup>5</sup></code></li>
	<li><code>fruits[i].length == 2</code></li>
	<li><code>0 &lt;= startPos, position<sub>i</sub> &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>position<sub>i-1</sub> &lt; position<sub>i</sub></code> for any <code>i &gt; 0</code>&nbsp;(<strong>0-indexed</strong>)</li>
	<li><code>1 &lt;= amount<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= k &lt;= 2 * 10<sup>5</sup></code></li>
</ul>


**Similar Questions**:
* [Maximum Performance of a Team (Hard)](https://leetcode.com/problems/maximum-performance-of-a-team/)

## Solution 1. Sliding Window

```cpp
// OJ: https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& A, int start, int k) {
        int N = A.size(), i = 0, sum = 0;
        for (; i < N && A[i][0] <= start; ++i);
        int j = i;
        while (j < N && A[j][0] - start <= k) sum += A[j++][1];
        --j;
        int ans = sum;
        while (i > 0) {
            --i;
            sum += A[i][1];
            while (j >= i && A[j][0] - start + A[j][0] - A[i][0] > k) {
                sum -= A[j--][1];
            }
            if (j < i) continue;
            if (A[j][0] < start) break;
            ans = max(ans, sum);
        }
        i = N - 1;
        sum = 0;
        for (; i >= 0 && A[i][0] >= start; --i);
        j = i;
        while (j >= 0 && start - A[j][0] <= k) sum += A[j--][1];
        ++j;
        ans = max(ans, sum);
        while (i < N - 1) {
            ++i;
            sum += A[i][1];
            while (j <= i && start - A[j][0] + A[i][0] - A[j][0] > k) {
                sum -= A[j++][1];
            }
            if (j > i) continue;
            if (A[j][0] > start) break;
            ans = max(ans, sum);
        }
        return ans;
    }
};
```

## Solution 2. Sliding Window

Note: when comparing 2 vectors, the result is determined in the following order:
1. The first place where the values differ between the two arrays. 
2. If we've exhausted one array and still can't have a difference, the array with longer length is greater.

In the following code, we use `{start - k}` in the binary search. It is always smaller than a position with the same `x` value `{start - k, amount}`. So using `upper_bound` or `lower_bound` makes no difference.

`(start - A[i][0]) + (A[j][0] - A[i][0])` is the steps needed to go left first then right.

`(A[j][0] - A[i][0]) + (A[j][0] - start)` is the steps needed to go right first then left.

```cpp
// OJ: https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/discuss/1624215/(Strange)-Sliding-Window
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& A, int start, int k) {
        int i = upper_bound(begin(A), end(A), vector<int>{start - k}) - begin(A), sum = 0, ans = 0, N = A.size();
        for (int j = i; j < N && A[j][0] <= start + k; ++j) {
            sum += A[j][1];
            while (min(start - 2 * A[i][0] + A[j][0], 2 * A[j][0] - A[i][0] - start) > k) sum -= A[i++][1];
            ans = max(ans, sum);
        }
        return ans;
    }
};
```