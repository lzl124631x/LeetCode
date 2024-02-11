# [3035. Maximum Palindromes After Operations (Medium)](https://leetcode.com/problems/maximum-palindromes-after-operations)

<p>You are given a <strong>0-indexed</strong> string array <code>words</code> having length <code>n</code> and containing <strong>0-indexed</strong> strings.</p>

<p>You are allowed to perform the following operation <strong>any</strong> number of times (<strong>including</strong> <strong>zero</strong>):</p>

<ul>
	<li>Choose integers <code>i</code>, <code>j</code>, <code>x</code>, and <code>y</code> such that <code>0 &lt;= i, j &lt; n</code>, <code>0 &lt;= x &lt; words[i].length</code>, <code>0 &lt;= y &lt; words[j].length</code>, and <strong>swap</strong> the characters <code>words[i][x]</code> and <code>words[j][y]</code>.</li>
</ul>

<p>Return <em>an integer denoting the <strong>maximum</strong> number of <span data-keyword="palindrome-string">palindromes</span> </em><code>words</code><em> can contain, after performing some operations.</em></p>

<p><strong>Note:</strong> <code>i</code> and <code>j</code> may be equal during an operation.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;abbb&quot;,&quot;ba&quot;,&quot;aa&quot;]
<strong>Output:</strong> 3
<strong>Explanation:</strong> In this example, one way to get the maximum number of palindromes is:
Choose i = 0, j = 1, x = 0, y = 0, so we swap words[0][0] and words[1][0]. words becomes [&quot;bbbb&quot;,&quot;aa&quot;,&quot;aa&quot;].
All strings in words are now palindromes.
Hence, the maximum number of palindromes achievable is 3.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;abc&quot;,&quot;ab&quot;]
<strong>Output:</strong> 2
<strong>Explanation: </strong>In this example, one way to get the maximum number of palindromes is: 
Choose i = 0, j = 1, x = 1, y = 0, so we swap words[0][1] and words[1][0]. words becomes [&quot;aac&quot;,&quot;bb&quot;].
Choose i = 0, j = 0, x = 1, y = 2, so we swap words[0][1] and words[0][2]. words becomes [&quot;aca&quot;,&quot;bb&quot;].
Both strings are now palindromes.
Hence, the maximum number of palindromes achievable is 2.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;cd&quot;,&quot;ef&quot;,&quot;a&quot;]
<strong>Output:</strong> 1
<strong>Explanation:</strong> In this example, there is no need to perform any operation.
There is one palindrome in words &quot;a&quot;.
It can be shown that it is not possible to get more than one palindrome after any number of operations.
Hence, the answer is 1.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 100</code></li>
	<li><code>words[i]</code> consists only of lowercase English letters.</li>
</ul>


**Similar Questions**:
* [Valid Palindrome (Easy)](https://leetcode.com/problems/valid-palindrome)

**Hints**:
* We can redistribute all the letters freely among the words.
* Calculate the frequency of each letter and total the number of matching letter pairs that can be formed from the letters, i.e., <code>total = sum(freq[ch] / 2)</code> for all <code>'a' <= ch <= 'z'</code>.
* We can greedily try making palindromes from <code>words[i]</code> with the smallest length to <code>words[i]</code> with the longest length.
* For the current index, <code>i</code>, we try to make <code>words[i]</code> a palindrome. We need <code>len(words[i]) / 2</code> matching character pairs, and the letter in the middle (if it exists) can be freely chosen afterward.
* We can check if we have enough pairs for index <code>i</code>; if we do, we increase the number of palindromes we can make and decrease the number of pairs we have. Otherwise, we end the loop at this index.
* The answer is the number of palindromes we were able to make in the end.

## Solution 1. Counting and Sort

```cpp
// OJ: https://leetcode.com/problems/maximum-palindromes-after-operations
// Author: github.com/lzl124631x
// Time: O(W * NlogN)
// Space: O(1)
class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& A) {
        int N = A.size(), cnt[26] = {}, oddLetter = 0, evenLetter = 0, ans = 0;
        for (auto &s : A) {
            for (char c : s) cnt[c - 'a']++;
        }
        for (int i = 0; i < 26; ++i) { // Count the number of letters with even and odd counts.
            oddLetter += cnt[i] % 2;
            evenLetter += cnt[i] - cnt[i] % 2;
        }
        sort(begin(A), end(A), [](auto& a, auto& b) { return a.size() < b.size(); });
        for (auto &s : A) {
            int needEven = s.size() - s.size() % 2, needOdd = s.size() % 2;
            if (evenLetter >= needEven && (oddLetter >= needOdd || evenLetter - needEven >= needOdd)) { // If this string can be formed with remaining letters
                evenLetter -= needEven;
                if (oddLetter >= needOdd) {
                    oddLetter -= needOdd;
                } else { // If there is no odd letters remaining but we need a single letter, we use a letter from a pair of even letters
                    evenLetter -= needOdd;
                    oddLetter += needOdd;
                }
                ++ans;
            }
        }
        return ans;
    }
};
```