---
title: Sieve of Eratosthenes
documentation_of: snow/math/simple-sieve.hpp
---

## About

エラトステネスの篩．

## How to

```simple_sieve sieve(n)``` : 前処理$O(n\log\log n)$

```bool sieve.isprime(x)``` : $x$が素数かどうかを返す

```vector<int> sieve.enumerate_primes()``` : 素数列挙