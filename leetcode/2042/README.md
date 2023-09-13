# [2042. Check if Numbers Are Ascending in a Sentence (Easy)](https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/)

<p>A sentence is a list of <strong>tokens</strong> separated by a <strong>single</strong> space with no leading or trailing spaces. Every token is either a <strong>positive number</strong> consisting of digits <code>0-9</code> with no leading zeros, or a <strong>word</strong> consisting of lowercase English letters.</p>

<ul>
	<li>For example, <code>"a puppy has 2 eyes 4 legs"</code> is a sentence with seven tokens: <code>"2"</code> and <code>"4"</code> are numbers and the other tokens such as <code>"puppy"</code> are words.</li>
</ul>

<p>Given a string <code>s</code> representing a sentence, you need to check if <strong>all</strong> the numbers in <code>s</code> are <strong>strictly increasing</strong> from left to right (i.e., other than the last number, <strong>each</strong> number is <strong>strictly smaller</strong> than the number on its <strong>right</strong> in <code>s</code>).</p>

<p>Return <code>true</code><em> if so, or </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="example-1" src="https://assets.leetcode.com/uploads/2021/09/30/example1.png" style="width: 637px; height: 48px;">
<pre><strong>Input:</strong> s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles"
<strong>Output:</strong> true
<strong>Explanation:</strong> The numbers in s are: 1, 3, 4, 6, 12.
They are strictly increasing from left to right: 1 &lt; 3 &lt; 4 &lt; 6 &lt; 12.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "hello world 5 x 5"
<strong>Output:</strong> false
<strong>Explanation:</strong> The numbers in s are: <u><strong>5</strong></u>, <strong><u>5</u></strong>. They are not strictly increasing.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="example-3" src="https://assets.leetcode.com/uploads/2021/09/30/example3.png" style="width: 794px; height: 48px;">
<pre><strong>Input:</strong> s = "sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s"
<strong>Output:</strong> false
<strong>Explanation:</strong> The numbers in s are: 7, <u><strong>51</strong></u>, <u><strong>50</strong></u>, 60. They are not strictly increasing.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "4 5 11 26"
<strong>Output:</strong> true
<strong>Explanation:</strong> The numbers in s are: 4, 5, 11, 26.
They are strictly increasing from left to right: 4 &lt; 5 &lt; 11 &lt; 26.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 200</code></li>
	<li><code>s</code> consists of lowercase English letters, spaces, and digits from <code>0</code> to <code>9</code>, inclusive.</li>
	<li>The number of tokens in <code>s</code> is between <code>2</code> and <code>100</code>, inclusive.</li>
	<li>The tokens in <code>s</code> are separated by a single space.</li>
	<li>There are at least <strong>two</strong> numbers in <code>s</code>.</li>
	<li>Each number in <code>s</code> is a <strong>positive</strong> number <strong>less</strong> than <code>100</code>, with no leading zeros.</li>
	<li><code>s</code> contains no leading or trailing spaces.</li>
</ul>


**Similar Questions**:
* [String to Integer (atoi) (Medium)](https://leetcode.com/problems/string-to-integer-atoi/)
* [Sorting the Sentence (Easy)](https://leetcode.com/problems/sorting-the-sentence/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence//
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool areNumbersAscending(string s) {
        string word;
        istringstream ss(s);
        int prev = -1;
        while (ss >> word) { 
            if (isdigit(word[0])) {
                int n = stoi(word);
                if (n <= prev) return false;
                prev = n;
            }
        }
        return true;
    }
};
```

## Discuss

https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/discuss/1525203/C%2B%2B-Brute-Force