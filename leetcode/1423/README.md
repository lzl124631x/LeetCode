# [1423. Maximum Points You Can Obtain from Cards (Medium)](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/)

<p>There are several cards&nbsp;<strong>arranged in a row</strong>, and each card has an associated number of points&nbsp;The points are given in the integer array&nbsp;<code>cardPoints</code>.</p>

<p>In one step, you can take one card from the beginning or from the end of the row. You have to take exactly <code>k</code> cards.</p>

<p>Your score is the sum of the points of the cards you have taken.</p>

<p>Given the integer array <code>cardPoints</code> and the integer <code>k</code>, return the <em>maximum score</em> you can obtain.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> cardPoints = [1,2,3,4,5,6,1], k = 3
<strong>Output:</strong> 12
<strong>Explanation:</strong> After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> cardPoints = [2,2,2], k = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> Regardless of which two cards you take, your score will always be 4.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> cardPoints = [9,7,7,9,7,7,9], k = 7
<strong>Output:</strong> 55
<strong>Explanation:</strong> You have to take all the cards. Your score is the sum of points of all cards.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> cardPoints = [1,1000,1], k = 1
<strong>Output:</strong> 1
<strong>Explanation:</strong> You cannot take the card in the middle. Your best score is 1. 
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> cardPoints = [1,79,80,1,1,1,200,1], k = 3
<strong>Output:</strong> 202
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= cardPoints.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= cardPoints[i] &lt;= 10^4</code></li>
	<li><code>1 &lt;= k &lt;= cardPoints.length</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

## Solution 1. Sliding Window

The cards selected must exist at the left edge or right edge of the array. So we can start from "selecting all cards from the right edge", then select one card from left edge and remove one card from right, and so forth.

We use `right` as the sum of cards we selected at the right edge, and `left` as the sum of the cards at the left edge.

We start with computing the `k` elements at the right edge as `right`, then for each `i` in range `[0, k)`, we add `A[i]` to `left`, and deduct `A[N - k + i]` from `right`, the result is the maximum `left + right`.

```cpp
// OJ: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
// Author: github.com/lzl124631x
// Time: O(K)
// Space: O(1)
class Solution {
public:
    int maxScore(vector<int>& A, int k) {
        int ans = 0, N = A.size(), left = 0, right = 0;
        for (int i = 0; i < k; ++i) right += A[N - i - 1];
        ans = right;
        for (int i = 0; i < k; ++i) {
            left += A[i];
            right -= A[N - k + i];
            ans = max(ans, left + right);
        }
        return ans;
    }
};
```