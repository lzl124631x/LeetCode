# [1642. Furthest Building You Can Reach (Medium)](https://leetcode.com/problems/furthest-building-you-can-reach/)

<p>You are given an integer array <code>heights</code> representing the heights of buildings, some <code>bricks</code>, and some <code>ladders</code>.</p>

<p>You start your journey from building <code>0</code> and move to the next building by possibly using bricks or ladders.</p>

<p>While moving from building <code>i</code> to building <code>i+1</code> (<strong>0-indexed</strong>),</p>

<ul>
	<li>If the current building's height is <strong>greater than or equal</strong> to the next building's height, you do <strong>not</strong> need a ladder or bricks.</li>
	<li>If the current building's height is <b>less than</b> the next building's height, you can either use <strong>one ladder</strong> or <code>(h[i+1] - h[i])</code> <strong>bricks</strong>.</li>
</ul>

<p><em>Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/27/q4.gif" style="width: 562px; height: 561px;">
<pre><strong>Input:</strong> heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
<strong>Output:</strong> 4
<strong>Explanation:</strong> Starting at building 0, you can follow these steps:
- Go to building 1 without using ladders nor bricks since 4 &gt;= 2.
- Go to building 2 using 5 bricks. You must use either bricks or ladders because 2 &lt; 7.
- Go to building 3 without using ladders nor bricks since 7 &gt;= 6.
- Go to building 4 using your only ladder. You must use either bricks or ladders because 6 &lt; 9.
It is impossible to go beyond building 4 because you do not have any more bricks or ladders.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
<strong>Output:</strong> 7
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> heights = [14,3,19,3], bricks = 17, ladders = 0
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= heights.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= heights[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>0 &lt;= bricks &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= ladders &lt;= heights.length</code></li>
</ul>


**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/), [Heap](https://leetcode.com/tag/heap/)

## Solution 1. Min heap

Firstly we only consider positive diffs, and ignore non-positive ones. 

Secondly, we use brick for small diffs, and ladder for large diffs.

We can turn the original array into the diffs.

```cpp
// original array
[4,2,7,6,9,14,12] 
// diff array
[0,5,0,3,5,0,x]
```

Now the problem becomes "find the maximum index `i` that `sum( A[0]...A[i] ) - sum( top L elements ) <= B`.

We can use a min heap to keep track of the top `L` items.

```cpp
// OJ: https://leetcode.com/problems/furthest-building-you-can-reach/
// Author: github.com/lzl124631x
// Time: O(NlogL)
// Space: O(L)
class Solution {
public:
    int furthestBuilding(vector<int>& A, int B, int L) {
        long N = A.size(), sum = 0, sumTop = 0;
        for (int i = 0; i < N - 1; ++i) { // convert to diff array
            A[i] = max(0, A[i + 1] - A[i]);
        }
        priority_queue<int, vector<int>, greater<>> pq; // min-heap storing the top L diffs
        for (int i = 0; i < N; ++i) {
            sum += A[i];
            sumTop += A[i];
            pq.push(A[i]);
            if (pq.size() > L) {
                sumTop -= pq.top();
                pq.pop();
            }
            if (sum - sumTop > B) return i;
        }
        return N - 1;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/furthest-building-you-can-reach/
// Author: github.com/lzl124631x
// Time: O(NlogL)
// Space: O(L)
class Solution {
public:
    int furthestBuilding(vector<int>& H, int B, int L) {
        int N = H.size(), sum = 0; // sum is the sum of the diffs that we want to use bricks to handle
        priority_queue<int, vector<int>, greater<>> pq; // min-heap, keep track of the L largest diffs
        for (int i = 1; i < N; ++i) {
            int diff = H[i] - H[i - 1]; // compute diff on the fly
            if (diff <= 0) continue; // ignore negative diffs
            pq.push(diff);
            if (pq.size() <= L) continue; // doesn't need any brick, continue
            sum += pq.top();
            pq.pop();
            if (sum > B) return i - 1;
        }
        return N - 1;
    }
};
```