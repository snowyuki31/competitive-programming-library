---
title: Sieve of Eratosthenes (for faster factorization)
documentation_of: snow/math/sieve.hpp
---

## About

最小の素因数を記録するエラトステネスの篩．

## How to use

```sieve sieve(n)``` : 前処理$O(N\log\logN)$

```bool sieve.isprime(x)``` : $x$が素数かどうかを返す

```std::vector<int> sieve.enumerate_primes()``` : 素数列挙

```std::map<int, int> factorize(int x)``` : $x$を素因数分解する．$O(\log x)$