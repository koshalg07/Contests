#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &s) {
    int l = 0, r = (int)s.size() - 1;
    while (l < r) if (s[l++] != s[r--]) return false;
    return true;
}

bool isNonDecreasing(const string &s) {
    for (int i = 1; i < (int)s.size(); i++)
        if (s[i] < s[i - 1]) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        bool found = false;
        vector<int> best;

        function<void(int, int, vector<int>&)> dfs = [&](int start, int k, vector<int>& curr) {
            if (found) return;
            if ((int)curr.size() == k) {
                string p = "", x = "";
                for (int i = 0; i < n; i++) {
                    if (find(curr.begin(), curr.end(), i) != curr.end())
                        p.push_back(s[i]);
                    else
                        x.push_back(s[i]);
                }
                if (isNonDecreasing(p) && isPalindrome(x)) {
                    best.clear();
                    for (int i : curr) best.push_back(i + 1);
                    found = true;
                }
                return;
            }
            for (int i = start; i < n; i++) {
                curr.push_back(i);
                dfs(i + 1, k, curr);
                curr.pop_back();
                if (found) return;
            }
        };

        for (int k = 0; k <= n && !found; k++) {
            vector<int> curr;
            dfs(0, k, curr);
        }

        if (!found) {
            cout << -1 << "\n";
        } else {
            cout << best.size() << "\n";
            if (!best.empty()) {
                for (int i = 0; i < (int)best.size(); i++)
                    cout << best[i] << (i + 1 == best.size() ? '\n' : ' ');
            }
        }
    }

    return 0;
}


// not solved
