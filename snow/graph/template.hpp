#pragma once

#include <vector>
#include <limits>

namespace snow {

/**
 * @brief Graph template
 */
template < typename T >
struct Graph {
    struct Edge {
        int from, to;
        T weight;
        Edge() : from(0), to(0), weight(0) {}
        Edge(int from, int to, T weight) : from(from), to(to), weight(weight) {}
    };
    using Edges = std::vector<Edge>;

    const T INF = std::numeric_limits<T>::max();
    std::vector<Edges> G;

    Graph() : G() {}
    
    Graph(int n) : G(n) {}

    Edges operator[](int k) const{
        return G[k];
    }

    size_t size() const{
        return G.size();
    }

    void add_edge(int a, int b, T w = 1){
        G[a].emplace_back(a, b, w);
        G[b].emplace_back(b, a, w);
    }

    void add_directed_edge(int a, int b, T w = 1){
        G[a].emplace_back(a, b, w);
    }

    void add_arrow(int a, int b, T w = 1){
        add_directed_edge(a, b, w);
    }

    //Dijkstra
    std::vector<T> dijkstra(int s) const;

    //Bellman-Ford
    std::vector<T> bellman_ford(int s) const;

    //Warshall-Floyd
    std::vector<std::vector<T>> warshall_floyd() const;

    //Topological sort
    std::vector<int> topological_sort() const;
};

} // namespace snow