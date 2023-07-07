# [2024. Maximize the Confusion of an Exam (Medium)](https://leetcode.com/problems/maximize-the-confusion-of-an-exam)

<p>A teacher is writing a test with <code>n</code> true/false questions, with <code>'T'</code> denoting true and <code>'F'</code> denoting false. He wants to confuse the students by <strong>maximizing</strong> the number of <strong>consecutive</strong> questions with the <strong>same</strong> answer (multiple trues or multiple falses in a row).</p>

<p>You are given a string <code>answerKey</code>, where <code>answerKey[i]</code> is the original answer to the <code>i<sup>th</sup></code> question. In addition, you are given an integer <code>k</code>, the maximum number of times you may perform the following operation:</p>

<ul>
	<li>Change the answer key for any question to <code>'T'</code> or <code>'F'</code> (i.e., set <code>answerKey[i]</code> to <code>'T'</code> or <code>'F'</code>).</li>
</ul>

<p>Return <em>the <strong>maximum</strong> number of consecutive</em> <code>'T'</code>s or <code>'F'</code>s <em>in the answer key after performing the operation at most</em> <code>k</code> <em>times</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> answerKey = "TTFF", k = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> We can replace both the 'F's with 'T's to make answerKey = "<u>TTTT</u>".
There are four consecutive 'T's.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> answerKey = "TFFT", k = 1
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can replace the first 'T' with an 'F' to make answerKey = "<u>FFF</u>T".
Alternatively, we can replace the second 'T' with an 'F' to make answerKey = "T<u>FFF</u>".
In both cases, there are three consecutive 'F's.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> answerKey = "TTFTTFTT", k = 1
<strong>Output:</strong> 5
<strong>Explanation:</strong> We can replace the first 'F' to make answerKey = "<u>TTTTT</u>FTT"
Alternatively, we can replace the second 'F' to make answerKey = "TTF<u>TTTTT</u>". 
In both cases, there are five consecutive 'T's.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == answerKey.length</code></li>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>answerKey[i]</code> is either <code>'T'</code> or <code>'F'</code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Binary Search](https://leetcode.com/tag/binary-search/), [Sliding Window](https://leetcode.com/tag/sliding-window/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Longest Substring with At Most K Distinct Characters (Medium)](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/)
* [Longest Repeating Character Replacement (Medium)](https://leetcode.com/problems/longest-repeating-character-replacement/)
* [Max Consecutive Ones III (Medium)](https://leetcode.com/problems/max-consecutive-ones-iii/)
* [Minimum Number of Days to Make m Bouquets (Medium)](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/)
* [Longest Nice Subarray (Medium)](https://leetcode.com/problems/longest-nice-subarray/)

## Solution 1. Sliding Window

Check out "[C++ Maximum Sliding Window Cheatsheet Template!](https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175088/C%2B%2B-Maximum-Sliding-Window-Cheatsheet-Template!)".

**Intuition**: Use a sliding window to get the longest substring with at most `k` `'T'` (or `'F'`).

**Algorithm**: Implement a function `count(c)` which gets the longest substring with at most `k` character `c`. The answer is `max(count('T'), count('F'))`

We can use a shrinkable sliding window:

```cpp
// OJ: https://leetcode.com/problems/maximize-the-confusion-of-an-exam/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        auto count = [&](char c) {
            int N = s.size(), cnt = 0, i = 0, ans = 0;
            for (int j = 0; j < N; ++j) {
                cnt += s[j] == c;
                while (cnt > k) cnt -= s[i++] == c; // if there are more than `k` `c` characters, shrink the window until the `cnt` drops back to `k`.
                ans = max(ans, j - i + 1);
            }
            return ans;
        };
        return max(count('T'), count('F'));
    }
};
```

Or use non-shrinkable sliding window:

```cpp
// OJ: https://leetcode.com/problems/maximize-the-confusion-of-an-exam/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        auto count = [&](char c) {
            int N = s.size(), cnt = 0, i = 0, j = 0;
            for (; j < N; ++j) {
                cnt += s[j] == c;
                if (cnt > k) cnt -= s[i++] == c; // If `cnt > k` we shift the window.
            }
            return j - i;
        };
        return max(count('T'), count('F'));
    }
};
```

## Solution 2. Binary Search

```cpp
// OJ: https://leetcode.com/problems/maximize-the-confusion-of-an-exam
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        auto count = [&](char c) {
            auto valid = [&](int len) {
                int N = s.size(), cnt = 0;
                for (int i = 0; i < N; ++i) {
                    cnt += s[i] != c;
                    if (i - len >= 0) cnt -= s[i - len] != c;
                    if (i >= len - 1 && cnt <= k) return true; 
                }
                return false;
            };
            int L = 1, R = s.size();
            while (L <= R) {
                int M = (L + R) / 2;
                if (valid(M)) L = M + 1;
                else R = M - 1;
            }
            return R;
        };
        return max(count('T'), count('F'));
    }
};
```

## Discuss

https://leetcode.com/problems/maximize-the-confusion-of-an-exam/discuss/1499033/C%2B%2B-Sliding-window