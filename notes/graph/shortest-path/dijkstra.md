# Dijkstra's algorithm

Dijkstra's original algorithm found the shortest path between two given nodes, but a more common variant fixes a single node as the "source" node and finds shortest paths from the source to all other nodes in the graph, producing a **shortest-path tree**.

It's a greedy BFS algorithm.

## Algorithm

Give a graph `G = <V, E>`. Put the start point `v0` into a vertices set `S`. Let `M` be the edges between `S` and `V/S`.

## Implementation

Let `pq` be a `priority_queue` of pairs of the cost (i.e. the length of the shortest path from `src`) and the vertex index. The element with the smallest cost is at the top of the queue (i.e. min-heap). Initially `pq` only has `(0, src)` in it.

Let `dist[u]` be the cost of `u`. Initially `dist[src] = 0` and `dist[u] = INF` for all other vertices.



```cpp
// Time: O(E + VlogV)
// Space: O(E)
typedef unordered_map<int, unordered_map<int, int>> Graph;
typedef pair<int, int> iPair;
vector<int> dijkstra(Graph &graph, int N, int source) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dists(N, INT_MAX);
    pq.emplace(0, source);
    dists[source] = 0;
    while (pq.size()) {
        int u = pq.top().second;
        pq.pop();
        for (auto neighbor : graph[u]) {
            int v = neighbor.first, weight = neighbor.second;
            if (dists[v] > dists[u] + weight) {
                dists[v] = dists[u] + weight;
                pq.emplace(dists[v], v);
            }
        }
    }
    return dists;
}
```

## Problems

* [743. Network Delay Time](https://leetcode.com/problems/network-delay-time/)
* [787. Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)

## Reference
* [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)
