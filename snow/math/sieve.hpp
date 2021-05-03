#pragma once

#include <algorithm>
#include <numeric>
#include <vector>
#include <map>

namespace snow {

struct Sieve {
    public:
        Sieve(int n) : _n(n + 1), _sieve(_n){
            std::iota(_sieve.begin(), _sieve.end(), 0);
            for(int i = 2; i * i <= n; ++i){
                if(_sieve[i] < i) continue;
                for(int j = i * i; j <= n; j += i) if(_sieve[j] == j) _sieve[j] = i;
            }
        }

        std::map<int, int> factorize(int x){
            std::map<int, int> res;
            while(x != 1){
                res[_sieve[x]]++;
                x /= _sieve[x];
            }
            return res;
        }

        std::vector<int> enumerate_primes() {
            std::vector<int> primes;
            for(int i = 2; i < (int)_sieve.size(); ++i) {
                if(_sieve[i] == i) primes.emplace_back(i);
            }
            return primes;
        }

        bool isprime(int x){
            if(x == 0 or x == 1) return 0;
            return _sieve[x] == x;
        }

    protected:
        int _n;
        std::vector<int> _sieve;
};

} // namespace snow