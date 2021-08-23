//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define F first
#define S second
#define maxn 1000005
#define mu2(x) (1 << (x))
#define reset(x) memset(x,0,sizeof(x))
#define sz(x) int(x.size())
#define Task "proE"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
ll SpT[20][maxn];
ll n, m;
ll tim(ll x, ll l, ll r)
{
    ll u = l;
    for (int i = 18; i >= 0; i --)
        if(u + mu2(i) <= r + 1 && SpT[i][u] > x)
            u += mu2(i);
    return u;
}
ll tinh(ll x, ll l, ll r)
{
    l = tim(x, l, r);
    while(l <= r)
    {
        x %= SpT[0][l];
        l = tim(x, l, r);
    }
    return x;
}
void nhap() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> SpT[0][i];
    for (int i = 1; i <= 18; i ++)
		for (int j = 1; j <= n - mu2(i) + 1; j ++)
			SpT[i][j] = min(SpT[i - 1][j], SpT[i - 1][j + mu2(i - 1)]);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    nhap();
    while (m --)
    {
        ll x, l, r;
        cin >> x >> l >> r;
        cout << tinh(x, l, r) << "\n";
    }
}
