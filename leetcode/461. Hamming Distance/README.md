# [461. Hamming Distance (Easy)](https://leetcode.com/problems/hamming-distance/)

<p>The <a href="https://en.wikipedia.org/wiki/Hamming_distance" target="_blank">Hamming distance</a> between two integers is the number of positions at which the corresponding bits are different.</p>

<p>Given two integers <code>x</code> and <code>y</code>, return <em>the <strong>Hamming distance</strong> between them</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> x = 1, y = 4
<strong>Output:</strong> 2
<strong>Explanation:</strong>
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> x = 3, y = 1
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;=&nbsp;x, y &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


**Companies**:  
[Adobe](https://leetcode.com/company/adobe), [Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [Number of 1 Bits (Easy)](https://leetcode.com/problems/number-of-1-bits/)
* [Total Hamming Distance (Medium)](https://leetcode.com/problems/total-hamming-distance/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/hamming-distance/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        for (int z = x ^ y; z; z >>= 1) ans += z & 1;
        return ans; 
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/hamming-distance/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        for (int z = x ^ y; z; z &= z - 1) ++ans;
        return ans; 
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/hamming-distance/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x ^ y);
    }
};
```