// OJ: https://leetcode.com/problems/find-smallest-letter-greater-than-target/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto i = upper_bound(letters.begin(), letters.end(), target);
        return i == letters.end() ? letters[0] : *i;
    }
};