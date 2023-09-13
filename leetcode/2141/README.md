# [2141. Maximum Running Time of N Computers (Hard)](https://leetcode.com/problems/maximum-running-time-of-n-computers)

<p>You have <code>n</code> computers. You are given the integer <code>n</code> and a <strong>0-indexed</strong> integer array <code>batteries</code> where the <code>i<sup>th</sup></code> battery can <strong>run</strong> a computer for <code>batteries[i]</code> minutes. You are interested in running <strong>all</strong> <code>n</code> computers <strong>simultaneously</strong> using the given batteries.</p>
<p>Initially, you can insert <strong>at most one battery</strong> into each computer. After that and at any integer time moment, you can remove a battery from a computer and insert another battery <strong>any number of times</strong>. The inserted battery can be a totally new battery or a battery from another computer. You may assume that the removing and inserting processes take no time.</p>
<p>Note that the batteries cannot be recharged.</p>
<p>Return <em>the <strong>maximum</strong> number of minutes you can run all the </em><code>n</code><em> computers simultaneously.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/01/06/example1-fit.png" style="width: 762px; height: 150px;">
<pre><strong>Input:</strong> n = 2, batteries = [3,3,3]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
Initially, insert battery 0 into the first computer and battery 1 into the second computer.
After two minutes, remove battery 1 from the second computer and insert battery 2 instead. Note that battery 1 can still run for one minute.
At the end of the third minute, battery 0 is drained, and you need to remove it from the first computer and insert battery 1 instead.
By the end of the fourth minute, battery 1 is also drained, and the first computer is no longer running.
We can run the two computers simultaneously for at most 4 minutes, so we return 4.

