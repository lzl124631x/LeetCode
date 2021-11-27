# [2086. Minimum Number of Buckets Required to Collect Rainwater from Houses (Medium)](https://leetcode.com/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses/)

<p>You are given a <b>0-index</b><strong>ed</strong> string <code>street</code>. Each character in <code>street</code> is either <code>'H'</code> representing a house or <code>'.'</code> representing an empty space.</p>

<p>You can place buckets on the <strong>empty spaces</strong> to collect rainwater that falls from the adjacent houses. The rainwater from a house at index <code>i</code> is collected if a bucket is placed at index <code>i - 1</code> <strong>and/or</strong> index <code>i + 1</code>. A single bucket, if placed adjacent to two houses, can collect the rainwater from <strong>both</strong> houses.</p>

<p>Return <em>the <strong>minimum </strong>number of buckets needed so that for <strong>every</strong> house, there is <strong>at least</strong> one bucket collecting rainwater from it, or </em><code>-1</code><em> if it is impossible.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> street = "H..H"
<strong>Output:</strong> 2
<strong>Explanation:</strong>
We can put buckets at index 1 and index 2.
"H..H" -&gt; "HBBH" ('B' denotes where a bucket is placed).
The house at index 0 has a bucket to its right, and the house at index 3 has a bucket to its left.
Thus, for every house, there is at least one bucket collecting rainwater from it.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> street = ".H.H."
<strong>Output:</strong> 1
<strong>Explanation:</strong>
We can put a bucket at index 2.
".H.H." -&gt; ".HBH." ('B' denotes where a bucket is placed).
The house at index 1 has a bucket to its right, and the house at index 3 has a bucket to its left.
Thus, for every house, there is at least one bucket collecting rainwater from it.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> street = ".HHH."
<strong>Output:</strong> -1
<strong>Explanation:</strong>
There is no empty space to place a bucket to collect the rainwater from the house at index 2.
Thus, it is impossible to collect the rainwater from all the houses.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> street = "H"
<strong>Output:</strong> -1
<strong>Explanation:</strong>
There is no empty space to place a bucket.
Thus, it is impossible to collect the rainwater from the house.
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> street = "."
<strong>Output:</strong> 0
<strong>Explanation:</strong>
There is no house to collect water from.
Thus, 0 buckets are needed.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= street.length &lt;= 10<sup>5</sup></code></li>
	<li><code>street[i]</code>&nbsp;is either<code>'H'</code>&nbsp;or&nbsp;<code>'.'</code>.</li>
</ul>


**Similar Questions**:
* [Maximum Number of People That Can Be Caught in Tag (Medium)](https://leetcode.com/problems/maximum-number-of-people-that-can-be-caught-in-tag/)
* [Brightest Position on Street (Medium)](https://leetcode.com/problems/brightest-position-on-street/)

## Solution 1. Greedy

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minimumBuckets(string s) {
        int N = s.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            if (s[i] != 'H') continue;
            if (i - 1 >= 0 && s[i - 1] == 'B') continue;
            if (i + 1 < N && s[i + 1] == '.') s[i + 1] = 'B', ++ans; // fill the right side as a priority
            else if (i - 1 >= 0 && s[i - 1] == '.') ++ans;
            else return -1;
        }
        return ans;
    }
};
```