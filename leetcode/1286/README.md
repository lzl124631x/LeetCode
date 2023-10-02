# [1286. Iterator for Combination (Medium)](https://leetcode.com/problems/iterator-for-combination/)

<p>Design the <code>CombinationIterator</code> class:</p>

<ul>
	<li><code>CombinationIterator(string characters, int combinationLength)</code>&nbsp;Initializes the object with&nbsp;a string&nbsp;<code>characters</code>&nbsp;of <strong>sorted distinct</strong> lowercase English letters and a number&nbsp;<code>combinationLength</code> as arguments.</li>
	<li><code>next()</code>&nbsp;Returns the next combination of length <code>combinationLength</code>&nbsp;in <strong>lexicographical order</strong>.</li>
	<li><code>hasNext()</code>&nbsp;Returns <code>true</code>&nbsp;if and only if&nbsp;there exists a next combination.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["CombinationIterator", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[["abc", 2], [], [], [], [], [], []]
<strong>Output</strong>
[null, "ab", true, "ac", true, "bc", false]

<strong>Explanation</strong>
CombinationIterator itr = new CombinationIterator("abc", 2);
itr.next();    // return "ab"
itr.hasNext(); // return True
itr.next();    // return "ac"
itr.hasNext(); // return True
itr.next();    // return "bc"
itr.hasNext(); // return False
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= combinationLength &lt;=&nbsp;characters.length &lt;= 15</code></li>
	<li>All the characters of <code>characters</code> are <strong>unique</strong>.</li>
	<li>At most <code>10<sup>4</sup></code>&nbsp;calls will be made to <code>next</code> and <code>hasNext</code>.</li>
	<li>It's guaranteed that all&nbsp;calls&nbsp;of the function <code>next</code>&nbsp;are valid.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Backtracking](https://leetcode.com/tag/backtracking/), [Design](https://leetcode.com/tag/design/), [Iterator](https://leetcode.com/tag/iterator/)

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
    string s;
    vector<int> index;
public:
    CombinationIterator(string s, int len) : s(s), index(len) {
        iota(begin(index), end(index), 0);
    }
    string next() {
        string ans;
        for (int n : index) ans += s[n];
        int i = index.size() - 1; // find the first from right index that should be incremented.
        while (i > 0 && index[i] == s.size() - index.size() + i) --i;
        ++index[i++];
        for (; i < index.size(); ++i) index[i] = index[i - 1] + 1;
        return ans;
    }
    bool hasNext() {
        return index[0] <= s.size() - index.size();
    }
};
```