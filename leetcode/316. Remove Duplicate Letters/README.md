# [316. Remove Duplicate Letters (Hard)](https://leetcode.com/problems/remove-duplicate-letters/)

<p>Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> <code>"bcabc"</code>
<b>Output:</b> <code>"abc"</code>
</pre>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> <code>"cbacdcbc"</code>
<b>Output:</b> <code>"acdb"</code>
</pre>

**Companies**:  
[Google](https://leetcode.com/company/google), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. Greedy

The first idea shall be greedy, namely picking the smallest letter whenever possible.

However we can easily give some counter example, e.g. `za`. We can't pick `a` since if we pick it, we don't have any `z` left to pick.

So if the count of a letter drop to `0`, we have to pick the current smallest letter we've seen.

Assume the index of it is `i`, then we should continue our greedy search from `i + 1`. (consider `abcab`)

Consider the following input whose result is `"bcda"`.

```
2 2 1 1 0 0 0 0
c b c b d a b c
  ^ ^   ^ ^
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
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.empty()) return s;
        unordered_map<char, int> cnt;
        for (char c : s) cnt[c]++;
        int best = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] < s[best]) best = i;
            if (--cnt[s[i]] == 0) break;
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
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.empty()) return s;
        vector<int> rightCnt(s.size(), 0);
        unordered_map<char, int> cnt;
        unordered_set<char> added;
        string ans;
        int N = s.size(), i = 0;
        for (int j = N - 1; j >= 0; --j) rightCnt[j] = cnt[s[j]]++;
        while (i < N) {
            int best = -1;
            for (; i < N; ++i) {
                if (added.find(s[i]) != added.end()) continue;
                if (best == -1 || s[i] < s[best]) best = i;
                if (!rightCnt[i]) break;
            }
            if (best == -1) best = i;
            if (best >= N) break;
            ans += s[best];
            added.insert(s[best]);
            i = best + 1;
        }
        return ans;
    }
};
```

## Solution 3. Stack + Greedy

See comments.

```cpp
// OJ: https://leetcode.com/problems/remove-duplicate-letters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/remove-duplicate-letters/discuss/76769/Java-solution-using-Stack-with-comments
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.empty()) return s;
        unordered_map<char, int> cnt;
        unordered_set<char> added;
        stack<char> st;
        for (char c : s) cnt[c]++;
        for (char c : s) {
            cnt[c]--;
            if (added.find(c) != added.end()) continue; // if the letter is added into stack, skip
            // If the stack top is poppable and the current letter is smaller than the stack top, pop the stack top.
            while (st.size() && c < st.top() && cnt[st.top()]) {
                added.erase(st.top());
                st.pop();
            }
            st.push(c); // push the current letter into stack
            added.insert(c);
        }
        string ans;
        while (st.size()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```