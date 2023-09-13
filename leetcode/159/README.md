# [159. Longest Substring with At Most Two Distinct Characters (Medium)](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/)

<p>Given a string <code>s</code>, return <em>the length of the longest substring that contains at most <strong>two distinct characters</strong></em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "eceba"
<strong>Output:</strong> 3
<strong>Explanation:</strong> The substring is "ece" which its length is 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "ccaabbb"
<strong>Output:</strong> 5
<strong>Explanation:</strong> The substring is "aabbb" which its length is 5.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of English letters.</li>
</ul>


**Companies**:  
[Yandex](https://leetcode.com/company/yandex)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Longest Substring Without Repeating Characters (Medium)](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
* [Sliding Window Maximum (Hard)](https://leetcode.com/problems/sliding-window-maximum/)
* [Longest Substring with At Most K Distinct Characters (Medium)](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/)
* [Subarrays with K Different Integers (Hard)](https://leetcode.com/problems/subarrays-with-k-different-integers/)

## Solution 1. Sliding Window

Check out "[C++ Maximum Sliding Window Cheatsheet Template!](https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175088/C%2B%2B-Maximum-Sliding-Window-Cheatsheet-Template!)".


Shrinkable Sliding Window:
```cpp
// OJ: https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(C) 
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> m(128, 0);
        int i = 0, j = 0, ans = 0, cnt = 0;
        while (j < s.size()) {
            if (m[s[j++]]++ == 0) ++cnt;
            while (cnt > 2) {
                if (m[s[i++]]-- == 1) --cnt;
            }
            ans = max(ans, j - i);
        }
        return ans;
    }
};
```

Non-shrinkable Sliding Window:

```cpp
// OJ: https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(C)
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int distinct = 0, cnt[128] = {}, N = s.size(), i = 0, j = 0;
        while (j < N) {
            distinct += ++cnt[s[j++]] == 1;
            if (distinct > 2) distinct -= --cnt[s[i++]] == 0;
        }
        return j - i;
    }
};
```

## Discuss

https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/discuss/1499839/C%2B%2B-Sliding-Window-(%2B-Cheat-Sheet)