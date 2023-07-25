# [2353. Design a Food Rating System (Medium)](https://leetcode.com/problems/design-a-food-rating-system)

<p>Design a food rating system that can do the following:</p>
<ul>
	<li><strong>Modify</strong> the rating of a food item listed in the system.</li>
	<li>Return the highest-rated food item for a type of cuisine in the system.</li>
</ul>
<p>Implement the <code>FoodRatings</code> class:</p>
<ul>
	<li><code>FoodRatings(String[] foods, String[] cuisines, int[] ratings)</code> Initializes the system. The food items are described by <code>foods</code>, <code>cuisines</code> and <code>ratings</code>, all of which have a length of <code>n</code>.

	<ul>
		<li><code>foods[i]</code> is the name of the <code>i<sup>th</sup></code> food,</li>
		<li><code>cuisines[i]</code> is the type of cuisine of the <code>i<sup>th</sup></code> food, and</li>
		<li><code>ratings[i]</code> is the initial rating of the <code>i<sup>th</sup></code> food.</li>
	</ul>
	</li>
	<li><code>void changeRating(String food, int newRating)</code> Changes the rating of the food item with the name <code>food</code>.</li>
	<li><code>String highestRated(String cuisine)</code> Returns the name of the food item that has the highest rating for the given type of <code>cuisine</code>. If there is a tie, return the item with the <strong>lexicographically smaller</strong> name.</li>
</ul>
<p>Note that a string <code>x</code> is lexicographically smaller than string <code>y</code> if <code>x</code> comes before <code>y</code> in dictionary order, that is, either <code>x</code> is a prefix of <code>y</code>, or if <code>i</code> is the first position such that <code>x[i] != y[i]</code>, then <code>x[i]</code> comes before <code>y[i]</code> in alphabetic order.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input</strong>
["FoodRatings", "highestRated", "highestRated", "changeRating", "highestRated", "changeRating", "highestRated"]
[[["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]], ["korean"], ["japanese"], ["sushi", 16], ["japanese"], ["ramen", 16], ["japanese"]]
<strong>Output</strong>
[null, "kimchi", "ramen", null, "sushi", null, "ramen"]

<strong>Explanation</strong>
FoodRatings foodRatings = new FoodRatings(["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]);
foodRatings.highestRated("korean"); // return "kimchi"
                                    // "kimchi" is the highest rated korean food with a rating of 9.
foodRatings.highestRated("japanese"); // return "ramen"
                                      // "ramen" is the highest rated japanese food with a rating of 14.
foodRatings.changeRating("sushi", 16); // "sushi" now has a rating of 16.
foodRatings.highestRated("japanese"); // return "sushi"
                                      // "sushi" is the highest rated japanese food with a rating of 16.
foodRatings.changeRating("ramen", 16); // "ramen" now has a rating of 16.
foodRatings.highestRated("japanese"); // return "ramen"
                                      // Both "sushi" and "ramen" have a rating of 16.
                                      // However, "ramen" is lexicographically smaller than "sushi".
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>n == foods.length == cuisines.length == ratings.length</code></li>
	<li><code>1 &lt;= foods[i].length, cuisines[i].length &lt;= 10</code></li>
	<li><code>foods[i]</code>, <code>cuisines[i]</code> consist of lowercase English letters.</li>
	<li><code>1 &lt;= ratings[i] &lt;= 10<sup>8</sup></code></li>
	<li>All the strings in <code>foods</code> are <strong>distinct</strong>.</li>
	<li><code>food</code> will be the name of a food item in the system across all calls to <code>changeRating</code>.</li>
	<li><code>cuisine</code> will be a type of cuisine of <strong>at least one</strong> food item in the system across all calls to <code>highestRated</code>.</li>
	<li>At most <code>2 * 10<sup>4</sup></code> calls <strong>in total</strong> will be made to <code>changeRating</code> and <code>highestRated</code>.</li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Design](https://leetcode.com/tag/design/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Ordered Set](https://leetcode.com/tag/ordered-set/)

**Similar Questions**:
* [Design a Number Container System (Medium)](https://leetcode.com/problems/design-a-number-container-system/)
* [Most Popular Video Creator (Medium)](https://leetcode.com/problems/most-popular-video-creator/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/design-a-food-rating-system
// Author: github.com/lzl124631x
// Time:
//      FoodRatings: O(NS * logR * logF) where N is the number of foods,
//                      S is the max length of string,
//                      R is the max number of unique ratings per cuisine
//                      and F is max the number of food in each rating of each cuisine.
//      changeRating: O(S * logR * logF)
//      highestRated: O(S)
// Space: O(N)
class FoodRatings {
    unordered_map<string, map<int, set<string>>> m;
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            m[cuisines[i]][ratings[i]].insert(foods[i]);
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
        }
    }
    void changeRating(string food, int newRating) {
        int oldRating = foodToRating[food];
        auto &cuisineMap = m[foodToCuisine[food]];
        cuisineMap[oldRating].erase(food);
        if (cuisineMap[oldRating].empty()) cuisineMap.erase(oldRating);
        cuisineMap[newRating].insert(food);
        foodToRating[food] = newRating;
    }
    string highestRated(string cuisine) {
        return *m[cuisine].rbegin()->second.begin();
    }
};
```