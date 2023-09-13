# [1860. Incremental Memory Leak (Medium)](https://leetcode.com/problems/incremental-memory-leak/)

<p>You are given two integers <code>memory1</code> and <code>memory2</code> representing the available memory in bits on two memory sticks. There is currently a faulty program running that consumes an increasing amount of memory every second.</p>

<p>At the <code>i<sup>th</sup></code> second (starting from 1), <code>i</code> bits of memory are allocated to the stick with <strong>more available memory</strong> (or from the first memory stick if both have the same available memory). If neither stick has at least <code>i</code> bits of available memory, the program <strong>crashes</strong>.</p>

<p>Return <em>an array containing </em><code>[crashTime, memory1<sub>crash</sub>, memory2<sub>crash</sub>]</code><em>, where </em><code>crashTime</code><em> is the time (in seconds) when the program crashed and </em><code>memory1<sub>crash</sub></code><em> and </em><code>memory2<sub>crash</sub></code><em> are the available bits of memory in the first and second sticks respectively</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> memory1 = 2, memory2 = 2
<strong>Output:</strong> [3,1,0]
<strong>Explanation:</strong> The memory is allocated as follows:
- At the 1<sup>st</sup> second, 1 bit of memory is allocated to stick 1. The first stick now has 1 bit of available memory.
- At the 2<sup>nd</sup> second, 2 bits of memory are allocated to stick 2. The second stick now has 0 bits of available memory.
- At the 3<sup>rd</sup> second, the program crashes. The sticks have 1 and 0 bits available respectively.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> memory1 = 8, memory2 = 11
<strong>Output:</strong> [6,0,4]
<strong>Explanation:</strong> The memory is allocated as follows:
- At the 1<sup>st</sup> second, 1 bit of memory is allocated to stick 2. The second stick now has 10 bit of available memory.
- At the 2<sup>nd</sup> second, 2 bits of memory are allocated to stick 2. The second stick now has 8 bits of available memory.
- At the 3<sup>rd</sup> second, 3 bits of memory are allocated to stick 1. The first stick now has 5 bits of available memory.
- At the 4<sup>th</sup> second, 4 bits of memory are allocated to stick 2. The second stick now has 4 bits of available memory.
- At the 5<sup>th</sup> second, 5 bits of memory are allocated to stick 1. The first stick now has 0 bits of available memory.
- At the 6<sup>th</sup> second, the program crashes. The sticks have 0 and 4 bits available respectively.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= memory1, memory2 &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


**Companies**:  
[tiktok](https://leetcode.com/company/tiktok)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1. Brute Force

For the first `i` seconds, `i * (i - 1) / 2` memory is taken. The process will stop before `i * (i - 1) / 2 >= A + B`. So the time complexity is at most `O(sqrt(A + B))`. Since `A` and `B` are at most `2^31-1 ~= 10^9`, so `sqrt(A + B)` is at most around `10^4.5` which is fine.  

```cpp
// OJ: https://leetcode.com/problems/incremental-memory-leak/
// Author: github.com/lzl124631x
// Time: O(sqrt(A + B))
// Space: O(1)
class Solution {
public:
    vector<int> memLeak(int A, int B) {
        int i = 1;
        while (A >= i || B >= i) {
            if (A >= B) {
                A -= i;
            } else {
                B -= i;
            }
            ++i;
        }
        return {i, A, B};
    }
};
```