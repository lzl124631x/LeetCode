# [1912. Design Movie Rental System (Hard)](https://leetcode.com/problems/design-movie-rental-system/)

<p>You have a movie renting company consisting of <code>n</code> shops. You want to implement a renting system that supports searching for, booking, and returning movies. The system should also support generating a report of the currently rented movies.</p>

<p>Each movie is given as a 2D integer array <code>entries</code> where <code>entries[i] = [shop<sub>i</sub>, movie<sub>i</sub>, price<sub>i</sub>]</code> indicates that there is a copy of movie <code>movie<sub>i</sub></code> at shop <code>shop<sub>i</sub></code> with a rental price of <code>price<sub>i</sub></code>. Each shop carries <strong>at most one</strong> copy of a movie <code>movie<sub>i</sub></code>.</p>

<p>The system should support the following functions:</p>

<ul>
	<li><strong>Search</strong>: Finds the <strong>cheapest 5 shops</strong> that have an <strong>unrented copy</strong> of a given movie. The shops should be sorted by <strong>price</strong> in ascending order, and in case of a tie, the one with the <strong>smaller </strong><code>shop<sub>i</sub></code> should appear first. If there are less than 5 matching shops, then all of them should be returned. If no shop has an unrented copy, then an empty list should be returned.</li>
	<li><strong>Rent</strong>: Rents an <strong>unrented copy</strong> of a given movie from a given shop.</li>
	<li><strong>Drop</strong>: Drops off a <strong>previously rented copy</strong> of a given movie at a given shop.</li>
	<li><strong>Report</strong>: Returns the <strong>cheapest 5 rented movies</strong> (possibly of the same movie ID) as a 2D list <code>res</code> where <code>res[j] = [shop<sub>j</sub>, movie<sub>j</sub>]</code> describes that the <code>j<sup>th</sup></code> cheapest rented movie <code>movie<sub>j</sub></code> was rented from the shop <code>shop<sub>j</sub></code>. The movies in <code>res</code> should be sorted by <strong>price </strong>in ascending order, and in case of a tie, the one with the <strong>smaller </strong><code>shop<sub>j</sub></code> should appear first, and if there is still tie, the one with the <strong>smaller </strong><code>movie<sub>j</sub></code> should appear first. If there are fewer than 5 rented movies, then all of them should be returned. If no movies are currently being rented, then an empty list should be returned.</li>
</ul>

<p>Implement the <code>MovieRentingSystem</code> class:</p>

<ul>
	<li><code>MovieRentingSystem(int n, int[][] entries)</code> Initializes the <code>MovieRentingSystem</code> object with <code>n</code> shops and the movies in <code>entries</code>.</li>
	<li><code>List&lt;Integer&gt; search(int movie)</code> Returns a list of shops that have an <strong>unrented copy</strong> of the given <code>movie</code> as described above.</li>
	<li><code>void rent(int shop, int movie)</code> Rents the given <code>movie</code> from the given <code>shop</code>.</li>
	<li><code>void drop(int shop, int movie)</code> Drops off a previously rented <code>movie</code> at the given <code>shop</code>.</li>
	<li><code>List&lt;List&lt;Integer&gt;&gt; report()</code> Returns a list of cheapest <strong>rented</strong> movies as described above.</li>
</ul>

<p><strong>Note:</strong> The test cases will be generated such that <code>rent</code> will only be called if the shop has an <strong>unrented</strong> copy of the movie, and <code>drop</code> will only be called if the shop had <strong>previously rented</strong> out the movie.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["MovieRentingSystem", "search", "rent", "rent", "report", "drop", "search"]
[[3, [[0, 1, 5], [0, 2, 6], [0, 3, 7], [1, 1, 4], [1, 2, 7], [2, 1, 5]]], [1], [0, 1], [1, 2], [], [1, 2], [2]]
<strong>Output</strong>
[null, [1, 0, 2], null, null, [[0, 1], [1, 2]], null, [0, 1]]

