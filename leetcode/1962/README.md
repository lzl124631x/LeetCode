# [1962. Remove Stones to Minimize the Total (Medium)](https://leetcode.com/problems/remove-stones-to-minimize-the-total/)

<p>You are given a <strong>0-indexed</strong> integer array <code>piles</code>, where <code>piles[i]</code> represents the number of stones in the <code>i<sup>th</sup></code> pile, and an integer <code>k</code>. You should apply the following operation <strong>exactly</strong> <code>k</code> times:</p>

<ul>
	<li>Choose any <code>piles[i]</code> and <strong>remove</strong> <code>floor(piles[i] / 2)</code> stones from it.</li>
</ul>

<p><strong>Notice</strong> that you can apply the operation on the <strong>same</strong> pile more than once.</p>

<p>Return <em>the <strong>minimum</strong> possible total number of stones remaining after applying the </em><code>k</code><em> operations</em>.</p>

<p><code>floor(x)</code> is the <b>greatest</b> integer that is <strong>smaller</strong> than or <strong>equal</strong> to <code>x</code> (i.e., rounds <code>x</code> down).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> piles = [5,4,9], k = 2
<strong>Output:</strong> 12
<strong>Explanation:</strong>&nbsp;Steps of a possible scenario are:
- Apply the operation on pile 2. The resulting piles are [5,4,<u>5</u>].
- Apply the operation on pile 0. The resulting piles are [<u>3</u>,4,5].
The total number of stones in [3,4,5] is 12.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> piles = [4,3,6,7], k = 3
<strong>Output:</strong> 12
<strong>Explanation:</strong>&nbsp;Steps of a possible scenario are:
- Apply the operation on pile 3. The resulting piles are [4,3,<u>3</u>,7].
- Apply the operation on pile 4. The resulting piles are [4,3,3,<u>4</u>].
- Apply the operation on pile 0. The resulting piles are [<u>2</u>,3,3,4].
The total number of stones in [2,3,3,4] is 12.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= piles.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= piles[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>

## Solution 2. Greedy + Max Heap

**Intuition**: We greedily remove stones from the largest pile repetitively.

**Algorithm**: Use a max heap `pq` to store the values. Keep popping the heap top (say `n`), remove `n / 2` stones, and push `n - n / 2` back to the heap, repeating `k` times. The answer is the sum of `piles` minus the sum of all stones removed.

```cpp
// OJ: https://leetcode.com/problems/remove-stones-to-minimize-the-total/
// Author: github.com/lzl124631x
// Time: O((N + K) * logN)
// Space: O(N)
class Solution {
public:
    int minStoneSum(vector<int>& A, int k) {
        priority_queue<int> pq;
        for (int n : A) pq.push(n);
        long rm = 0, sum = accumulate(begin(A), end(A), 0L);
        for (int i = 0; i < k; ++i) {
            int n = pq.top();
            pq.pop();
            if (n == 1) break;
            rm += n / 2;
            pq.push(n - n / 2);
        }
        return sum - rm;
    }
};
```