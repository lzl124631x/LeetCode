# C++ Standard Template Library (STL)

## lower_bound, upper_bound, equal_range

* `lower_bound`
  - Returns an iterator pointing to the first element in the range `[first,last)` which does not compare less than val. (i.e. `>=`).
  - The returned index `i` partitions the array `A` into two halves so that all elements in range `[first, i)` are `< x`, all elements in range `[i, last)` are `>= x`.
  - Same as `bisect.bisect_left` in python.

* `upper_bound`
  - Returns an iterator pointing to the first element in the range `[first,last)` which compares greater than val. (i.e. `>`).
  - The returned index `i` partitions the array `A` into two halves so that all elements in range `[first, i)` are `<= x`, all elements in range `[i, last)` are `> x`.
  - Same as `bisect.bisect_right` or `bisect.bisect` in python.

`equal_range`: Returns the bounds of the subrange that includes all the elements of the range `[first,last)` with values equivalent to val.

## set, map and their variants

`set`: The values are sorted.

`map`: The keys are sorted.

`multiset`: The values are sorted and duplicate values are allowed.

`multimap`: The keys are sorted and duplicate keys are allowed.

`unordered_set`, `unordered_map`, `unordered_multiset`, `unordered_multimap` are not sorted and organize their elements using hash tables. When you don't care about the ordering, use them. Their average time complexities are constants.

## Priority Queue

By default, `priority_queue` uses `less` as comparator, and is **Max-heap.** (In fact, STL always use `less` as the default comparator whenever it needs comparison.)

If you want to get a Min-heap, use `priority_queue<int, vector<int>, greater<int>>`.

It uses `make_heap`, `push_heap` and `pop_heap` algorithm functions under the hood.

### Why is it Max-heap by default?

According to http://www.cplusplus.com/reference/queue/priority_queue/

> Elements are popped from the "back" of the specific container, which is known as the top of the priority queue.

So `priority_queue` uses `less` to sort the elements in ascending order -- the smaller the element is, the closer it is to the front.

And since the **last element** if regarded as the top, so it is the largest element. Thus, by default `priority_queue` is a Max-heap. 

## Algorithm

* `iota`: Fills the range `[first, last)` with sequentially increasing values, starting with value and repetitively evaluating `++value`. Generating a sequentially increasing index array is one example use case as shown [here](https://leetcode.com/problems/maximum-profit-in-job-scheduling/discuss/409188/C%2B%2B-with-picture)