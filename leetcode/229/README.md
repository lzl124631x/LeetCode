# [229. Majority Element II (Medium)](https://leetcode.com/problems/majority-element-ii)

<p>Given an integer array of size <code>n</code>, find all elements that appear more than <code>&lfloor; n/3 &rfloor;</code> times.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,2,3]
<strong>Output:</strong> [3]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1]
<strong>Output:</strong> [1]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2]
<strong>Output:</strong> [1,2]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you solve the problem in linear time and in <code>O(1)</code> space?</p>


**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Adobe](https://leetcode.com/company/adobe), [Google](https://leetcode.com/company/google), [Apple](https://leetcode.com/company/apple), [Bloomberg](https://leetcode.com/company/bloomberg), [Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook), [Rubrik](https://leetcode.com/company/rubrik), [Zenefits](https://leetcode.com/company/zenefits)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Hash Table](https://leetcode.com/tag/hash-table), [Sorting](https://leetcode.com/tag/sorting), [Counting](https://leetcode.com/tag/counting)

**Similar Questions**:
* [Majority Element (Easy)](https://leetcode.com/problems/majority-element)
* [Check If a Number Is Majority Element in a Sorted Array (Easy)](https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array)
* [Most Frequent Even Element (Easy)](https://leetcode.com/problems/most-frequent-even-element)

**Hints**:
* How many majority elements could it possibly have?
<br/>
Do you have a better hint? <a href="mailto:admin@leetcode.com?subject=Hints for Majority Element II" target="_blank">Suggest it</a>!

## Solution 1. Boyer-Moore Majority Vote algorithm

<p><strong>Intuition</strong></p>
<p>To figure out a <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(1)O(1)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord">1</span><span class="mclose">)</span></span></span></span></span> space requirement, we would need to get this simple intuition first. For an array of length <code>n</code>:</p>
<ul>
<li>There can be at most <strong>one</strong> majority element which is <strong>more than</strong> <code>⌊n/2⌋</code> times.</li>
<li>There can be at most <strong>two</strong> majority elements which are <strong>more than</strong> <code>⌊n/3⌋</code> times.</li>
<li>There can be at most <strong>three</strong> majority elements which are <strong>more than</strong> <code>⌊n/4⌋</code> times.</li>
</ul>
<p>and so on.</p>
<p>Knowing this can help us understand how we can keep track of majority elements which satisfies <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(1)O(1)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord">1</span><span class="mclose">)</span></span></span></span></span> space requirement.</p>
<p>Let's try to get an intuition for the case where we would like to find a majority element which is more than <code>⌊n/2⌋</code> times in an array of length <code>n</code>.</p>
<p>The idea is to have two variables, one holding a potential candidate for majority element and a counter to keep track of whether to swap a potential candidate or not. Why can we get away with only two variables? Because <em>there can be at most <strong>one</strong> majority element which is more than <code>⌊n/2⌋</code> times</em>. Therefore, having only one variable to hold the only potential candidate and one counter is enough.</p>
<p>While scanning the array, the counter is incremented if you encounter an element which is exactly same as the potential candidate but decremented otherwise. When the counter reaches zero, the element which will be encountered next will become the potential candidate. Keep doing this procedure while scanning the array. However, when you have exhausted the array, you have to make sure that the element recorded in the potential candidate variable is the majority element by checking whether it occurs more than <code>⌊n/2⌋</code> times in the array. In the original <a href="https://leetcode.com/problems/majority-element/" target="_blank">Majority Element</a> problem, it is guaranteed that there is a majority element in the array so your implementation can omit the second pass. However, in a general case, you need this second pass since your array can have no majority elements at all!</p>
<p>The counter is initialized as <code>0</code> and the potential candidate as <code>None</code> at the start of the array.</p>
<p>If an element is truly a majority element, it will stick in the potential candidate variable, no matter how it shows up in the array (i.e. all clustered in the beginning of the array, all clustered near the end of the array, or showing up anywhere in the array), after the whole array has been scanned. Of course, while you are scanning the array, the element might be replaced by another element in the process, but the true majority element will definitely remain as the potential candidate in the end.</p>
<p>Now figuring out the majority elements which show up more than <code>⌊n/3⌋</code> times is not that hard anymore. Using the intuition presented in the beginning, we only need four variables: two for holding two potential candidates and two for holding two corresponding counters. Similar to the above case, both candidates are initialized as <code>None</code> in the beginning with their corresponding counters being 0. While going through the array:</p>
<ul>
<li>If the current element is equal to one of the potential candidate, the count for that candidate is increased while leaving the count of the other candidate as it is.</li>
<li>If the counter reaches zero, the candidate associated with that counter will be replaced with the next element <strong>if</strong> the next element is not equal to the other candidate as well.</li>
<li>Both counters are decremented <strong>only when</strong> the current element is different from both candidates.</li>
</ul>
<p><strong>Complexity Analysis</strong></p>
<ul>
<li>
<p>Time complexity : <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(N)O(N)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal" style="margin-right: 0.10903em;">N</span><span class="mclose">)</span></span></span></span></span> where <span class="math math-inline"><span class="katex"><span class="katex-mathml">NN</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.6833em;"></span><span class="mord mathnormal" style="margin-right: 0.10903em;">N</span></span></span></span></span> is the size of <code>nums</code>. We first go through <code>nums</code> looking for first and second potential candidates. We then count the number of occurrences for these two potential candidates in <code>nums</code>. Therefore, our runtime is <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(N)+O(N)=O(2N)≈O(N)O(N) + O(N) = O(2N) \approx O(N)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal" style="margin-right: 0.10903em;">N</span><span class="mclose">)</span><span class="mspace" style="margin-right: 0.2222em;"></span><span class="mbin">+</span><span class="mspace" style="margin-right: 0.2222em;"></span></span><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal" style="margin-right: 0.10903em;">N</span><span class="mclose">)</span><span class="mspace" style="margin-right: 0.2778em;"></span><span class="mrel">=</span><span class="mspace" style="margin-right: 0.2778em;"></span></span><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord">2</span><span class="mord mathnormal" style="margin-right: 0.10903em;">N</span><span class="mclose">)</span><span class="mspace" style="margin-right: 0.2778em;"></span><span class="mrel">≈</span><span class="mspace" style="margin-right: 0.2778em;"></span></span><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal" style="margin-right: 0.10903em;">N</span><span class="mclose">)</span></span></span></span></span>.</p>
</li>
<li>
<p>Space complexity : <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(1)O(1)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord">1</span><span class="mclose">)</span></span></span></span></span> since we only have four variables for holding two potential candidates and two counters. Even the returning array is at most 2 elements.</p>
</li>
</ul>

```cpp
// OJ: https://leetcode.com/problems/majority-element-ii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/17564/boyer-moore-majority-vote-algorithm-and-my-elaboration
class Solution {
public:
    vector<int> majorityElement(vector<int>& A) {
        int a = 0, b = 1, ca = 0, cb = 0, goal = A.size() / 3;
        for (int n : A) {
            if (n == a) ++ca;
            else if (n == b) ++cb;
            else if (!ca) a = n, ++ca;
            else if (!cb) b = n, ++cb;
            else --ca, --cb;
        }
        ca = cb = 0;
        for (int n : A) {
            if (n == a) ++ca;
            else if (n == b) ++cb;
        }
        vector<int> ans;
        if (ca > goal) ans.push_back(a);
        if (cb > goal) ans.push_back(b);
        return ans;
    }
};
```