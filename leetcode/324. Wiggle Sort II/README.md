# [324. Wiggle Sort II (Medium)](https://leetcode.com/problems/wiggle-sort-ii)

<p>Given an integer array <code>nums</code>, reorder it such that <code>nums[0] &lt; nums[1] &gt; nums[2] &lt; nums[3]...</code>.</p>
<p>You may assume the input array always has a valid answer.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,5,1,1,6,4]
<strong>Output:</strong> [1,6,1,5,1,4]
<strong>Explanation:</strong> [1,4,1,5,1,6] is also accepted.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,3,2,2,3,1]
<strong>Output:</strong> [2,3,1,3,1,2]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 5000</code></li>
	<li>It is guaranteed that there will be an answer for the given input <code>nums</code>.</li>
</ul>
<p>&nbsp;</p>
<strong>Follow Up:</strong>
<code>O(n)</code>
<strong>in-place</strong>
<code>O(1)</code>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Sorting](https://leetcode.com/tag/sorting/), [Quickselect](https://leetcode.com/tag/quickselect/)

**Similar Questions**:
* [Sort Colors (Medium)](https://leetcode.com/problems/sort-colors/)
* [Kth Largest Element in an Array (Medium)](https://leetcode.com/problems/kth-largest-element-in-an-array/)
* [Wiggle Sort (Medium)](https://leetcode.com/problems/wiggle-sort/)
* [Array With Elements Not Equal to Average of Neighbors (Medium)](https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/)

## Solution 1.

<p>First I find a median using <code>nth_element</code>. That only guarantees O(n) <strong>average</strong> time complexity and I don't know about space complexity. I might write this myself using O(n) time and O(1) space, but that's not what I want to show here.</p>
<p>This post is about what comes <strong>after</strong> that. We can use <a href="https://en.wikipedia.org/wiki/Dutch_national_flag_problem#Pseudocode" target="_blank">three-way partitioning</a> to arrange the numbers so that those <em>larger than</em> the median come first, then those <em>equal to</em> the median come next, and then those <em>smaller than</em> the median come last.</p>
<p>Ordinarily, you'd then use one more phase to bring the numbers to their final positions to reach the overall wiggle-property. But I don't know a nice O(1) space way for this. Instead, I embed this right into the partitioning algorithm. That algorithm simply works with indexes 0 to n-1 as usual, but sneaky as I am, I rewire those indexes where I want the numbers to actually end up. The partitioning-algorithm doesn't even know that I'm doing that, it just works like normal (it just uses <code>A(x)</code> instead of <code>nums[x]</code>).</p>
<p>Let's say <code>nums</code> is <code>[10,11,...,19]</code>. Then after nth_element and ordinary partitioning, we might have this (15 is my median):</p>
<div class="mb-6 rounded-lg px-3 py-2.5 font-menlo text-sm bg-fill-3 dark:bg-dark-fill-3"><div class="group relative" translate="no"><pre style="color: rgb(212, 212, 212); font-size: 13px; text-shadow: none; font-family: Menlo, Monaco, Consolas; direction: ltr; text-align: left; white-space: pre; word-spacing: normal; word-break: normal; line-height: 1.5; tab-size: 4; hyphens: none; padding: 0px; margin: 0px; overflow: auto; background: transparent;"><code style="color: rgb(212, 212, 212); font-size: 13px; text-shadow: none; font-family: Menlo, Monaco, Consolas, &quot;Andale Mono&quot;, &quot;Ubuntu Mono&quot;, &quot;Courier New&quot;, monospace; direction: ltr; text-align: left; white-space: pre; word-spacing: normal; word-break: normal; line-height: 1.5; tab-size: 4; hyphens: none;"><span><span>index:     0  1  2  3   4   5  6  7  8  9
</span></span><span>number:   18 17 19 16  15  11 14 10 13 12</span></code></pre><div class="h-4 w-4 cursor-pointer absolute top-0 right-0"></div></div></div>
<p>I rewire it so that the first spot has index 5, the second spot has index 0, etc, so that I might get this instead:</p>
<div class="mb-6 rounded-lg px-3 py-2.5 font-menlo text-sm bg-fill-3 dark:bg-dark-fill-3"><div class="group relative" translate="no"><pre style="color: rgb(212, 212, 212); font-size: 13px; text-shadow: none; font-family: Menlo, Monaco, Consolas; direction: ltr; text-align: left; white-space: pre; word-spacing: normal; word-break: normal; line-height: 1.5; tab-size: 4; hyphens: none; padding: 0px; margin: 0px; overflow: auto; background: transparent;"><code style="color: rgb(212, 212, 212); font-size: 13px; text-shadow: none; font-family: Menlo, Monaco, Consolas, &quot;Andale Mono&quot;, &quot;Ubuntu Mono&quot;, &quot;Courier New&quot;, monospace; direction: ltr; text-align: left; white-space: pre; word-spacing: normal; word-break: normal; line-height: 1.5; tab-size: 4; hyphens: none;"><span><span>index:     5  0  6  1  7  2  8  3  9  4
</span></span><span>number:   11 18 14 17 10 19 13 16 12 15</span></code></pre><div class="h-4 w-4 cursor-pointer absolute top-0 right-0"></div></div></div>
<p>And 11 18 14 17 10 19 13 16 12 15 is perfectly wiggly. And the whole partitioning-to-wiggly-arrangement (everything after finding the median) only takes O(n) time and O(1) space.</p>
<hr>
<p>If the above description is unclear, maybe this explicit listing helps:</p>
<p>Accessing <code>A(0)</code> actually accesses <code>nums[1]</code>.<br>
Accessing <code>A(1)</code> actually accesses <code>nums[3]</code>.<br>
Accessing <code>A(2)</code> actually accesses <code>nums[5]</code>.<br>
Accessing <code>A(3)</code> actually accesses <code>nums[7]</code>.<br>
Accessing <code>A(4)</code> actually accesses <code>nums[9]</code>.<br>
Accessing <code>A(5)</code> actually accesses <code>nums[0]</code>.<br>
Accessing <code>A(6)</code> actually accesses <code>nums[2]</code>.<br>
Accessing <code>A(7)</code> actually accesses <code>nums[4]</code>.<br>
Accessing <code>A(8)</code> actually accesses <code>nums[6]</code>.<br>
Accessing <code>A(9)</code> actually accesses <code>nums[8]</code>.</p>

```cpp
// OJ: https://leetcode.com/problems/wiggle-sort-ii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/wiggle-sort-ii/solutions/77677/o-n-o-1-after-median-virtual-indexing/
class Solution {
public:
    void wiggleSort(vector<int>& A) {
        int N = A.size();
        // Find a median.
        auto midptr = A.begin() + N / 2;
        nth_element(begin(A), midptr, end(A));
        int mid = *midptr;
        
        // Index-rewiring.
        #define R(i) A[(1+2*(i)) % (N|1)]
    
        // 3-way-partition-to-wiggly in O(n) time with O(1) space.
        int i = 0, j = 0, k = N - 1;
        while (j <= k) {
            if (R(j) > mid) swap(R(i++), R(j++));
            else if (R(j) < mid) swap(R(j), R(k--));
            else j++;
        }
    }
};
```