<strong>Explanation</strong>
MovieRentingSystem movieRentingSystem = new MovieRentingSystem(3, [[0, 1, 5], [0, 2, 6], [0, 3, 7], [1, 1, 4], [1, 2, 7], [2, 1, 5]]);
movieRentingSystem.search(1);  // return [1, 0, 2], Movies of ID 1 are unrented at shops 1, 0, and 2. Shop 1 is cheapest; shop 0 and 2 are the same price, so order by shop number.
movieRentingSystem.rent(0, 1); // Rent movie 1 from shop 0. Unrented movies at shop 0 are now [2,3].
movieRentingSystem.rent(1, 2); // Rent movie 2 from shop 1. Unrented movies at shop 1 are now [1].
movieRentingSystem.report();   // return [[0, 1], [1, 2]]. Movie 1 from shop 0 is cheapest, followed by movie 2 from shop 1.
movieRentingSystem.drop(1, 2); // Drop off movie 2 at shop 1. Unrented movies at shop 1 are now [1,2].
movieRentingSystem.search(2);  // return [0, 1]. Movies of ID 2 are unrented at shops 0 and 1. Shop 0 is cheapest, followed by shop 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 3 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= entries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= shop<sub>i</sub> &lt; n</code></li>
	<li><code>1 &lt;= movie<sub>i</sub>, price<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
	<li>Each shop carries <strong>at most one</strong> copy of a movie <code>movie<sub>i</sub></code>.</li>
	<li>At most <code>10<sup>5</sup></code> calls <strong>in total</strong> will be made to <code>search</code>, <code>rent</code>, <code>drop</code> and <code>report</code>.</li>
</ul>


**Companies**:  
[Flipkart](https://leetcode.com/company/flipkart)

**Related Topics**:  
[Heap](https://leetcode.com/tag/heap/), [Design](https://leetcode.com/tag/design/), [Ordered Map](https://leetcode.com/tag/ordered-map/)

## Solution 1.

**Intuition**: Since `search` is reporting `unrented` movies while `report` is reporting `rented` movies, we can use two data structures to store `unrented` and `rented` movies, and `rent` and `drop` just moves the entry between these two data structures.

**Algorithm**:

`search`: for a specific `movie`, we need the cheapest 5 `{price, shop}` pairs. So we can use `unordered_map<Movie, set<pair<Price, Shop>>>` for `unrented` (`movie -> set of {price, shop}`) so that we can simply return the first 5 shops in the set of `unrented[movie]`.

`report`: we need the cheapest 5 `{price, shop, movie}` tuple. So we can use `set<tuple<Price, Shop, Movie>>` for `rented` so that we can simply return the first 5 `{shop, movie}` pairs in the `rented` set.

`rent`: Given `shop, movie`, we need to move this entry from `unrented` to `rented`. We need a separate map `map<pair<Shop, Movie>, Price> price` (`{shop, movie} -> price`) to query the price given pair `{shop, movie}`. Then we just need to `unrented[movie].erase({price, shop})` and `rented.emplace(price, shop, movie)`.

`drop`: Similar to `rent`, we first get the corresponding `price` then move the entry from `rented` to `unrented`.

```cpp
// OJ: https://leetcode.com/problems/design-movie-rental-system/
// Author: github.com/lzl124631x
// Time:
//     MovieRentingSystem: O(ElogE)
//     search: O(1)
//     rent: O(logE)
//     drop: O(logE)
//     report: O(1)
// Space: O(E)
class MovieRentingSystem {
    map<pair<int, int>, int> price; // {shop, movie} -> price
    unordered_map<int, set<pair<int, int>>> unrented; // movie -> set of {price, shop}
    set<tuple<int, int, int>> rented; // set of {price, shop, movie}
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {// shop, movie, price
            int shop = e[0], movie = e[1], p = e[2];
            price[{shop, movie}] = p; 
            unrented[movie].emplace(p, shop);
        }
    }
    vector<int> search(int movie) {
        auto &s = unrented[movie];
        vector<int> ans;
        int i = 0;
        for (auto it = s.begin(); i < 5 && it != s.end(); ++it, ++i) {
            ans.push_back(it->second);
        }
        return ans;
    }
    void rent(int shop, int movie) {
        int p = price[{shop, movie}];
        unrented[movie].erase({p, shop});
        rented.emplace(p, shop, movie);
    }
    void drop(int shop, int movie) {
        int p = price[{shop, movie}];
        rented.erase({p, shop, movie});
        unrented[movie].emplace(p, shop);
    }
    vector<vector<int>> report() {// shop, movie
        vector<vector<int>> ans;
        int i = 0;
        for (auto it = rented.begin(); it != rented.end() && i < 5; ++i, ++it) {
            auto [p, s, m] = *it;
            ans.push_back({s, m});
        }
        return ans;
    }
};
```