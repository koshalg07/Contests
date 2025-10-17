#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;
int LOGN = 20;

vector<int> g[MAXN];
vector<int> colors[MAXN];
int up[MAXN][20];
int depth[MAXN];
unordered_map<int,int> freq[MAXN]; // freq[node][color] = # of color along path to root

void dfs(int u, int p) {
    if(p != -1) depth[u] = depth[p] + 1;
    up[u][0] = (p == -1 ? u : p);
    for(int i = 1; i < LOGN; i++)
        up[u][i] = up[up[u][i-1]][i-1];

    if(p != -1) freq[u] = freq[p]; // inherit from parent
    for(int c : colors[u])
        freq[u][c]++; // increment colors at this node

    for(int v : g[u]) if(v != p) dfs(v,u);
}

int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u,v);
    for(int k = LOGN-1; k >= 0; k--)
        if(depth[up[u][k]] >= depth[v]) u = up[u][k];
    if(u == v) return u;
    for(int k = LOGN-1; k >= 0; k--)
        if(up[u][k] != up[v][k]) {
            u = up[u][k];
            v = up[v][k];
        }
    return up[u][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n,k,s,q;
        cin >> n >> k >> s >> q;

        for(int i=1;i<=n;i++){
            g[i].clear();
            colors[i].clear();
            freq[i].clear();
        }

        for(int i=0;i<n-1;i++){
            int u,v; cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        for(int i=0;i<s;i++){
            int v,x; cin>>v>>x;
            colors[v].push_back(x);
        }

        vector<pair<int,int>> queries(q);
        for(int i=0;i<q;i++){
            cin>>queries[i].first>>queries[i].second;
        }

        depth[1]=0;
        dfs(1,-1);

        for(auto [u,v] : queries){
            if(u==v){
                cout<<colors[u].size()<<" ";
                continue;
            }
            int L = lca(u,v);
            int path_len = depth[u] + depth[v] - 2*depth[L] + 1;

            unordered_set<int> check;
            for(int c: colors[u]) check.insert(c);
            for(int c: colors[v]) check.insert(c);
            for(int c: colors[L]) check.insert(c);

            int ans = 0;
            for(int c: check){
                int cnt = freq[u][c] + freq[v][c] - 2*freq[L][c];
                if(find(colors[L].begin(),colors[L].end(),c)!=colors[L].end()) cnt++;
                if(cnt == path_len) ans++;
            }
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
}
