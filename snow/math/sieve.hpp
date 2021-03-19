#pragma once

#include <algorithm>
#include <numeric>
#include <vector>
#include <map>

namespace snow {

struct sieve {
    std::vector<int> _sieve;

    sieve(int n) : _sieve(++n){
        std::iota(_sieve.begin(), _sieve.end(), 0);
        for(int i = 2; i * i < n; ++i){
            if(_sieve[i] < i) continue;
            for(int j = i * i; j < n; j += i) if(_sieve[j] == j) _sieve[j] = i;
        }
    };

    std::map<int, int> factorize(int n){
        std::map<int, int> res;
        while(n != 1){
            res[_sieve[n]]++;
            n /= _sieve[n];
        }
        return res;
    };

    std::vector<int> divisor(int n){
        std::map<int, int> pf = factorize(n);
        std::vector<std::pair<int, int>> p;
        for(auto& [k, v] : pf) p.emplace_back(k, v);

        std::vector<int> res;
        auto culc = [&](auto &&self, int val, int ct)->void{
            if(ct == p.size()){
                res.emplace_back(val);
                return;
            }
            auto [prime, num] = p[ct];
            int tmp = 1;
            for(int _ = 0; _ < num + 1; ++_){
                self(self, val * tmp, ct + 1);
                tmp *= prime;
            }
        };
        culc(culc, 1, 0);
        //sort(ALL(res));
        return res;
    };

    std::vector<int> enumerate_prime() {
        std::vector<int> primes;
        for(int i = 2; i < _sieve.size(); ++i) {
            if(_sieve[i] == i) primes.emplace_back(i);
        }
        return primes;
    }
};

} // namespace snow