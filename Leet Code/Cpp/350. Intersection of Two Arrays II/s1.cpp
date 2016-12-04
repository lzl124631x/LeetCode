class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto i = nums1.begin(), j = nums2.begin();
        vector<int> v;
        while (i != nums1.end() && j != nums2.end()) {
            if (*j < *i) {
                while (j != nums2.end() && *j < *i) ++j;
            } else if (*i < *j) {
                while (i != nums1.end() && *i < *j) ++i;
            }
            if (i != nums1.end() && j != nums2.end() && *i == *j) {
                int target = *i;
                while (i != nums1.end() && *i == target
                && j != nums2.end() && *j == target) {
                    v.push_back(*i);
                    ++i;
                    ++j;
                }
                while (i != nums1.end() && *i == target) ++i;
                while (j != nums2.end() && *j == target) ++j;
            }
        }
        return v;
    }
};