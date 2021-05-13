# [1580. Put Boxes Into the Warehouse II (Medium)](https://leetcode.com/problems/put-boxes-into-the-warehouse-ii/)

<p>You are given two arrays of positive integers, <code>boxes</code> and <code>warehouse</code>, representing the heights of some boxes of unit width and the heights of <code>n</code> rooms in a warehouse respectively. The warehouse's rooms are labeled from <code>0</code> to <code>n - 1</code> from left to right where <code>warehouse[i]</code> (0-indexed) is the height of the <code>i<sup>th</sup></code> room.</p>

<p>Boxes are put into the warehouse by the following rules:</p>

<ul>
	<li>Boxes cannot be stacked.</li>
	<li>You can rearrange the insertion order of the boxes.</li>
	<li>Boxes can be pushed into the warehouse from <strong>either side</strong> (left or right)</li>
	<li>If the height of some room in the warehouse is less than the height of a box, then that box and all other boxes behind it will be stopped before that room.</li>
</ul>

<p>Return <em>the maximum number of boxes you can put into the warehouse.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/30/22.png" style="width: 401px; height: 202px;">
<pre><strong>Input:</strong> boxes = [1,2,2,3,4], warehouse = [3,4,1,2]
<strong>Output:</strong> 4
<strong>Explanation:
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/30/22-1.png" style="width: 240px; height: 202px;">
</strong>We can store the boxes in the following order:
1- Put the yellow box in room 2 from either the left or right side.
2- Put the orange box in room 3 from the right side.
3- Put the green box in room 1 from the left side.
4- Put the red box in room 0 from the left side.
Notice that there are other valid ways to put 4 boxes such as swapping the red and green boxes or the red and orange boxes.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/30/22-2.png" style="width: 401px; height: 242px;">
<pre><strong>Input:</strong> boxes = [3,5,5,2], warehouse = [2,1,3,4,5]
<strong>Output:</strong> 3
<strong>Explanation:
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/30/22-3.png" style="width: 280px; height: 242px;">
</strong>It's not possible to put the two boxes of height 5 in the warehouse since there's only 1 room of height &gt;= 5.
Other valid solutions are to put the green box in room 2 or to put the orange box first in room 2 before putting the green and red boxes.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> boxes = [1,2,3], warehouse = [1,2,3,4]
<strong>Output:</strong> 3
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> boxes = [4,5,6], warehouse = [3,3,3,3,3]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == warehouse.length</code></li>
	<li><code>1 &lt;= boxes.length, warehouse.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= boxes[i], warehouse[i] &lt;= 10<sup>9</sup></code></li>
</ul>

**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Put Boxes Into the Warehouse I (Medium)](https://leetcode.com/problems/put-boxes-into-the-warehouse-i/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/put-boxes-into-the-warehouse-ii/
// Author: github.com/lzl124631x
// Time: O(WlogW + BlogB)
// Space: O(W)
class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& B, vector<int>& W) {
        vector<int> left(W.size(), INT_MAX);
        left[0] = W[0];
        for (int i = 1; i < W.size(); ++i) {
            left[i] = min(left[i - 1], W[i]);
        }
        int right = W.back();
        for (int i = W.size() - 2; i >= 0; --i) {
            right = min(right, W[i]);
            W[i] = max(left[i], right);
        }
        sort(begin(W), end(W));
        sort(begin(B), end(B));
        int ans = 0;
        for (int w : W) {
            ans += ans < B.size() && B[ans] <= w;
        }
        return ans;
    }
};
```

## Solution 2. Greedy

```cpp
// OJ: https://leetcode.com/problems/put-boxes-into-the-warehouse-ii/
// Author: github.com/lzl124631x
// Time: O(BlogB + min(B, W))
// Space: O(1)
class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& B, vector<int>& W) {
        int L = 0, R = W.size() - 1, ans = 0;
        sort(begin(B), end(B), greater());
        for (int i = 0; i < B.size() && L <= R; ++i) {
            int tall = W[L] >= W[R] ? L : R;
            if (W[tall] < B[i]) continue;
            ++ans;
            if (tall == L) ++L;
            else --R;
        }
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/put-boxes-into-the-warehouse-ii/
// Author: github.com/lzl124631x
// Time: O(BlogB + min(B, W))
// Space: O(1)
class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& B, vector<int>& W) {
        int L = 0, R = W.size() - 1, ans = 0;
        sort(begin(B), end(B), greater());
        for (int i = 0; i < B.size() && L <= R; ++i) {
            if (B[i] <= W[L]) {
                ++ans;
                ++L;
            } else if (B[i] <= W[R]) {
                ++ans;
                --R;
            }
        }
        return ans;
    }
};
```