# [2366. Minimum Replacements to Sort the Array (Hard)](https://leetcode.com/problems/minimum-replacements-to-sort-the-array)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>. In one operation you can replace any element of the array with <strong>any two</strong> elements that <strong>sum</strong> to it.</p>
<ul>
	<li>For example, consider <code>nums = [5,6,7]</code>. In one operation, we can replace <code>nums[1]</code> with <code>2</code> and <code>4</code> and convert <code>nums</code> to <code>[5,2,4,7]</code>.</li>
</ul>
<p>Return <em>the minimum number of operations to make an array that is sorted in <strong>non-decreasing</strong> order</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [3,9,3]
<strong>Output:</strong> 2
<strong>Explanation:</strong> Here are the steps to sort the array in non-decreasing order:
- From [3,9,3], replace the 9 with 3 and 6 so the array becomes [3,3,6,3]
- From [3,3,6,3], replace the 6 with 3 and 3 so the array becomes [3,3,3,3,3]
There are 2 steps to sort the array in non-decreasing order. Therefore, we return 2.

</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3,4,5]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The array is already in non-decreasing order. Therefore, we return 0. 
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google), [Expedia](https://leetcode.com/company/expedia)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Minimum Operations to Make the Array Increasing (Easy)](https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/)

## Solution 1. Greedy

<h4 id="intuition">Intuition</h4>
<p>If <code>nums</code> is not sorted, there exists at least one adjacent pair <code>nums[i], nums[i + 1]</code> where <code>nums[i] &gt; nums[i + 1]</code>. How should we handle this pair of numbers that don't adhere to the sorted order? Should we break down the larger <code>nums[i]</code> using replacement operations or the smaller <code>nums[i + 1]</code>? To minimize the number of steps, it is unnecessary to break down the smaller number because it would only increase the number of replacement operations.</p>
<p><img src="https://leetcode.com/problems/minimum-replacements-to-sort-the-array/Figures/2366/1.png" alt="img"></p>
<p>Now that we understand the logic for handling adjacent unsorted pairs, the next question is the order in which we process <code>nums</code>. Here, we need to traverse in <strong>reverse</strong> order. The reason is that our replacement operations will only make the current <code>nums[i]</code> become two (or more) smaller numbers.</p>
<p>If we start from the end and move toward the beginning, we can ensure that the suffix array always remains sorted. This is because we are replacing <code>nums[i]</code> with smaller elements, which will not disrupt the sorting structure of the suffix array (elements at indices <code>i + 1, i + 2</code>, etc. that are already sorted).</p>
<p><img src="https://leetcode.com/problems/minimum-replacements-to-sort-the-array/Figures/2366/2.png" alt="img"></p>
<p>On the contrary, if we start from the beginning and replace a larger element with smaller elements, it may disrupt the sorted order of the previously processed elements on the left, and we'll end up needing more operations to sort the processed subarray again, as shown in the picture below.</p>
<p><img src="https://leetcode.com/problems/minimum-replacements-to-sort-the-array/Figures/2366/forward.png" alt="img"></p>
<p>Now that we know the traversal order, the next step is to minimize the number of operations. When we reach <code>nums[i]</code> during the reverse traversal, if <code>nums[i] &gt; nums[i + 1]</code>, how many smaller numbers should we break <code>nums[i]</code> into? Here are a few options:</p>
<ul>
<li>Breaking <code>nums[i]</code> into many 1s, which would require too many operations.</li>
<li>Breaking <code>nums[i]</code> according to the value of <code>nums[i + 1]</code>, with the remainder of <code>nums[i]</code> divided by <code>nums[i + 1]</code> becoming the new <code>nums[i]</code>. However, in some cases, this method can result in a very small <code>nums[i]</code>. For example, <code>[7]</code> will be replaced by <code>[1, 3, 3]</code>, thus all the previous elements must be replaced by 1s.</li>
<li>Any better method?</li>
</ul>
<p><img src="https://leetcode.com/problems/minimum-replacements-to-sort-the-array/Figures/2366/3.png" alt="img"></p>
<p>We can use a method similar to option 2:</p>
<ul>
<li>If <code>nums[i]</code> is divisible by <code>nums[i + 1]</code>, we break <code>nums[i]</code> into multiple elements of value <code>nums[i + 1]</code>.</li>
<li>If <code>nums[i]</code> is not divisible by <code>nums[i + 1]</code>, we break <code>nums[i]</code> into <code>(nums[i] / nums[i + 1] + 1)</code> sorted elements, with the largest element being <code>nums[i + 1]</code> and the smallest element being <code>nums[i + 1] - 1</code>. For example, if <code>nums[i] = 7</code> and <code>nums[i + 1] = 3</code>, we replace <code>[7]</code> with <code>[2, 2, 3]</code> by two replacement operations.</li>
</ul>
<p><img src="https://leetcode.com/problems/minimum-replacements-to-sort-the-array/Figures/2366/4.png" alt="img"></p>
<p>The reason that <code>[2, 2, 3]</code> is a better split than <code>[1, 3, 3]</code> is that all future elements on the left will need to be less than or equal to the elements we split into here. Thus, we would prefer the larger <code>2</code> over the smaller <code>1</code>, so we have more options for future splits.</p>
<p>In summary, we traverse <code>nums</code> in reverse and break down each <code>nums[i]</code> that violates the sorting order according to the approach mentioned above. We also accumulate the number of replacement operations. It is important to note that when we break <code>nums[i]</code> into <code>n</code> elements, it actually requires <code>n - 1</code> steps.</p>
<p>Please refer to the picture below as a detailed example:</p>
<p><img src="https://leetcode.com/problems/minimum-replacements-to-sort-the-array/Figures/2366/5.png" alt="img"></p>
<blockquote>
<p>In the previous paragraph, we discussed two cases for calculating <code>num_elements</code>, which can be simplified by <code>nums_elements = (nums[i] + nums[i + 1] - 1) / nums[i + 1]</code>. Regardless of whether <code>nums[i]</code> is divisible as <code>nums[i + 1]</code> or not, we will always obtain the correct result.</p>
</blockquote>
<br>
<h4 id="algorithm">Algorithm</h4>
<ol>
<li>
<p>Set <code>answer</code> as 0, and set <code>n</code> as the length of <code>nums</code>.</p>
</li>
<li>
<p>Iterate over <code>nums</code> backward from <code>nums[n - 2]</code>, as we don't need to replace <code>nums[n - 1]</code>.</p>
<ul>
<li>If <code>nums[i] &lt;= nums[i + 1]</code>, move on to the next element <code>nums[i - 1]</code>.</li>
<li>If <code>nums[i]</code> is divisible by <code>nums[i + 1]</code>, break <code>nums[i]</code> into <code>nums_elements = num[i] / nums[i + 1]</code> elements, otherwise, break <code>num[i]</code> into <code>nums_elements = nums[i] / nums[i + 1] + 1</code> elements. This requires <code>num_elements - 1</code> replacement operations. Hence, we increment <code>answer</code> by <code>num_elements - 1</code>.</li>
<li>The largest possible <code>nums[i]</code> after the operations is <code>nums[i] / num_elements</code>, update <code>nums[i]</code> as <code>nums[i] / num_elements</code>.</li>
</ul>
</li>
<li>
<p>Return <code>answer</code> once the iteration is complete.</p>
</li>
</ol>
<h4 id="complexity-analysis">Complexity Analysis</h4>
<p>Let <span class="math math-inline"><span class="katex"><span class="katex-mathml">nn</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.4306em;"></span><span class="mord mathnormal">n</span></span></span></span></span> be the size of <code>nums</code>.</p>
<ul>
<li>
<p>Time complexity: <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(n)O(n)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal">n</span><span class="mclose">)</span></span></span></span></span></p>
<ul>
<li>We iterate over <code>nums</code> once in reverse.</li>
<li>At each step, we calculate <code>num_elements</code>, <code>answer</code> and <code>nums[i]</code>, which takes <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(1)O(1)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord">1</span><span class="mclose">)</span></span></span></span></span> time.</li>
</ul>
</li>
<li>
<p>Space complexity: <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(1)O(1)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord">1</span><span class="mclose">)</span></span></span></span></span></p>
<ul>
<li>We're modifying <code>nums</code> in place and not using any additional data structures that scale with the size of the input.</li>
<li>Note that some interviewers might not want you to modify the input as it is not considered good practice in real-world coding. If that's the case, you could slightly modify the algorithm to use an integer to track the most recently split numbers.</li>
</ul>
</li>
</ul>
<br>

```cpp
// OJ: https://leetcode.com/problems/minimum-replacements-to-sort-the-array
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    long long minimumReplacement(vector<int>& A) {
        long long ans = 0, N = A.size();
        for (int i = N - 2; i >= 0; --i) {
            if (A[i] <= A[i + 1]) continue;
            long long cnt = (A[i] + A[i + 1] - 1LL) / A[i + 1];
            ans += cnt - 1;
            A[i] /= cnt;
        }
        return ans;
    }
};
```