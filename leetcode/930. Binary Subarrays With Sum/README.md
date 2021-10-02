# [930. Binary Subarrays With Sum (Medium)](https://leetcode.com/problems/binary-subarrays-with-sum/)

<p>In an array <code>A</code> of <code>0</code>s and <code>1</code>s, how many <strong>non-empty</strong> subarrays have sum <code>S</code>?</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-1-1">[1,0,1,0,1]</span>, S = <span id="example-input-1-2">2</span>
<strong>Output: </strong><span id="example-output-1">4</span>
<strong>Explanation: </strong>
The 4 subarrays are bolded below:
[<strong>1,0,1</strong>,0,1]
[<strong>1,0,1,0</strong>,1]
[1,<strong>0,1,0,1</strong>]
[1,0,<strong>1,0,1</strong>]
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>A.length &lt;= 30000</code></li>
	<li><code>0 &lt;= S &lt;= A.length</code></li>
	<li><code>A[i]</code>&nbsp;is either <code>0</code>&nbsp;or <code>1</code>.</li>
</ol>

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

## Solution 1. Prefix Sum

```cpp
// OJ: https://leetcode.com/problems/binary-subarrays-with-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        unordered_map<int, int> m{{0, 1}};
        int sum = 0, ans = 0;
        for (int n : A) {
            sum += n;
            ans += m.count(sum - S) ? m[sum - S] : 0;
            m[sum]++;
        }
        return ans;
    }
};
```

## Solution 2. Sliding Window

```cpp
// OJ: https://leetcode.com/problems/binary-subarrays-with-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int j = 0, N = A.size(), sum = 0, ans = 0;
        if (S == 0) {
            int cnt = 0;
            for (int i = 0; i <= N; ++i) {
                if (i == N || A[i] == 1) {
                    ans += cnt * (1 + cnt) / 2;
                    cnt = 0;
                } else ++cnt;
            }
            return ans;
        }
        while (j < N && A[j] == 0) ++j;
        int leadingZeros = j, i = j;
        while (j < N) {
            while (j < N && sum + A[j] <= S) {
                sum += A[j++];
                if (sum == S) ans += leadingZeros + 1;
            }
            while (i < j && sum == S) sum -= A[i++];
            leadingZeros = 0;
            while (i < j && A[i] == 0) {
                leadingZeros++; 
                ++i;
            }
        }
        return ans;
    }
};
```