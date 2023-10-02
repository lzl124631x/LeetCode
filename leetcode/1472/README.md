# [1472. Design Browser History (Medium)](https://leetcode.com/problems/design-browser-history/)

<p>You have a <strong>browser</strong> of one tab where you start on the <code>homepage</code> and you can visit another <code>url</code>, get back in the history number of <code>steps</code> or move forward in the history number of <code>steps</code>.</p>

<p>Implement the <code>BrowserHistory</code> class:</p>

<ul>
	<li><code>BrowserHistory(string homepage)</code> Initializes the object with the <code>homepage</code>&nbsp;of the browser.</li>
	<li><code>void visit(string url)</code>&nbsp;visits <code>url</code> from the current page. It clears up all the forward history.</li>
	<li><code>string back(int steps)</code>&nbsp;Move <code>steps</code> back in history. If you can only return <code>x</code> steps in the history and <code>steps &gt; x</code>, you will&nbsp;return only <code>x</code> steps. Return the current <code>url</code>&nbsp;after moving back in history <strong>at most</strong> <code>steps</code>.</li>
	<li><code>string forward(int steps)</code>&nbsp;Move <code>steps</code> forward in history. If you can only forward <code>x</code> steps in the history and <code>steps &gt; x</code>, you will&nbsp;forward only&nbsp;<code>x</code> steps. Return the current <code>url</code>&nbsp;after forwarding in history <strong>at most</strong> <code>steps</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example:</strong></p>

<pre><b>Input:</b>
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
<b>Output:</b>
[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]

<b>Explanation:</b>
BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
browserHistory.back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
browserHistory.back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
browserHistory.forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
browserHistory.back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
browserHistory.back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= homepage.length &lt;= 20</code></li>
	<li><code>1 &lt;= url.length &lt;= 20</code></li>
	<li><code>1 &lt;= steps &lt;= 100</code></li>
	<li><code>homepage</code> and <code>url</code> consist of&nbsp; '.' or lower case English letters.</li>
	<li>At most <code>5000</code>&nbsp;calls will be made to <code>visit</code>, <code>back</code>, and <code>forward</code>.</li>
</ul>

**Related Topics**:  
[Design](https://leetcode.com/tag/design/)

## Solution 1. Simulation

Keep a `vector<string> A` as the history and `i` as the current position which is initialized as `0`.

For `back` and `forward`, we just need to clamp the `i` to stay within `[0, A.size() - 1]`.

For `visit`, we need to `resize` the `A` to size `i + 1` before pushing the `url` into history.

```cpp
// OJ: https://leetcode.com/problems/design-browser-history/
// Author: github.com/lzl124631x
// Time:
//      BrowserHistory, back, forward: O(1)
//      visit: O(N)
// Space: O(N)
class BrowserHistory {
    vector<string> A;
    int i = 0;
public:
    BrowserHistory(string homepage) {
        A.push_back(homepage);
    }
    void visit(string url) {
        A.resize(i + 1);
        A.push_back(url);
        ++i;
    }
    string back(int steps) {
        return A[i = max(i - steps, 0)];
    }
    string forward(int steps) {
        return A[i = min(i + steps, (int)A.size() - 1)];
    }
};
```

## Solution 2.

Since it was `resize` that was taking `O(N)` time, we can avoid using `resize` by keeping track of the size of the history.

```cpp
// OJ: https://leetcode.com/problems/design-browser-history/
// Author: github.com/lzl124631x
// Time: O(1) for all
// Space: O(N)
class BrowserHistory {
    vector<string> A;
    int i = 0, sz = 1;
public:
    BrowserHistory(string homepage) {
        A.push_back(homepage);
    }
    void visit(string url) {
        sz = i + 2;
        if (A.size() < sz) A.push_back("");
        A[++i] = url;
    }
    string back(int steps) {
        return A[i = max(i - steps, 0)];
    }
    string forward(int steps) {
        return A[i = min(i + steps, sz - 1)];
    }
};
```