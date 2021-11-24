# [1429. First Unique Number (Medium)](https://leetcode.com/problems/first-unique-number/)

<div class="question-description__3U1T"><div><p>You have a queue of integers, you need to retrieve the first unique integer in the queue.</p>

<p>Implement the <code>FirstUnique</code>&nbsp;class:</p>

<ul>
	<li><code>FirstUnique(int[] nums)</code> Initializes the object with the numbers in the queue.</li>
	<li><code>int showFirstUnique()</code>&nbsp;returns the value of <strong>the&nbsp;first unique</strong> integer of the queue, and returns <strong>-1</strong> if there is no such integer.</li>
	<li><code>void add(int value)</code>&nbsp;insert value&nbsp;to&nbsp;the queue.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><b>Input: </b>
["FirstUnique","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique"]
[[[2,3,5]],[],[5],[],[2],[],[3],[]]
<b>Output: </b>
[null,2,null,2,null,3,null,-1]

<b>Explanation: </b>
FirstUnique firstUnique = new FirstUnique([2,3,5]);
firstUnique.showFirstUnique(); // return 2
firstUnique.add(5);            // the queue is now [2,3,5,5]
firstUnique.showFirstUnique(); // return 2
firstUnique.add(2);&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; // the queue is now [2,3,5,5,2]
firstUnique.showFirstUnique(); // return 3
firstUnique.add(3);&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; // the queue is now [2,3,5,5,2,3]
firstUnique.showFirstUnique(); // return -1

</pre>

<p><strong>Example 2:</strong></p>

<pre><b>Input: </b>
["FirstUnique","showFirstUnique","add","add","add","add","add","showFirstUnique"]
[[[7,7,7,7,7,7]],[],[7],[3],[3],[7],[17],[]]
<b>Output: </b>
[null,-1,null,null,null,null,null,17]

<b>Explanation: </b>
FirstUnique firstUnique = new FirstUnique([7,7,7,7,7,7]);
firstUnique.showFirstUnique(); // return -1
firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7]
firstUnique.add(3);&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; // the queue is now [7,7,7,7,7,7,7,3]
firstUnique.add(3);&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; // the queue is now [7,7,7,7,7,7,7,3,3]
firstUnique.add(7);&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; // the queue is now [7,7,7,7,7,7,7,3,3,7]
firstUnique.add(17);&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;// the queue is now [7,7,7,7,7,7,7,3,3,7,17]
firstUnique.showFirstUnique(); // return 17

</pre>

<p><strong>Example 3:</strong></p>

<pre><b>Input: </b>
["FirstUnique","showFirstUnique","add","showFirstUnique"]
[[[809]],[],[809],[]]
<b>Output: </b>
[null,809,null,-1]

<b>Explanation: </b>
FirstUnique firstUnique = new FirstUnique([809]);
firstUnique.showFirstUnique(); // return 809
firstUnique.add(809);          // the queue is now [809,809]
firstUnique.showFirstUnique(); // return -1

</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^8</code></li>
	<li><code>1 &lt;= value &lt;= 10^8</code></li>
	<li>At most <code>50000</code>&nbsp;calls will be made to <code>showFirstUnique</code>&nbsp;and <code>add</code>.</li>
</ul></div></div>

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/first-unique-number/
// Author: github.com/lzl124631x
// Time:
//    FirstUnique: O(N)
//    showFirstUnique: O(1)
//    add: O(1)
// Space: O(N)
class FirstUnique {
    list<int> data;
    typedef list<int>::iterator iter;
    unordered_map<int, iter> m;
    unordered_set<int> dup;
public:
    FirstUnique(vector<int>& A) {
        for (int n : A) add(n);
    }
    int showFirstUnique() {
        return data.empty() ? -1 : data.front();
    }
    void add(int value) {
        if (dup.count(value)) return;
        if (m.count(value)) {
            data.erase(m[value]);
            m.erase(value);
            dup.insert(value);
        } else {
            data.push_back(value);
            m[value] = prev(data.end());
        }
    }
};
```

## Solution 2. Lazy Delete

```cpp
// OJ: https://leetcode.com/problems/first-unique-number/
// Author: github.com/lzl124631x
// Time:
//    FirstUnique: O(N)
//    showFirstUnique: O(1) amortized
//    add: O(1)
// Space: O(N)
class FirstUnique {
    unordered_map<int, int> m;
    queue<int> q;
public:
    FirstUnique(vector<int>& A) {
        for (int n : A) add(n);
    }
    int showFirstUnique() {
        while (q.size() && m[q.front()] > 1) q.pop();
        return q.size() ? q.front() : -1;
    }
    void add(int value) {
        if (++m[value] == 1) q.push(value);
    }
};
```