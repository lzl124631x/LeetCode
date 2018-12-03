// OJ: https://leetcode.com/problems/largest-component-size-by-common-factor/
// Author: github.com/lzl124631x
// Time: O(N * sqrt(W)) where N is length of A, W is max(A[i])
// Space: O(N)
class UnionFind {
private:
  vector<int> id, rank, size;
public:
  UnionFind(int cnt) {
    id = vector<int>(cnt);
    rank = vector<int>(cnt, 0);
    for (int i = 0; i < cnt; ++i) id[i] = i;
  }
  int find(int p) {
      if (id[p] == p) return p;
      return id[p] = find(id[p]);
  }
  bool connected(int p, int q) { return find(p) == find(q); }
  void connect(int p, int q) {
    int i = find(p), j = find(q);
    if (i == j) return;
    if (rank[i] < rank[j]) {
        id[i] = j;
    }
    else {
      id[j] = i;
      if (rank[i] == rank[j]) rank[j]++;
    }
  }
};
class Solution {
private:
    vector<int> getFactors(int N) {
        int d = 2;
        vector<int> factors;
        for (int d = 2; d * d <= N; ++d) {
            if (N % d) continue;
            while (N % d == 0) N /= d;
            factors.push_back(d);
        }
        if (N > 1 || factors.empty()) factors.push_back(N);
        return factors;
    }
public:
    int largestComponentSize(vector<int>& A) {
        int N = A.size();
        vector<vector<int>> factors(N);
        for (int i = 0; i < N; ++i) {
            factors[i] = getFactors(A[i]);
        }
        unordered_set<int> primeSet;
        for (auto &fs : factors) {
            for (int f : fs) primeSet.insert(f);
        }
        vector<int> primes(primeSet.begin(), primeSet.end());
        unordered_map<int, int> primeToIndex;
        for (int i = 0; i < primes.size(); ++i) primeToIndex[primes[i]] = i;
        UnionFind uf(primes.size());
        for (auto &fs : factors) {
            for (int f : fs) uf.connect(primeToIndex[fs.front()], primeToIndex[f]);
        }
        vector<int> count(primes.size(), 0);
        for (auto &fs : factors) count[uf.find(primeToIndex[fs[0]])]++;
        return *max_element(count.begin(), count.end());
    }
};