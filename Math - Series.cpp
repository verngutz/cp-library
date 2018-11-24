#include <bits/stdc++.h>
#include "Math - Modular Arithmetic.cpp"
// Σ i for i in [0, n)
ll arith0(ll n) {
    return n * (n - 1) / 2;
}
// Σ i for i in [1, n]
ll arith1(ll n) {
    return n * (n + 1) / 2;
}
// Σ a0 + r*i for i in [0, n)
ll arith0(ll a0, ll r, ll n) {
    return a0 * n + r * arith0(n);
}
// Σ a0 + r*i for i in [1, n]
ll arith1(ll a0, ll r, ll n) {
    return a0 * n + r * arith1(n);
}
// Σ r^i for i in [0, ∞), r < 1
// fraction geom0_inf(fraction r) {
modint geom0_inf(modint r) {
    return 1 / (1 - r);
}
// Σ r^i for i in [1, ∞), r < 1
// fraction geom1_inf(fraction r) {
modint geom1_inf(modint r) {
    return r / (1 - r);
}
// Σ r^i for i in [0, n), r < 1
// fraction geom0_fin(fraction r, ll n) {
modint geom0_fin(modint r, ll n) {
    return (1 - (r ^ n)) / (1 - r);
}
// Σ r^i for i in [1, n], r < 1
// fraction geom1_fin(fraction r, ll n) {
modint geom1_fin(modint r, ll n) {
    return r * (1 - (r ^ n)) / (1 - r);
}
// Σ (i+1) * r^i for i in [0, ∞), r < 1
// fraction staircase0_inf(fraction r) {
modint staircase0_inf(modint r) {
    return geom0_inf(r) / (1 - r);
}
// Σ i * r^i for i in [1, ∞), r < 1
// fraction staircase1_inf(fraction r) {
modint staircase1_inf(modint r) {
    return r * geom0_inf(r) / (1 - r);
}
// Σ (i+1) * r^i for i in [0, n), r < 1
// fraction staircase0_fin(fraction r, ll n) {
modint staircase0_fin(modint r, ll n) {
    return (geom0_fin(r, n) - n * (r ^ n)) / (1 - r);
}
// Σ i * r^i for i in [1, n], r < 1
// fraction staircase1_fin(fraction r, ll n) {
modint staircase1_fin(modint r, ll n) {
    return r * (geom0_fin(r, n) - n * (r ^ n)) / (1 - r);
}
