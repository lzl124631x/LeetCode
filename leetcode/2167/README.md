# [2167. Minimum Time to Remove All Cars Containing Illegal Goods (Hard)](https://leetcode.com/problems/minimum-time-to-remove-all-cars-containing-illegal-goods/)

<p>You are given a <strong>0-indexed</strong> binary string <code>s</code> which represents a sequence of train cars. <code>s[i] = '0'</code> denotes that the <code>i<sup>th</sup></code> car does <strong>not</strong> contain illegal goods and <code>s[i] = '1'</code> denotes that the <code>i<sup>th</sup></code> car does contain illegal goods.</p>

<p>As the train conductor, you would like to get rid of all the cars containing illegal goods. You can do any of the following three operations <strong>any</strong> number of times:</p>

<ol>
	<li>Remove a train car from the <strong>left</strong> end (i.e., remove <code>s[0]</code>) which takes 1 unit of time.</li>
	<li>Remove a train car from the <strong>right</strong> end (i.e., remove <code>s[s.length - 1]</code>) which takes 1 unit of time.</li>
	<li>Remove a train car from <strong>anywhere</strong> in the sequence which takes 2 units of time.</li>
</ol>

<p>Return <em>the <strong>minimum</strong> time to remove all the cars containing illegal goods</em>.</p>

<p>Note that an empty sequence of cars is considered to have no cars containing illegal goods.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "<strong><u>11</u></strong>00<strong><u>1</u></strong>0<strong><u>1</u></strong>"
<strong>Output:</strong> 5
<strong>Explanation:</strong> 
One way to remove all the cars containing illegal goods from the sequence is to
- remove a car from the left end 2 times. Time taken is 2 * 1 = 2.
- remove a car from the right end. Time taken is 1.
- remove the car containing illegal goods found in the middle. Time taken is 2.
This obtains a total time of 2 + 1 + 2 = 5. 

An alternative way is to
- remove a car from the left end 2 times. Time taken is 2 * 1 = 2.
- remove a car from the right end 3 times. Time taken is 3 * 1 = 3.
This also obtains a total time of 2 + 3 = 5.

5 is the minimum time taken to remove all the cars containing illegal goods. 
There are no other ways to remove them with less time.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "00<strong><u>1</u></strong>0"
<strong>Output:</strong> 2
<strong>Explanation:</strong>
One way to remove all the cars containing illegal goods from the sequence is to
- remove a car from the left end 3 times. Time taken is 3 * 1 = 3.
This obtains a total time of 3.

Another way to remove all the cars containing illegal goods from the sequence is to
- remove the car containing illegal goods found in the middle. Time taken is 2.
This obtains a total time of 2.

Another way to remove all the cars containing illegal goods from the sequence is to 
- remove a car from the right end 2 times. Time taken is 2 * 1 = 2. 
This obtains a total time of 2.

2 is the minimum time taken to remove all the cars containing illegal goods. 
There are no other ways to remove them with less time.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
</ul>


**Similar Questions**:
* [Minimum Number of K Consecutive Bit Flips (Hard)](https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/)

## Solution 1.

The string needs to be split into 3 segments:
* We delete all the numbers in the left part
* We only delete the ones in the middle part
* We delete all the numbers in the right part

Ignoring the ones at the edges which must be removed using 1 unit of time, the rest of elements will be in the following form

```
| left   |        middle      | right |
0..0  1..1  0...0 1..1 0...0  1..1 0..0
```

Assume there are `x` ones in the middle, and `one` ones and `zero` zeroes in the right. The left part is symmetric to the right part so we ignore it for now.

The total cost is `2x + one + zero = 2(x+one) + zero - one`. `x + one` is the total number of ones in `s` which is a constant. So our goal is to minimize `zero - one` in the left part and right part. 

We can traverse from left to right, and calculate the `zero - one` value of the left part. For the min `zero - one` in the right part, we can use a mono-stack to precompute it.

```cpp
// OJ: https://leetcode.com/problems/minimum-time-to-remove-all-cars-containing-illegal-goods/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int minimumTime(string s) {
        int cnt = 0, N = s.size(), ans = INT_MAX;
        for (char c : s) cnt += c == '1';
        vector<int> right(N + 1);
        stack<int> st{{N}};
        for (int i = N - 1; i >= 0; --i) {
            right[i] = right[i + 1] + (s[i] == '0' ? 1 : -1);
            if (right[i] < right[st.top()]) st.push(i);
        }
        for (int i = 0, diff = 0; i < N; ++i) {
            ans = min(ans, 2 * cnt + diff + right[st.top()]);
            diff += s[i] == '0' ? 1 : -1;
            if (st.top() == i) st.pop();
        }
        return ans;
    }
};
```

## Solution 2. DP

`right[i]` is the min cost to remove `1`s in `s[i:]` using operation 2 and 3.

* If `s[i] == '0'`, `right[i] = right[i + 1]`.
* If `s[i] == '1'`:
  * If we use operation 3, `right[i] = right[i + 1] + 2`.
  * If we use operation 2, `right[i] = N - i`.
  * So, `right[i] = min( right[i + 1] + 2, N - i )`

Now scan from left to right. For each `s[i]`, we remove `s[0..(i-1)]` using operation 1 with cost `i`. Since `right[i]` is the min cost to remove `1`s in `s[i:]` using operation 2 and 3. The optimal total cost for this index `i` is `i + right[i]`. The answer is the global min `i + right[i]`.

```cpp
// OJ: https://leetcode.com/problems/minimum-time-to-remove-all-cars-containing-illegal-goods/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int minimumTime(string s) {
        int cnt = 0, N = s.size(), ans = INT_MAX;
        vector<int> right(N + 1);
        for (int i = N - 1; i >= 0; --i) {
            if (s[i] == '0') right[i] = right[i + 1];
            else right[i] = min(right[i + 1] + 2, N - i);
        }
        for (int i = 0; i < N; ++i) {
            ans = min(ans, i + right[i]);
        }
        return ans;
    }
};
```