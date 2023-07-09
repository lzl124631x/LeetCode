# [340. Longest Substring with At Most K Distinct Characters (Medium)](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters)

<p>Given a string <code>s</code> and an integer <code>k</code>, return <em>the length of the longest </em><span data-keyword="substring-nonempty" class=" cursor-pointer relative text-dark-blue-s text-sm"><div class="popover-wrapper inline-block" data-headlessui-state=""><div><div id="headlessui-popover-button-:r52:" aria-expanded="false" data-headlessui-state=""><em>substring</em></div></div></div></span><em> of</em> <code>s</code> <em>that contains at most</em> <code>k</code> <em><strong>distinct</strong> characters</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "eceba", k = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong> The substring is "ece" with length 3.</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "aa", k = 1
<strong>Output:</strong> 2
<strong>Explanation:</strong> The substring is "aa" with length 2.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= k &lt;= 50</code></li>
</ul>

**Companies**:
[Yandex](https://leetcode.com/company/yandex), [Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Longest Substring Without Repeating Characters (Medium)](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
* [Longest Substring with At Most Two Distinct Characters (Medium)](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/)
* [Longest Repeating Character Replacement (Medium)](https://leetcode.com/problems/longest-repeating-character-replacement/)
* [Subarrays with K Different Integers (Hard)](https://leetcode.com/problems/subarrays-with-k-different-integers/)
* [Max Consecutive Ones III (Medium)](https://leetcode.com/problems/max-consecutive-ones-iii/)
* [Maximize the Confusion of an Exam (Medium)](https://leetcode.com/problems/maximize-the-confusion-of-an-exam/)

## Solution 1. Sliding Window

Check out "[C++ Maximum Sliding Window Cheatsheet Template!](https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175088/C%2B%2B-Maximum-Sliding-Window-Cheatsheet-Template!)".

Shrinkable Sliding Window:

```cpp
// OJ: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int cnt[128] = {}, distinct = 0, i = 0, j = 0, ans = 0, N = s.size();
        while (j < N) {
            distinct += cnt[s[j++]]++ == 0;
            while (distinct > k) distinct -= --cnt[s[i++]] == 0;
            ans = max(ans, j - i);
        }
        return ans;
    }
};
```

Non-shrinkable Sliding Window:

```cpp
// OJ: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int cnt[128] = {}, distinct = 0, i = 0, j = 0, N = s.size();
        while (j < N) {
            distinct += cnt[s[j++]]++ == 0;
            if (distinct > k) distinct -= --cnt[s[i++]] == 0;
        }
        return j - i;
    }
};
```

## Discuss

https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/discuss/1499842/C%2B%2B-Sliding-Window-(%2B-Cheat-Sheet)