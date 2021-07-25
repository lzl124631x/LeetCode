# [1948. Delete Duplicate Folders in System (Hard)](https://leetcode.com/problems/delete-duplicate-folders-in-system/)

<p>Due to a bug, there are many duplicate folders in a file system. You are given a 2D array <code>paths</code>, where <code>paths[i]</code> is an array representing an absolute path to the <code>i<sup>th</sup></code> folder in the file system.</p>

<ul>
	<li>For example, <code>["one", "two", "three"]</code> represents the path <code>"/one/two/three"</code>.</li>
</ul>

<p>Two folders (not necessarily on the same level) are <strong>identical</strong> if they contain the <strong>same non-empty</strong> set of identical subfolders and underlying subfolder structure. The folders <strong>do not</strong> need to be at the root level to be identical. If two or more folders are <strong>identical</strong>, then <strong>mark</strong> the folders as well as all their subfolders.</p>

<ul>
	<li>For example, folders <code>"/a"</code> and <code>"/b"</code> in the file structure below are identical. They (as well as their subfolders) should <strong>all</strong> be marked:

	<ul>
		<li><code>/a</code></li>
		<li><code>/a/x</code></li>
		<li><code>/a/x/y</code></li>
		<li><code>/a/z</code></li>
		<li><code>/b</code></li>
		<li><code>/b/x</code></li>
		<li><code>/b/x/y</code></li>
		<li><code>/b/z</code></li>
	</ul>
	</li>
	<li>However, if the file structure also included the path <code>"/b/w"</code>, then the folders <code>"/a"</code> and <code>"/b"</code> would not be identical. Note that <code>"/a/x"</code> and <code>"/b/x"</code> would still be considered identical even with the added folder.</li>
</ul>

<p>Once all the identical folders and their subfolders have been marked, the file system will <strong>delete</strong> all of them. The file system only runs the deletion once, so any folders that become identical after the initial deletion are not deleted.</p>

<p>Return <em>the 2D array </em><code>ans</code> <em>containing the paths of the <strong>remaining</strong> folders after deleting all the marked folders. The paths may be returned in <strong>any</strong> order</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/19/lc-dupfolder1.jpg" style="width: 200px; height: 218px;">
<pre><strong>Input:</strong> paths = [["a"],["c"],["d"],["a","b"],["c","b"],["d","a"]]
<strong>Output:</strong> [["d"],["d","a"]]
<strong>Explanation:</strong> The file structure is as shown.
Folders "/a" and "/c" (and their subfolders) are marked for deletion because they both contain an empty
folder named "b".
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/19/lc-dupfolder2.jpg" style="width: 200px; height: 355px;">
<pre><strong>Input:</strong> paths = [["a"],["c"],["a","b"],["c","b"],["a","b","x"],["a","b","x","y"],["w"],["w","y"]]
<strong>Output:</strong> [["c"],["c","b"],["a"],["a","b"]]
<strong>Explanation: </strong>The file structure is as shown. 
Folders "/a/b/x" and "/w" (and their subfolders) are marked for deletion because they both contain an empty folder named "y".
Note that folders "/a" and "/c" are identical after the deletion, but they are not deleted because they were not marked beforehand.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/19/lc-dupfolder3.jpg" style="width: 200px; height: 201px;">
<pre><strong>Input:</strong> paths = [["a","b"],["c","d"],["c"],["a"]]
<strong>Output:</strong> [["c"],["c","d"],["a"],["a","b"]]
<strong>Explanation:</strong> All folders are unique in the file system.
Note that the returned array can be in a different order as the order does not matter.
</pre>

<p><strong>Example 4:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/19/lc-dupfolder4_.jpg" style="width: 300px; height: 290px;">
<pre><strong>Input:</strong> paths = [["a"],["a","x"],["a","x","y"],["a","z"],["b"],["b","x"],["b","x","y"],["b","z"]]
<strong>Output:</strong> []
<strong>Explanation:</strong> The file structure is as shown.
Folders "/a/x" and "/b/x" (and their subfolders) are marked for deletion because they both contain an
empty folder named "y".
Folders "/a" and "/b" (and their subfolders) are marked for deletion because they both contain an empty
folder "z" and the folder "x" described above.
</pre>

