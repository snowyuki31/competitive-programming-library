#pragma once

#include <vector>
#include <algorithm>
#include <numeric>

namespace snow {

struct simple_sieve {
    public:
        simple_sieve(int n) : _n(n + 1), prime(_n, true) {
            if(n >= 0) prime[0] = false;
            if(n >= 1) prime[1] = false;
            for(int i = 2; i * i <= n; ++i) if(prime[i]) {
                for (int j = i * i; j <= n; j += i) prime[j] = false;
            }
        }

        bool isprime(int x){
            return !!prime[x];
        }

        std::vector<int> enumerate_primes() {
            std::vector<int> prime_list;
            prime_list.reserve(std::count(prime.begin(), prime.end(), true));
            for(int i = 0; i < prime.size(); ++i) if(prime[i]) prime_list.emplace_back(i);
            return prime_list;
        }

    protected:
        int _n;
        std::vector<bool> prime;
};

} // namespace snow