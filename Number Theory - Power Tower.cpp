#include "Number Theory - Totient.cpp"
#include "Number Theory - Mod Pow.cpp"
using ll = long long;
ll mpow(ll x, ll y, ll z, ll m) {
    if(y == 0 and z == 0) {
        return x % m;
    } else if(y == 0) {
        return 1;
    } else {
        ll ph = phi(m);
        ll yz = 1;
        for(ll i = 0; i < z and yz < ph; i++) {
            yz *= y;
        }
        return mpow(x, (yz < ph ? 0 : ph) + mpow(y, z, ph), m);
    }
}