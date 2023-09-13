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

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/snapshot-array/
// Author: github.com/lzl124631x
// Time:
//      SnapshotArray, set, snap: O(1)
//      get: O(S) where S is the number of snapshots taken.
// Space: O(NS)
class SnapshotArray {
    vector<unordered_map<int, int>> snapshot;
public:
    SnapshotArray(int N) : snapshot(1) {}
    
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

## Solution 2. Brute Force

```cpp
// OJ: https://leetcode.com/problems/snapshot-array/
// Author: github.com/lzl124631x
// Time:
//      SnapshotArray: O(N)
//      set: O(1)
//      snap: O(N)
//      get: O(logS) where S is the number of snapshots taken
class SnapshotArray {
    vector<vector<int>> snapIds; // snapIds[i] is a list of snapshot IDs related to the `i`-th element in array.
    vector<unordered_map<int, int>> snapshot; // snapshot[i] contains all the values changed between snapshot `i-1` and `i`
public:
    SnapshotArray(int N) : snapshot(1), snapIds(N) {}
    
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

## Solution 3. Binary Search

The brute force solutions log all the snapshots in a single list.

To improve it, we make each `A[i]` have its own lists tracking all the snapshots related to it and the corresponding values.

```cpp
// OJ: https://leetcode.com/problems/snapshot-array/
// Author: github.com/lzl124631x
// Time:
//      SnapshotArray: O(N)
//      set: O(1)
//      snap: O(1)
//      get: O(logS)
// Space: O(NS)
class SnapshotArray {
    vector<vector<int>> ids, vals; // If `A[i]` changed in between snapshot `j-1` and `j`, we append `j` to `ids[i]`, and append the changed value to `vals[i]`.
    int id = 0;
public:
    SnapshotArray(int N) : ids(N, {-1}), vals(N, {0}) {}
    void set(int i, int val) {
        if (ids[i].back() != id) {
            ids[i].push_back(id);
            vals[i].push_back(val);
        } else vals[i].back() = val;
    }
    int snap() {
        return id++;
    }
    int get(int i, int snap_id) {
        return vals[i][upper_bound(begin(ids[i]), end(ids[i]), snap_id) - begin(ids[i]) - 1];
    }
};
```