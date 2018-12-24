# [638. Shopping Offers (Medium)](https://leetcode.com/problems/shopping-offers/)

<p>
In LeetCode Store, there are some kinds of items to sell. Each item has a price.
</p>

<p>
However, there are some special offers, and a special offer consists of one or more different kinds of items with a sale price.
</p>

<p>
You are given the each item's price, a set of special offers, and the number we need to buy for each item.
The job is to output the lowest price you have to pay for <b>exactly</b> certain items as given, where you could make optimal use of the special offers.
</p>

<p>
Each special offer is represented in the form of an array, the last number represents the price you need to pay for this special offer, other numbers represents how many specific items you could get if you buy this offer.
</p>

<p>You could use any of special offers as many times as you want.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> [2,5], [[3,0,5],[1,2,10]], [3,2]
<b>Output:</b> 14
<b>Explanation:</b> 
There are two kinds of items, A and B. Their prices are $2 and $5 respectively. 
In special offer 1, you can pay $5 for 3A and 0B
In special offer 2, you can pay $10 for 1A and 2B. 
You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), and $4 for 2A.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> [2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1]
<b>Output:</b> 11
<b>Explanation:</b> 
The price of A is $2, and $3 for B, $4 for C. 
You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C. 
You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special offer #1), and $3 for 1B, $4 for 1C. 
You cannot add more items, though only $9 for 2A ,2B and 1C.
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>There are at most 6 kinds of items, 100 special offers.</li>
<li>For each item, you need to buy at most 6 of them.</li>
<li>You are <b>not</b> allowed to buy more items than you want, even if that would lower the overall price.</li>
</ol>
<p></p>

**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

## Solution 1. DFS

DFS the special offers one by one. For each special offer, try:
1. Don't use it
1. Use it once
1. Use it twice  
...  
Until we don't have enough need to take the offer.

The ending cases are:
1. we traversed every special offer. For the remaining needs, buy them using `price`.
1. all the needs are `0`.


```cpp
// OJ: https://leetcode.com/problems/shopping-offers/
// Author: github.com/lzl124631x
// Time: O(NS) where N is length of `needs` and S is length of `special`.
// Space: O(NS)
class Solution {
private:
    int ans = INT_MAX;
    void dfs(vector<int>& price, vector<vector<int>>& special, vector<int> needs, int index, int cost) {
        if (index == special.size()) {
            for (int i = 0; i < needs.size(); ++i) {
                cost += needs[i] * price[i];
            }
            ans = min(ans, cost);
            return;
        }
        bool done = true;
        for (int n : needs) {
            if (n) {
                done = false;
                break;
            }
        }
        if (done) {
            ans = min(ans, cost);
            return;
        }
        auto &offer = special[index];
        dfs(price, special, needs, index + 1, cost);
        for (int i = 0; true; ++i) {
            for (int j = 0; j < needs.size(); ++j) {
                needs[j] -= offer[j];
                if (needs[j] < 0) return;
            }
            dfs(price, special, needs, index + 1, cost += offer.back());
        }
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        dfs(price, special, needs, 0, 0);
        return ans;
    }
};
```