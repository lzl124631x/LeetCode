# Euler path

An Euler path is a path visiting every edge exactly once.

Any connected directed graph where all nodes have equal in-degree and out-degree has an Euler circuit (an Euler path ending where it started.)

## Hierholzer’s Algorithm

[Hierholzer’s Algorithm for directed graph](https://www.geeksforgeeks.org/hierholzers-algorithm-directed-graph/)

We can find the circuit/path in `O(E)`, i.e. linear time.

The algorithem is as follows ([wiki](https://en.wikipedia.org/wiki/Eulerian_path#Hierholzer.27s_algorithm)):
* Choose any starting vertex `v`, and follow a trail of edges from that vertex until returning to `v`. It is not possible to get stuck at any vertex other than `v`, because the even degree of all vertices ensures that, when the trail enters another vertex `w` there must be an unused edge leaving `w`. The tour formed in this way is a closed tour, but may not cover all the vertices and edges of the initial graph.
* As long as there exists a vertex `u` that belongs to the current tour but that has adjacent edges not part of the tour, start another trail from `u`, following unused edges until returning to `u`, and join the tour formed in this way to the previous tour.
* Since we assume the original graph is connected, repeating the previous step will exhaust all edges of the graph.

## Problems

* [753. Cracking the Safe (Hard)](https://leetcode.com/problems/cracking-the-safe/)