#define PROBLEM "https://yukicoder.me/problems/no/517"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

#include "snow/io/helper.hpp"
#include "snow/graph/topological-sort.hpp"

int main(){
    int N;
    std::cin >> N;
    std::vector<std::string> A(N);
    std::cin >> A;

    int M;
    std::cin >> M;
    std::vector<std::string> B(M);
    std::cin >> B;

    int idx = 0;
    std::map<char, int> memo, inv;
    for(auto s : A) for(auto c : s) {
        if(!memo.count(c)){
            memo[c] = idx;
            inv[idx] = c;
            ++idx;
        }
    }

    snow::Graph<int> G(memo.size());
    std::set<std::pair<int, int>> edges;

    for(auto s : A){
        for(int i = 0; i < (int)s.size() - 1; ++i){
            G.add_directed_edge(memo[s[i]], memo[s[i + 1]]);
            edges.insert({memo[s[i]], memo[s[i + 1]]});
        }
    }
    for(auto s : B){
        for(int i = 0; i < (int)s.size() - 1; ++i){
            G.add_directed_edge(memo[s[i]], memo[s[i + 1]]);
            edges.insert({memo[s[i]], memo[s[i + 1]]});
        }
    }

    auto ret = G.topological_sort();

    bool okay = true;
    okay &= !ret.empty();

    std::string ans = "";
    for(int i = 0; i < (int)ret.size() - 1; ++i){
        okay &= edges.count({ret[i], ret[i + 1]});
        ans += inv[ret[i]];
    }
    if(!ret.empty()) ans += inv[ret.back()];

    std::cout << (okay ? ans : "-1") << '\n';

    return 0;
}