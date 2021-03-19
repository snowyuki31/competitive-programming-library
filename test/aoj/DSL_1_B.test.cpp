// #define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"

// #include <iostream>
// #include "snow/datastructure/weighted-unionfind.hpp"

// int main() {
//     int n, q;
//     std::cin >> n >> q;

//     snow::WeightedUnionFind<int> wuf(n, 0);

//     while(q--){
//         int t;
//         std::cin >> t;

//         if(t == 0){
//             int x, y, z;
//             std::cin >> x >> y >> z;
//             wuf.merge(x, y, z);
//         }
//         else{
//             int x, y;
//             std::cin >> x >> y;
//             if(!wuf.same(x, y)) std::cout << '?' << '\n';
//             else std::cout << wuf.diff(x, y) << '\n';
//         }
//     }

//     return 0;
// }