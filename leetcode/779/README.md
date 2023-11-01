# [779. K-th Symbol in Grammar (Medium)](https://leetcode.com/problems/k-th-symbol-in-grammar)

<p>We build a table of <code>n</code> rows (<strong>1-indexed</strong>). We start by writing <code>0</code> in the <code>1<sup>st</sup></code> row. Now in every subsequent row, we look at the previous row and replace each occurrence of <code>0</code> with <code>01</code>, and each occurrence of <code>1</code> with <code>10</code>.</p>

<ul>
	<li>For example, for <code>n = 3</code>, the <code>1<sup>st</sup></code> row is <code>0</code>, the <code>2<sup>nd</sup></code> row is <code>01</code>, and the <code>3<sup>rd</sup></code> row is <code>0110</code>.</li>
</ul>

<p>Given two integer <code>n</code> and <code>k</code>, return the <code>k<sup>th</sup></code> (<strong>1-indexed</strong>) symbol in the <code>n<sup>th</sup></code> row of a table of <code>n</code> rows.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 1, k = 1
<strong>Output:</strong> 0
<strong>Explanation:</strong> row 1: <u>0</u>
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 2, k = 1
<strong>Output:</strong> 0
<strong>Explanation:</strong> 
row 1: 0
row 2: <u>0</u>1
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 2, k = 2
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
row 1: 0
row 2: 0<u>1</u>
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 30</code></li>
	<li><code>1 &lt;= k &lt;= 2<sup>n - 1</sup></code></li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Bloomberg](https://leetcode.com/company/bloomberg), [Facebook](https://leetcode.com/company/facebook), [Adobe](https://leetcode.com/company/adobe), [Apple](https://leetcode.com/company/apple), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation), [Recursion](https://leetcode.com/tag/recursion)

**Hints**:
* Try to represent the current (N, K) in terms of some (N-1, prevK).  What is prevK ?

## Solution 1. Recursive

```cpp
// OJ: https://leetcode.com/problems/k-th-symbol-in-grammar/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) return 0;
        return k <= (1 << (n - 2)) ? kthGrammar(n - 1, k) : (1 - kthGrammar(n - 1, k - (1 << (n - 2))));
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/k-th-symbol-in-grammar
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) return 0;
        return kthGrammar(n - 1, (k + 1) / 2) == k % 2;
    }
};
```

## Solution 2. Iterative

```cpp
// OJ: https://leetcode.com/problems/k-th-symbol-in-grammar/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int kthGrammar(int n, int k) {
        int ans = 0;
        for (; n > 1; --n) {
            if (k > (1 << (n - 2))) {
                ans = 1 - ans;
                k -= (1 << (n - 2));
            }
        }
        return ans;
    }
};
```

## Solution 3. 

```cpp
// OJ: https://leetcode.com/problems/k-th-symbol-in-grammar/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
// Ref: https://leetcode.com/problems/k-th-symbol-in-grammar/discuss/113736/PythonJavaC%2B%2B-Easy-1-line-Solution-with-detailed-explanation
class Solution {
public:
    int kthGrammar(int N, int K) {
        return __builtin_popcount(K - 1) & 1;
    }
};
```