<p><strong>Example 5:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/19/lc-dupfolder5_.jpg" style="width: 300px; height: 282px;">
<pre><strong>Input:</strong> paths = [["a"],["a","x"],["a","x","y"],["a","z"],["b"],["b","x"],["b","x","y"],["b","z"],["b","w"]]
<strong>Output:</strong> [["b"],["b","w"],["b","z"],["a"],["a","z"]]
<strong>Explanation:</strong> This has the same structure as the previous example, except with the added "/b/w".
Folders "/a/x" and "/b/x" are still marked, but "/a" and "/b" are no longer marked because "/b" has the
empty folder named "w" and "/a" does not.
Note that "/a/z" and "/b/z" are not marked because the set of identical subfolders must be non-empty, but these folders are empty.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= paths.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= paths[i].length &lt;= 500</code></li>
	<li><code>1 &lt;= paths[i][j].length &lt;= 10</code></li>
	<li><code>1 &lt;= sum(paths[i][j].length) &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>path[i][j]</code> consists of lowercase English letters.</li>
	<li>No two paths lead to the same folder.</li>
	<li>For any folder not at the root level, its parent folder will also be in the input.</li>
</ul>


**Similar Questions**:
* [Find Duplicate File in System (Medium)](https://leetcode.com/problems/find-duplicate-file-in-system/)
* [Find Duplicate Subtrees (Medium)](https://leetcode.com/problems/find-duplicate-subtrees/)

## Solution 1. DFS

1. **Build Tree**: Build a folder tree based on the `paths`. The process is similar to the Trie building process.
2. **Dedupe**: Use post-order traversal to visit all the nodes. If we've seen the subfolder structure before, mark the node as deleted.
3. **Generate Paths**: DFS to generate the output. We skip the nodes that have been deleted.

Note:
* To ensure we visit the subfolders in the same order, changed `Node::next` to `unordered_map` to `map`. (Testcase: `[["a"],["a","a"],["a","b"],["a","b","a"],["b"],["b","a"],["b","a","a"],["b","b"]]`.)
* To ensure the subfolder structure string only map to a unique tree structure, changed the encoding to use parenthesis instead, e.g. `(root(firstChild)(secondChild)...)`. (Testcase: `[["r","x"],["r","x", "b"],["r","x","b","a"],["r", "y"],["r","y", "a"],["r","y", "b"],["r"]]`.)

**Complexity Analysis**

Assume `N` is the number of folders, `W` is the maximum length of folder name, `D` is the deepest folder depth, and `C` is the maximum number of direct **c**hild folders.

1. **Build Tree**: We need to add all the `N` folders, each of which takes `O(DWlogC)` time. So overall it takes `O(NDWlogC)` time, and `O(NW)` space.
2. **Dedupe**: We traverse the `N` folders in post-order. The maximum length of `subfolder` structure string is roughly `O(NW)`, so each node visit need `O(NW)` time to check if it's a duplicate. The overall time complexity is `O(N^2 * W)` and the space complexity is `O(N^2 * W)`.
3. **Generate Paths**: In the worst case we traverse the `N` nodes again. Each visit takes `O(W)` time to update the current `path` and `O(DW)` time to update the answer. So overall the time complexity is `O(NDW)` and space complexity is `O(DW)` for the temporary `path`.

```cpp
// OJ: https://leetcode.com/problems/delete-duplicate-folders-in-system/
// Author: github.com/lzl124631x
// Time: O(NDWlogC + N^2 * W) where `N` is the number of folders, `W` is the maximum length of folder name, 
//                                  `D` is the deepest folder depth, and `C` is the maximum number of direct child folders.
// Space: O(N^2 * W)
struct Node {
    string name;
    map<string, Node*> next; // mapping from folder name to the corresponding child node.
    bool del = false; // whether this folder is deleted.
    Node(string n = "") : name(n) {}
};
class Solution {
    void addPath(Node *node, vector<string> &path) { // Given a path, add nodes to the folder tree. This is similar to the Trie build process.
        for (auto &s : path) {
            if (node->next.count(s) == 0) node->next[s] = new Node(s);
            node = node->next[s];
        }
    }
    unordered_map<string, Node*> seen; // mapping from subfolder structure string to the first occurrence node.
    string dedupe(Node *node) { // post-order traversal to dedupe. If we've seen the subfolder structure before, mark it as deleted.
        string subfolder;
        for (auto &[name, next] : node->next) {
            subfolder += dedupe(next);
        }
        if (subfolder.size()) { // leaf nodes should be ignored
            if (seen.count(subfolder)) { // if we've seen this subfolder structure before, mark them as deleted.
                seen[subfolder]->del = node->del = true;
            } else {
                seen[subfolder] = node; // otherwise, add the mapping
            }
        }
        return "(" + node->name + subfolder + ")"; // return the folder structure string of this node.
    }
    vector<vector<string>> ans;
    vector<string> path;
    void getPath(Node *node) {
        if (node->del) return; // if the current node is deleted, skip it.
        path.push_back(node->name);
        ans.push_back(path);
        for (auto &[name, next] : node->next) {
            getPath(next);
        }
        path.pop_back();
    }
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& A) {
        Node root;
        for (auto &path : A) addPath(&root, path);
        dedupe(&root);
        for (auto &[name, next] : root.next) getPath(next);
        return ans;
    }
};
```