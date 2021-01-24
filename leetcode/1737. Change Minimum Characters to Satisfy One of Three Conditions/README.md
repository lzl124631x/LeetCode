# [1737. Change Minimum Characters to Satisfy One of Three Conditions (Medium)](https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/)

<p>You are given two strings <code>a</code> and <code>b</code> that consist of lowercase letters. In one operation, you can change any character in <code>a</code> or <code>b</code> to <strong>any lowercase letter</strong>.</p>

<p>Your goal is to satisfy <strong>one</strong> of the following three conditions:</p>

<ul>
	<li><strong>Every</strong> letter in <code>a</code> is <strong>strictly less</strong> than <strong>every</strong> letter in <code>b</code> in the alphabet.</li>
	<li><strong>Every</strong> letter in <code>b</code> is <strong>strictly less</strong> than <strong>every</strong> letter in <code>a</code> in the alphabet.</li>
	<li><strong>Both</strong> <code>a</code> and <code>b</code> consist of <strong>only one</strong> distinct letter.</li>
</ul>

<p>Return <em>the <strong>minimum</strong> number of operations needed to achieve your goal.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> a = "aba", b = "caa"
<strong>Output:</strong> 2
<strong>Explanation:</strong> Consider the best way to make each condition true:
1) Change b to "ccc" in 2 operations, then every letter in a is less than every letter in b.
2) Change a to "bbb" and b to "aaa" in 3 operations, then every letter in b is less than every letter in a.
3) Change a to "aaa" and b to "aaa" in 2 operations, then a and b consist of one distinct letter.
The best way was done in 2 operations (either condition 1 or condition 3).
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> a = "dabadd", b = "cda"
<strong>Output:</strong> 3
<strong>Explanation:</strong> The best way is to make condition 1 true by changing b to "eee".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= a.length, b.length &lt;= 10<sup>5</sup></code></li>
	<li><code>a</code> and <code>b</code> consist only of lowercase letters.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/
// Author: github.com/lzl124631x
// Time: O(A + B)
// Space: O(1)
class Solution {
    int count(string &a, string &b) { // make all chars in `b` strictly greater than `a`.
        int ans = INT_MAX; 
        for (char c = 'a'; c < 'z'; ++c) { // assume `c` is the breakpoint -- make all chars in `a` <= `c` and all chars in `b` > `c`
            int cnt = 0;
            for (char x : a) cnt += x > c; // all the chars in `a` that `> c` should be changed.
            for (char x : b) cnt += x <= c; // all the chars in `b` that `<= c` should be changed.
            ans = min(ans, cnt);
        }
        return ans;
    }
public:
    int minCharacters(string a, string b) {
        int x = count(a, b), y = count(b, a); // try operation 1 and 2.
        int ans = INT_MAX;
        for (char c = 'a'; c <= 'z'; ++c) { // try operation 3. Assume we change all chars to `c`
            int cnt = 0;
            for (char x : a) cnt += x != c;
            for (char x : b) cnt += x != c;
            ans = min(ans, cnt);
        }
        return min({ x, y, ans });
    }
};
```

## Solution 2.

Use `ca` and `cb` to store the frequence of characters in `a` and `b` respectively.

We can try each character in `[a, z]` and use it as a break point.

Take operation 1 for example, if we use `'a' + 2 = 'c'` as a break point, that is, changing all `a[i] > 'c'` to `'c'` and changing all `b[i] <= 'c'` to `'d'`.

The count of required operations is `op1[2] = SUM(ca, 3, 25) + SUM(cb, 0, 2)` where `SUM(arr, i, j) = arr[i] + arr[i + 1] + ... + arr[j]`.

So `op1[i] = SUM(ca, i + 1, 25) + SUM(cb, 0, i)` where `0 <= i < 25`.

`op1[i] - op1[i - 1] = cb[i] - ca[i]`

Similarly `op2[i] = SUM(cb, i + 1, 25) + SUM(ca, 0, i)` where `0 <= i < 25`.

`op2[i] - op2[i - 1] = ca[i] - cb[i]`

For operation 3, if we pick `'a' + i` as the breakpoint, we need to sum all `ca[j]` and `cb[j]` where `j != i`.

So `op3[i] = SUM(ca) + SUM(cb) - ca[i] - cb[i]`

```cpp
// OJ: https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/
// Author: github.com/lzl124631x
// Time: O(A + B)
// Space: O(1)
class Solution {
public:
    int minCharacters(string a, string b) {
        array<int, 26> ca = {}, cb = {};
        for (char c : a) ca[c - 'a']++;
        for (char c : b) cb[c - 'a']++;
        int M = a.size(), N = b.size(), op1 = M, op2 = N, ans = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            op1 += cb[i] - ca[i];
            op2 += ca[i] - cb[i];
            if (i < 25) ans = min({ ans, op1, op2 });
            ans = min(ans, M + N - ca[i] - cb[i]);
        }
        return ans;
    }
};
```