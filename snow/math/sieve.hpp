#pragma once

#include <algorithm>
#include <numeric>
#include <vector>
#include <map>

namespace snow {

struct sieve {
    public:
        sieve(int n) : n(n + 1), _sieve(n + 1){
            std::iota(_sieve.begin(), _sieve.end(), 0);
            for(int i = 2; i * i < n; ++i){
                if(_sieve[i] < i) continue;
                for(int j = i * i; j < n; j += i) if(_sieve[j] == j) _sieve[j] = i;
            }
        }

        std::map<int, int> factorize(int n){
            std::map<int, int> res;
            while(n != 1){
                res[_sieve[n]]++;
                n /= _sieve[n];
            }
            return res;
        }

        std::vector<int> enumerate_prime() {
            std::vector<int> primes;
            for(int i = 2; i < _sieve.size(); ++i) {
                if(_sieve[i] == i) primes.emplace_back(i);
            }
            return primes;
        }

        bool isprime(int n){
            return _sieve[n] == n;
        }

    protected:
        std::vector<int> _sieve;
        int n;
};

} // namespace snow