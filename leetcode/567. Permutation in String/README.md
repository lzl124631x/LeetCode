# [567. Permutation in String (Medium)](https://leetcode.com/problems/permutation-in-string/)

<p>Given two strings <code>s1</code> and <code>s2</code>, return <code>true</code><em> if </em><code>s2</code><em> contains a permutation of </em><code>s1</code><em>, or </em><code>false</code><em> otherwise</em>.</p>

<p>In other words, return <code>true</code> if one of <code>s1</code>'s permutations is the substring of <code>s2</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s1 = "ab", s2 = "eidbaooo"
<strong>Output:</strong> true
<strong>Explanation:</strong> s2 contains one permutation of s1 ("ba").
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s1 = "ab", s2 = "eidboaoo"
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s1.length, s2.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s1</code> and <code>s2</code> consist of lowercase English letters.</li>
</ul>


**Companies**:  
[Yandex](https://leetcode.com/company/yandex), [Amazon](https://leetcode.com/company/amazon), [Oracle](https://leetcode.com/company/oracle), [Facebook](https://leetcode.com/company/facebook), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Minimum Window Substring (Hard)](https://leetcode.com/problems/minimum-window-substring/)
* [Find All Anagrams in a String (Medium)](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

## Solution 1. Fixed-length Sliding Window

Store the counts of letters of `a` in `cnts` array.

* When we consume a letter `b[i]`, we decrement its count.
* When we pop a letter `b[i - N]`, we increment its count. We start popping when `i - N >= 0` to make sure the sliding window is at most as long as `a`.

Once all the counts in `cnts` array are zeros, we return `true`. If we reached end of array and still haven't clear out the `cnts`, return `false`.

The time complexity is `O(26 * S2) = O(S2)`.

```cpp
// OJ: https://leetcode.com/problems/permutation-in-string/
// Author: github.com/lzl124631x
// Time: O(B)
// Space: O(1)
class Solution {
public:
    bool checkInclusion(string a, string b) {
        if (a.size() > b.size()) return false;
        int N = a.size(), cnts[26] = {};
        for (char c : a) cnts[c - 'a']++;
        for (int i = 0; i < b.size(); ++i) {
            cnts[b[i] - 'a']--;
            if (i - N >= 0) cnts[b[i - N] - 'a']++;
            bool match = true;
            for (int j = 0; j < 26 && match; ++j) {
                if (cnts[j]) match = false;
            }
            if (match) return true;
        }
        return false;
    }
};
```

## Solution 2. Fixed-length Sliding Window

Similar to Solution 1, we keep a sliding window of size `a.size()`. Instead of checking the count for 26 characters, we just use a `matched` variable to store the number of matched characters within the sliding window.

```cpp
// OJ: https://leetcode.com/problems/permutation-in-string/
// Author: github.com/lzl124631x
// Time: O(B)
// Space: O(1)
class Solution {
public:
    bool checkInclusion(string a, string b) {
        if (a.size() > b.size()) return false;
        int cnt[26] = {}, matched = a.size(), N = a.size();
        for (char c : a) cnt[c - 'a']++;
        for (int i = 0; i < b.size(); ++i) {
            if (i >= N) matched += cnt[b[i - N] - 'a']++ >= 0;
            matched -= cnt[b[i] - 'a']-- > 0;
            if (!matched) return true;
        }
        return false;
    }
};
```

## Solution 3. Variable-length Sliding Window

We keep the counts of letters of `s1` in `goal` array. And we use two pointers `i` and `j` to consume `s2`, and store the counts of letters within range `[i, j)` in `cnt` array.

1. We keep incrementing `j` and the corresponding count `cnt[s2[j]]` until it reaches the end or `cnt[s2[j]] + 1 <= goal[s2[j]]`. Let `X` be `s2[j]` then `X` is the letter we don't want to consume.
2. If the gap between `i` and `j` is the length of `s1`, then we've found match and just return `true`.
4. Since `s2[j]` is unwanted, we keep popping `s2[i]` by incrementing `i` until `s2[i] == s2[j]`, meanwhile, we decrement `cnt[s2[i]]`.
5. Now `s[i]` and `s[j]` are all pointing to the unwanted letter `X`, increment `i` and `j` both so that the `cnt[X]` will be unchanged. Go to Step 1 until `j` reaches end.

```cpp
// OJ: https://leetcode.com/problems/permutation-in-string/
// Author: github.com/lzl124631x
// Time: O(S2)
// Space: O(1)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int M = s1.size(), N = s2.size(), i = 0, j = 0, goal[26] = {0}, cnt[26] = {0};
        for (char c : s1) goal[c - 'a']++;
        for (; j < N; ++i, ++j) {
            while (j < N && cnt[s2[j] - 'a'] + 1 <= goal[s2[j] - 'a']) cnt[s2[j++] - 'a']++;
            if (j - i == M) return true;
            while (j < N && i < j && s2[i] != s2[j]) cnt[s2[i++] - 'a']--;
        }
        return false;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/permutation-in-string/
// Author: github.com/lzl124631x
// Time: O(B)
// Space: O(1)
class Solution {
public:
    bool checkInclusion(string a, string b) {
        if (a.size() > b.size()) return false;
        int cnt[26] = {};
        for (char c : a) cnt[c - 'a']++;
        for (int i = 0, j = 0; j < b.size(); ++j) {
            if (--cnt[b[j] - 'a'] < 0) { // We can't have this `b[j]` in the window
                while (b[i] != b[j]) cnt[b[i++] - 'a']++; // keep skipping until `b[i] == b[j]`
                cnt[b[i++] - 'a']++; // remove `b[i]` from the window
            }
            if (j - i + 1 == a.size()) return true; // If the window has the same length as `a`, return true
        }
        return false;
    }
};
```