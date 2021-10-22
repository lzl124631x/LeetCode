# [451. Sort Characters By Frequency (Medium)](https://leetcode.com/problems/sort-characters-by-frequency/)

<p>Given a string <code>s</code>, sort it in <strong>decreasing order</strong> based on the <strong>frequency</strong> of the characters. The <strong>frequency</strong> of a character is the number of times it appears in the string.</p>

<p>Return <em>the sorted string</em>. If there are multiple answers, return <em>any of them</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "tree"
<strong>Output:</strong> "eert"
<strong>Explanation:</strong> 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "cccaaa"
<strong>Output:</strong> "aaaccc"
<strong>Explanation:</strong> Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "Aabb"
<strong>Output:</strong> "bbAa"
<strong>Explanation:</strong> "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>s</code> consists of uppercase and lowercase English letters and digits.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Bloomberg](https://leetcode.com/company/bloomberg), [Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook), [Salesforce](https://leetcode.com/company/salesforce)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Sorting](https://leetcode.com/tag/sorting/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Bucket Sort](https://leetcode.com/tag/bucket-sort/), [Counting](https://leetcode.com/tag/counting/)

**Similar Questions**:
* [Top K Frequent Elements (Medium)](https://leetcode.com/problems/top-k-frequent-elements/)
* [First Unique Character in a String (Easy)](https://leetcode.com/problems/first-unique-character-in-a-string/)
* [Sort Array by Increasing Frequency (Easy)](https://leetcode.com/problems/sort-array-by-increasing-frequency/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/sort-characters-by-frequency/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(C)
class Solution {
public:
    string frequencySort(string s) {
        int cnt[256] = {};
        for (char c : s) cnt[c]++;
        sort(s.begin(), s.end(), [&](char a, char b) {
            return cnt[a] == cnt[b] ? a > b : cnt[a] > cnt[b];
        });
        return s;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/sort-characters-by-frequency/
// Author: github.com/lzl124631x
// Time: O(N + ClogC) where C is the number of unique characters in `s`.
// Space: O(C)
class Solution {
public:
    string frequencySort(string s) {
        vector<char> v;
        int cnt[256] = {};
        for (char c : s) {
            if (cnt[c]++ == 0) v.push_back(c);
        }
        sort(v.begin(), v.end(), [&](char a, char b) { return cnt[a] > cnt[b]; });
        string ans;
        for (char c : v) {
            for (int i = 0; i < cnt[c]; ++i) ans.push_back(c);
        }
        return ans;
    }
};
```