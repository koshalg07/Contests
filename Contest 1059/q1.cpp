/*****************************
 *  Author: _koshal_
 *  Contest: Codeforces / AtCoder / etc
 *  Template: Ultimate Competitive Programming Setup
 *****************************/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << x << endl
#else
#define dbg(x)
#endif

#define int long long
#define ll long long
#define ull unsigned long long
#define ld long double

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const int INF = 1e18;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

inline int mod_add(int a, int b, int m = MOD) { return ((a % m + b % m) % m + m) % m; }
inline int mod_sub(int a, int b, int m = MOD) { return ((a % m - b % m) % m + m) % m; }
inline int mod_mul(int a, int b, int m = MOD) { return ((a % m) * (b % m)) % m; }

int mod_pow(int a, int b, int m = MOD) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mod_mul(res, a, m);
        a = mod_mul(a, a, m);
        b >>= 1;
    }
    return res;
}

int mod_inv(int a, int m = MOD) { return mod_pow(a, m - 2, m); }

template<typename T> inline bool chmax(T &a, T b) { return (b > a) ? (a = b, true) : false; }
template<typename T> inline bool chmin(T &a, T b) { return (b < a) ? (a = b, true) : false; }

template <typename T>
void printv(const vector<T>& v) { for (auto &x : v) cout << x << " "; cout << "\n"; }

void solve() {
    // Your per-testcase logic here
    int n, m;
    cin >> n >> m;
    cout << n + m << "\n";
}

int32_t main() {
    fast_io();

    int T = 1;
    // cin >> T; // Uncomment if multiple testcases

    while (T--) solve();
    return 0;
}