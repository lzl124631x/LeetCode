# [3. Longest Substring Without Repeating Characters (Medium)](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

<p>Given a string, find the length of the <b>longest substring</b> without repeating characters.</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">"abcabcbb"</span>
<strong>Output: </strong><span id="example-output-1">3 
<strong>Explanation:</strong></span> The answer is <code>"abc"</code>, with the length of 3. 
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">"bbbbb"</span>
<strong>Output: </strong><span id="example-output-2">1
</span><span id="example-output-1"><strong>Explanation: </strong>T</span>he answer is <code>"b"</code>, with the length of 1.
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">"pwwkew"</span>
<strong>Output: </strong><span id="example-output-3">3
</span><span id="example-output-1"><strong>Explanation: </strong></span>The answer is <code>"wke"</code>, with the length of 3. 
             Note that the answer must be a <b>substring</b>, <code>"pwke"</code> is a <i>subsequence</i> and not a substring.
</pre>
</div>
</div>
</div>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Bloomberg](https://leetcode.com/company/bloomberg), [Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft), [Adobe](https://leetcode.com/company/adobe), [Apple](https://leetcode.com/company/apple), [Alibaba](https://leetcode.com/company/alibaba), [Uber](https://leetcode.com/company/uber), [ByteDance](https://leetcode.com/company/bytedance), [Cisco](https://leetcode.com/company/cisco), [Huawei](https://leetcode.com/company/huawei), [Zillow](https://leetcode.com/company/zillow), [Yahoo](https://leetcode.com/company/yahoo), [Grab](https://leetcode.com/company/grab), [eBay](https://leetcode.com/company/ebay), [Twitch](https://leetcode.com/company/twitch), [Atlassian](https://leetcode.com/company/atlassian)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Longest Substring with At Most Two Distinct Characters (Hard)](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/)
* [Longest Substring with At Most K Distinct Characters (Hard)](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/)
* [Subarrays with K Different Integers (Hard)](https://leetcode.com/problems/subarrays-with-k-different-integers/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, i = 0, j = 0;
        unordered_set<char> st;
        while (j < s.size()) {
            while (j < s.size() && !st.count(s[j])) st.insert(s[j++]);
            ans = max(ans, j - i);
            while (i < j && s[i] != s[j]) st.erase(s[i++]);
            ++i;
            ++j;
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/24739/c-code-in-9-lines
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, start = -1;
        vector<int> m(256, -1);
        for (int i = 0; i < s.size(); ++i) {
            if (m[s[i]] > start) start = m[s[i]];
            m[s[i]] = i;
            ans = max(ans, i - start);
        }
        return ans;
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128, 0);
        int i = 0, j = 0, cnt = 0, ans = 0;
        while (j < s.size()) {
            if (m[s[j++]]++ == 1) cnt++;
            while (cnt) {
                if (m[s[i++]]-- == 2) cnt--;
            }
            ans = max(ans, j - i);
        }
        return ans;
    }
};
```