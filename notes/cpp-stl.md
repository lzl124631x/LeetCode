# C++ Standard Template Library (STL)

## lower_bound, upper_bound, equal_range

`lower_bound`: Returns an iterator pointing to the first element in the range [first,last) which does not compare less than val. (i.e. `>=`)

`upper_bound`: Returns an iterator pointing to the first element in the range [first,last) which compares greater than val. (i.e. `>`)

`equal_range`: Returns the bounds of the subrange that includes all the elements of the range [first,last) with values equivalent to val.

## set, map and their variants

`set`: The values are sorted.

`map`: The keys are sorted.

`multiset`: The values are sorted and duplicate values are allowed.

`multimap`: The keys are sorted and duplicate keys are allowed.

`unordered_set`, `unordered_map`, `unordered_multiset`, `unordered_multimap` are not sorted and organize their elements using hash tables. When you don't care about the ordering, use them. Their average time complexities are constants.
