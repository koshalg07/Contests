#include <bits/stdc++.h>
#ifdef _WIN32
#include <intrin.h>
#endif
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;

    if (a == b) {
        cout << 0 << "\n\n";
        return;
    }

    if (a < b) {
        int msa = 0;
        if (a > 0) {
#if defined(__GNUC__) || defined(__clang__)
            msa = 31 - __builtin_clz(a);
#elif _WIN32
            unsigned long index;
            _BitScanReverse(&index, a);
            msa = index;
#endif
        }

        int msb = 0;
        if (b > 0) {
#if defined(__GNUC__) || defined(__clang__)
            msb = 31 - __builtin_clz(b);
#elif _WIN32
            unsigned long index;
            _BitScanReverse(&index, b);
            msb = index;
#endif
        }

        if (msa < msb) {
            cout << -1 << "\n";
        } else {
            cout << 1 << "\n";
            cout << (a ^ b) << "\n";
        }
    } else { // a > b
        if ((a ^ b) <= a) {
            cout << 1 << "\n";
            cout << (a ^ b) << "\n";
        } else {
            cout << 2 << "\n";
            cout << ((a ^ b) & a) << " " << a << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
