# [1375. Bulb Switcher III (Medium)](https://leetcode.com/problems/bulb-switcher-iii/)

<p>There is a room with <code>n</code> bulbs, numbered from <code>1</code> to <code>n</code>, arranged in a row from left to right. Initially, all the bulbs are turned off.</p>

<p>At moment <em>k</em> (for <em>k</em> from <code>0</code> to <code>n - 1</code>), we turn on the <code>light[k]</code> bulb. A bulb <strong>change&nbsp;color to blue</strong> only if it is on and all the previous bulbs (to the left)&nbsp;are turned on too.</p>

<p>Return the number of moments in&nbsp;which <strong>all&nbsp;turned on</strong> bulbs&nbsp;<strong>are blue.</strong></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/02/29/sample_2_1725.png" style="width: 575px; height: 300px;"></p>

<pre><strong>Input:</strong> light = [2,1,3,5,4]
<strong>Output:</strong> 3
<strong>Explanation:</strong> All bulbs turned on, are blue at the moment 1, 2 and 4.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> light = [3,2,4,1,5]
<strong>Output:</strong> 2
<strong>Explanation:</strong> All bulbs turned on, are blue at the moment 3, and 4 (index-0).
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> light = [4,1,2,3]
<strong>Output:</strong> 1
<strong>Explanation:</strong> All bulbs turned on, are blue at the moment 3 (index-0).
Bulb 4th changes to blue at the moment 3.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> light = [2,1,4,3,6,5]
<strong>Output:</strong> 3
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> light = [1,2,3,4,5,6]
<strong>Output:</strong> 6
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n ==&nbsp;light.length</code></li>
	<li><code>1 &lt;= n &lt;= 5 * 10^4</code></li>
	<li><code>light</code> is a permutation of&nbsp;&nbsp;<code>[1, 2, ..., n]</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Bulb Switcher (Medium)](https://leetcode.com/problems/bulb-switcher/)
* [Bulb Switcher II (Medium)](https://leetcode.com/problems/bulb-switcher-ii/)

## Solution 1. Brute Force

Try to turn the bulb from the current one as far as possible to blue. If the count of turned-on bulbs equals the count of blue bulbs, then increment the answer.

```cpp
// OJ: https://leetcode.com/problems/bulb-switcher-iii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int numTimesAllBlue(vector<int>& A) {
        int N = A.size(), ans = 0, on = 0, blue = 0;
        vector<int> v(N, 0);
        for (int n : A) {
            int i = n - 1;
            v[i] = 1;
            on++;
            while (i < N && v[i] > 0 && (i == 0 || v[i - 1] == 2)) {
                if (v[i] == 1) blue++;
                v[i++] = 2;
            } 
            if (on == blue) ++ans;
        }
        return ans;
    }
};
```

## Solution 2.

What's the feature of the moments we care about? One is that the maximum ID we've seen equals the count of bulbs we've turned on.

```cpp
// OJ: https://leetcode.com/problems/bulb-switcher-iii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numTimesAllBlue(vector<int>& A) {
        int N = A.size(), maxId = 0, cnt = 0, ans = 0;
        for (int n : A) {
            maxId = max(maxId, n);
            if (++cnt == maxId) ++ans;
        }
        return ans;
    }
};
```