# [316. Remove Duplicate Letters (Medium)](https://leetcode.com/problems/remove-duplicate-letters/)

<p>Given a string <code>s</code>, remove duplicate letters so that every letter appears once and only once. You must make sure your result is <strong>the smallest in lexicographical order</strong> among all possible results.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "bcabc"
<strong>Output:</strong> "abc"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "cbacdcbc"
<strong>Output:</strong> "acdb"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Note:</strong> This question is the same as 1081: <a href="https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/" target="_blank">https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/</a></p>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Apple](https://leetcode.com/company/apple), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/), [Greedy](https://leetcode.com/tag/greedy/), [Monotonic Stack](https://leetcode.com/tag/monotonic-stack/)

**Similar Questions**:
* [Smallest K-Length Subsequence With Occurrences of a Letter (Hard)](https://leetcode.com/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter/)

## Solution 1. Greedy + Recursion

Which character can be placed at the first index?

The characters that have all the unique characters to their right (including themselves). We pick the smallest one from this set.

For example, `s = "cbca"`, both `b` and `c` can have all of `abc` to its right, but `a` can only have `a` to its right. So we must pick the smallest from `bc`, i.e. `b`.

If we scan from left to right, we need to stop the search when the count of the current character drops to `0` because that's when we have one less unique character (the current one) to the right.

We pick the smallest character when we stop the search at put it at the beginning.

Assume the index of this smallest character is `i`, then we should continue our greedy search from `i + 1`.

Consider the following input whose result is `"bcda"`.

```
2 2 1 1 0 0 0 0
c b c b d a b c
  ^ ^   ^ ^        <- selected characters
```

The number above each letter is the count of the same letters to its right.

We traverse from left to right:
1. For `s[0]=c`, it's the smallest so far, so `best = 0`.
1. For `s[1]=b`, it's the smallest so far, so `best = 1`.
1. For `s[2]=c`, it's not the smallest, skip.
1. For `s[3]=b`, it's the same as `s[best]`, skip.
1. For `s[4]=d`, the count of `d` is `0` so we must stop our greedy search here and pick `best = 1, s[best] = b`.
1. Then we continue our greedy search from `best + 1 = 2`.

```cpp
// OJ: https://leetcode.com/problems/remove-duplicate-letters/
// Author: github.com/lzl124631x
// Time: O(NC) where `N` is the length of `s`, and `C` is the range of the letters
// Space: O(NC)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.empty()) return s;
        int cnt[26] = {};
        for (char c : s) cnt[c - 'a']++;
        int best = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] < s[best]) best = i;
            if (--cnt[s[i] - 'a'] == 0) break;
        }
        string t = s.substr(best + 1);
        t.erase(remove(t.begin(), t.end(), s[best]), t.end());
        return s[best] + removeDuplicateLetters(t);
    }
};
```

## Solution 2. Greedy

Same idea as Solution 1, use iterative method instead of recursive.

```cpp
// OJ: https://leetcode.com/problems/remove-duplicate-letters/
// Author: github.com/lzl124631x
// Time: O(NC) where `N` is the length of `s`, and `C` is the range of the letters
// Space: O(N + C)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.empty()) return s;
        int N = s.size(), cnt[26] = {}, added[26] = {}, unique = 0;
        vector<int> rightCnt(N); // `rightCnt[i]` is the count of `s[i]` to the right of `s[i]`
        string ans;
        for (int i = N - 1; i >= 0; --i) {
            unique += cnt[s[i] - 'a'] == 0; // `unique` is the count of unique characters in `s`
            rightCnt[i] = cnt[s[i] - 'a']++;
        }
        for (int i = 0; i < N && ans.size() < unique;) {
            int best = -1;
            for (; i < N; ++i) {
                if (added[s[i] - 'a']) continue;
                if (best == -1 || s[i] < s[best]) best = i;
                if (!rightCnt[i]) break;
            }
            ans += s[best];
            added[s[best] - 'a'] = 1;
            i = best + 1;
        }
        return ans;
    }
};
```

## Solution 3. Monotonic stack + Greedy

We **try** to keep a monotonic inscreasing stack. That is, before we push `s[i]` into the stack, we pop all the elements in the stack that
1. **non-optimal**: `s.top() >= s[i]`
2. **poppable**: `s.top()` has more occurrences later in the string.

To support checking if a letter is poppable, we precompute a `last[26]` array where `last[i]` is the index of the last occurrence of letter `'a' + i`. If `i < last[s.top() - 'a']`, `s.top()` is poppable.

After this above stack popping, we need to push `s[i]` into the stack. Do we always push `s[i]` into the stack? No. Not when `s[i]` is still in the stack.

For example, `s="aba"`, we shouldn't push the 2nd `a` into the stack because the first `a` is already in the stack.

So, to support checking if a letter is already in stack, we use a `used[26]` array where `used[i] = true` if letter `'a' + i` is currently used in the stack.

Now, when we pop an element `x` from the stack, we should reset `used[x - 'a']` to `false`. If `s[i]` is already used in the stack, we directy skip it because if `s[i]` can be selected earlier and now, selecting it now is no better than selecting it earlier. Directly skipping it means that we don't even pop elements from the stack, because we pop element from the stack only because we find `s[i]` is a better option; If `s[i]` is used already and can't be pushed, don't even pop any elements from stack.

Cases to consider:
|s|Expected Result|
|---|---|
|"abacb"|"abc"|
|"bbcaac"|"bac"|

```cpp
// OJ: https://leetcode.com/problems/remove-duplicate-letters/
// Author: github.com/lzl124631x
// Time: O(N) where `N` is the length of `s`, and `C` is the range of the letters
// Space: O(C)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int last[26] = {}, used[26] = {}, N = s.size();
        for (int i = 0; i < N; ++i) last[s[i] - 'a'] = i;
        string ans;
        for (int i = 0; i < N; ++i) {
            if (used[s[i] - 'a']) continue; // once used, don't use it again.
            while (ans.size() && ans.back() > s[i] && i < last[ans.back() - 'a']) { // If the stack top `x` is greater than the current letter, and there are more letters `x` available, we pop `x`
                used[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            used[s[i] - 'a'] = 1;
        }
        return ans;
    }
};
```

Or use `cnt` array to check if an element in array is poppable.

```cpp
// OJ: https://leetcode.com/problems/remove-duplicate-letters/
// Author: github.com/lzl124631x
// Time: O(N) where `N` is the length of `s`, and `C` is the range of the letters
// Space: O(C)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int cnt[26] = {}, used[26] = {}, N = s.size();
        for (char c : s) cnt[c - 'a']++;
        string ans;
        for (char c : s) {
            cnt[c - 'a']--;
            if (used[c - 'a']) continue;
            while (ans.size() && ans.back() > c && cnt[ans.back() - 'a']) {
                used[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            ans.push_back(c);
            used[c - 'a'] = 1;
        }
        return ans;
    }
};
```