// https://discuss.leetcode.com/topic/66580/n-2logn-cpp-solution-beats-100-582ms
class Solution {
public:
	double getdistance(pair<int, int> p1, pair<int, int>p2) {
		return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
	}
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		int n = points.size();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			vector<double> v;
			for (int j = 0; j < n; j++) {
				if (j == i)
					v.push_back(-1);
				else
					v.push_back(getdistance(points[i], points[j]));
			}
			sort(v.begin(), v.end());
			double k = -1;
			int count = 0;
			for (int j = 0; j < n; j++) {
				if (k == v[j])
					count++;
				else {
					ans += (count*(count - 1));
					count = 1;
					k = v[j];
				}
			}
			if(count!=1)
				ans += (count*(count - 1));
		}
		return ans;
	}
};
// Time O(N^2lgN), Space O(N)