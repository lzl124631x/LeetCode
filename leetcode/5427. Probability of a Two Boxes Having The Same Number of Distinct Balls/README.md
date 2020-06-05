var title = `# [${$('[data-cy=question-title]').textContent} (${$('[diff]').textContent})](${location.href})\n\n`;
var question = `${$('.question-content__JfgR').children[0].innerHTML}\n\n`;

var companyClass = '.company-tag-wrapper__1rBy a';
var companyElems = $$(companyClass);
var companies = companyElems.length? `**Companies**:  \n${companyElems.map(x => `[${$('.btn-content__lOBM', x).textContent}](${x.href})`).join(', ')}\n\n` : '';

var topicClass = '.topic-tag__1jni';
var topicElems = $$(topicClass);
var topics = topicElems.length ?`**Related Topics**:  \n${topicElems.map(x => `[${x.textContent}](${x.href})`).join(', ')}\n\n` : '';

var similarQuestionClass = '.question__25Pw';
var similarQuestionTitleClass = '.title__1kvt';
var similarQuestionDifficultyClass = '.difficulty__ES5S';
var similarQuestonElems = $$(similarQuestionClass);
var similarQuestions = similarQuestonElems.length ? `**Similar Questions**:\n${similarQuestonElems.map(x => { let link = $(similarQuestionTitleClass, x); return `* [${link.textContent} (${$(similarQuestionDifficultyClass,x).textContent})](${link.href})` }).join('\n')}\n\n` : '' ;

copy(
    `${title}`
    + `${question}`
    + `${companies}`
    + `${topics}`
    + `${similarQuestions}`
    + `## Solution 1.\n\n\`\`\`cpp\n\n\`\`\``)

## Solution 1.

First, compute the total number of distinct shuffles. 

```
total = factorial(sum( A[i] | 0 <= i < k )) / ( factorial(A[0]) * factorial(A[1]) * ... * factorial(A[k-1]) )
```

where `factorial(x)` is the number of permutations of `x` different items. For example, `factorial(3) = 1 * 2 * 3 = 6`.

I denote the right-hand side of the above equation as `perm(A)` where `A` is an array of numbers. We'll need it later.

Then we need to compute the count of valid splits. Assume array `a` and `b` is a split of `A`, then:

* `size(a) == size(b) == size(A) == k`
* For each `0 <= i < k`, `a[i] + b[i] = A[i]`

For example, if `A = [1, 2, 2]`, then `a = [1, 0, 1]`, `b = [0, 2, 1]` is a *valid* split of `A`.

A split is valid if:
* Each of them contains half of the balls: `sum( a[i] | 0 <= i < k ) == sum( b[i] | 0 <= i < k ) == sum( A[i] | 0 <= i < k ) / 2`
* They contain equal number of distinct colors: `count(a) == count(b)` where `count(x)` is the number of positive numbers in array `x`.

For example, if `A = [1, 1, 2]`, then `a = [1, 0, 1]`, `b = [0, 1, 1]` is a split of `A`.

So we can use DFS to get different valid splits of `A`. For each valid split `a, b`, the count of distinct permutation of the split is `perm(a) * perm(b)` .

The answer is `total` divided by the sum of `perm(a) * perm(b)` of all valid splits `a, b`.

```cpp
// OJ: https://leetcode.com/contest/weekly-contest-191/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/
// Author: github.com/lzl124631x
// Time: O((M+1)^K * K) where M is the maximum number of A[i]. It's O(7^8 * 8) given the constraints of this problem.
// Space: O(K)
class Solution {
    double perm(vector<int> &A) {
        double ans = 1;
        for (int i = 0, j = 1; i < A.size(); ++i) {
            int n = A[i];
            for (int k = 1; k <= n; ++k, ++j) ans = ans * j / k; 
        }
        return ans;
    }
    int sum = 0;
    double dfs(vector<int> &A, vector<int>& a, vector<int> &b, int i, int sa, int sb) {
        if (sa > sum / 2 || sb > sum / 2) return 0; // invalid split because either `a` or `b` takes up more than half of the balls.
        if (i == A.size()) {
            int ca = 0, cb = 0;
            for (int i = 0; i < A.size(); ++i) ca += a[i] > 0;
            for (int i = 0; i < A.size(); ++i) cb += b[i] > 0;
            if (ca != cb) return 0; // invalid split because `a` and `b` don't have the same number of distinct colors.
            return perm(a) * perm(b);
        }
        double ans = 0;
        for (int j = 0; j <= A[i]; ++j) { // try different splits at the `i`-th element, i.e. a[i] + b[i] = A[i]`
            a[i] = j;
            b[i] = A[i] - j;
            ans += dfs(A, a, b, i + 1, sa + a[i], sb + b[i]);
        }
        a[i] = b[i] = 0;
        return ans;
    }
public:
    double getProbability(vector<int>& A) {
        sum = accumulate(begin(A), end(A), 0);
        vector<int> a(A.size()), b(A.size());
        return dfs(A, a, b, 0, 0, 0) / perm(A);
    }
};
```