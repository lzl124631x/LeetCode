# [1146. Snapshot Array (Medium)](https://leetcode.com/problems/snapshot-array/)

<p>Implement a SnapshotArray that supports the following interface:</p>

<ul>
	<li><code>SnapshotArray(int length)</code> initializes an array-like data structure with the given length.&nbsp; <strong>Initially, each element equals 0</strong>.</li>
	<li><code>void set(index, val)</code> sets the element at the given <code>index</code> to be equal to <code>val</code>.</li>
	<li><code>int snap()</code>&nbsp;takes a snapshot of the array and returns the <code>snap_id</code>: the total number of times we called <code>snap()</code> minus <code>1</code>.</li>
	<li><code>int get(index, snap_id)</code>&nbsp;returns the value at the given <code>index</code>, at the time we took the snapshot with the given <code>snap_id</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> ["SnapshotArray","set","snap","set","get"]
[[3],[0,5],[],[0,6],[0,0]]
<strong>Output:</strong> [null,null,0,null,5]
<strong>Explanation: </strong>
SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
snapshotArr.set(0,5);  // Set array[0] = 5
snapshotArr.snap();  // Take a snapshot, return snap_id = 0
snapshotArr.set(0,6);
snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return 5</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= length&nbsp;&lt;= 50000</code></li>
	<li>At most <code>50000</code>&nbsp;calls will be made to <code>set</code>, <code>snap</code>, and <code>get</code>.</li>
	<li><code>0 &lt;= index&nbsp;&lt;&nbsp;length</code></li>
	<li><code>0 &lt;=&nbsp;snap_id &lt;&nbsp;</code>(the total number of times we call <code>snap()</code>)</li>
	<li><code>0 &lt;=&nbsp;val &lt;= 10^9</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/snapshot-array/
// Author: github.com/lzl124631x
// Time:
//      SnapshotArray, set, snap: O(1)
//      get: O(S) where S is the number of snapshots taken.
// Space: O(length * S)
class SnapshotArray {
    vector<unordered_map<int, int>> snapshot;
public:
    SnapshotArray(int length) : snapshot(1) {}
    
    void set(int index, int val) {
        snapshot.back()[index] = val;
    }
    
    int snap() {
        snapshot.emplace_back();
        return snapshot.size() - 2;
    }
    
    int get(int index, int snap_id) {
        for (int i = snap_id; i >= 0; --i) {
            if (snapshot[i].count(index) == 0) continue;
            return snapshot[i][index];
        }
        return 0;
    }
};
```

## Solution 2.

```cpp
// Time:
//      SnapshotArray: O(length)
//      set: O(1)
//      snap: O(length)
//      get: O(logS) where S is the number of snapshots taken
class SnapshotArray {
    vector<vector<int>> snapIds;
    vector<unordered_map<int, int>> snapshot;
public:
    SnapshotArray(int length) : snapshot(1), snapIds(length) {}
    
    void set(int index, int val) {
        snapshot.back()[index] = val;
    }
    
    int snap() {
        int id = snapshot.size() - 1;
        for (auto &[num, val] : snapshot.back()) snapIds[num].push_back(id);
        snapshot.emplace_back();
        return id;
    }
    
    int get(int index, int snap_id) {
        auto &snaps = snapIds[index];
        int i = upper_bound(begin(snaps), end(snaps), snap_id) - begin(snaps) - 1;
        return i == -1 ? 0 : snapshot[snaps[i]][index];
    }
};
```