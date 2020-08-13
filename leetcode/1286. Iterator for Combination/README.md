# [1286. Iterator for Combination (Medium)](https://leetcode.com/problems/iterator-for-combination/)

<p>Design an Iterator class, which has:</p>

<ul>
	<li>A constructor that takes a string&nbsp;<code>characters</code>&nbsp;of <strong>sorted distinct</strong> lowercase English letters and a number&nbsp;<code>combinationLength</code> as arguments.</li>
	<li>A function <em>next()</em>&nbsp;that returns the next combination of length <code>combinationLength</code>&nbsp;in <strong>lexicographical order</strong>.</li>
	<li>A function <em>hasNext()</em> that returns <code>True</code>&nbsp;if and only if&nbsp;there exists a next combination.</li>
</ul>

<p>&nbsp;</p>

<p><b>Example:</b></p>

<pre>CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= combinationLength &lt;=&nbsp;characters.length &lt;= 15</code></li>
	<li>There will be at most <code>10^4</code> function calls per test.</li>
	<li>It's guaranteed that all&nbsp;calls&nbsp;of the function <code>next</code>&nbsp;are valid.</li>
</ul>


**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking/), [Design](https://leetcode.com/tag/design/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/iterator-for-combination/
// Author: github.com/lzl124631x
// Time:
//      CombinationIterator: O(S)
//      next: O(L)
//      hasNext: O(1)
// Space: O(S)
class CombinationIterator {
    vector<int> index;
    string s;
public:
    CombinationIterator(string s, int len) : s(s), index(len) {
        iota(begin(index), end(index), 0);
    }
    string next() {
        string ans; 
        for (int n : index) ans += s[n];
        for (int i = index.size() - 1; i >= 0; --i) {
            if (i > 0 && index[i] == s.size() - index.size() + i) continue;
            ++index[i++];
            for (; i < index.size(); ++i) index[i] = index[i - 1] + 1;
            break;
        }
        return ans;
    }
    bool hasNext() {
        return index[0] <= s.size() - index.size();
    }
};
```