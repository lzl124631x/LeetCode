# [470. Implement Rand10() Using Rand7() (Medium)](https://leetcode.com/problems/implement-rand10-using-rand7/)

<p>Given a function <code>rand7</code> which generates a uniform random integer in the range 1 to 7, write a function <code>rand10</code>&nbsp;which generates a uniform random integer in the range 1 to 10.</p>

<p>Do NOT use system's <code>Math.random()</code>.</p>

<ol>
</ol>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">1</span>
<strong>Output: </strong><span id="example-output-1">[7]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">2</span>
<strong>Output: </strong><span id="example-output-2">[8,4]</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">3</span>
<strong>Output: </strong><span id="example-output-3">[8,1,10]</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>rand7</code> is predefined.</li>
	<li>Each testcase has one argument:&nbsp;<code>n</code>, the number of times that <code>rand10</code> is called.</li>
</ol>

<p>&nbsp;</p>

<p><strong>Follow up:</strong></p>

<ol>
	<li>What is the <a href="https://en.wikipedia.org/wiki/Expected_value" target="_blank">expected value</a>&nbsp;for the number of calls to&nbsp;<code>rand7()</code>&nbsp;function?</li>
	<li>Could you minimize the number of calls to <code>rand7()</code>?</li>
</ol>
</div>
</div>
</div>


**Related Topics**:  
[Random](https://leetcode.com/tag/random/), [Rejection Sampling](https://leetcode.com/tag/rejection-sampling/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/implement-rand10-using-rand7/
// Author: github.com/lzl124631x
// Time: O(1) on average, O(Infinity) in worst case
// Space: O(1)
class Solution {
    int rand2() {
        while (true) {
            int r = rand7();
            if (r <= 6) return 1 + (r >= 4);
        }
    }
    int rand5() {
        while (true) {
            int r = rand7();
            if (r <= 5) return r;
        }
    }
public:
    int rand10() {
        return (rand2() - 1) * 5 + rand5();
    }
};
```

## Solution 2. Rejection Sampling

```cpp
// OJ: https://leetcode.com/problems/implement-rand10-using-rand7/solution/
// Author: github.com/lzl124631x
// Time: O(1) on average, O(Infinity) in worst case
// Space: O(1)
// Ref: https://leetcode.com/problems/implement-rand10-using-rand7/solution/
class Solution {
public:
    int rand10() {
        while (true) {
            int r = (rand7() - 1) * 7 + rand7(); // generate evenly distributed [1, 49].
            if (r <= 40) return r % 10 + 1; // Only accept numbers in range [1, 40]
        }
    }
};
```