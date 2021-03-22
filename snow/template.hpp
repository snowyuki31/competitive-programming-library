#pragma once
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

constexpr long long INF = 1LL << 60;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (n); ++i)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; --i)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define pb push_back
#define to_s to_string
#define len(v) (ll) v.size()
#define debug(x) cout << #x << ": " << (x) << '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> tpl;

template <typename T = ll>
using vec = vector<T>;

template <typename T = ll>
using vec2 = vector<vector<T>>;

template <typename T = ll>
using vec3 = vector<vector<vector<T>>>;

template < typename T >
inline bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template < typename T >
inline bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}