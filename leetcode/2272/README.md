# [2272. Substring With Largest Variance (Hard)](https://leetcode.com/problems/substring-with-largest-variance)

<p>The <strong>variance</strong> of a string is defined as the largest difference between the number of occurrences of <strong>any</strong> <code>2</code> characters present in the string. Note the two characters may or may not be the same.</p>
<p>Given a string <code>s</code> consisting of lowercase English letters only, return <em>the <strong>largest variance</strong> possible among all <strong>substrings</strong> of</em> <code>s</code>.</p>
<p>A <strong>substring</strong> is a contiguous sequence of characters within a string.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "aababbb"
<strong>Output:</strong> 3
<strong>Explanation:</strong>
All possible variances along with their respective substrings are listed below:
- Variance 0 for substrings "a", "aa", "ab", "abab", "aababb", "ba", "b", "bb", and "bbb".
- Variance 1 for substrings "aab", "aba", "abb", "aabab", "ababb", "aababbb", and "bab".
- Variance 2 for substrings "aaba", "ababbb", "abbb", and "babb".
- Variance 3 for substring "babbb".
Since the largest possible variance is 3, we return it.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "abcde"
<strong>Output:</strong> 0
<strong>Explanation:</strong>
No letter occurs more than once in s, so the variance of every substring is 0.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Maximum Subarray (Medium)](https://leetcode.com/problems/maximum-subarray/)

## Solution 1. Kadane's Algorithm
<h3 id="overview">Overview</h3>
<blockquote>
<p>If you are not familiar with Kadane's algorithm, you may refer to <a href="https://en.wikipedia.org/wiki/Maximum_subarray_problem" target="_blank">this wikipedia's page</a>.</p>
</blockquote>
<p>Kadane's algorithm is a dynamic programming algorithm that finds the maximum subarray sum in an array of integers.  It maintains two values: global_max, which represents the maximum sum encountered so far, and local_max, which represents the maximum sum ending at the current index.  As the algorithm traverses the array from left to right, it updates these values. The algorithm is efficient because it only requires <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(n)O(n)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal">n</span><span class="mclose">)</span></span></span></span></span> time and <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(1)O(1)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord">1</span><span class="mclose">)</span></span></span></span></span> space to store two values and does not need any additional data structures.</p>
<p>As shown in the figure below, <code>local_max</code> represents the maximum value of the subarray ending at the current index. We update <code>local_max</code> at each index and update <code>global_max</code> by the maximum <code>local_max</code>. This ensures that we always have the maximum sum subarray at each position.</p>
<p><img src="https://leetcode.com/problems/substring-with-largest-variance/Figures/2272/1.png" alt="img"></p>
<p>Note that if the current subarray has a negative sum, we can discard it. In other words, if <code>local_max</code> is less than 0, we reset <code>local_max</code> to 0.</p>
<hr>
<h3 id="approach-kadanes-algorithm">Approach: Kadane's Algorithm</h3>
<h4 id="intuition">Intuition</h4>
<p>A similar approach can be used to solve this problem. Although <code>s</code> may contain many different characters, we can focus on one pair of letters <code>(major, minor)</code> at a time and calculate the maximum difference between their occurrences by applying Kadane's algorithm over all substrings of <code>s</code> that contain both <code>major</code> and <code>minor</code>.</p>
<blockquote>
<p>In other words, we assign the value of <code>major</code> as 1, the value of <code>minor</code> as -1, and the value of all other letters as 0, and use the standard Kadane's algorithm to find the maximum subarray sum in the array representing <code>s</code>.</p>
</blockquote>
<p><img src="https://leetcode.com/problems/substring-with-largest-variance/Figures/2272/exp.png" alt="img"></p>
<p>For instance, let's consider the pair of letters <code>(a, b)</code> as <code>(major, minor)</code> and determine their maximum variance in <code>s</code>. We update two variables <code>major_count</code> and <code>minor_count</code>, to keep track of the number of <code>major</code> and <code>minor</code> in the substring ending at the current index. Thus, <code>local_max</code> can be represented as <code>major_count - minor_count</code>. The equivalent of resetting <code>local_max</code> to 0 is setting both <code>major_count</code> and <code>minor_count</code> to 0.</p>
<p><img src="https://leetcode.com/problems/substring-with-largest-variance/Figures/2272/2.png" alt="img"></p>
<p>We notice that the standard Kadane's algorithm has failed to solve the problem. This is because Kadane's algorithm allows the subarray being considered to have no element with negative value. However, in our problem, a valid substring must contain at least one <code>major</code> and one <code>minor</code>, so the maximum variance calculated by regular Kadane's algorithm does not necessarily represent a valid substring.</p>
<p>Therefore, we need to modify Kadane's algorithm to solve this problem.</p>
<blockquote>
<p>Update <code>global_max</code> only when <code>minor_count &gt; 0</code>.</p>
</blockquote>
<p>This ensures that we only consider valid substrings that contain at least one <code>minor</code>. As shown in the picture below, we cannot update <code>global_max</code> if <code>minor_count = 0</code>. However, after encountering at least one <code>minor</code>, we can update <code>global_max</code> as <code>global_max = max(global_max, local_max) = 2</code>.</p>
<p><img src="https://leetcode.com/problems/substring-with-largest-variance/Figures/2272/3.png" alt="img"></p>
<blockquote>
<p>Reset <code>local_max</code> to 0 only when there is at least one <code>minor</code> in the remaining substring.</p>
</blockquote>
<p>Recall that we need a step <code>local_max = max(local_max, 0)</code> in regular Kadane's algorithm, which always discards the current subarray if it has a negative sum.</p>
<p>In this problem, however, we cannot simply reset <code>local_max</code> to 0 whenever it becomes negative because doing so would reset both <code>major_count</code> and <code>minor_count</code> to 0. If there are no more <code>minor</code> in the remaining string, the <code>minor_count</code> will remain 0, and we will never be able to update <code>global_max</code> during the remaining traversal. To avoid this situation, we reset <code>local_max</code> to 0 only when there is at least one <code>minor</code> in the remaining <code>s</code>. To achieve this, we can use an additional variable <code>rest_minor</code> to keep track of the number of <code>minor</code> in the remaining string.</p>
<p>As shown below, if <code>local_max &lt; 0</code> and there is still <code>minor</code> in the remaining string, we can reset it to 0 (i.e., reset both <code>minor_count</code> and <code>major_count</code> to 0).</p>
<p><img src="https://leetcode.com/problems/substring-with-largest-variance/Figures/2272/4.png" alt="img"></p>
<p>However, if there is no <code>minor</code> left in the remaining string, we cannot reset <code>minor_count</code> or <code>major_count</code> to 0, as any valid string found in the following iteration must contain at least one <code>minor</code>, so we cannot discard the last <code>minor</code> by setting <code>minor_count</code> to 0.</p>
<p><img src="https://leetcode.com/problems/substring-with-largest-variance/Figures/2272/5.png" alt="img"></p>
<p>To sum up, we will identify every pair of different letters in the given string, treat one as a <code>major</code> letter and the other as a <code>minor</code> letter, and then apply the modified Kadane's algorithm to traverse <code>s</code>. During the traversal, we need to keep track of the maximum variance between the occurrences of <code>major</code> and <code>minor</code>, which we call <code>global_max</code>. After traversing all the substrings for each pair of <code>major</code> and <code>minor</code>, we take the maximum value of <code>global_max</code> as the final result.</p>
<br>
<h4 id="algorithm">Algorithm</h4>
<ol>
<li>
<p>Initialize a counter to record the count of each distinct character in <code>s</code>. (Since we already know in advance that <code>s</code> contains only 26 different letters, we can use an array of length 26 as the counter)</p>
</li>
<li>
<p>For each pair of distinct letters <code>major</code> and <code>minor</code>, we apply Kadane's algorithm with modifications. All different pairs of distinct letters are considered, and <strong>two pairs of the same letters in different orders are considered to be different</strong>. In short, we will consider both <code>(a, b)</code> and <code>(b, a)</code>.</p>
</li>
<li>
<p>Set <code>global_max</code>, <code>major_count</code> and <code>minor_count</code> to 0, and let <code>rest_minor</code> be the number of character <code>minor</code> in the string.</p>
</li>
<li>
<p>Traverse the string <code>s</code>, and for each letter <code>ch</code>:</p>
<ul>
<li>If <code>ch</code> is <code>major</code>, increment <code>major_count</code> by 1.</li>
<li>If <code>ch</code> is <code>minor</code>, increment <code>minor_count</code> by 1 and decrement <code>rest_minor</code> by 1.</li>
</ul>
</li>
<li>
<p>Update <code>global_max</code> only when <code>minor_count &gt; 0</code> (The first modification).</p>
</li>
<li>
<p>If <code>major_count - minor_count &lt; 0</code>, reset them to 0 only when <code>rest_minor &gt; 0</code>  (The second modification).</p>
</li>
<li>
<p>Move on to the next pair of letters <code>(major, minor)</code> and repeat from step 3.</p>
</li>
<li>
<p>Return <code>global_max</code> when the iteration is complete.</p>
</li>
</ol>

<h4 id="complexity-analysis">Complexity Analysis</h4>
<p>Let <span class="math math-inline"><span class="katex"><span class="katex-mathml">nn</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.4306em;"></span><span class="mord mathnormal">n</span></span></span></span></span> be the length of the input string <code>s</code> and <span class="math math-inline"><span class="katex"><span class="katex-mathml">kk</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.6944em;"></span><span class="mord mathnormal" style="margin-right: 0.03148em;">k</span></span></span></span></span> be the number of distinct characters in <code>s</code>.</p>
<ul>
<li>
<p>Time complexity: <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(n⋅k2)O(n \cdot k^2)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal">n</span><span class="mspace" style="margin-right: 0.2222em;"></span><span class="mbin">⋅</span><span class="mspace" style="margin-right: 0.2222em;"></span></span><span class="base"><span class="strut" style="height: 1.0641em; vertical-align: -0.25em;"></span><span class="mord"><span class="mord mathnormal" style="margin-right: 0.03148em;">k</span><span class="msupsub"><span class="vlist-t"><span class="vlist-r"><span class="vlist" style="height: 0.8141em;"><span style="top: -3.063em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight">2</span></span></span></span></span></span></span></span><span class="mclose">)</span></span></span></span></span></p>
<ul>
<li>Kadane's algorithm requires <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(n)O(n)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord mathnormal">n</span><span class="mclose">)</span></span></span></span></span> time to traverse <code>s</code>. For each pair of alphabets <code>(major, minor)</code>, we need to traverse <code>s</code> once. In the worst-case scenario, <code>s</code> contains <span class="math math-inline"><span class="katex"><span class="katex-mathml">k=26k = 26</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.6944em;"></span><span class="mord mathnormal" style="margin-right: 0.03148em;">k</span><span class="mspace" style="margin-right: 0.2778em;"></span><span class="mrel">=</span><span class="mspace" style="margin-right: 0.2778em;"></span></span><span class="base"><span class="strut" style="height: 0.6444em;"></span><span class="mord">26</span></span></span></span></span> different letters, so there are <span class="math math-inline"><span class="katex"><span class="katex-mathml">k⋅(k−1)k\cdot (k - 1)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.6944em;"></span><span class="mord mathnormal" style="margin-right: 0.03148em;">k</span><span class="mspace" style="margin-right: 0.2222em;"></span><span class="mbin">⋅</span><span class="mspace" style="margin-right: 0.2222em;"></span></span><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mopen">(</span><span class="mord mathnormal" style="margin-right: 0.03148em;">k</span><span class="mspace" style="margin-right: 0.2222em;"></span><span class="mbin">−</span><span class="mspace" style="margin-right: 0.2222em;"></span></span><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord">1</span><span class="mclose">)</span></span></span></span></span> possible pairs of letters.</li>
</ul>
</li>
<li>
<p>Space complexity: <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(1)O(1)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord">1</span><span class="mclose">)</span></span></span></span></span></p>
<ul>
<li>In the Kadane's algorithm, we only need to update a few variables, <code>major_count</code>, <code>minor_count</code>, <code>rest_minor</code> and <code>global_max</code>, which require <span class="math math-inline"><span class="katex"><span class="katex-mathml">O(1)O(1)</span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathnormal" style="margin-right: 0.02778em;">O</span><span class="mopen">(</span><span class="mord">1</span><span class="mclose">)</span></span></span></span></span> space.</li>
</ul>
</li>
</ul>
<br>

```cpp
// OJ: https://leetcode.com/problems/substring-with-largest-variance
// Author: github.com/lzl124631x
// Time: O(N * C^2) where C is the range of character set
// Space: O(1)
    int largestVariance(string s) {
        int N = s.size(), cnt[26] = {}, ans = 0;
        for (char c : s) cnt[c - 'a']++;
        auto variance = [&](char major, char minor) {
            int majorCnt = 0, minorCnt = 0, restMinor = cnt[minor - 'a'], ans = 0;
            for (char c : s) {
                majorCnt += c == major;
                if (c == minor) {
                    minorCnt++;
                    restMinor--;
                }
                if (minorCnt > 0) ans = max(ans, majorCnt - minorCnt);
                if (majorCnt < minorCnt && restMinor > 0) {
                    majorCnt = 0;
                    minorCnt = 0;
                }
            }
            return ans;
        };
        for (char a = 'a'; a <= 'z'; ++a) {
            for (char b = 'a'; b <= 'z'; ++b) {
                if (a == b || cnt[a - 'a'] == 0 || cnt[b - 'a'] == 0) continue;
                ans = max(ans, variance(a, b));
            }
        }
        return ans;
    }
};
```