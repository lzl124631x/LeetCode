# [495. Teemo Attacking (Medium)](https://leetcode.com/problems/teemo-attacking/)

<p>In LOL world, there is a hero called Teemo and his attacking can make his enemy Ashe be in poisoned condition. Now, given the Teemo's attacking <b>ascending</b> time series towards Ashe and the poisoning time duration per Teemo's attacking, you need to output the total time that Ashe is in poisoned condition.</p>

<p>You may assume that Teemo attacks at the very beginning of a specific time point, and makes Ashe be in poisoned condition immediately.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> [1,4], 2
<b>Output:</b> 4
<b>Explanation:</b> At time point 1, Teemo starts attacking Ashe and makes Ashe be poisoned immediately. 
This poisoned status will last 2 seconds until the end of time point 2. 
And at time point 4, Teemo attacks Ashe again, and causes Ashe to be in poisoned status for another 2 seconds. 
So you finally need to output 4.
</pre>

<p>&nbsp;</p>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> [1,2], 2
<b>Output:</b> 3
<b>Explanation:</b> At time point 1, Teemo starts attacking Ashe and makes Ashe be poisoned. 
This poisoned status will last 2 seconds until the end of time point 2. 
However, at the beginning of time point 2, Teemo attacks Ashe again who is already in poisoned status. 
Since the poisoned status won't add up together, though the second poisoning attack will still work at time point 2, it will stop at the end of time point 3. 
So you finally need to output 3.
</pre>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<ol>
	<li>You may assume the length of given time series array won't exceed 10000.</li>
	<li>You may assume the numbers in the Teemo's attacking time series and his poisoning time duration per attacking are non-negative integers, which won't exceed 10,000,000.</li>
</ol>

<p>&nbsp;</p>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Merge Intervals (Medium)](https://leetcode.com/problems/merge-intervals/)
* [Can Place Flowers (Easy)](https://leetcode.com/problems/can-place-flowers/)
* [Dota2 Senate (Medium)](https://leetcode.com/problems/dota2-senate/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/teemo-attacking/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int end = 0, ans = 0;
        for (int n : timeSeries) {
            if (end <= n) ans += duration;
            else ans += n + duration - end;
            end = n + duration;
        }
        return ans;
    }
};
```