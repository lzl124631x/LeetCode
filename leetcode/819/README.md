# [819. Most Common Word (Easy)](https://leetcode.com/problems/most-common-word/)

Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.

**Example:**

**Input:**   
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = \["hit"\]
**Output:** "ball"  
**Explanation:**   
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph.   
Note that words in the paragraph are not case sensitive, 
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.

**Note:**

*   `1 <= paragraph.length <= 1000`.
*   `1 <= banned.length <= 100`.
*   `1 <= banned[i].length <= 10`.
*   The answer is unique, and written in lowercase (even if its occurrences in `paragraph` may have uppercase symbols, and even if it is a proper noun.)
*   `paragraph` only consists of letters, spaces, or the punctuation symbols `!?',;.`
*   There are no hyphens or hyphenated words.
*   Words only consist of letters, never apostrophes or other punctuation symbols.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/most-common-word/
// Author: github.com/lzl124631x
// Time: O(N) where N is character count in paragraph
// Space: O((B + P)W)
//     where B is the size of ban list,
//     P is unique count of words in paragraph that are not banned,
//     and W is average word length
class Solution {
private:
    string getWord(string::iterator& it, string::iterator end) {
        while (it != end && !isalpha(*it)) ++it;
        string res;
        for (; it != end && isalpha(*it); ++it) {
            res += tolower(*it);
        }
        return res;
    }
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> m;
        unordered_set<string> ban(banned.begin(), banned.end());
        string word;
        string res;
        int maxCnt = 0;
        auto it = paragraph.begin();
        while ((word = getWord(it, paragraph.end())) != "") {
            if (ban.find(word) != ban.end()) continue;
            m[word]++;
            if (m[word] > maxCnt) {
                maxCnt = m[word];
                res = word;
            }
        }
        return res;
    }
};
```

## Solution 2.
```cpp
// OJ: https://leetcode.com/problems/most-common-word/
// Author: github.com/lzl124631x
// Time: O(N) where N is character count in paragraph
// Space: O(N)
// Ref: https://leetcode.com/problems/most-common-word/discuss/184971/C%2B%2B-4ms-straightforward-solution
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for (auto &c : paragraph) {
            c = isalpha(c) ? tolower(c) : ' ';
        }
        
        istringstream iss(paragraph);
        string word;
        unordered_map<string, int> cnt;
        while (iss >> word) ++cnt[word];
        
        for (auto b : banned) cnt[b] = 0;
        
        int maxCnt = 0;
        for (auto p : cnt) {
            if (p.second > maxCnt) {
                maxCnt = p.second;
                word = p.first;
            }
        }
        return word;
    }
};
```