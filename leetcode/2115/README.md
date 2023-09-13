# [2115. Find All Possible Recipes from Given Supplies (Medium)](https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/)

<p>You have information about <code>n</code> different recipes. You are given a string array <code>recipes</code> and a 2D string array <code>ingredients</code>. The <code>i<sup>th</sup></code> recipe has the name <code>recipes[i]</code>, and you can <strong>create</strong> it if you have <strong>all</strong> the needed ingredients from <code>ingredients[i]</code>. Ingredients to a recipe may need to be created from <strong>other </strong>recipes, i.e., <code>ingredients[i]</code> may contain a string that is in <code>recipes</code>.</p>

<p>You are also given a string array <code>supplies</code> containing all the ingredients that you initially have, and you have an infinite supply of all of them.</p>

<p>Return <em>a list of all the recipes that you can create. </em>You may return the answer in <strong>any order</strong>.</p>

<p>Note that two recipes may contain each other in their ingredients.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
<strong>Output:</strong> ["bread"]
<strong>Explanation:</strong>
We can create "bread" since we have the ingredients "yeast" and "flour".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
<strong>Output:</strong> ["bread","sandwich"]
<strong>Explanation:</strong>
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
<strong>Output:</strong> ["bread","sandwich","burger"]
<strong>Explanation:</strong>
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
We can create "burger" since we have the ingredient "meat" and can create the ingredients "bread" and "sandwich".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == recipes.length == ingredients.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= ingredients[i].length, supplies.length &lt;= 100</code></li>
	<li><code>1 &lt;= recipes[i].length, ingredients[i][j].length, supplies[k].length &lt;= 10</code></li>
	<li><code>recipes[i], ingredients[i][j]</code>, and <code>supplies[k]</code> consist only of lowercase English letters.</li>
	<li>All the values of <code>recipes</code> and <code>supplies</code>&nbsp;combined are unique.</li>
	<li>Each <code>ingredients[i]</code> does not contain any duplicate values.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Graph](https://leetcode.com/tag/graph/), [Topological Sort](https://leetcode.com/tag/topological-sort/)

**Similar Questions**:
* [Course Schedule II (Medium)](https://leetcode.com/problems/course-schedule-ii/)
* [Count Good Meals (Medium)](https://leetcode.com/problems/count-good-meals/)

## Solution 1. Topological Sort

```cpp
// OJ: https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/
// Author: github.com/lzl124631x
// Time: O(NW) where `N` is the total number of unique recipes and ingredients and `W` is the maximum number of occurrence of an ingredients showing up in recipes
// Space: O(NW)
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int id = 0;
        unordered_map<string, int> m; // name -> id
        for (auto &r : recipes) m[r] = id++;
        for (auto &v : ingredients) {
            for (auto &s : v) {
                if (m.count(s) == 0) m[s] = id++;
            }
        }
        vector<vector<int>> G(id);
        vector<int> indegree(id);
        for (int i = 0; i < recipes.size(); ++i) {
            for (auto &s : ingredients[i]) {
                G[m[s]].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for (auto &s : supplies) q.push(m[s]);
        vector<string> ans;
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int v : G[u]) {
                if (--indegree[v] == 0) {
                    q.push(v);
                    ans.push_back(recipes[v]);
                }
            }
        }
        return ans;
    }
};
```