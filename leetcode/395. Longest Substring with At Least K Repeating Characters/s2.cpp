// https://discuss.leetcode.com/topic/57134/two-short-c-solutions-3ms-and-6ms
class Solution {
private:
    int longestSubstring(string &s, int k, int begin, int end) {
        unordered_map<char, int> cnt;
        for (int i = begin; i < end; ++i) cnt[s[i]]++;
        int i = begin, ans = 0;
        while (i < end) {
            while (i < end && cnt[s[i]] < k) ++i;
            int j = i;
            while (j < end && cnt[s[j]] >= k) ++j;
            if (i == begin && j == end) return end - begin;
            ans = max(ans, longestSubstring(s, k, i, j));
            i = j;
        }
        return ans;
    }
public:
    int longestSubstring(string s, int k) {
        return longestSubstring(s, k, 0, s.size());
    }
};