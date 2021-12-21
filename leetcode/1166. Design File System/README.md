# [1166. Design File System (Medium)](https://leetcode.com/problems/design-file-system/)

<p>You are asked to design a file system&nbsp;that allows you to create new paths and associate them with different values.</p>

<p>The format of a path is&nbsp;one or more concatenated strings of the form:&nbsp;<code>/</code> followed by one or more lowercase English letters. For example, "<code>/leetcode"</code>&nbsp;and "<code>/leetcode/problems"</code>&nbsp;are valid paths while an empty&nbsp;string <code>""</code> and <code>"/"</code>&nbsp;are not.</p>

<p>Implement the&nbsp;<code>FileSystem</code> class:</p>

<ul>
	<li><code>bool createPath(string path, int value)</code>&nbsp;Creates a new <code>path</code> and associates a <code>value</code> to it if possible and returns <code>true</code>.&nbsp;Returns <code>false</code>&nbsp;if the path <strong>already exists</strong> or its parent path <strong>doesn't exist</strong>.</li>
	<li><code>int get(string path)</code>&nbsp;Returns the value associated with <code>path</code> or returns&nbsp;<code>-1</code>&nbsp;if the path doesn't exist.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> 
["FileSystem","createPath","get"]
[[],["/a",1],["/a"]]
<strong>Output:</strong> 
[null,true,1]
<strong>Explanation:</strong> 
FileSystem fileSystem = new FileSystem();

fileSystem.createPath("/a", 1); // return true
fileSystem.get("/a"); // return 1
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 
["FileSystem","createPath","createPath","get","createPath","get"]
[[],["/leet",1],["/leet/code",2],["/leet/code"],["/c/d",1],["/c"]]
<strong>Output:</strong> 
[null,true,true,2,false,-1]
<strong>Explanation:</strong> 
FileSystem fileSystem = new FileSystem();

fileSystem.createPath("/leet", 1); // return true
fileSystem.createPath("/leet/code", 2); // return true
fileSystem.get("/leet/code"); // return 2
fileSystem.createPath("/c/d", 1); // return false because the parent path "/c" doesn't exist.
fileSystem.get("/c"); // return -1 because this path doesn't exist.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of&nbsp;calls to the two functions&nbsp;is less than or equal to <code>10<sup>4</sup></code> in total.</li>
	<li><code>2 &lt;= path.length &lt;= 100</code></li>
	<li><code>1 &lt;= value &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Airbnb](https://leetcode.com/company/airbnb), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Design](https://leetcode.com/tag/design/), [Trie](https://leetcode.com/tag/trie/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/design-file-system/
// Author: github.com/lzl124631x
// Time:
//      FileSystem: O(1)
//      createPath, get: O(P)
// Space: O(N)
class FileSystem {
    unordered_map<string, int> m;
public:
    FileSystem() {}
    bool createPath(string path, int value) {
        if (m.count(path)) return false;
        auto i = path.find_last_of("/");
        auto parent = path.substr(0, i);
        if (parent.size() && m.count(parent) == 0) return false;
        m[path] = value;
        return true;
    }
    int get(string path) {
        return m.count(path) ? m[path] : -1;
    }
};
```