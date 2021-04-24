#pragma once
#include <iostream>
#include <complex>
#include <utility>

namespace geometry {

constexpr long double EPS = 1e-12;

template < typename T >
struct Point {
    std::complex<T> data;

    Point() : data(0, 0) {}
    Point(T a, T b) : data(a, b) {}
    Point(std::complex<T> c) : data(c) {}

    constexpr T real() const noexcept{ return data.real(); }
    constexpr T imag() const noexcept { return data.imag(); }
    constexpr Point operator+ (const Point &r) const noexcept { return Point(*this) += r; }
    constexpr Point operator- (const Point &r) const noexcept { return Point(*this) -= r; }
    constexpr Point operator* (const Point &r) const noexcept { return Point(*this) *= r; }
    constexpr Point operator/ (const Point &r) const noexcept { return Point(*this) /= r; }
    constexpr bool operator==(const Point &x) const noexcept { return this->data == x.data; }
    constexpr bool operator!=(const Point &x) const noexcept { return !(*this == x); }
    constexpr bool operator< (const Point &x) const noexcept { return this->real() < x.real() || (!(x.real() < this->real()) && this->imag() < x.imag()); }
    constexpr bool operator>=(const Point &x) const noexcept { return !(*this < x); }
    constexpr bool operator> (const Point &x) const noexcept { return x < *this; }
    constexpr bool operator<=(const Point &x) const noexcept { return !(*this > x); }
    
    constexpr Point& operator+=(const Point &x) noexcept {
        this->data += x.data;
        return *this;
    }
    constexpr Point& operator-=(const Point &x) noexcept {
        this->data -= x.data;
        return *this;
    }
    constexpr Point& operator*=(const Point &x) noexcept {
        this->data *= x.data;
        return *this;
    }
    constexpr Point& operator/=(const Point &x) noexcept {
        this->data /= x.data;
        return *this;
    }

    friend constexpr std::ostream& operator<< (std::ostream& os, const Point& x) noexcept {
        os << x.real() << " " << x.imag();
        return os;
    }
    friend constexpr std::istream& operator>>(std::istream& is, Point& x) noexcept {
        T a, b;
        is >> a >> b;
        x = Point(a, b);
        return is;
    }

    template <std::size_t N>
    T get() const{
        if constexpr (N == 0) return data.real();
        else return data.imag();
    }
};

template < typename T>
T abs(const Point<T> &x) { return abs(x.data); }

template < typename T>
T arg(const Point<T> &x) { return arg(x.data); }

template < typename T>
T norm(const Point<T> &x) { return norm(x.data); }

template < typename T>
Point<T> conj(const Point<T> &x) { return Point<T>(conj(x.data)); }

template < typename T>
Point<T> proj(const Point<T> &x) { return Point<T>(proj(x.data)); }

template < typename T >
T cross(const Point<T> &a, const Point<T> &b){ return a.real() * b.imag() - a.imag() * b.real(); }

template < typename T >
T dot(const Point<T> &a, const Point<T> &b){ return a.real() * b.real() + a.imag() * b.imag(); }

} // namespace geometry

namespace std {
    template< typename T >
    struct tuple_size<geometry::Point<T>> : integral_constant<size_t, 2> {};

    template< size_t N, typename T >
    struct tuple_element<N, geometry::Point<T>> { using type = T; };

} // namespace std