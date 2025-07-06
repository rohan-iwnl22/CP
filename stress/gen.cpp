#include <bits/stdc++.h>
using namespace std;

using ll = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll random(ll a, ll b) {
    return uniform_int_distribution<ll>(a, b)(rng);
}

int main() {
    int n = random(1, 20);          
    int l = random(1, 50);          
    int r = random(l, 100);          

    cout << n << " " << l << " " << r << "\n";

    for (int i = 0; i < n; ++i) {
        cout << random(1, 50) << " ";
    }
    cout << "\n";

    return 0;
}
