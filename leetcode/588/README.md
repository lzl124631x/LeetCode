# [588. Design In-Memory File System (Hard)](https://leetcode.com/problems/design-in-memory-file-system/)

<p>Design a data structure that simulates an in-memory file system.</p>

<p>Implement the FileSystem class:</p>

<ul>
	<li><code>FileSystem()</code> Initializes the object of the system.</li>
	<li><code>List&lt;String&gt; ls(String path)</code>
	<ul>
		<li>If <code>path</code> is a file path, returns a list that only contains this file's name.</li>
		<li>If <code>path</code> is a directory path, returns the list of file and directory names <strong>in this directory</strong>.</li>
	</ul>
	The answer should in <strong>lexicographic order</strong>.</li>
	<li><code>void mkdir(String path)</code> Makes a new directory according to the given <code>path</code>. The given directory path does not exist. If the middle directories in the path do not exist, you should create them as well.</li>
	<li><code>void addContentToFile(String filePath, String content)</code>
	<ul>
		<li>If <code>filePath</code> does not exist, creates that file containing given <code>content</code>.</li>
		<li>If <code>filePath</code> already exists, appends the given <code>content</code> to original content.</li>
	</ul>
	</li>
	<li><code>String readContentFromFile(String filePath)</code> Returns the content in the file at <code>filePath</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/28/filesystem.png" style="width: 650px; height: 315px;">
<pre><strong>Input</strong>
["FileSystem", "ls", "mkdir", "addContentToFile", "ls", "readContentFromFile"]
[[], ["/"], ["/a/b/c"], ["/a/b/c/d", "hello"], ["/"], ["/a/b/c/d"]]
<strong>Output</strong>
[null, [], null, null, ["a"], "hello"]

<strong>Explanation</strong>
FileSystem fileSystem = new FileSystem();
fileSystem.ls("/");                         // return []
fileSystem.mkdir("/a/b/c");
fileSystem.addContentToFile("/a/b/c/d", "hello");
fileSystem.ls("/");                         // return ["a"]
fileSystem.readContentFromFile("/a/b/c/d"); // return "hello"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= path.length,&nbsp;filePath.length &lt;= 100</code></li>
	<li><code>path</code> and <code>filePath</code>&nbsp;are absolute paths which begin with <code>'/'</code>&nbsp;and do not end with <code>'/'</code>&nbsp;except that the path is just&nbsp;<code>"/"</code>.</li>
	<li>You can assume that all directory names and file names only contain lowercase letters, and the same names will not exist in the same directory.</li>
	<li>You can assume that all operations will be passed valid parameters, and users will not attempt to retrieve file content or list a directory or file that does not exist.</li>
	<li><code>1 &lt;= content.length &lt;= 50</code></li>
	<li>At most <code>300</code> calls will be made to <code>ls</code>, <code>mkdir</code>,&nbsp;<code>addContentToFile</code>, and&nbsp;<code>readContentFromFile</code>.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google), [Airbnb](https://leetcode.com/company/airbnb), [Salesforce](https://leetcode.com/company/salesforce), [Tesla](https://leetcode.com/company/tesla)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Design](https://leetcode.com/tag/design/), [Trie](https://leetcode.com/tag/trie/)

**Similar Questions**:
* [LRU Cache (Medium)](https://leetcode.com/problems/lru-cache/)
* [LFU Cache (Hard)](https://leetcode.com/problems/lfu-cache/)
* [Design Log Storage System (Medium)](https://leetcode.com/problems/design-log-storage-system/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/design-in-memory-file-system/
// Author: github.com/lzl124631x
struct File {
    bool isDirectory = true;
    map<string, File*> contents;
    string name, content;
    File(string name) : name(name) {}
};
class FileSystem {
    File root = File("");
    File *getFile(string path, bool createFile = false) {
        istringstream ss(path);
        string name;
        auto fp = &root;
        getline(ss, name, '/');
        while (getline(ss, name, '/')) {
            if (fp->contents.count(name) == 0) {
                fp->contents[name] = new File(name);
            }
            fp = fp->contents[name];
        }
        if (createFile) fp->isDirectory = false;
        return fp;
    }
public:
    FileSystem() {}
    vector<string> ls(string path) {
        auto fp = getFile(path);
        if (fp->isDirectory) {
            vector<string> ans;
            for (auto &[name, fp] : fp->contents) {
                ans.push_back(name);
            }
            return ans;
        }
        return { fp->name };
    }
    void mkdir(string path) {
        getFile(path);
    }
    void addContentToFile(string filePath, string content) {
        getFile(filePath, true)->content += content;
    }
    string readContentFromFile(string filePath) {
        return getFile(filePath)->content;
    }
};
```