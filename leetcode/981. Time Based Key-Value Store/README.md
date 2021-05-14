# [981. Time Based Key-Value Store (Medium)](https://leetcode.com/problems/time-based-key-value-store/)

<p>Create a timebased key-value store class&nbsp;<code>TimeMap</code>, that supports two operations.</p>

<p>1. <code>set(string key, string value, int timestamp)</code></p>

<ul>
	<li>Stores the <code>key</code> and <code>value</code>, along with the given <code>timestamp</code>.</li>
</ul>

<p>2. <code>get(string key, int timestamp)</code></p>

<ul>
	<li>Returns a value such that <code>set(key, value, timestamp_prev)</code> was called previously, with <code>timestamp_prev &lt;= timestamp</code>.</li>
	<li>If there are multiple such values, it returns the one with the largest <code>timestamp_prev</code>.</li>
	<li>If there are no values, it returns the empty string (<code>""</code>).</li>
</ul>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>inputs = <span id="example-input-1-1">["TimeMap","set","get","get","set","get","get"]</span>, inputs = <span id="example-input-1-2">[[],["foo","bar",1],["foo",1],["foo",3],["foo","bar2",4],["foo",4],["foo",5]]</span>
<strong>Output: </strong><span id="example-output-1">[null,null,"bar","bar",null,"bar2","bar2"]</span>
<strong>Explanation: </strong><span id="example-output-1">&nbsp; 
TimeMap kv; &nbsp; 
kv.set("foo", "bar", 1); // store the key "foo" and value "bar" along with timestamp = 1 &nbsp; 
kv.get("foo", 1);  // output "bar" &nbsp; 
kv.get("foo", 3); // output "bar" since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 ie "bar" &nbsp; 
kv.set("foo", "bar2", 4); &nbsp; 
kv.get("foo", 4); // output "bar2" &nbsp; 
kv.get("foo", 5); //output "bar2" &nbsp; 
</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>inputs = <span id="example-input-2-1">["TimeMap","set","set","get","get","get","get","get"]</span>, inputs = <span id="example-input-2-2">[[],["love","high",10],["love","low",20],["love",5],["love",10],["love",15],["love",20],["love",25]]</span>
<strong>Output: </strong><span id="example-output-2">[null,null,null,"","high","high","low","low"]</span>
</pre>
</div>
</div>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li>All key/value strings are lowercase.</li>
	<li>All key/value strings have&nbsp;length in the range&nbsp;<code>[1, 100]</code></li>
	<li>The <code>timestamps</code> for all <code>TimeMap.set</code> operations are strictly increasing.</li>
	<li><code>1 &lt;= timestamp &lt;= 10^7</code></li>
	<li><code>TimeMap.set</code> and <code>TimeMap.get</code>&nbsp;functions will be called a total of <code>120000</code> times (combined) per test case.</li>
</ol>


**Companies**:  
[Google](https://leetcode.com/company/google), [ByteDance](https://leetcode.com/company/bytedance), [Apple](https://leetcode.com/company/apple), [Netflix](https://leetcode.com/company/netflix), [Oracle](https://leetcode.com/company/oracle), [Sumologic](https://leetcode.com/company/sumologic), [Facebook](https://leetcode.com/company/facebook), [Atlassian](https://leetcode.com/company/atlassian), [Microsoft](https://leetcode.com/company/microsoft), [Uber](https://leetcode.com/company/uber), [Twitter](https://leetcode.com/company/twitter), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Binary Search](https://leetcode.com/tag/binary-search/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/time-based-key-value-store/
// Author: github.com/lzl124631x
// Time:
//      TimeMap: O(1)
//      set: O(logT)
//      get: O(logT)
// Space: O(N)
class TimeMap {
    unordered_map<string, map<int, string, greater<>>> m;
public:
    TimeMap() {}
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    string get(string key, int timestamp) {
        if (m.count(key) == 0) return "";
        auto it = m[key].lower_bound(timestamp);
        return it == m[key].end() ? "" : it->second;
    }
};
```