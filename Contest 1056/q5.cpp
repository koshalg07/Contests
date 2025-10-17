#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        int k;
        cin >> n >> m >> k;

        unordered_map<int, int> cnt;
        cnt.reserve(k * 2);

        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            cnt[y] ^= 1; // track parity only
        }

        bool mimo = false;
        if (n == 1) {
            mimo = cnt[2] & 1;
        } else {
            for (auto &[col, val] : cnt) {
                if (col >= 2 && (val & 1)) {
                    mimo = true;
                    break;
                }
            }
        }

        cout << (mimo ? "Mimo\n" : "Yuyu\n");
    }
    return 0;
}