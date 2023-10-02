# [553. Optimal Division (Medium)](https://leetcode.com/problems/optimal-division/)

<p>Given a list of <b>positive integers</b>, the adjacent integers will perform the float division. For example, [2,3,4] -&gt; 2 / 3 / 4.</p>

<p>However, you can add any number of parenthesis at any position to change the priority of operations. You should find out how to add parenthesis to get the <b>maximum</b> result, and return the corresponding expression in string format. <b>Your expression should NOT contain redundant parenthesis.</b></p>

<p><b>Example:</b><br>
</p><pre><b>Input:</b> [1000,100,10,2]
<b>Output:</b> "1000/(100/10/2)"
<b>Explanation:</b>
1000/(100/10/2) = 1000/((100/10)/2) = 200
However, the bold parenthesis in "1000/(<b>(</b>100/10<b>)</b>/2)" are redundant, <br>since they don't influence the operation priority. So you should return "1000/(100/10/2)". 

Other cases:
1000/(100/10)/2 = 50
1000/(100/(10/2)) = 50
1000/100/10/2 = 0.5
1000/100/(10/2) = 2
</pre>
<p></p>

<p><b>Note:</b>
</p><ol>
<li>The length of the input array is [1, 10].</li>
<li>Elements in the given array will be in range [2, 1000].</li>
<li>There is only one optimal division for each test case.</li>
</ol>
<p></p>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/)

## Solution 1. Brute Force + Memo

The goal is to make the numerator as great as possible, and the denominator as small as possible.

Assume `F(x, y, z, ...)` is the greatest division we can get out of `x, y, z, ...`, and `G(x, y, z, ...)` is the smallest division we can get.

```
F(x) = G(x) = x

F(x, y) = G(x, y) = x / y

F(x, y, z) = max(
  F(x, y) / z,
  x / G(y, z))
G(x, y, z) = min(
  G(x, y) / z,
  x / F(y, z))

...
```

So we can compute `F` and `G` from small scale to large scale. `F(...nums)` is the answer.

```cpp
// OJ: https://leetcode.com/problems/optimal-division/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^3)
class Pair {
private:
    bool isNum;
    int num;
    Pair *numerator, *denominator;
    float val;
public:
    Pair(int n) : isNum(true), num(n), val(n) {}
    Pair(Pair* n, Pair* d) : isNum(false), numerator(n), denominator(d), val(numerator->val / denominator->val) {}
    float value() { return val; }
    string toString() {
        if (isNum) return to_string(num);
        string ans;
        ans = numerator->toString() + "/";
        if (!denominator->isNum) ans += "(";
        ans += denominator->toString();
        if (!denominator->isNum) ans += ")";
        return ans;
    }
};
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        unordered_map<int, unordered_map<int, Pair*>> great, small;
        for (int i = 0; i < nums.size(); ++i)
            great[i][i + 1] = small[i][i + 1] = new Pair(nums[i]);
        for (int len = 2; len <= nums.size(); ++len) {
            for (int i = 0; i < nums.size() - len + 1; ++i) {
                Pair *greatest = NULL, *smallest = NULL;
                for (int j = i + 1; j < i + len; ++j) {
                    if (!greatest || greatest->value() < great[i][j]->value() / small[j][i + len]->value()) {
                        greatest = new Pair(great[i][j], small[j][i + len]);
                    }
                    if (!smallest || smallest->value() > small[i][j]->value() / great[j][i + len]->value()) {
                        smallest = new Pair(small[i][j], great[j][i + len]);
                    }
                }
                great[i][i + len] = greatest;
                small[i][i + len] = smallest;
            }
        }
        return great[0][nums.size()]->toString();
    }
};
```

## Solution 2. Math

To maximize `a, b, c` we pick the greater one from `a / b / c` and `a / (b / c)`.

Let's compare them.

Since `a / b / c = a / (b * c)` and `a / (b / c) = a * c / b`.

Multiplying `b / a` we get `1 / c` and `c`. So given `c >= 1` we always have `1 / c <= c`, and thus `a / b / c <= a / (b / c)`.

So given `a, b, c`, `a / (b / c)` is always greater than `a / b / c`.

For `a, b, c, d`:
* If we divide it into `a` and `b, c, d`, the greatest result is `a / (b / c / d) = a * c * d / b`.
* If we divide it into `a, b` and `c, d`, the result is `(a / b) / (c / d) = a * d / (b * c)`.
* If we devide it into `a, b, c` and `d`, the greatest result is `a / (b / c) / d = a * c / (b * d)`.

We can see `a * c * d / b` is the greatest since its denominator is the smallest.

So given `a, b, c, d`, `a / (b / c / d)` is the greatest division.

Generally, the best division of `x_1, x_2, ..., x_n` is `x_1 / (x_2 / ... / x_n)` (which equals `x_1 * x_3 * ... x_n / x_2`).

```cpp
// OJ: https://leetcode.com/problems/optimal-division/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if (nums.size() == 1) return to_string(nums[0]);
        if (nums.size() == 2) return to_string(nums[0]) + "/" + to_string(nums[1]);
        string ans = to_string(nums[0]) + "/(" + to_string(nums[1]);
        for (int i = 2; i < nums.size(); ++i) ans += "/" + to_string(nums[i]);
        return ans += ")";
    }
};
```