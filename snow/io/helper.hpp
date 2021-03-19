#pragma once
#include <iostream>
#include <vector>
#include <set>

template< typename T1, typename T2 >
std::ostream &operator << (std::ostream &os, const std::pair< T1, T2 > &p) {
    os << p.first << " " << p.second;
    return os;
}

template< typename T1, typename T2 >
std::istream &operator >> (std::istream &is, std::pair< T1, T2 > &p) {
    is >> p.first >> p.second;
    return is;
}

template< typename T1, typename T2, typename T3 >
std::ostream &operator << (std::ostream &os, const std::tuple< T1, T2, T3 > &t) {
    os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t);
    return os;
}

template< typename T1, typename T2, typename T3 >
std::istream &operator >> (std::istream &is, std::tuple< T1, T2, T3 > &t) {
    is >> get<0>(t) >> get<1>(t) >> get<2>(t);
    return is;
}

template< typename T >
std::ostream &operator << (std::ostream &os, const std::vector< T > &v){
    for (int i = 0; i < (int)v.size(); ++i) {
        os << v[i] << (i + 1 != v.size() ? " " : "");
    }
    return os;
}

template< typename T >
std::istream &operator >>  (std::istream &is, std::vector< T > &v){
    for(T &in : v) is >> in;
    return is;
}

template< typename T >
std::ostream &operator << (std::ostream &os, const std::set< T > &st){
    int ct = 0;
    for(auto& s : st) cout << s << (++ct != st.size() ? " " : "");
    return os;
}
