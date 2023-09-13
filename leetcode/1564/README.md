# [1564. Put Boxes Into the Warehouse I (Medium)](https://leetcode.com/problems/put-boxes-into-the-warehouse-i/)

<p>You are given two arrays of positive integers, <code>boxes</code> and <code>warehouse</code>, representing the heights of some boxes of unit width and the heights of <code>n</code> rooms in a warehouse respectively. The warehouse's rooms are labelled from <code>0</code> to <code>n - 1</code> from left to right where <code>warehouse[i]</code> (0-indexed) is the height of the <code>i<sup>th</sup></code> room.</p>

<p>Boxes are put into the warehouse by the following rules:</p>

<ul>
	<li>Boxes cannot be stacked.</li>
	<li>You can rearrange the insertion order of the boxes.</li>
	<li>Boxes&nbsp;can only be pushed into the warehouse from left to right only.</li>
	<li>If the height of some room in the warehouse is less than the height of a box, then that box and all other boxes behind it will be stopped before that room.</li>
</ul>

<p>Return <em>the maximum number of boxes you can put into the warehouse.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/26/11.png" style="width: 400px; height: 242px;">
<pre><strong>Input:</strong> boxes = [4,3,4,1], warehouse = [5,3,3,4,1]
<strong>Output:</strong> 3
<strong>Explanation:&nbsp;
</strong><img alt="" src="https://assets.leetcode.com/uploads/2020/08/26/12.png" style="width: 280px; height: 242px;">
We can first put the box of height 1 in room 4. Then we can put the box of height 3 in either of the 3 rooms 1, 2, or 3. Lastly, we can put one box of height 4 in room 0.
There is no way we can fit all 4 boxes in the warehouse.</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/26/21.png" style="width: 400px; height: 202px;">
<pre><strong>Input:</strong> boxes = [1,2,2,3,4], warehouse = [3,4,1,2]
<strong>Output:</strong> 3
<strong>Explanation: 
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/26/22.png" style="width: 280px; height: 202px;">
</strong>Notice that it's not possible to put the box of height 4 into the warehouse since it cannot pass the first room of height 3.
Also, for the last two rooms, 2 and 3, only boxes of height 1 can fit.
We can fit 3 boxes maximum as shown above. The yellow box can also be put in room 2 instead.
Swapping the orange and green boxes is also valid, or swapping one of them with the red box.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> boxes = [1,2,3], warehouse = [1,2,3,4]
<strong>Output:</strong> 1
<strong>Explanation: </strong>Since the first room in the warehouse is of height 1, we can only put boxes of height 1.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> boxes = [4,5,6], warehouse = [3,3,3,3,3]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == warehouse.length</code></li>
	<li><code>1 &lt;= boxes.length, warehouse.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= boxes[i], warehouse[i] &lt;= 10^9</code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Put Boxes Into the Warehouse II (Medium)](https://leetcode.com/problems/put-boxes-into-the-warehouse-ii/)

## Solution 1. Mono-stack

```cpp
// OJ: https://leetcode.com/problems/put-boxes-into-the-warehouse-i/
// Author: github.com/lzl124631x
// Time: O(W + BlogB + WlogB)
// Space: O(W)
class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& B, vector<int>& W) {
        vector<int> s(1, W.size());
        for (int i = W.size() - 1; i >= 0; --i) {
            while (s.size() > 1 && W[s.back()] >= W[i]) s.pop_back();
            s.push_back(i);
        }
        sort(begin(B), end(B));
        int ans = 0;
        for (int i = 1; i < s.size(); ++i) {
            int h = W[s[i]], cnt = s[i - 1] - s[i];
            int num = upper_bound(begin(B), end(B), h) - begin(B) - ans;
            ans += min(cnt, num);
        }
        return ans;
    }
};
```

## Solution 2. Mono-stack + Two Pointers

```cpp
// OJ: https://leetcode.com/problems/put-boxes-into-the-warehouse-i/
// Author: github.com/lzl124631x
// Time: O(BlogB + W)
// Space: O(1)
// Ref: https://leetcode.com/problems/put-boxes-into-the-warehouse-i/discuss/821966/C%2B%2B-Two-Approaches
class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& B, vector<int>& W) {
        sort(begin(B), end(B));
        for (int i = 1; i < W.size(); ++i) {
            W[i] = min(W[i], W[i - 1]);
        }
        int ans = 0;
        for (int i = W.size() - 1; i >= 0; --i) {
            ans += ans < B.size() && B[ans] <= W[i];
        }
        return ans;
    }
};
```

## Solution 3. Greedy + Two Pointers

```cpp
// OJ: https://leetcode.com/problems/put-boxes-into-the-warehouse-i/
// Author: github.com/lzl124631x
// Time: O(BlogB)
// Space: O(1)
// Ref: https://leetcode.com/problems/put-boxes-into-the-warehouse-i/discuss/821966/C%2B%2B-Two-Approaches
class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& B, vector<int>& W) {
        sort(begin(B), end(B), greater());
        int ans = 0;
        for (int b : B) {
            ans += ans < W.size() && b <= W[ans];
        }
        return ans;
    }
};
```