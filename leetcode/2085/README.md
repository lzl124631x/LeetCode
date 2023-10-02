# [2085. Count Common Words With One Occurrence (Easy)](https://leetcode.com/problems/count-common-words-with-one-occurrence/)

<p>Given two string arrays <code>words1</code> and <code>words2</code>, return <em>the number of strings that appear <strong>exactly once</strong> in <b>each</b>&nbsp;of the two arrays.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
<strong>Output:</strong> 2
<strong>Explanation:</strong>
- "leetcode" appears exactly once in each of the two arrays. We count this string.
- "amazing" appears exactly once in each of the two arrays. We count this string.
- "is" appears in each of the two arrays, but there are 2 occurrences of it in words1. We do not count this string.
- "as" appears once in words1, but does not appear in words2. We do not count this string.
Thus, there are 2 strings that appear exactly once in each of the two arrays.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no strings that appear in each of the two arrays.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> words1 = ["a","ab"], words2 = ["a","a","a","ab"]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The only string that appears exactly once in each of the two arrays is "ab".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words1.length, words2.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words1[i].length, words2[j].length &lt;= 30</code></li>
	<li><code>words1[i]</code> and <code>words2[j]</code> consists only of lowercase English letters.</li>
</ul>


**Similar Questions**:
* [Intersection of Two Arrays (Easy)](https://leetcode.com/problems/intersection-of-two-arrays/)
* [Uncommon Words from Two Sentences (Easy)](https://leetcode.com/problems/uncommon-words-from-two-sentences/)
* [Kth Distinct String in an Array (Easy)](https://leetcode.com/problems/kth-distinct-string-in-an-array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-common-words-with-one-occurrence/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int countWords(vector<string>& A, vector<string>& B) {
        unordered_map<string, int> a, b;
        for (auto &s : A) a[s]++;
        for (auto &s : B) b[s]++;
        int ans = 0;
        for (auto &[s, cnt] : a) {
            if (cnt == 1 && b.count(s) && b[s] == 1) ++ans;
        }
        return ans;
    }
};
```