# [567. Permutation in String (Medium)](https://leetcode.com/problems/permutation-in-string/)

Given two strings <b>s1</b> and <b>s2</b>, write a function to return true if <b>s2</b> contains the permutation of <b>s1</b>. In other words, one of the first string's permutations is the <b>substring</b> of the second string.

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b>s1 = "ab" s2 = "eidbaooo"
<b>Output:</b>True
<b>Explanation:</b> s2 contains one permutation of s1 ("ba").
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b>s1= "ab" s2 = "eidboaoo"
<b>Output:</b> False
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>The input strings only contain lower case letters.</li>
<li>The length of both given strings is in range [1, 10,000].</li>
</ol>
<p></p>

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [Minimum Window Substring (Hard)](https://leetcode.com/problems/minimum-window-substring/)
* [Find All Anagrams in a String (Easy)](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

## Solution 1. Sliding window

Store the counts of letters of `s1` in `cnts` array.

* When we consume a letter `s2[i]`, we decrement its count.
* When we pop a letter `s2[i - N]`, we increment its count. We start popping when `i - N >= 0` to make sure the sliding window is at most as long as `s1`.

Once all the counts in `cnts` array are zeros, we return `true`. If we reached end of array and still haven't clear out the `cnts`, return `false`.

The time complexity is `O(26 * S2) = O(S2)`.

```cpp
// OJ: https://leetcode.com/problems/permutation-in-string/
// Author: github.com/lzl124631x
// Time: O(S2)
// Space: O(1)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int N = s1.size();
        int cnts[26] = {0};
        for (char c : s1) cnts[c - 'a']++;
        for (int i = 0; i < s2.size(); ++i) {
            cnts[s2[i] - 'a']--;
            if (i - N >= 0) cnts[s2[i - N] - 'a']++;
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

## Solution 2. Sliding Window

Similar to Solution 1, we keep a sliding window of size `s1.size()`. Instead of checking the count for 26 characters, we just use a `count` variable to store the number of matched characters within the sliding window.

```cpp
// OJ: https://leetcode.com/problems/permutation-in-string/
// Author: github.com/lzl124631x
// Time: O(S2)
// Space: O(1)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int cnt[26] = {}, count = s1.size(), N = s1.size();
        for (char c : s1) cnt[c - 'a']++;
        for (int i = 0; i < s2.size(); ++i) {
            if (i >= N) count += cnt[s2[i - N] - 'a']++ >= 0;
            count -= cnt[s2[i] - 'a']-- > 0;
            if (!count) return true;
        }
        return false;
    }
};
```

## Solution 3. Two pointers

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