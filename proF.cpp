//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define F first
#define S second
#define reset(x) memset(x,0,sizeof(x))
#define sz(x) int(x.size())
#define oo 1000000000000000005
#define Task "proF"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
ll n, m, k;
ll f[40][105][105];
ll g[40][105][105];
void nhap() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++) f[0][i][j] = oo;
    while(m --){
        ll u, v, w;
        cin >> u >> v >> w;
        f[0][u][v] = min(f[0][u][v], w);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    nhap();
    int lg = log2(k);
    for(int i = 1; i <= lg; i ++)
        for(int u = 1; u <= n; u ++)
            for(int v = 1; v <= n; v ++) {
                f[i][u][v] = oo;
                for(int t = 1; t <= n; t ++)
                    f[i][u][v] = min(f[i][u][v], f[i - 1][u][t] + f[i - 1][t][v]);
            }
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            g[lg][i][j] = f[lg][i][j];
    for(int i = lg - 1; i >= 0; i --)
        for(int u = 1; u <= n; u ++)
            for(int v = 1; v <= n; v ++)
                if((k >> i) & 1) {
                    g[i][u][v] = oo;
                    for(int p = 1; p <= n; p ++)
                        g[i][u][v] = min(g[i][u][v], g[i + 1][u][p] + f[i][p][v]);
                }
                else g[i][u][v] = g[i + 1][u][v];

    ll res = oo;
    for(int i = 1; i <= n; i ++)
        res = min(res, g[0][i][i]);
    if (res == oo)
        cout << "-1";
    else cout << res;
}
