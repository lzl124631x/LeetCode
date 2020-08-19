# [609. Find Duplicate File in System (Medium)](https://leetcode.com/problems/find-duplicate-file-in-system/)

<p>Given a list of directory info including directory path, and all the files with contents in this directory, you need to find out all the groups of duplicate files in the file system in terms of their paths.</p>

<p>A group of duplicate files consists of at least <b>two</b> files that have exactly the same content.</p>

<p>A single directory info string in the <b>input</b> list has the following format:</p>

<p><code>"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"</code></p>

<p>It means there are <b>n</b> files (<code>f1.txt</code>, <code>f2.txt</code> ... <code>fn.txt</code> with content <code>f1_content</code>, <code>f2_content</code> ... <code>fn_content</code>, respectively) in directory <code>root/d1/d2/.../dm</code>. Note that n &gt;= 1 and m &gt;= 0. If m = 0, it means the directory is just the root directory.</p>

<p>The <b>output</b> is a list of group of duplicate file paths. For each group, it contains all the file paths of the files that have the same content. A file path is a string that has the following format:</p>

<p><code>"directory_path/file_name.txt"</code></p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b>
["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]
<b>Output:</b>  
[["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
</pre>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<ol>
	<li>No order is required for the final output.</li>
	<li>You may assume the directory name, file name and file content only has letters and digits, and the length of file content is in the range of [1,50].</li>
	<li>The number of files given is in the range of [1,20000].</li>
	<li>You may assume no files or directories share the same name in the same directory.</li>
	<li>You may assume each given directory info represents a unique directory. Directory path and file info are separated by a single blank space.</li>
</ol>

<p>&nbsp;</p>
<b>Follow-up beyond contest:</b>

<ol>
	<li>Imagine you are given a real file system, how will you search files? DFS or BFS?</li>
	<li>If the file content is very large (GB level), how will you modify your solution?</li>
	<li>If you can only read the file by 1kb each time, how will you modify your solution?</li>
	<li>What is the time complexity of your modified solution? What is the most time-consuming part and memory consuming part of it? How to optimize?</li>
	<li>How to make sure the duplicated files you find are not false positive?</li>
</ol>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-duplicate-file-in-system/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        for (auto &path : paths) {
            istringstream ss(path);
            string folder, file;
            ss >> folder;
            while (ss >> file) {
                int i = file.find('(');
                string name = file.substr(0, i), content = file.substr(i + 1, file.size() - i - 2);
                m[content].push_back(folder + "/" + name);
            }
        }
        vector<vector<string>> ans;
        for (auto &[content, files] : m) {
            if (files.size() == 1) continue;
            ans.emplace_back();
            for (auto &file : files) ans.back().push_back(file);
        }
        return ans;
    }
};
```