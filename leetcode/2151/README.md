# [2151. Maximum Good People Based on Statements (Hard)](https://leetcode.com/problems/maximum-good-people-based-on-statements/)

<p>There are two types of persons:</p>

<ul>
	<li>The <strong>good person</strong>: The person who always tells the truth.</li>
	<li>The <strong>bad person</strong>: The person who might tell the truth and might lie.</li>
</ul>

<p>You are given a <strong>0-indexed</strong> 2D integer array <code>statements</code> of size <code>n x n</code> that represents the statements made by <code>n</code> people about each other. More specifically, <code>statements[i][j]</code> could be one of the following:</p>

<ul>
	<li><code>0</code> which represents a statement made by person <code>i</code> that person <code>j</code> is a <strong>bad</strong> person.</li>
	<li><code>1</code> which represents a statement made by person <code>i</code> that person <code>j</code> is a <strong>good</strong> person.</li>
	<li><code>2</code> represents that <strong>no statement</strong> is made by person <code>i</code> about person <code>j</code>.</li>
</ul>

<p>Additionally, no person ever makes a statement about themselves. Formally, we have that <code>statements[i][i] = 2</code> for all <code>0 &lt;= i &lt; n</code>.</p>

<p>Return <em>the <strong>maximum</strong> number of people who can be <strong>good</strong> based on the statements made by the </em><code>n</code><em> people</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/01/15/logic1.jpg" style="width: 600px; height: 262px;">
<pre><strong>Input:</strong> statements = [[2,1,2],[1,2,2],[2,0,2]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> Each person makes a single statement.
- Person 0 states that person 1 is good.
- Person 1 states that person 0 is good.
- Person 2 states that person 1 is bad.
Let's take person 2 as the key.
- Assuming that person 2 is a good person:
    - Based on the statement made by person 2, person 1 is a bad person.
    - Now we know for sure that person 1 is bad and person 2 is good.
    - Based on the statement made by person 1, and since person 1 is bad, they could be:
        - telling the truth. There will be a contradiction in this case and this assumption is invalid.
        - lying. In this case, person 0 is also a bad person and lied in their statement.
    - <strong>Following that person 2 is a good person, there will be only one good person in the group</strong>.
- Assuming that person 2 is a bad person:
    - Based on the statement made by person 2, and since person 2 is bad, they could be:
        - telling the truth. Following this scenario, person 0 and 1 are both bad as explained before.
            - <strong>Following that person 2 is bad but told the truth, there will be no good persons in the group</strong>.
        - lying. In this case person 1 is a good person.
            - Since person 1 is a good person, person 0 is also a good person.
            - <strong>Following that person 2 is bad and lied, there will be two good persons in the group</strong>.
We can see that at most 2 persons are good in the best case, so we return 2.
Note that there is more than one way to arrive at this conclusion.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/01/15/logic2.jpg" style="width: 600px; height: 262px;">
<pre><strong>Input:</strong> statements = [[2,0],[0,2]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> Each person makes a single statement.
- Person 0 states that person 1 is bad.
- Person 1 states that person 0 is bad.
Let's take person 0 as the key.
- Assuming that person 0 is a good person:
    - Based on the statement made by person 0, person 1 is a bad person and was lying.
    - <strong>Following that person 0 is a good person, there will be only one good person in the group</strong>.
- Assuming that person 0 is a bad person:
    - Based on the statement made by person 0, and since person 0 is bad, they could be:
        - telling the truth. Following this scenario, person 0 and 1 are both bad.
            - <strong>Following that person 0 is bad but told the truth, there will be no good persons in the group</strong>.
        - lying. In this case person 1 is a good person.
            - <strong>Following that person 0 is bad and lied, there will be only one good person in the group</strong>.
We can see that at most, one person is good in the best case, so we return 1.
Note that there is more than one way to arrive at this conclusion.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == statements.length == statements[i].length</code></li>
	<li><code>2 &lt;= n &lt;= 15</code></li>
	<li><code>statements[i][j]</code> is either <code>0</code>, <code>1</code>, or <code>2</code>.</li>
	<li><code>statements[i][i] == 2</code></li>
</ul>


**Similar Questions**:
* [Maximum Score Words Formed by Letters (Hard)](https://leetcode.com/problems/maximum-score-words-formed-by-letters/)

## Solution 1. Bitmask Subset Traversal

Enumerate bitmask `m` from `1` to `2^N - 1`. If the `i`th bit of `m` is `1`/`0`, it means that person `i` is good/bad.

We can ignore bad persons' statements because they can be either true or false. But good persons' statements must be all correct.

To test if this bitmask `m` is valid, we go through all the good persons' statements and see if there is any contradiction.

```cpp
// OJ: https://leetcode.com/problems/maximum-good-people-based-on-statements/
// Author: github.com/lzl124631x
// Time: O(2^N * N^2)
// Space: O(1)
class Solution {
public:
    int maximumGood(vector<vector<int>>& A) {
        int N = A.size(), ans = 0;
        auto valid = [&](int m) {
            for (int i = 0; i < N; ++i) {
                if (m >> i & 1) { // person i is good
                    for (int j = 0; j < N; ++j) { // test if there is any contradiction in the statements from person i
                        int good = m >> j & 1; // whether person j is good
                        if ((A[i][j] == 0 && good) || (A[i][j] == 1 && !good)) return false;
                    }
                }
            }
            return true;
        };
        for (int m = 1; m < (1 << N); ++m) {
            if (valid(m)) ans = max(ans, __builtin_popcount(m));
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/maximum-good-people-based-on-statements/discuss/1711219/C%2B%2B-Bitmask-Subset-Traversal-O(2N-*-N2)