</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/01/06/example2.png" style="width: 629px; height: 150px;">
<pre><strong>Input:</strong> n = 2, batteries = [1,1,1,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
Initially, insert battery 0 into the first computer and battery 2 into the second computer. 
After one minute, battery 0 and battery 2 are drained so you need to remove them and insert battery 1 into the first computer and battery 3 into the second computer. 
After another minute, battery 1 and battery 3 are also drained so the first and second computers are no longer running.
We can run the two computers simultaneously for at most 2 minutes, so we return 2.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= n &lt;= batteries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= batteries[i] &lt;= 10<sup>9</sup></code></li>
</ul>

**Companies**:
[Deutsche Bank](https://leetcode.com/company/deutsche-bank)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Minimum Moves to Equal Array Elements (Medium)](https://leetcode.com/problems/minimum-moves-to-equal-array-elements/)
* [Sell Diminishing-Valued Colored Balls (Medium)](https://leetcode.com/problems/sell-diminishing-valued-colored-balls/)
* [Maximum Number of Tasks You Can Assign (Hard)](https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/)
* [Minimum Time to Complete Trips (Medium)](https://leetcode.com/problems/minimum-time-to-complete-trips/)
* [Minimum Amount of Time to Fill Cups (Easy)](https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/)

## Solution 1.

<h2 id="solution">Solution</h2>
<hr>
<h3 id="overview">Overview</h3>
<p>From the first example, let's try another distribution plan first. Suppose we let 2 batteries support 2 computers continuously, we will end up with 2 empty batteries and 1 full battery. Then the running time is fixed at <code>3</code> since we can't use the only battery left to support 2 computers simultaneously.</p>
<p><img src="https://leetcode.com/problems/maximum-running-time-of-n-computers/Figures/2141/intro.png" alt="img"></p>
<p>It implies that there is a strategy to distribute the batteries properly. Let's move on to finding the best patterns.</p>
<hr>
<h3 id="approach-1-sorting-and-prefix-sum">Approach 1: Sorting and Prefix Sum</h3>
<h4 id="intuition">Intuition</h4>
<p>First, we simplify the original problem a little bit:</p>
<p><strong>Suppose we have 4 computers (named A, B, C and D) and have to pick exactly 4 batteries. What is the maximum running time?</strong></p>
<p>This is quite straightforward. We just pick the largest 4 batteries and let them support these 4 computers separately (let's call the list that contains these 4 batteries <code>live</code>), and the running time is determined by the smallest battery picked.</p>
<p><img src="https://leetcode.com/problems/maximum-running-time-of-n-computers/Figures/2141/n4.png" alt="img"></p>
<p><strong>What if we are allowed to pick a 5th battery?</strong></p>
<p>Let's pick the largest battery that isn't in use. Clearly, the smallest of these 4 batteries will be the bottleneck, so we use the power in the 5th battery to increase the running time of computer A that has the smallest battery.</p>
<p><img src="https://leetcode.com/problems/maximum-running-time-of-n-computers/Figures/2141/n5.png" alt="img"></p>
<p><strong>What if we are allowed to pick more batteries?</strong></p>
<p>We can freely use every battery except the largest 4 to increase the total running time. Because we can freely swap batteries in 0 time, all the extra power is interchangeable. We can take this extra power and "transfer" it to the batteries in <code>live</code>. Let <code>extra</code> be the sum of all the extra power.</p>
<p>Let's say live is sorted. We try using some of our extra power to increase live[0] running time to live[1]. In the process, <code>extra -= live[1] - live[0]</code>.</p>
<p><img src="https://leetcode.com/problems/maximum-running-time-of-n-computers/Figures/2141/n6.png" alt="img"></p>
<p>Now, <code>live[0] = live[1]</code>. Can we continue? We try increasing the running time to <code>live[2]</code>. However, not only would we need to increase <code>live[1]</code> to <code>live[2]</code>, we also need to increase <code>live[0]</code> to <code>live[2]</code> so it doesn't bottleneck the running time. We already spent some power to increase <code>live[0]</code> to <code>live[1]</code>, so we just need to spend twice as much power as the difference <code>live[2] - live[1]</code>.</p>
<p><img src="https://leetcode.com/problems/maximum-running-time-of-n-computers/Figures/2141/n70.png" alt="img"></p>
<p>Now we have <code>live[0] = live[1] = live[2]</code>. If we want to increase the running time to <code>live[3]</code>, we need to spend three times as much power as the difference <code>(live[3] - live[2])</code>.</p>
<br>
<p><img src="https://leetcode.com/problems/maximum-running-time-of-n-computers/Figures/2141/n71.png" alt="img"></p>
<p>Oops, seems we are running out of <code>extra</code> power before reaching <code>live[3]</code>, so the bottleneck is decided by <code>live[2]</code>. We have some extra power remaining, so we do our best to increase the running time by evenly splitting the remaining power to the computers  (<code>extra / 3</code>).</p>
<br>
<p>What if we have an example where <code>extra</code> is large enough to support all batteries in <code>live</code> becoming equal to <code>live[n - 1]</code>. Any remaining power in <code>extra</code> should similarly be evenly split across all the computers to increase the final running time. The final running time is determined by <code>live[n - 1]</code> plus the extra running time we can make using <code>extra</code> power, which is <code>extra / n</code>.</p>
<p><img src="https://leetcode.com/problems/maximum-running-time-of-n-computers/Figures/2141/n8.png" alt="img"></p>
<p>To generalize, at each battery <code>live[i]</code>, if we want to increase the running time to <code>live[i + 1]</code>, we need to spend <code>(i + 1)</code> times as much power as <code>(live[i + 1] - live[i])</code>. With this formula, we don't actually need to update the values of <code>live</code>. Since after each iteration, we already know that <code>live[0] = live[1] = ... = live[i]</code>.</p>
<p>We iterate through <code>live</code> until we either cannot afford to increase to <code>live[i + 1]</code> anymore, or we manage to iterate through the entire array. In both cases, we do our best to evenly allocate the remaining extra power.</p>
<br>
<p>You may be thinking that in the case below, since there is some unused power in the larger batteries (like the largest battery on the right), can we further increase the total running time using this unused power? The answer is NO.</p>
<p><img src="https://leetcode.com/problems/maximum-running-time-of-n-computers/Figures/2141/n7.png" alt="img"></p>
<p>As shown in the following picture, suppose we do allocate the power "equally" by using the excess power of the largest battery (colored in red) on other computers. It means that there are times when the red battery is used on other computers, but the same battery also supports the computer D <strong>all the time</strong>. This contradicts the rule that <em>one battery can't support more than one computer at the same time</em>.</p>
<p><img src="https://leetcode.com/problems/maximum-running-time-of-n-computers/Figures/2141/7.png" alt="img"></p>
<p>Therefore, we observe the pattern that:</p>
<blockquote>
<p>If a battery <code>batteries[i]</code> has more power than the total running time, there is no way we can use its excess power to further increase the running time. Therefore, once we have picked the largest <code>n</code> batteries and assign them to <code>n</code> computers, these batteries are tied to their computer and swapping them does not bring any longer running time.</p>
</blockquote>
<br>
<h4 id="algorithm">Algorithm</h4>
<ol>
<li>
<p>Sort <code>batteries</code>.</p>
</li>
<li>
<p>Find the largest <code>n</code> batteries and assign them to <code>n</code> computers, these <code>n</code> batteries are exclusively used by each computer and cannot be shared with other computers. Create an array <code>live</code> that contains the largest <code>n</code> batteries in sorted order, which represents the <code>n</code> computers.</p>
</li>
<li>
<p>Sum up the power of the remaining batteries as <code>extra</code>.</p>
</li>
<li>
<p>Iterate over <code>live</code> from <code>0</code> to <code>n - 2</code>, for each index <code>i</code>:</p>
<ul>
<li>If <code>extra</code> power can increase the running time of the first <code>i</code> computers from <code>live[i]</code> to <code>live[i + 1]</code>, then we subtract the required power from <code>extra</code> and move on to the next index.</li>
<li>Otherwise, we have to stop at this point and return <code>live[i] + extra / (i + 1)</code>.</li>
</ul>
</li>
<li>
<p>If there is still power left after the iteration, it means we can further increase the total running time of <code>n</code> computers from <code>live[n - 1]</code> by <code>extra / n</code>. Therefore, return <code>live[n - 1] + extra / n</code>.</p>
</li>
</ol>
<h4 id="complexity-analysis">Complexity Analysis</h4>
<p>Let <span class="math math-inline"><span class="katex"><span class="katex-mathml">mm</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.4306em;"></span><span class="mord mathnormal">m</span></span></span></span></span> be the length of the input array <code>batteries</code>.</p>
<ul>
<li>
<p>Time complexity: <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(m⋅log⁡m)O(m \cdot\log m)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal">m</span><span class="mspace" style="margin-right: 0.2222em;"></span><span class="mbin">⋅</span><span class="mspace" style="margin-right: 0.2222em;"></span></span><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mop">lo<span style="margin-right: 0.01389em;">g</span></span><span class="mspace" style="margin-right: 0.1667em;"></span><span class="mord mathnormal">m</span><span class="mclose">)</span></span></span></span></span></p>
<ul>
<li>
<p>We sort <span class="math math-inline"><span class="katex"><span class="katex-mathml">batteries\text{batteries}</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.6944em;"></span><span class="mord text"><span class="mord">batteries</span></span></span></span></span></span> in place, it takes <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(m⋅log⁡m)O(m \cdot\log m)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal">m</span><span class="mspace" style="margin-right: 0.2222em;"></span><span class="mbin">⋅</span><span class="mspace" style="margin-right: 0.2222em;"></span></span><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mop">lo<span style="margin-right: 0.01389em;">g</span></span><span class="mspace" style="margin-right: 0.1667em;"></span><span class="mord mathnormal">m</span><span class="mclose">)</span></span></span></span></span> time.</p>
</li>
<li>
<p>Picking the largest n-th batteries from a sorted array takes <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(n)O(n)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal">n</span><span class="mclose">)</span></span></span></span></span> time. Note that since <span class="math math-inline"><span class="katex"><span class="katex-mathml">n&lt;mn &lt; m</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.5782em; vertical-align: -0.0391em;"></span><span class="mord mathnormal">n</span><span class="mspace" style="margin-right: 0.2778em;"></span><span class="mrel">&lt;</span><span class="mspace" style="margin-right: 0.2778em;"></span></span><span class="base"><span class="strut" style="height: 0.4306em;"></span><span class="mord mathnormal">m</span></span></span></span></span>, this term will be dominated.</p>
</li>
<li>
<p>Then we iterate over the remaing part of the <code>batteries</code>, the computation at each step takes constant time. Thus it takes <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(m)O(m)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal">m</span><span class="mclose">)</span></span></span></span></span> time to finish the iteration.</p>
</li>
<li>
<p>To sum up, the overall time complexity is <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(m⋅log⁡m)O(m \cdot\log m)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal">m</span><span class="mspace" style="margin-right: 0.2222em;"></span><span class="mbin">⋅</span><span class="mspace" style="margin-right: 0.2222em;"></span></span><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mop">lo<span style="margin-right: 0.01389em;">g</span></span><span class="mspace" style="margin-right: 0.1667em;"></span><span class="mord mathnormal">m</span><span class="mclose">)</span></span></span></span></span>.</p>
</li>
</ul>
</li>
<li>
<p>Space complexity: <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(m)O(m)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal">m</span><span class="mclose">)</span></span></span></span></span></p>
<ul>
<li>Some extra space is used when we sort <span class="math math-inline"><span class="katex"><span class="katex-mathml">batteries\text{batteries}</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.6944em;"></span><span class="mord text"><span class="mord">batteries</span></span></span></span></span></span> in place. The space complexity of the sorting algorithm depends on the programming language.
<ul>
<li>In python, the <code>sort</code> method sorts a list using the Timsort algorithm, which is a combination of Merge Sort and Insertion Sort and uses <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(m)O(m)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal">m</span><span class="mclose">)</span></span></span></span></span> additional space.</li>
<li>In Java, Arrays.sort() is implemented using a variant of the Quick Sort algorithm which has a space complexity of <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(log⁡m)O(\log m)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mop">lo<span style="margin-right: 0.01389em;">g</span></span><span class="mspace" style="margin-right: 0.1667em;"></span><span class="mord mathnormal">m</span><span class="mclose">)</span></span></span></span></span>.</li>
</ul>
</li>
<li>We create an array of size <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(n)O(n)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal">n</span><span class="mclose">)</span></span></span></span></span> to record the power (running time) of each computer.</li>
<li>To sum up, the overall space complexity is <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(m)O(m)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal">m</span><span class="mclose">)</span></span></span></span></span>.</li>
</ul>
</li>
</ul>


```cpp
// OJ: https://leetcode.com/problems/maximum-running-time-of-n-computers
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    long long maxRunTime(int n, vector<int>& A) {
        sort(begin(A), end(A));
        long long N = A.size(), extra = accumulate(begin(A), end(A) - n, 0LL), start = N - n, ans = 
A[start];
        for (int i = start, len = 1; i < N - 1; ++i, ++len) {
            long long d = A[i + 1] - A[i];
            if (extra < len * d) return A[i] + extra / len;
            extra -= len * d;
        }
        return A.back() + extra / n;
    }
};
```

## Solution 2. Binary Search

<h4 id="intuition-1">Intuition</h4>
<p>In the previous approach, we began by selecting the largest <code>n</code> batteries (one for each computer) and then assigning the remaining power <code>extra</code> to these computers using a greedy approach until we reach the longest running time.</p>
<p>Alternatively, we can first set a target running time, <code>target</code>, then try to reach this running time using all batteries.</p>
<p><img src="https://leetcode.com/problems/maximum-running-time-of-n-computers/Figures/2141/b1.png" alt="img"></p>
<p>Here we still take advantage of the conclusion we reached at the end of the previous approach (Please refer to the previous approach):</p>
<ul>
<li>If the power of a battery is smaller than <code>target</code>, we can use all of its power.</li>
<li>If the power of a battery is larger than <code>target</code>, we can only use <code>target</code> power from it.</li>
</ul>
<p><img src="https://leetcode.com/problems/maximum-running-time-of-n-computers/Figures/2141/b2.png" alt="img"></p>
<p>Therefore, we can traverse through <code>batteries</code> and collect all the power that can be used. If the sum of collected power is larger than or equal to <code>target * n</code>, all computers can run for <code>target</code> time.</p>
<p>As shown in the picture above, suppose we set a running time <code>target</code>, then we collect power from all batteries (colored in green). Finally, we check if the sum of the collected power is larger than or equals to <code>target * 2</code>.</p>
<p><strong>How to find the largest running time?</strong></p>
<p>Instead of trying every <code>target</code> from <code>1</code> until finding the largest possible running time, we can take advantage of binary search to locate the largest <code>target</code> faster than linear search.</p>
<p><img src="https://leetcode.com/problems/maximum-running-time-of-n-computers/Figures/2141/b3.png" alt="img"></p>
<p>Initially, we set the left boundary as <code>1</code> as the minimum possible running time. Assuming we can use all the power perfectly, the maximum running time is <code>sum(batteries) / n</code>, so we set the right boundary as <code>sum(batteries) / n</code>. As a result, the largest <code>target</code> is limited to the inclusive range <code>[left, right]</code>, and we can apply binary search in this range to find it.</p>
<br>
<h4 id="algorithm-1">Algorithm</h4>
<ol>
<li>
<p>Initialize the boundaries of the search space as <code>left = 1</code>, and <code>right = sum(batteries) / n</code>.</p>
</li>
<li>
<p>While <code>left &lt; right</code>:</p>
<ul>
<li>Find the middle value <code>target = right - (right - left) / 2</code>.</li>
<li>Check if batteries can support <code>n</code> computers run <code>target</code> time. Iterate over <code>batteries</code> and record <code>extra</code>, the accumulative sum of <code>min(batteries[i], target)</code>.</li>
</ul>
</li>
<li>
<p>Check if <code>extra &gt;= n * target</code>:</p>
<ul>
<li>If so, set <code>left = target</code> and repeat step 2.</li>
<li>Otherwise, set <code>right = target - 1</code> and repate step 2.</li>
</ul>
</li>
<li>
<p>Once the binary search ends, return <code>left</code>.</p>
</li>
</ol>
<h4 id="complexity-analysis-1">Complexity Analysis</h4>
<p>Let <span class="math math-inline"><span class="katex"><span class="katex-mathml">mm</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.4306em;"></span><span class="mord mathnormal">m</span></span></span></span></span> be the length of the input array <code>batteries</code> and <span class="math math-inline"><span class="katex"><span class="katex-mathml">kk</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.6944em;"></span><span class="mord mathnormal" style="margin-right: 0.03148em;">k</span></span></span></span></span> be the maximum power of one battery.</p>
<ul>
<li>
<p>Time complexity: <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(m⋅log⁡k)O(m \cdot\log k)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal">m</span><span class="mspace" style="margin-right: 0.2222em;"></span><span class="mbin">⋅</span><span class="mspace" style="margin-right: 0.2222em;"></span></span><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mop">lo<span style="margin-right: 0.01389em;">g</span></span><span class="mspace" style="margin-right: 0.1667em;"></span><span class="mord mathnormal" style="margin-right: 0.03148em;">k</span><span class="mclose">)</span></span></span></span></span></p>
<ul>
<li>
<p>Initially, we set <code>1</code> as the left boundary and <code>sum(batteries) / n</code> as the right boundary. Thus it takes <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(log⁡(m⋅kn))O(\log (\frac{m\cdot k}{n}))</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1.2251em; vertical-align: -0.345em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mop">lo<span style="margin-right: 0.01389em;">g</span></span><span class="mopen">(</span><span class="mord"><span class="mopen nulldelimiter"></span><span class="mfrac"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 0.8801em;"><span style="top: -2.655em;"><span class="pstrut" style="height: 3em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mathnormal mtight">n</span></span></span></span><span style="top: -3.23em;"><span class="pstrut" style="height: 3em;"></span><span class="frac-line" style="border-bottom-width: 0.04em;"></span></span><span style="top: -3.394em;"><span class="pstrut" style="height: 3em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mathnormal mtight">m</span><span class="mbin mtight">⋅</span><span class="mord mathnormal mtight" style="margin-right: 0.03148em;">k</span></span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.345em;"><span></span></span></span></span></span><span class="mclose nulldelimiter"></span></span><span class="mclose">))</span></span></span></span></span> steps to locate the maximum running time in the worst-case scenario.</p>
</li>
<li>
<p>At each step, we need to iterate over <code>batteries</code> to add up the power that can be used, which takes <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(m)O(m)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal">m</span><span class="mclose">)</span></span></span></span></span> time.</p>
</li>
<li>
<p>Therefore, the overall time complexity is <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(m⋅log⁡(m⋅kn))=O(m⋅log⁡k)O(m \cdot\log (\frac{m\cdot k}{n})) = O(m\cdot \log k)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal">m</span><span class="mspace" style="margin-right: 0.2222em;"></span><span class="mbin">⋅</span><span class="mspace" style="margin-right: 0.2222em;"></span></span><span class="base"><span class="strut" style="height: 1.2251em; vertical-align: -0.345em;"></span><span class="mop">lo<span style="margin-right: 0.01389em;">g</span></span><span class="mopen">(</span><span class="mord"><span class="mopen nulldelimiter"></span><span class="mfrac"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 0.8801em;"><span style="top: -2.655em;"><span class="pstrut" style="height: 3em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mathnormal mtight">n</span></span></span></span><span style="top: -3.23em;"><span class="pstrut" style="height: 3em;"></span><span class="frac-line" style="border-bottom-width: 0.04em;"></span></span><span style="top: -3.394em;"><span class="pstrut" style="height: 3em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mathnormal mtight">m</span><span class="mbin mtight">⋅</span><span class="mord mathnormal mtight" style="margin-right: 0.03148em;">k</span></span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.345em;"><span></span></span></span></span></span><span class="mclose nulldelimiter"></span></span><span class="mclose">))</span><span class="mspace" style="margin-right: 0.2778em;"></span><span class="mrel">=</span><span class="mspace" style="margin-right: 0.2778em;"></span></span><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal">m</span><span class="mspace" style="margin-right: 0.2222em;"></span><span class="mbin">⋅</span><span class="mspace" style="margin-right: 0.2222em;"></span></span><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mop">lo<span style="margin-right: 0.01389em;">g</span></span><span class="mspace" style="margin-right: 0.1667em;"></span><span class="mord mathnormal" style="margin-right: 0.03148em;">k</span><span class="mclose">)</span></span></span></span></span><br>
<span class="math math-inline"><span class="katex"><span class="katex-mathml">,k≫m,n, k \gg m, n</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.8889em; vertical-align: -0.1944em;"></span><span class="mpunct">,</span><span class="mspace" style="margin-right: 0.1667em;"></span><span class="mord mathnormal" style="margin-right: 0.03148em;">k</span><span class="mspace" style="margin-right: 0.2778em;"></span><span class="mrel">≫</span><span class="mspace" style="margin-right: 0.2778em;"></span></span><span class="base"><span class="strut" style="height: 0.625em; vertical-align: -0.1944em;"></span><span class="mord mathnormal">m</span><span class="mpunct">,</span><span class="mspace" style="margin-right: 0.1667em;"></span><span class="mord mathnormal">n</span></span></span></span></span></p>
</li>
</ul>
</li>
<li>
<p>Space complexity: <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(1)O(1)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord">1</span><span class="mclose">)</span></span></span></span></span></p>
<ul>
<li>During the binary search, we only need to record the boundaries of the searching space and the power <code>extra</code>, and the accumulative sum of <code>extra</code>, which only takes constant space.</li>
</ul>
</li>
</ul>
<br>

```cpp
// OJ: https://leetcode.com/problems/maximum-running-time-of-n-computers
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    long long maxRunTime(int n, vector<int>& A) {
        long long sum = accumulate(begin(A), end(A), 0LL), L = 1, R = sum / n;
        auto valid = [&](long long target) {
            long long extra = 0;
            for (int n : A) extra += min((long long)n, target);
            return extra >= n * target;
        };
        while (L <= R) {
            long long M = L + (R - L) / 2, extra = 0;
            if (valid(M)) L = M + 1;
            else R = M - 1;
        }
        return R;
    }
};
```