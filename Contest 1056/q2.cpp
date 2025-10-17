#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        int n, k;
        cin >> n >> k;
        int total = n * n;
        int m = total - k;
        if (m == 1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        vector<vector<char>> grid(n, vector<char>(n, 'R'));
        if (m == 0) {
            // already all 'R'
        } else if (n == 2 && m == 3) {
            // special case
            grid[0][0] = 'U';
            grid[0][1] = 'D';
            grid[1][0] = 'R';
            grid[1][1] = 'L';
        } else {
            vector<pair<int, int>> col_trap;
            int col = 0;
            int rem = m;
            while (rem >= 2) {
                int take = min(n, rem);
                col_trap.emplace_back(col, take);
                ++col;
                rem -= take;
            }
            bool adjusted = false;
            if (rem > 0) {
                // rem == 1
                for (int i = (int)col_trap.size() - 1; i >= 0; --i) {
                    int& ts = col_trap[i].second;
                    if (ts >= 3) {
                        --ts;
                        col_trap.emplace_back(col, 2);
                        ++col;
                        adjusted = true;
                        break;
                    }
                }
            }
            // if not adjusted, it would have been handled as special above
            for (auto [c, size] : col_trap) {
                for (int i = 0; i < size - 1; ++i) {
                    grid[i][c] = 'D';
                }
                if (size >= 2) {
                    grid[size - 1][c] = 'U';
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << grid[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}