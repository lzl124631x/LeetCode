# [面试题64. 求1+2+…+n](https://leetcode-cn.com/problems/qiu-12n-lcof/)

<div class="content__1Y2H"><div class="notranslate"><p>求 <code>1+2+...+n</code> ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入:</strong> n = 3
<strong>输出:&nbsp;</strong>6
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入:</strong> n = 9
<strong>输出:&nbsp;</strong>45
</pre>

<p>&nbsp;</p>

<p><strong>限制：</strong></p>

<ul>
	<li><code>1 &lt;= n&nbsp;&lt;= 10000</code></li>
</ul>
</div></div>

## Solution 1.

思略: 计算 (n^2 + n) / 2

其中`n^2`没法简单地用位运算直接得到. 考虑`6 * 6`可以拆解为`6 * 4 + 6 * 2`, 也就是

数字 | 二进制 | 左移位数 | 结果
---|---|---|---
4 | 100 | 左移2位 | `110 << 2`
2 | 10 | 左移1位 | `110 << 1`

所以, 规律就是如果`n`的第`i`位是`1`, 就将`n << i`加到结果中.

对于给定`i`, 我想到一种表达方式为`-((n >> i) & 1) & (n << i)`.

因为10000只有14bits, 所以`i`枚举从`0`到`13`即可.

```cpp
// OJ: https://leetcode-cn.com/problems/qiu-12n-lcof/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
    int d(unsigned n, int i) {
        return -((n >> i) & 1) & (n << i);
    }
public:
    int sumNums(int n) {
        return (d(n, 0) + d(n, 1) + d(n, 2) + d(n, 3) + d(n, 4) + d(n, 5) + d(n, 6)
                + d(n, 7) + d(n, 8) + d(n, 9) + d(n, 10) + d(n, 11) + d(n, 12) + d(n, 13) + n) >> 1;
    }
}
```

## Solution 2.

```cpp
// OJ: https://leetcode-cn.com/problems/qiu-12n-lcof/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int sumNums(int n) {
        n > 0 && (n += sumNums(n - 1));
        return n;
    }
};
```