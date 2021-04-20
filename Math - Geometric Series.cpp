#include "Math - Modular Arithmetic.cpp"
// Σ r^i for i in [0, ∞), r < 1
// fraction geom0_inf(fraction r) {
template <typename T = mint> T geom0_inf(T r) {
    return 1 / (1 - r);
}
// Σ r^i for i in [1, ∞), r < 1
// fraction geom1_inf(fraction r) {
template <typename T = mint> T geom1_inf(T r) {
    return r / (1 - r);
}
// Σ r^i for i in [0, n), r < 1
// fraction geom0_fin(fraction r, ll n) {
template <typename T = mint> T geom0_fin(T r, ll n) {
    return (1 - (r ^ n)) / (1 - r);
}
// Σ r^i for i in [1, n], r < 1
// fraction geom1_fin(fraction r, ll n) {
template <typename T = mint> T geom1_fin(T r, ll n) {
    return r * (1 - (r ^ n)) / (1 - r);
}
// Σ (i+1) * r^i for i in [0, ∞), r < 1
// fraction staircase0_inf(fraction r) {
template <typename T = mint> T staircase0_inf(T r) {
    return geom0_inf(r) / (1 - r);
}
// Σ i * r^i for i in [1, ∞), r < 1
// fraction staircase1_inf(fraction r) {
template <typename T = mint> T staircase1_inf(T r) {
    return r * geom0_inf(r) / (1 - r);
}
// Σ (i+1) * r^i for i in [0, n), r < 1
// fraction staircase0_fin(fraction r, ll n) {
template <typename T = mint> T staircase0_fin(T r, ll n) {
    return (geom0_fin(r, n) - n * (r ^ n)) / (1 - r);
}
// Σ i * r^i for i in [1, n], r < 1
// fraction staircase1_fin(fraction r, ll n) {
template <typename T = mint> T staircase1_fin(T r, ll n) {
    return r * (geom0_fin(r, n) - n * (r ^ n)) / (1 - r);
}
