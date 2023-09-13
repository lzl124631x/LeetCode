# [1. Two Sum (Easy)](https://leetcode.com/problems/two-sum)

<p>Given an array of integers <code>nums</code>&nbsp;and an integer <code>target</code>, return <em>indices of the two numbers such that they add up to <code>target</code></em>.</p>

<p>You may assume that each input would have <strong><em>exactly</em> one solution</strong>, and you may not use the <em>same</em> element twice.</p>

<p>You can return the answer in any order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,7,11,15], target = 9
<strong>Output:</strong> [0,1]
<strong>Explanation:</strong> Because nums[0] + nums[1] == 9, we return [0, 1].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,2,4], target = 6
<strong>Output:</strong> [1,2]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,3], target = 6
<strong>Output:</strong> [0,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= target &lt;= 10<sup>9</sup></code></li>
	<li><strong>Only one valid answer exists.</strong></li>
</ul>

<p>&nbsp;</p>
<strong>Follow-up:&nbsp;</strong>Can you come up with an algorithm that is less than <code>O(n<sup>2</sup>)</code><font face="monospace">&nbsp;</font>time complexity?

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Adobe](https://leetcode.com/company/adobe), [Apple](https://leetcode.com/company/apple), [Microsoft](https://leetcode.com/company/microsoft), [Yahoo](https://leetcode.com/company/yahoo), [Bloomberg](https://leetcode.com/company/bloomberg), [Facebook](https://leetcode.com/company/facebook), [Uber](https://leetcode.com/company/uber), [Yandex](https://leetcode.com/company/yandex), [Spotify](https://leetcode.com/company/spotify), [Oracle](https://leetcode.com/company/oracle), [Accenture](https://leetcode.com/company/accenture), [Deloitte](https://leetcode.com/company/deloitte), [tcs](https://leetcode.com/company/tcs), [Tinkoff](https://leetcode.com/company/tinkoff), [IBM](https://leetcode.com/company/ibm), [wipro](https://leetcode.com/company/wipro), [Capgemini](https://leetcode.com/company/capgemini), [Careem](https://leetcode.com/company/careem), [Expedia](https://leetcode.com/company/expedia), [Cisco](https://leetcode.com/company/cisco), [Visa](https://leetcode.com/company/visa), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Morgan Stanley](https://leetcode.com/company/morgan-stanley), [Samsung](https://leetcode.com/company/samsung), [Barclays](https://leetcode.com/company/barclays), [BlackRock](https://leetcode.com/company/blackrock), [eBay](https://leetcode.com/company/ebay), [Nagarro](https://leetcode.com/company/nagarro), [Zillow](https://leetcode.com/company/zillow), [Accolite](https://leetcode.com/company/accolite), [Zoho](https://leetcode.com/company/zoho), [American Express](https://leetcode.com/company/american-express), [Walmart Labs](https://leetcode.com/company/walmart-labs), [Dell](https://leetcode.com/company/dell), [PayPal](https://leetcode.com/company/paypal), [JPMorgan](https://leetcode.com/company/jpmorgan), [VMware](https://leetcode.com/company/vmware), [Intel](https://leetcode.com/company/intel), [Salesforce](https://leetcode.com/company/salesforce), [Infosys](https://leetcode.com/company/infosys), [MakeMyTrip](https://leetcode.com/company/makemytrip), [ServiceNow](https://leetcode.com/company/servicenow), [Citadel](https://leetcode.com/company/citadel), [Qualcomm](https://leetcode.com/company/qualcomm), [ZScaler](https://leetcode.com/company/zscaler), [Zoom](https://leetcode.com/company/zoom), [Zomato](https://leetcode.com/company/zomato), [Info Edge](https://leetcode.com/company/info-edge), [turing](https://leetcode.com/company/turing), [Bank of America](https://leetcode.com/company/bank-of-america), [SAP](https://leetcode.com/company/sap), [Grab](https://leetcode.com/company/grab), [Intuit](https://leetcode.com/company/intuit), [Nvidia](https://leetcode.com/company/nvidia), [Twitter](https://leetcode.com/company/twitter), [Deutsche Bank](https://leetcode.com/company/deutsche-bank), [Capital One](https://leetcode.com/company/capital-one), [FactSet](https://leetcode.com/company/factset), [Cruise Automation](https://leetcode.com/company/cruise-automation), [Twitch](https://leetcode.com/company/twitch), [LinkedIn](https://leetcode.com/company/linkedin), [Airbnb](https://leetcode.com/company/airbnb), [Yelp](https://leetcode.com/company/yelp), [Dropbox](https://leetcode.com/company/dropbox)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Hash Table](https://leetcode.com/tag/hash-table)

**Similar Questions**:
* [3Sum (Medium)](https://leetcode.com/problems/3sum)
* [4Sum (Medium)](https://leetcode.com/problems/4sum)
* [Two Sum II - Input Array Is Sorted (Medium)](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted)
* [Two Sum III - Data structure design (Easy)](https://leetcode.com/problems/two-sum-iii-data-structure-design)
* [Subarray Sum Equals K (Medium)](https://leetcode.com/problems/subarray-sum-equals-k)
* [Two Sum IV - Input is a BST (Easy)](https://leetcode.com/problems/two-sum-iv-input-is-a-bst)
* [Two Sum Less Than K (Easy)](https://leetcode.com/problems/two-sum-less-than-k)
* [Max Number of K-Sum Pairs (Medium)](https://leetcode.com/problems/max-number-of-k-sum-pairs)
* [Count Good Meals (Medium)](https://leetcode.com/problems/count-good-meals)
* [Count Number of Pairs With Absolute Difference K (Easy)](https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k)
* [Number of Pairs of Strings With Concatenation Equal to Target (Medium)](https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target)
* [Find All K-Distant Indices in an Array (Easy)](https://leetcode.com/problems/find-all-k-distant-indices-in-an-array)
* [First Letter to Appear Twice (Easy)](https://leetcode.com/problems/first-letter-to-appear-twice)
* [Number of Excellent Pairs (Hard)](https://leetcode.com/problems/number-of-excellent-pairs)
* [Number of Arithmetic Triplets (Easy)](https://leetcode.com/problems/number-of-arithmetic-triplets)
* [Node With Highest Edge Score (Medium)](https://leetcode.com/problems/node-with-highest-edge-score)
* [Check Distances Between Same Letters (Easy)](https://leetcode.com/problems/check-distances-between-same-letters)
* [Find Subarrays With Equal Sum (Easy)](https://leetcode.com/problems/find-subarrays-with-equal-sum)
* [Largest Positive Integer That Exists With Its Negative (Easy)](https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative)
* [Number of Distinct Averages (Easy)](https://leetcode.com/problems/number-of-distinct-averages)
* [Count Pairs Whose Sum is Less than Target (Easy)](https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/two-sum/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& A, int target) {
        vector<vector<int>> v; 
        int N = A.size(), L = 0, R = N - 1;
        for (int i = 0; i < N; ++i) v.push_back({ A[i], i });
        sort(begin(v), end(v));
        while (L < R) {
            int sum = v[L][0] + v[R][0];
            if (sum == target) return { v[L][1], v[R][1] };
            if (sum < target) ++L;
            else --R;
        }
        return {};
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/two-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& A, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < A.size(); ++i) {
            int t = target - A[i];
            if (m.count(t)) return { m[t], i };
            m[A[i]] = i;
        }
        return {};
    }
};
```