# [843. Guess the Word (Hard)](https://leetcode.com/problems/guess-the-word/)

<p>This problem is an&nbsp;<strong><em>interactive problem</em></strong>&nbsp;new to the LeetCode platform.</p>

<p>We are given a word list of unique words, each word is 6 letters long, and one word in this list is chosen as <strong>secret</strong>.</p>

<p>You may call <code>master.guess(word)</code>&nbsp;to guess a word.&nbsp; The guessed word should have&nbsp;type <code>string</code>&nbsp;and must be from the original list&nbsp;with 6 lowercase letters.</p>

<p>This function returns an&nbsp;<code>integer</code>&nbsp;type, representing&nbsp;the number of exact matches (value and position) of your guess to the <strong>secret word</strong>.&nbsp; Also, if your guess is not in the given wordlist, it will return <code>-1</code> instead.</p>

<p>For each test case, you have 10 guesses to guess the word. At the end of any number of calls, if you have made 10 or less calls to <code>master.guess</code>&nbsp;and at least one of these guesses was the <strong>secret</strong>, you pass the testcase.</p>

<p>Besides the example test case below, there will be 5&nbsp;additional test cases, each with 100 words in the word list.&nbsp; The letters of each word in those testcases were chosen&nbsp;independently at random from <code>'a'</code> to <code>'z'</code>, such that every word in the given word lists is unique.</p>

<pre><strong>Example 1:</strong>
<strong>Input:</strong>&nbsp;secret = "acckzz", wordlist = ["acckzz","ccbazz","eiowzz","abcczz"]

<strong>Explanation:</strong>

<code>master.guess("aaaaaa")</code> returns -1, because&nbsp;<code>"aaaaaa"</code>&nbsp;is not in wordlist.
<code>master.guess("acckzz") </code>returns 6, because&nbsp;<code>"acckzz"</code> is secret and has all 6&nbsp;matches.
<code>master.guess("ccbazz")</code> returns 3, because<code>&nbsp;"ccbazz"</code>&nbsp;has 3 matches.
<code>master.guess("eiowzz")</code> returns 2, because&nbsp;<code>"eiowzz"</code>&nbsp;has 2&nbsp;matches.
<code>master.guess("abcczz")</code> returns 4, because&nbsp;<code>"abcczz"</code> has 4 matches.

We made 5 calls to&nbsp;master.guess and one of them was the secret, so we pass the test case.
</pre>

<p><strong>Note:</strong>&nbsp; Any solutions that attempt to circumvent the judge&nbsp;will result in disqualification.</p>


**Related Topics**:  
[Minimax](https://leetcode.com/tag/minimax/)

## Solution 1.

Make a random guess `w`. Assume the result is `cnt`.

The secret must be among those which have `cnt` matches with `w`. So filter the `wordList` to these words.

Keep redoing these, you'll find the secret.

```cpp
// OJ: https://leetcode.com/problems/guess-the-word/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    int countSame(string &a, string &b) {
        int cnt = 0;
        for (int i = 0; i < 6; ++i) cnt += a[i] == b[i];
        return cnt;
    }
public:
    void findSecretWord(vector<string>& A, Master& master) {
        int N = A.size();
        while (true) {
            string w = A[rand() % N];
            int cnt = master.guess(w), len = 0;
            if (cnt == 6) break;
            for (int i = 0; i < N; ++i) {
                if (countSame(A[i], w) == cnt) swap(A[i], A[len++]);
            }
            N = len;
        }
    }
};
```