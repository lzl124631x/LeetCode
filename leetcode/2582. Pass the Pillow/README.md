# [2582. Pass the Pillow (Easy)](https://leetcode.com/problems/pass-the-pillow)

<p>There are <code>n</code> people standing in a line labeled from <code>1</code> to <code>n</code>. The first person in the line is holding a pillow initially. Every second, the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction changes, and people continue passing the pillow in the opposite direction.</p>

<ul>
	<li>For example, once the pillow reaches the <code>n<sup>th</sup></code> person they pass it to the <code>n - 1<sup>th</sup></code> person, then to the <code>n - 2<sup>th</sup></code> person and so on.</li>
</ul>

<p>Given the two positive integers <code>n</code> and <code>time</code>, return <em>the index of the person holding the pillow after </em><code>time</code><em> seconds</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> n = 4, time = 5
<strong>Output:</strong> 2
<strong>Explanation:</strong> People pass the pillow in the following way: 1 -&gt; 2 -&gt; 3 -&gt; 4 -&gt; 3 -&gt; 2.
Afer five seconds, the pillow is given to the 2<sup>nd</sup> person.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> n = 3, time = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong> People pass the pillow in the following way: 1 -&gt; 2 -&gt; 3.
Afer two seconds, the pillow is given to the 3<sup>r</sup><sup>d</sup> person.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= time &lt;= 1000</code></li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Simulation](https://leetcode.com/tag/simulation/)

**Similar Questions**:
* [Find the Student that Will Replace the Chalk (Medium)](https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/)

## Solution 1. Math

Say `n = 3`, what's the pattern?

* time = 1, result = 2, distance from 1 = 1, left-to-right = true
* time = 2, result = 3, distance from 1 = 2, left-to-right = true
* time = 3, result = 2, distance from 3 = 1, left-to-right = false
* time = 4, result = 1, distance from 3 = 2, left-to-right = false
* time = 5, result = 2, distance from 1 = 1, left-to-right = true
* ...

From the distance, we can see that we need to divide or modulos by `n - 1 = 2` since it's repeating every 2 steps. The result is `{left-to-right} ? 1 + {distance from 1} : 3 - {distance from 3}`

Let `div = (time - 1) / (n - 1)`, `mod = (time - 1) % (n - 1)`, `{left-to-right} = div % 2 == 0`, `{distance from 1} = 1 + mod` and `{distance from 3} = 1 + mod`. 

So, let `dist = 1 + mod`, the result is `div % 2 ? n - dist : 1 + dist`.

```cpp
// OJ: https://leetcode.com/problems/pass-the-pillow
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int passThePillow(int n, int time) {
        int div = (time - 1) / (n - 1), dist = (time - 1) % (n - 1) + 1;
        return div % 2 ? n - dist : 1 + dist;
    }
};
```