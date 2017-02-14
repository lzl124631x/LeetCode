class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        vector<int> v;
        for (int n : nums1) s.insert(n);
        for (int n : nums2) {
            if (s.count(n)) {
                s.erase(n);
                v.push_back(n);
            }
        }
        return v;
    }
};